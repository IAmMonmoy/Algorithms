img = imread('monmoy.jpg');
img = rgb2gray(img);
threshold = img>120; %value greater than 120 are 1 .. rest are 0
imshow(threshold);