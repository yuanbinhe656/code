function x = yuanbinhe1( img )
%UNTITLED2 �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��

f = fspecial('gaussian');
img1 = filter2(f,img);
%ԭͼ��+ԭͼ��-ƽ��ͼ��
x = double(img) + double(img) - img1;
end

