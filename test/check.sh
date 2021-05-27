#!/bin/bash
# docker pull asmimproved/qemu-mips
ASM_PATH="/run/media/ybc/working/school/3_2/Compiler/lab/mycc/test/assembly/"
asm="demo.s"
docker run -v $ASM_PATH:/project asmimproved/qemu-mips \
  bash -c "ls; mips-linux-gnu-gcc -static -mips32r5 $asm -o test; qemu-mips test; rm test"
