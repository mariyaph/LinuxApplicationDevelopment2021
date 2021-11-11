#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([rhasher.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([foreign subdir-objects])
# Checks for programs.
AC_PROG_CC

# Checks for libraries.

AC_CHECK_LIB([rhash],[rhash_library_init, rhash_msg, rhash_file, rhash_print_bytes], [], [AC_MSG_ERROR([Rhash is needed])])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])
AC_CHECK_HEADER([rhash.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([strerror])

#Optional clues
AC_ARG_WITH([readline],
    [AS_HELP_STRING([--without-readline],  [disable support for readline])], [], [with_readline=yes])
    AS_IF([test "x$with_readline" != xno], [
    AC_CHECK_LIB([readline],[readline], [], [AC_MSG_ERROR([Readline is needed])])
    AC_CHECK_HEADER([readline/readline.h])
    ])

AC_ARG_ENABLE([readline],
    AS_HELP_STRING([--enable-readline], [Use readline instead of getline]),
    AC_DEFINE(FUN,[],[if FUN is defined than use readline instead of getline])
  )    
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
