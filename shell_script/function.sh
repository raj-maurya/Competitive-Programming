
function cal()
{
n1=$1
op=$2
n3=$3
ans=0
if [ $# -eq 3 ];
then
# ans=$(( $n1 $op $n2))
# echo " $n1 $op $n2 =$ans"
 #return $ans
echo "`5 + 2`"
else
echo "function requires atleast 3 arguments"

fi
return
}
#cal 5+3
#cal 10 - 2
echo $?
