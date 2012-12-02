#!/bin/bash
#
g++ -c -g cavity.cpp >& compiler.txt
if [ $? -ne 0 ]; then
  echo "Errors compiling cavity.cpp"
  exit
fi
rm compiler.txt
#
g++ ~/libcpp/$ARCH/fem2d_stokes.o cavity.o
if [ $? -ne 0 ]; then
  echo "Errors linking and loading fem2d_stokes.o + cavity.o"
  exit
fi
rm cavity.o
#
chmod ugo+x a.out
mv a.out cavity
./cavity nodes6.txt triangles6.txt > cavity_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running cavity."
  exit
fi
rm cavity
#
echo "The cavity program has been executed."
