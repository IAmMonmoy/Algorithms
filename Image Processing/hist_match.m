    input = imread('match1.tif');
    desired = imread('match2.tif');
    img2 = input;
    
    input_hist = imhist(input);
    output_hist = imhist(desired);
    
    inputMax = max(input_hist);
    outputMax = max(output_hist);
    
    [rInput,cInput] = size(input); %total pixel values of input image
    [rOutput,cOutput] = size(desired); %total pixel values of output image
    
    totalInput = rInput*cInput;
    totalOutput = rOutput*cOutput;
    
    
    cummulativeInput = zeros(1,256);
    cummulativeOutput = zeros(1,256);
    
    cummulativeInput(1) = input_hist(1)/totalInput;
    cummulativeOutput(1) = output_hist(1)/totalOutput;
    
    for i = 2:256
        cummulativeInput(i) = cummulativeInput(i-1) + input_hist(i)/totalInput; %finding probablity and adding to cummulative
        cummulativeOutput(i) = cummulativeOutput(i-1) + output_hist(i)/totalOutput; %finding probablity and adding to cummulative
    end
    
    for i = 1:256
          cummulativeInput(i) = floor(cummulativeInput(i)*inputMax); %floor both input and output image 
          cummulativeOutput(i) = floor(cummulativeOutput(i)*outputMax);
    end
    
    map = zeros(1,256);
    
    for i = 1:256
        for j = 1:256
            if cummulativeInput(i) <= cummulativeOutput(j) %find out value for each  input cummulative which is greater than or equal from ouput cummulative and map that index
                map(i) = j;
                break;
            end
        end
    end
    
   
    for i = 1:rInput
        for j = 1:cInput
            img2(i,j) = map(img2(i,j)+1); %make the original image by mapping
        end
    end
    
    
    subplot(2,3,1);
    imshow(input);
    title('Original Image');
    
     subplot(2,3,2);
    imshow(desired);
    title('Desired Image');
    
     subplot(2,3,3);
    imshow(img2);
    title('Matched Image');
    
    subplot(2,3,4);
    stem(imhist(input),'marker','none');
    title('Histogram of Original Image');
    
    subplot(2,3,5);
    stem(imhist(desired),'marker','none');
    title('Histogram of desired Image');
    
    subplot(2,3,6);
    stem(imhist(img2),'marker','none');
    title('Histogram of matched Image');