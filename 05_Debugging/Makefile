GENERATES = range *output*
test: output_01 output_02
	cmp output_01 file_01
	cmp output_02 file_02
range: range.c
	    gcc -g -O0 range.c -o range
output_01: range script_01
	cgdb -x  script_01 ./range
	cat gdb.output_01 | grep @@@ | tr -d "@@@" > output_01
output_02: range script_02
	cgdb -x  script_02 ./range
	cat gdb.output_02 | grep @@@ | tr -d "@@@" > output_02
clean:
	rm -f $(GENERATES)