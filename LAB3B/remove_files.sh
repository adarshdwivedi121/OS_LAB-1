#!/bin/sh

#Write a shell script to remove all files 
#that are passed as command line arguments interactively.

for i in $@
do
	rm -i $i
done
