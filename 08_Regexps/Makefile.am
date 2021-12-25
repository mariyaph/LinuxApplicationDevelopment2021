bin_PROGRAMS=esub
esub_SOURCES=esub.c
test: esub
	sh  test.sh
clean:
	ls | grep -v configure.ac| grep -v Makefile.am | grep -v esub.c | grep -v test.sh | xargs rm -rf
