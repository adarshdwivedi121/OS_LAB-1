#!/bin/sh
 
#Write a menu driven shell script to read list of patterns as command 
#line arguments and perform following operations.
#	a. Search the patterns in the given input file. Display all 
#          lines containing the pattern in the given input file.
#	b. Delete all occurances of the pattern in the given input file.
#	c. Exit from the shell script.
#0 is filename, 1 is inputFile, 2 is Option, 3- are patterns

declare -a arr
arr=("$@")

case $2 in
	'a') 
		for ((i=2;i<$#;i++))
		do
			echo ${arr[$i]}
			grep ${arr[$i]} $1
		done ;;

	'b') 
		for ((i=2;i<$#;i++))
		do
			sed -ie s/${arr[$i]}//g $1
		done ;;

	'c') 	exit ;; 
esac
