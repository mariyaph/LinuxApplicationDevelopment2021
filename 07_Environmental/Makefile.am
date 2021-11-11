bin_PROGRAMS=rhasher
rhasher_SOURCES=rhasher.c
test: rhasher
	sh test.sh
clean:
	ls | grep -v configure.ac| grep -v Makefile.am | grep -v rhasher.c | grep -v test.s? | xargs rm -rf
