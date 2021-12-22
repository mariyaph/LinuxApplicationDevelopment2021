SUBDIRS = src po
@DX_RULES@
all-local: doxygen-doc
http: doxygen-doc
	python3 -m http.server --directory $</html
gitclean:
	git clean -fd