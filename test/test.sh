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
  echo $in >./out/tmp_gcc.c
  gcc ./out/tmp_gcc.c -o ./out/tmp_gcc
  ./out/tmp_gcc
  ans=$?

  echo $in | $COMPILER >"./assembly/tmp_mycc.s"
  ./dockercross-mips bash -c "\$CC ./assembly/tmp_mycc.s -o ./out/tmp_mycc; qemu-mips ./out/tmp_mycc; echo \$?" >./out/tmp_res &
  wait
  res=$(cat ./out/tmp_res)
  if [ $res -eq $ans ]; then
    echo "OK!  Result: $res, Ans: $ans"
  else
    echo "FAIL! Result: $res, Ans: $ans"
    exit 1
  fi
}
set -f

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
#
#test 'int main() { return -(1 + !12 + ~3) - 2 + 4 - (-5);}'

test 'int main() { return 1 * 1; }'
test 'int main() { return 3 * 9; }'
test 'int main() { return 2 * -2; }'
test 'int main() { return 3 / 1; }'
test 'int main() { return 9 / 3; }'
test 'int main() { return 9 % 3; }'
test 'int main() { return 9 % 4; }'
test 'int main() { return 3 + 2 * -2 - 1; }'
test 'int main() { return -123 / -43 -(!3 - + ~2) * -2 % 6 - 1; }'
