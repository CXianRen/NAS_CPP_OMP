#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define _HACK_MAX_THREADS 8
#define _HACK_MAX_RECORDS 8192 // 记录条数上限，根据需要调整

// 1. Thread-local timing (Padded)
typedef struct {
	int id;
    double exec_time;
} thread_info;

thread_info t_infos[_HACK_MAX_THREADS][_HACK_MAX_RECORDS];

typedef struct {
    int val;
    char padding[64 - sizeof(int)];
} padded_int;

padded_int counters[_HACK_MAX_THREADS]; // 每个线程的记录计数


// 3. Dump function (Called automatically at exit using GCC attribute)
void __attribute__((destructor)) _hack_dump_stats() {
    printf("\n=== HACK PROFILING DUMP ===\n");
    for(int i=0; i<counters[0].val; i++) {
        for(int j=0; j<_HACK_MAX_THREADS; j++) {
			if (j == 0) {
				printf("%d,", t_infos[j][i].id);
			}
			printf("%f,", t_infos[j][i].exec_time);
		}
        printf("\n");
    }
    printf("=== END DUMP ===\n");
}


#define MONITOR_START(lid)\
    double t_start_##lid = omp_get_wtime();\
    int tid_##lid = omp_get_thread_num();

#define MONITOR_STOP(lid)\
    double t_end_##lid = omp_get_wtime();\
	{ \
		int idx = counters[tid_##lid].val; \
		t_infos[tid_##lid][idx].id = lid; \
		t_infos[tid_##lid][idx].exec_time = (t_end_##lid - t_start_##lid); /* Convert to milliseconds */\
	} \
    counters[tid_##lid].val++; \
	_Pragma("omp barrier")
