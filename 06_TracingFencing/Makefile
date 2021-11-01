GENERATES = move testfile  remove.so
FILES = testfile iamPROTECTed infile outfile
all:test
move: move.c
	gcc -Wall -Wextra  move.c -o move
remove.so: remove.c
	gcc remove.c -fPIC -shared -o remove.so -ldl
test: move remove.so tests
	echo 1 2 3 4 5 > testfile

	cp testfile iamPROTECTed
	LD_PRELOAD=./remove.so ./move iamPROTECTed outfile
	if [ -f iamPROTECTed ]; then echo ok;else echo not ok; fi

	cp testfile infile
	LD_PRELOAD=./remove.so ./move infile outfile
	if [ -f infile ]; then echo not ok; else echo ok; fi

	sh tests
clean:
	rm -f $(GENERATES) $(FILES)