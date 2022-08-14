#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main(void)
{
   
   Mat srcImage=imread("1.png",CV_8UC3);
   Mat dstImage=Mat::zeros(srcImage.rows,srcImage.cols,CV_8UC3);
   int K[3][3]={{1,2,1},{2,4,2},{1,2,1}};
   int cvlt=0;//卷积和
   for(int i=0;i<srcImage.rows;i++){
      for(int j=0;j<srcImage.cols;j++){
         //三通道
         for(int z=0;z<3;z++){
            //卷积
            cvlt=0;
            for(int x=-1;x<=1;x++){
               for(int y=-1;y<=1;y++){
                  if((i+x==-1)||(j+y==-1)||(i+x==srcImage.rows)||(j+y==srcImage.cols)){cvlt+=0;}
                  else cvlt+=srcImage.at<Vec3b>(i+x,j+y)[z]*K[x+1][y+1]; 
               }
            }

            dstImage.at<Vec3b>(i,j)[z]=floor((float)cvlt/16.0);
            cvlt=0;
         }
      }
   }

   imshow("example",dstImage);
   //imwrite("answer_9.jpg",dstImage);
   waitKey(0);
   return 0;
}


