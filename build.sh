#!/bin/bash
#执行cmake -S . -B build
#执行cmake --build build --config Release
echo "删除build目录"
rm -rf build
echo "创建build目录"
cmake -S . -B build
echo "编译"
cd build
make -j4
echo "执行"
./cplusDemo
