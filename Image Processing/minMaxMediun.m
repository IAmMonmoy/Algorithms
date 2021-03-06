img = imread('median.tif');

workImage = double(img);

[r,c,d] = size(workImage);

box=ones(3,3); %3*3 mask

[p,q] = size(box);
x = floor(p/2);
y = floor(q/2);

disp(ceil((p*q)/2));

finalImage = zeros(r,c,d);

for j = 1:r
    for k = 1:c
        mn = 20000; %find minimum
        for l = -x:x %for mask iteration
            for m = -y:y
                if(j+l >=1 && j+l <= r && k+m >=1 && k+m <= c) %if inside the bound then calculate. Otherwise add nothing
                    if(workImage(j+l,k+m)< mn)
                        mn = workImage(j+l,k+m);
                    end
                end
            end
        end
        finalImage(j,k) = mn;
    end
end


finalImage1 = zeros(r,c,d);

for j = 1:r
    for k = 1:c
        mx = 0; %find maximum
        for l = -x:x %for mask iteration
            for m = -y:y
                if(j+l >=1 && j+l <= r && k+m >=1 && k+m <= c) %if inside the bound then calculate. Otherwise add nothing
                    if(workImage(j+l,k+m)> mx)
                        mx = workImage(j+l,k+m);
                    end
                end
            end
        end
        finalImage1(j,k) = mx;
    end
end


finalImage2 = zeros(r,c,d);
A = zeros(9,1);

for j = 1:r
    for k = 1:c
        index = 1; %array index of A
        for l = -x:x %for mask iteration
            for m = -y:y
                 if(j+l >=1 && j+l <= r && k+m >=1 && k+m <= c) %if inside the bound then calculate. Otherwise add nothing
                   A(index,1) = workImage(j+l,k+m);
                   index = index+1;
                 end
            end
        end
        A=sort(A);
        mid = ceil((p*q)/2); %if 3*3 mask it's 5 if 5*5 its 13
        finalImage2(j,k) = A(mid,1);
    end
end


subplot(2,2,1);
imshow(img);
subplot(2,2,2);
imshow(uint8(finalImage));
title('minimum');
subplot(2,2,3);
imshow(uint8(finalImage1));
title('maximum');
subplot(2,2,4);
imshow(uint8(finalImage2));
title('median');








