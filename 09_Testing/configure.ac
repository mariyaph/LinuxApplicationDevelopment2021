#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_INIT([growable-buf], [VERSION], [BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([src/prog.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE ([foreign])
LT_INIT([disable-static])

# Checks for programs.
AC_PROG_CC


PKG_CHECK_MODULES([CHECK],check)
# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stddef.h stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 tests/Makefile])
AC_ARG_ENABLE([gcov],
              [AS_HELP_STRING([--enable-gcov],
              [use gcov to test the test suite])],
              [],
              [enable_gcov=no])
AM_CONDITIONAL([COND_GCOV],[test '!' "$enable_gcov" = no])

AC_OUTPUT
