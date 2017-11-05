img = imread('sobel.tif');

workImage = double(img);

[r,c,d] = size(workImage);

mask=[-1 0 1; -2 0 2; -1 0 1]; 

[x,y] = size(mask);
x = floor(x/2);
y = floor(y/2);

finalImage = zeros(r,c,d);


for j = x+1:r-x
    for k = y+1:c-y
        for l = -x:x
            for m = -y:y
                if(j+l >=1 && j+l <= r && k+m >=1 && k+m <= c) %if inside the bound then calculate. Otherwise add nothing
                    finalImage(j,k) = finalImage(j,k)-(workImage(j+l,k+m)*mask(l+x+1,m+y+1));
                end
            end
        end
    end
end


subplot(2,2,1);
imshow(img);
title('real image')
subplot(2,2,2);
imshow(uint8(finalImage));
title('3*3 without diagonal');
subplot(2,2,3);
imshow(uint8(finalImage1));
title('3*3 with diagonal');