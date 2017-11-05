img = imread('smooth.tif');

workImage = double(img);

[r,c,d] = size(workImage);

box=[1 1 1; 1 1 1; 1 1 1]*(1/9); %3*3 box mask

[x,y] = size(box);
x = floor(x/2);
y = floor(y/2);

finalImage = zeros(r,c,d);

for j = 1:r
    for k = 1:c
        for l = -x:x
            for m = -y:y
                if(j+l >=1 && j+l <= r && k+m >=1 && k+m <= c) %if inside the bound then calculate. Otherwise add nothing
                    finalImage(j,k) = finalImage(j,k)+(workImage(j+l,k+m)*box(l+x+1,m+y+1));
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


for j = x+1:r-x
    for k = y+1:c-y
        for l = -x:x
            for m = -y:y
                if(j+l >=1 && j+l <= r && k+m >=1 && k+m <= c) %if inside the bound then calculate. Otherwise add nothing
                  finalImage1(j,k) = finalImage1(j,k)+workImage(j+l,k+m)*weighted(l+x+1,m+y+1);
                end
            end
        end
    end
end


finalImage2 = zeros(r,c,d);

box=ones(7,7)*(1/49); 

[x,y] = size(box);
x = floor(x/2);
y = floor(y/2);

for j = x+1:r-x
    for k = y+1:c-y
        for l = -x:x
            for m = -y:y
                if(j+l >=1 && j+l <= r && k+m >=1 && k+m <= c) %if inside the bound then calculate. Otherwise add nothing
                  finalImage2(j,k) = finalImage2(j,k)+workImage(j+l,k+m)*box(l+x+1,m+y+1);
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
