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
  echo $in
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

test 'int main() { return 123; }'
test 'int main() { return 0; }'
test 'int main() { return -1; }'
test 'int main() { return +2; }'
test 'int main() { return - -4; }'
test 'int main() { return ~+6; }'
test 'int main() { return !-9; }'

test 'int main() { return 1 + 2; }'
test 'int main() { return 3 - 4; }'
test 'int main() { return 3 + 2 + + 4; }'
test 'int main() { return 3 + - 4; }'

test 'int main() { return -(1 + !12 + ~3) - 2 + 4 - (-5);}'

test 'int main() { return 1 * 1; }'
test 'int main() { return 3 * 9; }'
test 'int main() { return 2 * -2; }'
test 'int main() { return 3 / 1; }'
test 'int main() { return 9 / 3; }'
test 'int main() { return 9 % 3; }'
test 'int main() { return 9 % 4; }'
test 'int main() { return 3 + 2 * -2 - 1; }'

test 'int main() { return -123 / -43 -(!3 - + ~2) * -2 % 6 - 1; }'

test 'int main() { return 1 << 2; }'
test 'int main() { return 4 << 3; }'
test 'int main() { return 10 >> 5; }'
test 'int main() { return 10 >> 0; }'

test 'int main() { return -123 >> 2 / -43 << 2 + 2 << - ( 3 * -(!3 - + ~2) * -2 % 6 - 1); }'
test 'int main() { return 0 == 0; }'
test 'int main() { return 1 == 1; }'
test 'int main() { return 123 == 321; }'
test 'int main() { return 11 != 22; }'
test 'int main() { return 14 != 14; }'
test 'int main() { return 1 == 0 == 1; }'

test 'int main() { return 0 > 0; }'
test 'int main() { return 1 >= 1; }'
test 'int main() { return 1 >= 2; }'
test 'int main() { return 2 >= 1; }'
test 'int main() { return 123 <= 321; }'
test 'int main() { return 11 < 22; }'
test 'int main() { return 14 < 14; }'
test 'int main() { return 1 > 0 == 1; }'

test 'int main() { return 1 != 0 + 2 < 1 + 1 == 2 == 1 == -123 >> 2 / -43 << 2 + 2 << - ( 3 * -(!3 - + ~2) * -2 % 6 - 1); }'
test 'int main() { return 111 & 2; }'
test 'int main() { return 123 & 456 | 675; }'
test 'int main() { return 213 | 123 | 280; }'
test 'int main() { return 110 ^ 293; }'
test 'int main() { return 110 ^ +393 <= 321 / -43 -(!3 - + ~2) * -2 % 6 - 1; }'
test 'int main() { return ~1567810 ^ ~393351 + ~3211235 / -43 -(!3 - + ~2) * -2 % 6 - 1; }'
test 'int main() { return 110  && 293; }'
test 'int main() { return 110  && 293 && 0; }'
test 'int main() { return 0  && 293; }'
test 'int main() { return 110  && 0; }'
test 'int main() { return 0  && 0; }'
test 'int main() { return 0  && 0 && 0; }'
test 'int main() { return 0  && 0 && 1; }'
test 'int main() { return 231 || 221 || 0; }'
test 'int main() { return 110 || 0 || 1; }'
test 'int main() { return 0 || 293 || 2; }'
test 'int main() { return 0 || 0 || 1; }'
test 'int main() { return 0 || 0 || 0; }'
test 'int main() { return 123  && 0 || 3; }'
test 'int main() { return 110 ^ +393 <= 321 / -43 -(!3 - + ~2) * -2 % 6 - 1 + (0 && 0 || 0 && 0); }'
test 'int main() { return -1 < 0; }'
test 'int main() { return -2 < 2; }'
test 'int main() { return 3 > -2; }'

test 'int main() { int a = 0; return a; }'
test 'int main() { int a = 2; return a; }'
test 'int main() { int a = 110 ^ +393 <= 321 / -43 -(!3 - + ~2) * -2 % 6 - 1 + (0 && 0 || 0 && 0); return a;}'
test 'int main() { int a = 0; return a; }'
test 'int main() { int a = 0; ; return a; }'
test 'int main() { int a = 0; int b; return a; }'
test 'int main() { int a = 0; int b = 0; return a; }'
test 'int main() { int a = 2; int b = 3; return a + b; }'
test 'int main() { int a = 2; int b = -3; return a + b; }'
test 'int main() { int a = 2; int b = -3; return a + b; }'
test 'int main() { int a = 2; int b = -3; int c = a + b; a = a - b; b = b * c; return a + b + c; }'
test 'int main() { int a = 2; int b = -3; int c = a + b; a = a - b; b = -b * ~c; return !a * b + c; }'
test 'int main() { int a; int b; a = b = 11 ; return b * a; }'
test 'int main() { int a,b; a = 11; b = 12 ; return b * a; }'
test 'int main() { int a,b; a = b = 11 ; return b * a; }'
test 'int main() { int a = 7; int b = -3; int c = a + b; a = b = 17; c; a = a - b; b = -b * ~c; return !a * b + c; }'
test 'int main() { int a = 1; int b = 2; int c = 3; int d = -2; a = b = (c = d = 3); return a * b + c + d;}'

