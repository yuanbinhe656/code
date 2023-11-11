function x = yuanbinhe2( img )
%UNTITLED4 此处显示有关此函数的摘要
%   此处显示详细说明
f = fspecial('prewitt');
img1 = filter2(f,img);
x = double(img) + img1;

end

