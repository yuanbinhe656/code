function x = yuanbinhe2( img )
%UNTITLED4 �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
f = fspecial('prewitt');
img1 = filter2(f,img);
x = double(img) + img1;

end

