#!/bin/bash
COMPILER="../cmake-build-debug/mycc"
FILE=$1

assert() {
  ans=$1
  in=$2
  while [[ $ans -lt "0" ]]; do
    ans=$((256 + $ans))
  done
  while [[ $ans -gt "255" ]]; do
    ans=$(($ans - 256))
  done

  echo "input: $2, ans: $1"
  echo $2 | $COMPILER >"./assembly/a.s"
  ./dockercross-mips bash -c "\$CC ./assembly/a.s -o ./out/a.out; qemu-mips ./out/a.out; echo \$?" >./tmp_out &
  wait
  res=$(cat ./tmp_out)
  if [ $res -eq $ans ]; then
    echo "OK!  Result: $res, Ans: $ans"
  else
    echo -e "\033[0;31mNG\033[0;39m"
    echo "FAIL! Result: $res, Ans: $ans"
    exit 1
  fi
}

test() {
  in=$1
  ans=$(
    echo $in >./out/tmp.c
    gcc ./out/tmp.c -o ./out/tmp
    ./out/tmp
    echo $? &
  )

  echo $in | $COMPILER >"./assembly/a.s"
  ./dockercross-mips bash -c "\$CC ./assembly/a.s -o ./out/a.out; qemu-mips ./out/a.out; echo \$?" >./tmp_out &
  wait
  res=$(cat ./tmp_out)
  if [ $res -eq $ans ]; then
    echo "OK!  Result: $res, Ans: $ans"
  else
    echo "FAIL! Result: $res, Ans: $ans"
    exit 1
  fi
}

#test 'int main() { return 123; }'
#test 'int main() { return 0; }'
#test 'int main() { return -1; }'
#test 'int main() { return +2; }'
#test 'int main() { return - -4; }'
#test 'int main() { return ~+6; }'
#test 'int main() { return !-9; }'
#
#test 'int main() { return 1 + 2; }'
#test 'int main() { return 3 - 4; }'
#test 'int main() { return 3 + 2 + + 4; }'
#test 'int main() { return 3 + - 4; }'

test 'int main() {
    return -(1 + !12 + ~3) - 2 + 4 - (-5);
}'

#assert 0 'int main() { return 0; }'
#assert 123 'int main() { return 123; }'
#assert -2 'int main() { return -2; }'
#
#assert -2 'int main() { return -+-2; }'
#assert -2 'int main() { return -2; }'
#assert -2 'int main() { return -2; }'
