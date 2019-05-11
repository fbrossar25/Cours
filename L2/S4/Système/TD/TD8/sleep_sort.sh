#! /bin/sh
for i in $*
do
	(sleep $i; echo $i)&
done