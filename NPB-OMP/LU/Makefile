SHELL=/bin/sh
BENCHMARK=lu
BENCHMARKU=LU

include ../config/make.def

OBJS = ${BENCHMARK}${VERSION_TAIL}.o ${COMMON}/c_print_results.o \
       ${COMMON}/c_timers.o ${COMMON}/c_wtime.o

include ../sys/make.common

${PROGRAM}: config ${OBJS}
	${CLINK} ${CLINKFLAGS} -o ${PROGRAM} ${OBJS} ${C_LIB}

${BENCHMARK}${VERSION_TAIL}.o:		${BENCHMARK}${VERSION_TAIL}.cpp npbparams.hpp
	${CCOMPILE} ${BENCHMARK}${VERSION_TAIL}.cpp -o ${BENCHMARK}${VERSION_TAIL}.o

clean:
	- /bin/rm -f npbparams.hpp
	- /bin/rm -f *.o *~
