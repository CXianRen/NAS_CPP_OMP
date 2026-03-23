make clean

function build() {
    benches="bt cg ep ft is lu mg sp"
    BUILD_CLASS=$1
    VERSION_TAIL=$2
    for bench in $benches; do
        make $bench CLASS=$BUILD_CLASS VERSION_TAIL=$VERSION_TAIL
    done 2>&1 | tee ./bin/build_${BUILD_CLASS}${VERSION_TAIL}.log
}

build "C" ""
build "C" "_dynamic"
build "C" "_monodynamic"
build "C" "_taskloop"

build "D" ""
build "D" "_dynamic"
build "D" "_monodynamic"
build "D" "_taskloop"

build "S" ""
build "S" "_dynamic"
build "S" "_monodynamic"
build "S" "_taskloop"