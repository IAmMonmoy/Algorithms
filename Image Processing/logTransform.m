img=imread('logTransform.tif');

img2=im2double(img); %because gray level transformation
[r,c,d] = size(img2);

factor= 2;
workImage = img2;

for i=1:r
    for j=1:c
        workImage(i,j) = factor*log(1+img2(i,j));
    end
end


subplot(1,2,1);
imshow(img);
title('Original Image.');
subplot(1,2,2);
imshow((workImage));
title('Transformed Image.');