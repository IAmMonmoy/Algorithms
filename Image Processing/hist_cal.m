function y = hist_cal(img)

    [r,c] = size(img);
    hist_array = zeros(1,256);
    
    for i = 1:r
        for j = 1:c
            hist_array(img(i,j)+1) = hist_array(img(i,j)+1)+1; %because value is 0 to 255 but array 1 to 256
        end
    end
    
    y = hist_array;
end