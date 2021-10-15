GENERATES = prog prog-a prog-so liboutput_static.a liboutput.so file*
TRASH = *.o *~ o.*
CFLAGS = -fPIC

all: test

test: prog prog-a prog-so
	./prog 2>file1_1
	./prog-a 2>&1 | sed s/prog-a/prog/ > file1_2
	LD_LIBRARY_PATH=`pwd` ./prog-so 2>&1 | sed s/prog-so/prog/ > file1_3
	
	./prog aaa 1>file2_1
	./prog-a aaa 1>file2_2
	LD_LIBRARY_PATH=`pwd` ./prog-so aaa 1>file2_3

	./prog aaa bbb ccc 1>file3_1
	./prog-a aaa bbb ccc 1>file3_2
	LD_LIBRARY_PATH=`pwd` ./prog-so aaa bbb ccc 1>file3_3
	
	cmp file1_1 file1_2
	cmp file1_2 file1_3
	cmp file2_1 file2_2
	cmp file2_2 file2_3
	cmp file3_1 file3_2
	cmp file3_2 file3_3

fun.o:  outlib.h
prog: const.o fun.o prog.o

liboutput_static.a: fun.o const.o
	ar -rcs liboutput_static.a fun.o const.o
prog-a: prog.o liboutput_static.a
	gcc  prog.o -loutput_static -L. -o prog-a

liboutput.so: fun.o const.o
	gcc -shared fun.o const.o -o liboutput.so
prog-so: prog.o liboutput.so
	gcc -L. prog.o -loutput -o prog-so

clean:
	rm -f $(TRASH)
distclean:      clean
	rm -rf $(GENERATES)