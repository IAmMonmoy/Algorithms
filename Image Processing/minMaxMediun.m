img = imread('smooth.gif');

workImage = double(img);

[r,c,d] = size(workImage);

box=ones(3,3); %3*3 mask

[p,q] = size(box);
x = floor(p/2);
y = floor(q/2);

disp(ceil((p*q)/2));

finalImage = zeros(r,c,d);
for i = 1:d %for dimension of image
    for j = 2:r-1
        for k = 2:c-1
            mn = 20000; %find minimum
            for l = -x:x %for mask iteration
                for m = -y:y
                    if(workImage(j+l,k+m,i)< mn)
                        mn = workImage(j+l,k+m,i);
                    end
                end
            end
            finalImage(j,k,i) = mn;
        end
    end
end

finalImage1 = zeros(r,c,d);
for i = 1:d %for dimension of image
    for j = 2:r-1
        for k = 2:c-1
            mx = 0; %find maximum
            for l = -x:x %for mask iteration
                for m = -y:y
                    if(workImage(j+l,k+m,i)> mx)
                        mx = workImage(j+l,k+m,i);
                    end
                end
            end
            finalImage1(j,k,i) = mx;
        end
    end
end

finalImage2 = zeros(r,c,d);
A = zeros(9,1);
for i = 1:d %for dimension of image
    for j = 2:r-1
        for k = 2:c-1
            index = 1; %array index of A
            for l = -x:x %for mask iteration
                for m = -y:y
                   A(index,1) = workImage(j,k,i);
                   index = index+1;
                end
            end
            sort(A);
            mid = ceil((p*q)/2); %if 3*3 mask it's 5 if 5*5 its 13
            finalImage2(j,k,i) = A(mid,1);
        end
    end
end

figure,imshow(img);
figure,imshow(uint8(finalImage));
figure,imshow(uint8(finalImage1));
figure,imshow(uint8(finalImage2));








