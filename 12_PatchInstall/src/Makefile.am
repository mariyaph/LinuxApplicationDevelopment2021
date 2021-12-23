bin_PROGRAMS = prog
AM_CFLAGS=-D'LOCALE_PATH="$(localedir)"'
man1_MANS = prog.1
%.1: %
	$(HELP2MAN) --no-info --output=$@ --name="Guessing name" ./$<