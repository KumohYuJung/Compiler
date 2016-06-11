#!/bin/bash

if (($# != 1))
then
	echo "input file name to compile !"
	exit 1
fi

name=$(echo $1 | cut -f1 -d".")
echo $name


./minic $name.mc
mkdir -p Compiled-$name
mv $name.ast Compiled-$name
mv $name.uco Compiled-$name
./Ucodei Compiled-$name/$name.uco
