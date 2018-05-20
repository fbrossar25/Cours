#!/bin/bash
if [ $# -eq 2 -a $1 -lt $2 ]
then 
	i=$1
	while [ i -lt $2 ]
	do
		history | grep "^ $i" | cut -d' ' -f4- 
	done
else
fi
