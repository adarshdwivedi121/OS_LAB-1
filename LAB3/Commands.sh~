echo Enter two numbers:
read a b
echo $a $b
c=`expr $a+$b|bc`
echo Sum is $c
d=`echo $a-$b+$c|bc`
echo $d

#-----IF ELSE----
echo Enter value of a:
read a
if [ $a -gt 0 ] ;
then
	echo $a "is greater than zero"
elif [ $a == 0 ]; then
	echo $a "is equal to zero"
else 
echo $a "is less than zero"
fi

#-----FOR LOOP----
for ((i=0;i<10;i++)); do
	echo $i
done

#-------
x=`ls`
for i in $x; do
	echo $i
done

#----SWITCH CASE----
echo (Switch Case) Enter value of a b:
read a b
echo Enter value of c (a for Add/s for Sub):
read c
case $c in
	'a') x=`echo $a+$b|bc`
		    echo $x ;;
	's') x=`echo $a-$b|bc`
			echo $x ;;
esac

#----WHILE-----
echo (While Loop) Enter value of i:
read i
while ((i<5)) ; do
	echo -n $i              #-n supresses newline
    ((i++))
done


	
