#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main(void)
{
   
   Mat srcImage=imread("imori.jpg");
   int max_h;
   int min_h;
   float C,h,H,V,S,X;
   int r,g,b;
   for(int i=0;i<srcImage.cols;i++){
      for(int j=0;j<srcImage.rows;j++){
         max_h=max(srcImage.at<Vec3b>(i,j)[0],max(srcImage.at<Vec3b>(i,j)[1],srcImage.at<Vec3b>(i,j)[2]));
         min_h=min(srcImage.at<Vec3b>(i,j)[0],max(srcImage.at<Vec3b>(i,j)[1],srcImage.at<Vec3b>(i,j)[2]));
         if(min_h==max_h){
            H=0;
         }
         else if(min_h==srcImage.at<Vec3b>(i,j)[0]){
            H=(srcImage.at<Vec3b>(i,j)[1]-srcImage.at<Vec3b>(i,j)[2])/(max_h-min_h)*60+60;
         }
         else if(min_h==srcImage.at<Vec3b>(i,j)[1]){
            H=(srcImage.at<Vec3b>(i,j)[0]-srcImage.at<Vec3b>(i,j)[1])/(max_h-min_h)*60+180;
         }
         else if(min_h==srcImage.at<Vec3b>(i,j)[2]){
            H=(srcImage.at<Vec3b>(i,j)[2]-srcImage.at<Vec3b>(i,j)[0])/(max_h-min_h)*60+300;
         }
         S=max_h-min_h;        
         V=max_h;
         //色相反转
         H=(H>180)?H-180:H+180;

        
         C=S;
         h=H/60;
         X=C*(1-(fmod(h,2)-1));

         if(h<1){
            r=V-C+C;
            g=V-C+X;
            b=V-C;
         }
         else if(h<2){
            r=V-C+X;
            g=V-C+C;
            b=V-C;
         }
         else if(h<3){
            r=V-C;
            g=V-C+C;
            b=V-C+X;
         }
         else if(h<4){
            r=V-C;
            g=V-C+X;
            b=V-C+C;
         }
         else if(h<5){
            r=V-C+X;
            g=V-C;
            b=V-C+C;
         }
         else if(h<6){
            r=V-C+C;
            g=V-C;
            b=V-C+X;
         }
         srcImage.at<Vec3b>(i,j)[0]=b;
         srcImage.at<Vec3b>(i,j)[1]=g;
         srcImage.at<Vec3b>(i,j)[2]=r;
      }
   }

   imwrite("answer_5.jpg",srcImage);
   return 0;
}
