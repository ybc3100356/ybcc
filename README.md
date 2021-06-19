### Build

```shell
mkdir build
cd ./build/
cmake ..
make -j8
```



### mycc usage

```shell
./mycc ../test/src/test.c ./test.s
```



### MIPS-tool-chains

```shell
cd ./test
docker pull dockcross/linux-mips:latest
docker run --rm dockcross/linux-mips > ./dockercross-mips
chmod +x ./dockercross-mips
```



### MIPS-tool-chains usage

```shell
./dockercross-mips bash -c "\$CC hello.c -o hello; qemu-mips hello"
```





