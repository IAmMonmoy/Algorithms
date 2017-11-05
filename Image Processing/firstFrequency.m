clc, clear, close all;

img= imread('imgfft.png');   %Main Image
img=rgb2gray(img);

fftImg = fft2(img);
shiftFftImg = fftshift(fftImg);
subplot(2,2,1);
imshow(fftImg);
title('Without Log WithOut fftshitf');
subplot(2,2,2);
imshow(shiftFftImg);
title('Only FFT SHIFT Image');
logImage = mat2gray(log(1+abs(fftImg)));
subplot(2,2,3);
imshow(logImage);
title('Log without fftshift Image');
logAndFftshit = mat2gray(log(1+abs(shiftFftImg)));
subplot(2,2,4);
imshow(logAndFftshit);
title('Log With FFt Shitf');