test 'int main() { int a = 0; if(0) a = 1; return a; }'
test 'int main() { int a = 0; if(1) a = 1; return a; }'
test 'int main() { int a = 0; if(1) a = 1; else a = 0; return a; }'
test 'int main() { int a=1; if(a) return a+1+3; else return a-1; return a; }'
test 'int main() { int a=0; if(a) return a+1+2; else return a-1; return a; }'
test 'int main() { int a=0; int b=0; if(a) if(b) return 3; else return 7; return a; }'
test 'int main() { int a=1; int b=0; if(a) if(b) return 3; else return 7; return a; }'
test 'int main() { int a=0; int b=1; if(a) if(b) return 3; else return 7; return a; }'
test 'int main() { int a=1; int b=1; if(a) if(b) return 3; else return 7; return a; }'
test 'int main() { int a = 0; int b = a ? 123:456;  return a+b; }'
test 'int main() { int a = 1; int b = a ? 123:456;  return a+b; }'
test 'int main() { int a = 0; int b = a ? a:456;  return a+b; }'
test 'int main() { int a = 1; int b = a ? a:456;  return a+b; }'
test 'int main() { int a = 0; int c=7; int b = a ? a:c;  return a+b; }'
test 'int main() { int a = 1; int c=7; int b = a ? a:c;  return a+b; }'
test 'int main() { int a = 1; int c=7; a = (c = 3); a = -c * ~c;   int b = a ? a:c;  return 0?a+b:a-b; }'
test 'int main() { int a = 1; int c=7; a = (c = 3); a = -c * ~c;   int b = a ? a:c;  return 1123?a+b:a-b; }'
test 'int main() { int a = 1; int c=7; a = (c = 3); a = -c * ~c;   int b = a ? a:c;  return -1?a+b:a-b; }'
test 'int main() { int a = 0; if(a) { return a; } else { int a = 1;} return a;}'
test 'int main() { int a = -1; if(a) { return a; } else { int a = 1;} return a;}'
test 'int main() { int a = 1231; if(a) { return a; } else { int a = 1;} return a;}'
test 'int main() { int a = 1231; if(a) { a;return a; } else { a;int a = 1;  return a;} return a;}'
test 'int main() { int a = 1231; if(a) { a;return a; } else { return a;int a = 1;} return a;}'
test 'int main() { int a = 7; {a = 2; int a = 12;} return a;}'
test 'int main() {int a = 0;int b = 1;{int a = 1;}{if (a == 0) {a = 3;int a = 2;} else {a = 5;int a = 4;}}{{{{b = 1;{{{{{int b = 3;}}}}}}}b = 4;}}return a + b;}'
test 'int main() { int a = 7; {a = 2; int a = 12;} }'
test 'int main() {    int a = 0;    int b = 100;    while (b > 0) {        a = a + b;        b = b - 1;    }    return a;}'
test 'int main() {    int a = 0;    for(int i=0;i<10;i=i+1)    {        a = a + i;    }    return a;}'
test 'int main() {    int a = 0;    for (int i = 0; i < 10; i = i + 1) {        for (int i = 0; i < 10; i = i + 1) {            a = a + i;        }        for (int i = 0; i < 10; i = i + 1) {            a = a + i;            for (int i = 0; i < 10; i = i + 1) {                a = a + i;            }            a = a + i;            for (int i = 0; i < 10; i = i + 1) {                a = a + i;            }            a = a + i;        }        a = a + i;    }    return a;}'
test 'int main() {    int a = 0;    int i = 0;    do {        a = a + 10;    } while (i>0);    return a;}'
test 'int main() {    int a = 0;    int i = 2;    do {        a = a + 10;        i = i - 1;    } while (i>0);    return a;}'
test 'int main() {    int a = 0;    for (int i = 0; i < 10; i = i + 1) {        a = a + i;        if (i == 5)            break;    }    return a;}'
test 'int main() {    int a = 0;    for (int i = 0; i < 10; i = i + 1) {        if (i == 5 || i > 8)            continue;        for (int i = 0; i < 10; i = i + 1) {            if (i == 5 || i > 8)            {                for (int i = 0; i < 10; i = i + 1) {                    if (i == 5 || i > 8)                        continue;                    a = a + i;                }                continue;            }            a = a + i;            for (int i = 0; i < 10; i = i + 1) {                if (i == 5 || i > 8)                    continue;                a = a + i;            }        }        a = a + i;    }    return a;}'
test 'int main() {    int a = 0;    for (int i = 0; i < 10; i = i + 1) {        if (i == 5 || i > 8)            continue;        for (int i = 0; i < 10; i = i + 1) {            if (i == 5 || i > 8)            {                for (int i = 0; i < 10; i = i + 1) {                    if (i == 5 || i > 8)                        continue;                    a = a + i;                }                continue;            }            a = a + i;            for (int i = 0; i < 10; i = i + 1) {                if (i == 5 || i > 8)                    break;                a = a + i;            }            if(a > 10)                break;            continue;        }        a = a + i;    }    return a;}'
test 'int main() { for (int i=0;;i=i+1) { int i=1; return i; }}'
test 'int main() { int s = 1;  for (int i=0;i<100;i=i+1) { s=s+i; continue; } return s;}'
test 'int main() {    int s = 1;    int i = 1;    for (s;s>-10;i = i - 2) {        s = s + i;        i = i + 1;        if (i > 10)            break;    }    return s;}'
test 'int main(int a, int b) { a = 20; b = 3; return  a+b;}'
test 'int main(int a, int b) { a = 3; {int b; b = 2;} b = 1; return a+b;}'
test 'int main(int a, int b) { a = 20; b = 3; return  a+b;}'

