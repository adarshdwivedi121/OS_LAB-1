#!/bin/sh
echo Enter number:
read p
flag=0
for ((i=2;i<=p/2;i++)) ; do
	x=`expr $p % $i|bc`
	if [ $x==0 ] ; then
		flag=1
		echo x $x i $i flag $flag
	fi
done 

if [ $flag==0 ] ;
then 
echo Number is prime.
else
echo Number is not prime.
fi
