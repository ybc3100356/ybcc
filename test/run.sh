#!/bin/bash
COMPILER="../cmake-build-debug/mycc"
FILE=$1

if test -f $FILE; then
  #compile: .c-->.s
  cat $FILE | $COMPILER >"./assembly/a.s"
  echo 1
  #test   : .s-->exe
  if [ $? -eq 0 ]; then
    if test -f "./assembly/a.s"; then
      ./dockercross-mips bash -c "\$CC ./assembly/a.s -o ./out/a.out; qemu-mips ./out/a.out; echo mycc:\$?"
      bash -c "gcc $1 -o ./out/b.out; ./out/b.out; echo gcc:\$?"
    else
      echo "FILE \"$FILE\" doesn't exist"
    fi
  fi
else
  echo "FILE \"$FILE\" doesn't exist"
fi
