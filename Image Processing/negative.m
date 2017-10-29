img = imread('monmoy.jpg');

negativeImage(:,:,:) = 255-img(:,:,:); %loop through whole 3d  array and negate with 255 to do complement

figure,imshow(img);
figure,imshow(negativeImage);