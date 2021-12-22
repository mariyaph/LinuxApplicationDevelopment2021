bin_PROGRAMS = prog
pkgdata_DATA = prog.man
%.man: %
	$(HELP2MAN) --no-info --output=$@ --name="Guessing name" ./$<