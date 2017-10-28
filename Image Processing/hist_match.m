function y = hist_match(input,desired)

    img2 = input;
    
    input_hist = imhist(input);
    output_hist = imhist(desired);
    
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
          cummulativeInput(i) = floor(cummulativeInput(i)*255); %floor both input and output image 
          cummulativeOutput(i) = floor(cummulativeOutput(i)*255);
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
            img2(i,j) = map(img2(i,j)); %make the original image by mapping
        end
    end
    
    
    subplot(2,2,1);
    imshow(input);
    title('Original Image');
    
     subplot(2,2,2);
    imshow(desired);
    title('Desired Image');
    
     subplot(2,2,3);
    imshow(img2);
    title('Matched Image');
end