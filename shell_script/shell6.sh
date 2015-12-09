clear

if [ $#  -eq  0 ]

then
echo "error: the argument is not given"
echo "pls provide the argument"
exit 1
fi
n=$1
for((i=0; i<5; i++))
do 
echo " this is uiet $1"
echo " $1 * $i =`expr $i \* $1` "
done
