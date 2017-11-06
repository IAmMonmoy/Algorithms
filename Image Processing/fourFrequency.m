clear;clc;
img = imread('lenna.tiff');
img = rgb2gray(img);

noiseImage = imnoise(img,'salt & pepper');
fftShiftImg = fftshift(fft2(img));

[r,c] = size(noiseImage);

r =(r-1)/2;
c = (c-1)/2;

[x,y] = meshgrid(-c:c,-r:r);

DUV = sqrt(x.^2+y.^2);

D0 = 15;
n = 2; %order

idealLow = DUV <= D0;

idealLowImage = fftShiftImg.*idealLow;

reconstruct = mat2gray(abs(ifft2(idealLowImage)));

subplot(3,2,1);
imshow(reconstruct);
title('Ideal low pass filter');

idealHigh = DUV > D0;

idealLowImage = fftShiftImg.*idealHigh;

reconstruct = mat2gray(abs(ifft2(idealLowImage)));

subplot(3,2,2);
imshow(reconstruct);
title('Idea High pass filter');

butterLow = 1./(1+(DUV./D0).^(2*n));

butterLowImage = fftShiftImg.*butterLow;

reconstruct = mat2gray(abs(ifft2(butterLowImage)));

subplot(3,2,3);
imshow(reconstruct);
title('ButterWorth low pass filter');

butterHigh = 1./(1+(D0./DUV).^(2*n));

butterHighImage = fftShiftImg.*butterHigh;

reconstruct = mat2gray(abs(ifft2(butterHighImage)));

subplot(3,2,4);
imshow(reconstruct);
title('ButterWorth High pass filter');

gaussLow = exp(-DUV.^2/(2*D0.^2));
gaussLowImage = fftShiftImg.*gaussLow;

reconstruct = mat2gray(abs(ifft2(gaussLowImage)));

subplot(3,2,5);
imshow(reconstruct);
title('Gauss low pass filter');

gaussHigh = 1-exp(-DUV.^2/(2*D0.^2));
gaussHighImage = fftShiftImg.*gaussHigh;

reconstruct = mat2gray(abs(ifft2(gaussHighImage)));

subplot(3,2,6);
imshow(reconstruct);
title('Gauss low pass filter');

