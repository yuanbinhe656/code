me = imread('me.jpg');
me = imresize(me,0.2);

gray_me = rgb2gray(me);
ave = fspecial('average');
imave = filter2(ave,gray_me);
gus = fspecial('gaussian',3,0.5);
imgus = filter2(gus,gray_me);
lap = fspecial('laplacian');
imlap = filter2(lap,gray_me);
lo = fspecial('log');
imlo  = filter2(lo ,gray_me);
pre = fspecial('prewitt');
impre = filter2(pre,gray_me);
sob = fspecial('sobel');
imsob  = filter2(sob ,gray_me);

subplot(3,3,1),imshow(me);
subplot(3,3,2),imshow(imave,[]);
subplot(3,3,3),imshow(imgus,[]);
subplot(3,3,4),imshow(imlap,[]);
subplot(3,3,5),imshow(imlo,[] );
subplot(3,3,6),imshow(impre,[]);
subplot(3,3,7),imshow(imsob ,[]);
