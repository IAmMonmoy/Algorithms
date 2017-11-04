img = imread('smooth.gif');

workImage = double(img);

[r,c,d] = size(workImage);

box=[1 1 1; 1 1 1; 1 1 1]*(1/9); %3*3 box mask

finalImage = workImage;

for i = 1:d
    for j = 2:r-1
        for k = 2:c-1
            finalImage(j,k,i) = workImage(j-1,k-1,i)*box(1,1)+ workImage(j-1,k,i)*box(1,2)+ workImage(j-1,k+1,i)*box(1,3)... %... is for breaking long line into multiple line
                + workImage(j,k-1,i)*box(2,1)+ workImage(j,k,i)*box(2,2)+ workImage(j,k+1,i)*box(2,3) ...
                +workImage(j+1,k-1,i)*box(3,1) +workImage(j+1,k,i)*box(3,2)+ workImage(j+1,k+1,i)*box(3,3); 
        end
    end
end

finalImage1 = workImage;

box=[1 2 1; 2 4 2; 1 2 1]*(1/16); %3*3 weighted average mask

for i = 1:d
    for j = 2:r-1
        for k = 2:c-1
            finalImage1(j,k,i) = workImage(j-1,k-1,i)*box(1,1)+ workImage(j-1,k,i)*box(1,2)+ workImage(j-1,k+1,i)*box(1,3)... %... is for breaking long line into multiple line
                + workImage(j,k-1,i)*box(2,1)+ workImage(j,k,i)*box(2,2)+ workImage(j,k+1,i)*box(2,3) ...
                +workImage(j+1,k-1,i)*box(3,1) +workImage(j+1,k,i)*box(3,2)+ workImage(j+1,k+1,i)*box(3,3); 
        end
    end
end

figure,imshow(img);
figure,imshow(uint8(finalImage)); %box .. more blured
figure,imshow(uint8(finalImage1)); %weighted less blured