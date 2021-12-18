TESTS = test1 test2 test3 test4
check_PROGRAMS = test1 test2 test3 test4
AM_CFLAGS = -I$(top_builddir)/src @CHECK_CFLAGS@
LDADD = $(top_builddir)/src/libprog.la @CHECK_LIBS@
.ts.c:
	checkmk $< > $@