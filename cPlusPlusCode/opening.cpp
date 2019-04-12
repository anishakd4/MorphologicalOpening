#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(){
    //Read image on which opening operation is to be applied on
    Mat image = imread("../assets/opening.png");

    //In some cases, it may be required to implement a particular morphological operation more than once. 
    //In those cases, we need to define the number of iterations required.
    //Initializing number of iterations
    int iterations = 1;

    //Create structuring element/kernel. Here we are creating a elliptical kernel
    int kernelSize = 3;
    Mat element = getStructuringElement(MORPH_ELLIPSE, Size(2*kernelSize + 1, 2*kernelSize + 1), Point(kernelSize, kernelSize));

    Mat result;
    //Applying erosion followed by dilation on image.
    morphologyEx(image, result, MORPH_OPEN, element, Point(-1, -1), iterations);

    //Create windows to show images
    namedWindow("input image", WINDOW_NORMAL);
    namedWindow("morph opened image", WINDOW_NORMAL);

    //Display images
    imshow("input image", image);
    imshow("morph opened image", result);

    //Press esc to exit the program
    waitKey(0);

    //Close all the opened windows
    destroyAllWindows();

    return 0;
}