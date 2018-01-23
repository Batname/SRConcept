
#if defined _WIN32 || defined _WIN64
    #include <Windows.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

    #define DLLEXPORT __declspec(dllexport)
#else
    #include <stdio.h>
#endif

#ifndef DLLEXPORT
    #define DLLEXPORT
#endif


DLLEXPORT void ExampleLibraryFunction(const char* ImagePath)
{
#if defined _WIN32 || defined _WIN64
	MessageBox(NULL, TEXT("2 >>DEBUG nice BAT world!"), NULL, MB_OK);

	Mat image;
	image = imread(ImagePath, IMREAD_COLOR); // Read the file

	if (!image.data) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
	}

	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display window", image); // Show our image inside it.

#else
    printf("Hello World");
#endif
}