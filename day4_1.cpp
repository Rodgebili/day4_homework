#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main(void)
{
   
   Mat srcImage=imread("imori.jpg");
   
   int exchange;
   for(int i=0;i<srcImage.rows;i++){
      for(int j=0;j<srcImage.cols;j++){
         exchange=srcImage.at<Vec3b>(i,j)[0];
         srcImage.at<Vec3b>(i,j)[0]=srcImage.at<Vec3b>(i,j)[2];
         srcImage.at<Vec3b>(i,j)[2]=exchange;
      }
   }
   
   imwrite("answer_1.jpg",srcImage);
   
   return 0;
}


