#!/bin/bash
./esub '([0-9]+)([0-9])+' 'abcd' 1>/dev/null 2> file01
echo 'Not enough arguments' > file02
cmp file01 file02
if [ $? -eq 0 ]; then echo ok; else echo not ok; fi 

./esub '([0-9]+)([0-9])+' '==' 'abcd'> file01
echo 'No Match' > file02
cmp file01 file02
if [ $? -eq 0 ]; then echo ok; else echo not ok; fi 

./esub '([0-9]+)([0-9])+' '=\3=' '12abcd'  1>/dev/null 2> file01
echo 'Incorrect number of pocket' > file02
cmp file01 file02
if [ $? -eq 0 ]; then echo ok; else echo not ok; fi 

./esub '([0-9]+)([0-9])+' '\\\' '12abcd'  1>/dev/null 2> file01
echo 'Unfinished command' > file02
cmp file01 file02
if [ $? -eq 0 ]; then echo ok; else echo not ok; fi 

echo 'abc567def' | sed -E 's/([0-9]+)([0-9]+)([0-9]+)/===/' > file01
./esub '([0-9]+)([0-9]+)([0-9]+)' '===' 'abc567def'> file02
cmp file01 file02
if [ $? -eq 0 ]; then echo ok; else echo not ok; fi 

echo 'abc567def' | sed -E 's/([0-9]+)([0-9]+)([0-9]+)/=\0=\1=\2=\3=/' > file01
./esub '([0-9]+)([0-9]+)([0-9]+)' '=\0=\1=\2=\3=' 'abc567def'> file02
cmp file01 file02
if [ $? -eq 0 ]; then echo ok; else echo not ok; fi 

echo 'abc567def' | sed -E 's/([0-9]+)([0-9]+)([0-9]+)/\=\\1=\\\2=\\\\3=\\\\\=/' > file01
./esub '([0-9]+)([0-9]+)([0-9]+)' '\=\\1=\\\2=\\\\3=\\\\\=' 'abc567def'> file02
cmp file01 file02
if [ $? -eq 0 ]; then echo ok; else echo not ok; fi 