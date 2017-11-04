    img = imread('stretch.tif');

    img2 = img; %for equalized image
    
    histogram = hist_cal(img); %calculate the histogram from define function
    
    [r,c] = size(img); %for finding row and column to find total element for finding probability
    
    n = r*c; %total element
    
    probability = zeros(1,256);
    
    for i = 1:256
        probability(i) = histogram(i)/n; %finding probability
    end
    
    cummulativeProbability = zeros(1,256);
    cummulativeProbability(1) = probability(1);
    
    for i = 2:256
        cummulativeProbability(i) = probability(i)+cummulativeProbability(i-1); %cummulative probability
    end
    
    for i = 1:256
        cummulativeProbability(i) = floor(cummulativeProbability(i)*255); %if we want the intensity range from 1-255 and if value 13.75 round to 13 by floor
    end
    
    
    for i = 1:r
        for j = 1:c
            img2(i,j) = cummulativeProbability(img2(i,j)+1);
        end
    end
    
    histogramEqualizedImage = hist_cal(img2);
    
    subplot(2,2,1);
    imshow(img);
    subplot(2,2,2);
    stem(histogram,'marker','none');
    subplot(2,2,3);
    imshow(img2);
    subplot(2,2,4);
    stem(histogramEqualizedImage,'marker','none');
    
   