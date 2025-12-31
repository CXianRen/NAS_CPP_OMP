SHELL=/bin/sh
BENCHMARK=cg
BENCHMARKU=CG

include ../config/make.def

OBJS = cg.o ${COMMON}/c_print_results.o  \
       ${COMMON}/c_${RAND}.o ${COMMON}/c_timers.o ${COMMON}/c_wtime.o

include ../sys/make.common

${PROGRAM}: config ${OBJS}
	${CLINK} ${CLINKFLAGS} -o ${PROGRAM} ${OBJS} ${C_LIB}

cg.o:             cg.cpp npbparams.hpp
	${CCOMPILE} cg.cpp

clean:
	- rm -f *.o *~ 
	- rm -f npbparams.hpp core



# export PATH=$PWD/external/install/x86/sycl/bin:$PATH
# export CPLUS_INCLUDE_PATH=~/DARE/Gromacs/external/install/x86/omp/current/include/:$CPLUS_INCLUDE_PATH
# export LD_LIBRARY_PATH=~/DARE/Gromacs/external/install/x86/omp/current/lib:$LD_LIBRARY_PATH
# export LIBRARY_PATH=~/DARE/Gromacs/external/install/x86/omp/current/lib:$LIBRARY_PATH