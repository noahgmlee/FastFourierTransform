clear all;
clc;
close all;

cppFile = fopen('~/C++Workspace/FFT/fft_output.txt','r');
cpp_freqdomain = fscanf(cppFile, '%f');

figure
plot (cpp_freqdomain);
title('frequency domain from CPP code');