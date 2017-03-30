#!/bin/sh

#Implement wordcount script that takes -linecount, -wordcount, -charcount 
#options and performs accordingly, on the input file that is passed as 
#command line argument (use case statement)

case $2 in
	'-linecount')		wc -l $1 ;;
	'-wordcount')		wc -w $1 ;;
	'-charcount')		wc -c $1 ;;
	
esac
