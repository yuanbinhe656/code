#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;
class color
{
public:
	color();
	int operator()()
	{
		Mat img = imread("D:/桌面/icon.png");
		if (img.empty())
		{
			cout << "请确认图像恩建名称是否正确" << endl;
			return -1;
		}
		Mat img32;

		img.convertTo(img32, CV_32F, 1 / 255.0, 0);

		Mat HSV, HSV32;

		cvtColor(img, HSV, COLOR_BGR2HSV);
		cvtColor(img32, HSV32, COLOR_BGR2HSV);

		Mat gray0, gray1;
		cvtColor(img, gray0, COLOR_BGR2GRAY);
		cvtColor(img32, gray1, COLOR_BGR2GRAY);
		
		return 0;

	}
private:

};

