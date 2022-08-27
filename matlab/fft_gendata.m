clear all;
clc;
close all;

N = 64;
input_data = zeros(1,N);
for n = 0 : N-1
input_data(n+1) = cos((2*pi/N)*n) + sin((2*pi*5/N)*n);
end

figure
plot (input_data);
title('input function');

freq_domain = fft(input_data);
disp(freq_domain);
freq_domain_real = abs(freq_domain/N);

figure
plot (freq_domain_real);
title('frequency domain');

fileID = fopen('~/C++Workspace/FFT/input_data.txt', 'w');
fprintf(fileID, '%d\n',input_data);
fclose(fileID);

input_comp = zeros(1,N);
for n = 0 : N-1
input_comp(n+1) = exp(1i*2*pi*n/N);
end
fileID2 = fopen('~/C++Workspace/FFT/input_comp.txt', 'w');
fmt='%.4f %.4f \n';
fprintf(fileID2, fmt, [real(input_comp); imag(input_comp)]);
fclose(fileID2);

