pkgdata_DATA = ru/LC_MESSAGES/prog.mo
ru.po: ../prog.c
	xgettext --keyword=_ --add-comments $< -o messages.po
	msgmerge -U $@ messages.po
ru/LC_MESSAGES/prog.mo: ru.po
	mkdir -p ru/LC_MESSAGES
	msgfmt -o $@ $<