SHELL=/bin/sh
CLASS=S
SFILE=config/suite.def

VERSION_TAIL=""

default: header
	@ $(SHELL) sys/print_instructions


all: BT SP LU MG FT IS CG EP

BT: bt
bt: header
	cd BT; $(MAKE) CLASS=$(CLASS) VERSION_TAIL=$(VERSION_TAIL)
		       
SP: sp		       
sp: header	       
	cd SP; $(MAKE) CLASS=$(CLASS) VERSION_TAIL=$(VERSION_TAIL)
		       
LU: lu		       
lu: header	       
	cd LU; $(MAKE) CLASS=$(CLASS) VERSION_TAIL=$(VERSION_TAIL)
		       
MG: mg		       
mg: header	       
	cd MG; $(MAKE) CLASS=$(CLASS) VERSION_TAIL=$(VERSION_TAIL)
		       
FT: ft		       
ft: header	       
	cd FT; $(MAKE) CLASS=$(CLASS) VERSION_TAIL=$(VERSION_TAIL)
		       
IS: is		       
is: header	       
	cd IS; $(MAKE) CLASS=$(CLASS) VERSION_TAIL=$(VERSION_TAIL)
		       
CG: cg		       
cg: header	       
	cd CG; $(MAKE) CLASS=$(CLASS) VERSION_TAIL=$(VERSION_TAIL)
		       
EP: ep		       
ep: header	       
	cd EP; $(MAKE) CLASS=$(CLASS) VERSION_TAIL=$(VERSION_TAIL)


# Awk script courtesy cmg@cray.com
suite:
	@ awk '{ if ($$1 !~ /^#/ &&  NF > 0)                              \
	printf "make %s CLASS=%s\n", $$1, $$2 }' $(SFILE)  \
	| $(SHELL)


# It would be nice to make clean in each subdirectory (the targets
# are defined) but on a really clean system this will won't work
# because those makefiles need config/make.def
clean:
	- rm -f core 
	- rm -f *~ */core */*~ */*.o */npbparams.hpp */*.obj */*.exe
	- rm -f sys/setparams sys/makesuite sys/setparams.hpp
	- rm -f bin/*

cleanall: clean
	- rm -r bin/*

veryclean: clean
	- rm config/make.def config/suite.def Part*
	- rm bin/sp.* bin/lu.* bin/mg.* bin/ft.* bin/bt.* bin/is.* bin/ep.* bin/cg.*

header:
	@ $(SHELL) sys/print_header

kit: 
	- makekit -s100k -k30 * */* */*/*


