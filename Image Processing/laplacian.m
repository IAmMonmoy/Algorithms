img = imread('laplacian.tif');

workImage = double(img);

[r,c,d] = size(workImage);

mask=[0 1 0; 1 -4 1; 0 1 0]; 

[x,y] = size(mask);
x = floor(x/2);
y = floor(y/2);

finalImage = zeros(r,c,d);

for i = 1:d
    for j = x+1:r-x
        for k = y+1:c-y
            for l = -x:x
                for m = -y:y
                    finalImage(j,k,i) = finalImage(j,k,i)+(workImage(j+l,k+m,i)*mask(l+x+1,m+y+1));
                end
            end
        end
    end
end

mask1=[1 1 1; 1 -8 1; 1 1 1]; 

[x,y] = size(mask1);
x = floor(x/2);
y = floor(y/2);

finalImage1 = zeros(r,c,d);

for i = 1:d
    for j = x+1:r-x
        for k = y+1:c-y
            for l = -x:x
                for m = -y:y
                    finalImage1(j,k,i) = finalImage1(j,k,i)+(workImage(j+l,k+m,i)*mask1(l+x+1,m+y+1));
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