### 文件说明

- src：编译器源代码
  - Error：错误处理
  - Declaration：语义分析
  - CodeGen：代码生成
  - utilities：类型，符号表等
- test：测试代码、脚本
  - test.sh：自动测试脚本，需要获取MIPS工具链（具体过程见下方）
- grammar：
  - C.g4：C语法文件
  - gen：ANTLR根据C.g4生成的词法、语法分析器
- doc：实验报告
- antlr：ANTLR的运行时



### 编译

```shell
mkdir build
cd ./build/
cmake ..
make -j8
```



### mycc 使用

```shell
./mycc ../test/src/test.c ./test.s
```



### MIPS工具链获取

```shell
cd ./test
docker pull dockcross/linux-mips:latest
docker run --rm dockcross/linux-mips > ./dockercross-mips
chmod +x ./dockercross-mips
```



### MIPS工具链使用

```shell
./dockercross-mips bash -c "\$CC hello.c -o hello; qemu-mips hello"
```
