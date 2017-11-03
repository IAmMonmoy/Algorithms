img = imread('monmoy.jpg');
workImage = double(img);

for i = 1:8
    slicedImage = mod(workImage,2); %take out the bits
    
    figure,imshow(slicedImage);
    
    workImage = floor(workImage/2);
end