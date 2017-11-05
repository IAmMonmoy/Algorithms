img = imread('monmoy.jpg');

negativeImage(:,:,:) = 255-img(:,:,:); %loop through whole 3d  array and negate with 255 to do complement

subplot(1,2,1);
imshow(img);
subplot(1,2,2);
imshow(negativeImage);