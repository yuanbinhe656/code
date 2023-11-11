function x = yuanbinhe1( img )
%UNTITLED2 此处显示有关此函数的摘要
%   此处显示详细说明

f = fspecial('gaussian');
img1 = filter2(f,img);
%原图像+原图像-平滑图像
x = double(img) + double(img) - img1;
end

