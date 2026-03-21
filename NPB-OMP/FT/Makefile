SHELL=/bin/sh
BENCHMARK=ft
BENCHMARKU=FT

include ../config/make.def

OBJS = ${BENCHMARK}${VERSION_TAIL}.o ${COMMON}/c_${RAND}.o ${COMMON}/c_print_results.o \
       ${COMMON}/c_timers.o ${COMMON}/c_wtime.o #../omp-prof.o

include ../sys/make.common

${PROGRAM}: config ${OBJS}
	${CLINK} ${CLINKFLAGS} -o ${PROGRAM} ${OBJS} ${C_LIB}

${BENCHMARK}${VERSION_TAIL}.o:             ${BENCHMARK}${VERSION_TAIL}.cpp npbparams.hpp
	${CCOMPILE} ${BENCHMARK}${VERSION_TAIL}.cpp -o ${BENCHMARK}${VERSION_TAIL}.o

clean:
	- rm -f *.o *~ mputil*
	- rm -f ft npbparams.hpp core