test 'int f(int x, int y) {    return x + y;}int main() {    int a = 2;    int b = 3;    return f(a, b);}'
test 'int g(int x, int y, int z) {    int c = 3;    return x + y * z;}int f(int x, int y) {    return x * g(x, y, 11);}int main() {    int a = 2;    int b = 3;    return f(a, b);}'
test 'int f(int x, int y) {    return 7 * y;}int main() {    int a = 2;    int b = 3;    return f(a, b);}'
test 'int g(int x, int y, int z) {    return x;}int f(int x, int y) {    return x - g(x, y, 3);}int main() {    int a = 2;    int b = 3;    return a + f(a, b);}'
test 'int g(int x, int y, int z) {
    return x + y * z;
}

int f(int x, int y) {
    return x - g(x, y, 3);
}

int main() {
    int a = 2;
    int b = 3;
    return a + f(a, b + a);
}'

test '
int g(int x, int y, int z) {
  return x+x+x+x+y+y+y+z;
}

int f(int x, int y) {
    return x - g(13,x,y+x);
}

int main() {
    int a = 2;
    int b = 3;
    return a + f(a, b + a);
}'

test 'int main() { return 1; 2; 3; }'
test 'int main() { 1; return 2; 3; }'
test 'int main() { 1; 2; return 3; }'

test 'int main() { int foo=3; return foo; }'
test 'int main() { int foo123=3; int bar=5; return foo123+bar; }'

test 'int main() { if (0) return 2; return 3; }'
test 'int main() { if (1-1) return 2; return 3; }'
test 'int main() { if (1) return 2; return 3; }'
test 'int main() { if (2-1) return 2; return 3; }'

test 'int main() { {1; {2;} return 3;} }'

test 'int main() { int i=0; i=0; while(i<10) i=i+1; return i; }'
test 'int main() { int i=0; int j=0; while(i<=10) {j=i+j; i=i+1;} return j; }'

test 'int main() { int i=0; int j=0; for (i=0; i<=10; i=i+1) j=i+j; return j; }'
test 'int main() { for (;;) return 3; return 5; }'

test 'int ret3() { return 3; } int main() { return ret3(); }'
test 'int ret5() { return 5; }int main() { return ret5(); }'
test 'int add(int x, int y) { return x+y; } int main() { return add(3, 5); }'
test 'int sub(int x, int y) { return x-y; }  int main() { return sub(5, 3); }'
test 'int add6(int a, int b, int c, int d, int e, int f) {    return a+b+c+d+e+f;} int main() { return add6(1,2,3,4,5,6); }'

echo "Well done!"

#echo "Wrong case testing:"
#test 'int main(int a, int b) { a = 21; int b; return  a;}'
#test 'int main() { int a=0; if(a) return a+1+2; else return a-1; else return a + 2 * 3; return a; }'
#test 'int main() { break; return 0; }'
#test 'int main() { continue; return 0; }'
#test 'int main() { int a = 1; int b = 2; int c = 3; int d = -2; a = b = (c = d) = 3; return a * b + c + d;}'
#
