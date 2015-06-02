#!/bin/bash
#
cp blas1_z.hpp $HOME/include
#
g++ -c -g -I $HOME/include blas1_z.cpp >& compiler.txt
if [ $? -ne 0 ]; then
  echo "Errors compiling blas1_z.cpp"
  exit
fi
rm compiler.txt
#
mv blas1_z.o ~/libcpp/$ARCH/blas1_z.o
#
echo "Library installed as ~/libcpp/$ARCH/blas1_z.o"
