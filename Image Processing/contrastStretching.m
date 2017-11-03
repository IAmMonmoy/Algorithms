img = imread('stretch.jpg');

maxi = max(img(:));
mini = min(img(:));

workImage = img;

workImage = ((workImage-mini))*(255/(maxi-mini));

figure,imshow(img);
figure,imshow(workImage);

x = hist_cal(img);
y = hist_cal(workImage);

subplot(2,1,1);
stem(x,'marker','none');
subplot(2,1,2);
stem(y,'marker','none');