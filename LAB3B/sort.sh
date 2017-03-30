#!/bin/sh

#Write a program to sort the strings that are passed as a command line 
#arguments. (ex: ./script.sh “OS Lab” “Quoted strings” “Command Line” “Sort It” )
#The output should be “Command Line” “OS Lab” “Quoted strings” “Sort It”. 
# (make use of userdefined sort function)

declare -a arr
arr=("$@")
sort()
{

	for ((i=0;i<$#-1;i++))
		do

			for ((j=i+1;j<$#;j++))
				do
					if [ ${arr[$i]} \> ${arr[$j]} ] ;
					then

						t=${arr[$i]}
						arr[$i]=${arr[$j]}
						arr[$j]=$t	
					fi
			done
	done

echo "${arr[@]}"
}

sort "${arr[@]}"


