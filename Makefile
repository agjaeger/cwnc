

test_sources = $(wildcard test/*)

test: FORCE
	clang++ -Iexternal/gtest/include -pthread $(test_sources) external/gtest/lib/libgtest.a -o build/test_executable
	./build/test_executable

FORCE: ;
