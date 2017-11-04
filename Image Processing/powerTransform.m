img=imread('logTransform.tif');

img2=im2double(img);
[r,c] = size(img2);

factor = 3;
power= 2;

for i=1:r;
    for j=1:c
        img2(i,j) = factor * img2(i,j)^power;
    end
end

subplot(1,2,1);
imshow(img);
title('Original Image.');
subplot(1,2,2);
imshow(img2);
title('Transformed Image.');