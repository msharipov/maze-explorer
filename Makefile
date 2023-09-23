CXX ?= g++
CXXFLAGS ?= --std=c++17 -Wall -Werror -pedantic -g -Wno-sign-compare -Wno-comment

items.test: items_test.cpp items.cpp
    $(CXX) $(CXXFLAGS) $^ -o $@

.SUFFIXES:
clean:
    rm -rvf *.exe *.out.txt *.out.ppm *.dSYM *.stackdump