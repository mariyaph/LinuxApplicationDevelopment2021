#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([prog], [0.0], [bug@gmail.com])
AM_INIT_AUTOMAKE([foreign])
#DX_INIT_DOXYGEN([prog])
AC_CONFIG_SRCDIR([src/prog.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PATH_PROG([HELP2MAN], [help2man])
# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h locale.h  stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([setlocale])

AC_CONFIG_FILES([Makefile src/Makefile po/Makefile])
AC_OUTPUT
