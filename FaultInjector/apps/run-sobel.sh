clang++  -std=c++11 -fno-use-cxa-atexit -emit-llvm -c ../runtime/Runtime.cpp -o runtime.bc
clang++ -g -emit-llvm -c sobel/sobel.c -o sobel/sobel.bc
llvm-link  runtime.bc sobel/sobel.bc -S -o sobel.bc
opt -load ../cmake-build-debug/errorinjector/liberrorinjector.so -FaultInjector <sobel.bc> sobelfinal.bc
lli sobelfinal.bc sobel/i2.pgm
