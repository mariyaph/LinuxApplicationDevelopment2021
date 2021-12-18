AM_CFLAGS  = -ansi -pedantic -Wall -Wextra -O3 -g3
if COND_GCOV
    AM_CFLAGS+=-fprofile-arcs -ftest-coverage -O0 -g
endif    

lib_LTLIBRARIES = libprog.la
libprog_la_SOURCES = libprog.c
libprog_la_LDFLAGS = -version-info 0:0:0

bin_PROGRAMS = prog
prog_SOURCES = prog.c
prog_LDADD = libprog.la

gcov:
	gcov .libs/libprog  -j