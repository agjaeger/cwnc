
sources = $(wildcard source/*)
test_sources = $(wildcard test/*)

build: FORCE
	clang -Iinclude/ $(sources) -o build/cwnc

run: FORCE
	./build/cwnc

build_test: FORCE
	clang++ -Iexternal/gtest/include -pthread $(test_sources) external/gtest/lib/libgtest.a -o build/test_executable

run_test: FORCE
	./build/test_executable

FORCE: ;
