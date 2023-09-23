CXX ?= g++
CXXFLAGS ?= --std=c++17 -Wall -Werror -pedantic -g -Wno-sign-compare -Wno-comment

game.exe: 

.SUFFIXES:
clean:
        rm -rvf *.exe *.out.txt *.out.ppm *.dSYM *.stackdump