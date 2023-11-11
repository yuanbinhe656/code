#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
#include<opencv2/features2d.hpp>
#include<opencv2/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

void savevideo()
{
	Mat img;
	VideoCapture video(0);// use camer

	// read cam
	if (!video.isOpened())
	{
		cout << "打开摄像头失败" << endl;
		return;
	}

	video >> img;// 先拿第一张图像作为视频保存的格式
	bool isColor = (img.type() == CV_8UC3);
	int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');//选择编码格式
	VideoWriter writer;
	double fps = 25.0;
	string filename = "live.avi";
	writer.open(filename, codec, fps, img.size(), isColor);
	if (!writer.isOpened())
	{
		cout << "打开视频失败" << endl;
		return;
	}
	while (1)
	{
		video.read(img);
		writer.write(img);
		imshow("live", img);
		char c = waitKey(25);
		if (c == 27)
		{
			break;
		}

		

	}
	
}

int main(int argc, char** argv)
{
	savevideo();

	
	return 0;



}

