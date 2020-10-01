#include <SFML/Graphics.hpp>
#include <eigen3/Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include <time.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

// int main()
// {
//     std::cout << "main function\n";

//     return 0;
// }

using namespace cv;
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
    Mat image;
    image = imread(argv[1], 1);
    if (!image.data)
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    waitKey(0);
    return 0;
}