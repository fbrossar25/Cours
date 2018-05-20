#!/bin/bash
if [ $# -eq 1 ]
then $(history | grep "^ $1" | cut -d' ' -f4-)
else echo "Il faut un seul parametre entier > 0!"
fi
