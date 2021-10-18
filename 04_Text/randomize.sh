x=0
y=0
sym=''
t=0
if [ $# -gt 0 ]
then t=$1
fi
k=0
text=$(od -An -t x1 -v)
for c in $text
do
    if [ $c != 0a ]
    then
        if [ $c != 20 ]
        then
            sym+="$c $y $x \n"
            k="$(($k+1))"
        fi
        x="$(($x+1))"
    else
        y="$(($y+1))"
        x=0
    fi
done
y_max=$y
rand=$(/bin/echo -e "$sym"|head -$k|shuf)
tput clear
/bin/echo "$rand" |
while read c y x
do
    tput cup $y $x
    /bin/echo -ne "\x$c"
    tput cup $y $x
    sleep $t
done
tput cup $y_max 0