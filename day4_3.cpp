#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main(void)
{
   
   Mat srcImage=imread("2.png",0);
   
   for(int i=0;i<srcImage.cols;i++){
      for(int j=0;j<srcImage.rows;j++){
         srcImage.at<uchar>(i,j)=(srcImage.at<uchar>(i,j)>128)?255:0;
      }
   }
   imwrite("answer_3.jpg",srcImage);
   
   return 0;
}
