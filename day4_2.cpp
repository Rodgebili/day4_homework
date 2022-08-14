#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
   
   Mat srcImage=imread("imori.jpg");
   Mat img_out=Mat::zeros(Size(srcImage.cols,srcImage.rows),CV_8UC1);
   cvtColor(srcImage, img_out, COLOR_BGR2GRAY);
   for(int i=0;i<srcImage.rows;i++){
      for(int j=0;j<srcImage.cols;j++){
         img_out.at<uchar>(i,j)=0.2126*srcImage.at<Vec3b>(i,j)[2]+0.7152*srcImage.at<Vec3b>(i,j)[1]+0.0722*srcImage.at<Vec3b>(i,j)[0];
      }
   }
   imwrite("answer_2.jpg",img_out);
   waitKey(0);
   return 0;
}