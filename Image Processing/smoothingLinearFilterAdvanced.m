img = imread('smooth.gif');

workImage = double(img);

[r,c,d] = size(workImage);

box=[1 1 1; 1 1 1; 1 1 1]*(1/9); %3*3 box mask

[x,y] = size(box);
x = floor(x/2);
y = floor(y/2);

finalImage = zeros(r,c,d);

for i = 1:d
    for j = 2:r-1
        for k = 2:c-1
            for l = -x:x
                for m = -y:y
                    finalImage(j,k,i) = finalImage(j,k,i)+(workImage(j+l,k+m,i)*box(l+2,m+2));
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
    for j = 2:r-1
        for k = 2:c-1
            for l = -x:x
                for m = -y:y
                      finalImage1(j,k,i) = finalImage1(j,k,i)+workImage(j+l,k+m,i)*weighted(l+2,m+2);
                end
            end
        end
    end
end

figure,imshow(img);
figure,imshow(uint8(finalImage)); %box .. more blured
figure,imshow(uint8(finalImage1)); %weighted less blured
