clear;clc;
img = imread('lenna.tiff');
img = rgb2gray(img);

noiseImage = imnoise(img,'salt & pepper');
fftImg = fftshift(fft2(noiseImage));

%logImage = log(1+abs(fftImg));
%imshow(mat2gray(logImage));
ObservePSNR=zeros(1,29);
cutoff = 15;
n = 2; %order 2

[r,c] = size(noiseImage);
r = (r-1)/2;
c = (c-1)/2;

[x,y] = meshgrid(-r:r,-c:c);

mask = 1./(1.+(((x.^2+y.^2).^0.5)./cutoff).^(2*n));
imshow(mask);

temp = fftImg.*mask;

reconstruct = mat2gray(abs(ifft2(temp)));

 maxValue = double(max(noiseImage(:)));
mseImage = (double(noiseImage) - double(reconstruct)) .^ 2;
[rows columns] = size(noiseImage);   
mse = sum(mseImage(:)) / (rows * columns);
ObservePSNR(cutoff) = 10 * log10( 256^2 / mse);
disp(ObservePSNR(cutoff));


subplot(2,2,1);
imshow(noiseImage);
subplot(2,2,2);
imshow(reconstruct);
subplot(2,2,3);
plot(ObservePSNR);
ylabel('PSNR')
xlabel('Cut Off')
title('PSNR');