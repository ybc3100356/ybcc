#!/bin/bash
FILE=$1
echo $FILE
if test -f $FILE; then
  ./dockercross-mips bash -c "\$CC $1 -o ./out/a.out; qemu-mips ./out/a.out; echo"
else
  echo "FILE \"$FILE\" doesn't exist"
fi
