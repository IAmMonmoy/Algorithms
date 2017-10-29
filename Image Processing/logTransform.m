img=imread('monmoy.jpg');
img=rgb2gray(img);

img2=im2double(img);
[r,c] = size(img2);

factor= 2;

for i=1:size(img2,1);
    for j=1:size(img2,2)
        img2(i,j) = factor * log(1+img2(i,j));
    end
end

subplot(1,2,1);
imshow(img);
title('Original Image.');
subplot(1,2,2);
imshow(img2);
title('Transformed Image.');