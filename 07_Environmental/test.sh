echo "SHA1 Makefile.am" | ./rhasher   > file01
sha1sum Makefile.am | cut -f 1 -d " " | tr a-z A-Z > file02 
cmp file01 file02
echo "MD5 Makefile.am" | ./rhasher  '>' > file01
md5sum Makefile.am | cut -f 1 -d " " | tr a-z A-Z > file02
cmp file01 file02
