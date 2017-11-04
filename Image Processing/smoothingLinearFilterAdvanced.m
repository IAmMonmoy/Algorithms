img = imread('smooth.tif');

workImage = double(img);

[r,c,d] = size(workImage);

box=[1 1 1; 1 1 1; 1 1 1]*(1/9); %3*3 box mask

[x,y] = size(box);
x = floor(x/2);
y = floor(y/2);

finalImage = zeros(r,c,d);

for i = 1:d
    for j = x+1:r-x
        for k = y+1:c-y
            for l = -x:x
                for m = -y:y
                    finalImage(j,k,i) = finalImage(j,k,i)+(workImage(j+l,k+m,i)*box(l+x+1,m+y+1));
                end
            end
        end
    end
end

finalImage1 = zeros(r,c,d);

weighted=[1 2 1; 2 4 2; 1 2 1]*(1/16); %3*3 weighted average mask

[x,y] = size(weighted);
x = floor(x/2);
y = floor(y/2);

for i = 1:d
    for j = x+1:r-x
        for k = y+1:c-y
            for l = -x:x
                for m = -y:y
                      finalImage1(j,k,i) = finalImage1(j,k,i)+workImage(j+l,k+m,i)*weighted(l+x+1,m+y+1);
                end
            end
        end
    end
end

finalImage2 = zeros(r,c,d);

box=ones(7,7)*(1/49); %3*3 weighted average mask

[x,y] = size(box);
x = floor(x/2);
y = floor(y/2);

for i = 1:d
    for j = x+1:r-x
        for k = y+1:c-y
            for l = -x:x
                for m = -y:y
                      finalImage2(j,k,i) = finalImage2(j,k,i)+workImage(j+l,k+m,i)*box(l+x+1,m+y+1);
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
title('3*3 box mask');
subplot(2,2,3);
imshow(uint8(finalImage1));
title('3*3 weighted average mask');
subplot(2,2,4);
imshow(uint8(finalImage2));
title('7*7 mask');
