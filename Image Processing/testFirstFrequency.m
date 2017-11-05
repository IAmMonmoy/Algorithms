clc; clear; close all;
row = 3; 
col = 2;
img1 = zeros(256,256);
img1(108:148, 108:148) = 1;

% img2 = ones(256,256);
% img2(78:178, 78:178) = 0;

subplot(row,col,1);
imshow(img1);
title('Original Image1');

% subplot(row,col,2);
% imshow(img2);
% title('Original Image2');

f_img = fftshift(fft2(img1)); 
f_img1 = log(1+abs(f_img));
%f_img2 = uint8(255*mat2gray(f_img1));
f_img2 = (mat2gray(f_img1));

nf_img = (fft2(img1));
nf_img1 = log(1+abs(nf_img));


% ff_img = fftshift(fft2(img2)); 
% ff_img1 = log(1+abs(ff_img));
% ff_img2 = mat2gray(ff_img1);

subplot(row,col,2);
imshow(((f_img2)));
title('Shift & Log');

subplot(row,col,3);
imshow((f_img));
title('Shift & Without Log');

subplot(row,col,4);
imshow((nf_img));
title('Non Shift & Without Log');


subplot(row,col,5);
imshow((nf_img1));
title('Non Shift & With Log');



subplot(row,col,6);
imshow(real(nf_img));
title('Non Shift & Without Log(Real)');



% subplot(row,col,4);
% imshow((ff_img));
% title('Fourier Transformed Image with Shifting');