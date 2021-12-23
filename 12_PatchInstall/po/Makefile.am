pkgdata_DATA = ru/LC_MESSAGES/prog.mo
pkgdatadir = $(localedir)/ru/LC_MESSAGES
ru.po: ../src/prog.c
	xgettext --keyword=_ --add-comments $< -o messages.po
	msgmerge -U $@ messages.po
ru/LC_MESSAGES/prog.mo: ru.po
	mkdir -p ru/LC_MESSAGES
	msgfmt -o $@ $<