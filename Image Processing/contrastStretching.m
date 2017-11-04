img = imread('stretch.tif');

maxi = max(img(:));
mini = min(img(:));

workImage = img;

workImage = ((workImage-mini))*(255/(maxi-mini));

subplot(2,2,1);
imshow(img);
title('original image');
subplot(2,2,2);
imshow(workImage);
title('stretched image');

x = hist_cal(img);
y = hist_cal(workImage);

subplot(2,2,3);
stem(x,'marker','none');
subplot(2,2,4);
stem(y,'marker','none');