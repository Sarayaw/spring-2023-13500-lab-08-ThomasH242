#include <iostream>
#include <cmath>
#include "imageio.h"
#include <cstdlib>
#include "funcs.h"

void invert(std::string input){

  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);

  int image[MAX_H][MAX_W];
  for(int i = 0; i< h;i++){
    for(int j = 0;j< w;j++){
        image[i][j] = 255 - img[i][j];
    }
  }
  writeImage("taskA.pgm",image,h,w);
}
void inverthalf(std::string input){
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int imga[MAX_H][MAX_W];
  for(int i = 0;i<h;i++){
    for(int j = 0;j<w;j++){
        if(j >= w/2){
            imga[i][j] = 255-img[i][j];
        }
        else{
            imga[i][j]=img[i][j];
        }
    }
  }
    writeImage("taskB.pgm",imga,h,w);
}
void box(std::string input){
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int imga[MAX_H][MAX_W];
  int hmid = h/2;
  int wmid = w/2;
  for(int i = 0; i< h;i++){
    for(int j = 0;j< w;j++){
        if(j >= wmid/2 && i >= hmid/2 && j <=wmid*1.5 && i <=hmid*1.5){
            imga[i][j] = 255;
        }
        else{
            imga[i][j] = img[i][j];
        }
    }
  }
  writeImage("taskC.pgm",imga,h,w);
}
void frame(std::string input){
  int img[MAX_H][MAX_W];
  int h, w;
  
  readImage(input, img, h, w);
  int wmid = w/2;
  int hmid = h/2;
  int imga[MAX_H][MAX_W];
  for(int i = 0; i< h;i++){
    for(int j = 0;j< w;j++){
        if((((i == h/4 || i == (h - h/4)) && (j > w/4 && j < (w - w/4)))) || ((j == w/4 || j == (w - w/4)) && (i > h/4 && i < (h - h/4)))){
            imga[i][j] = 255;
        }
        else{
            imga[i][j] = img[i][j];
        } 
    }
  }
  writeImage("taskD.pgm",imga,h,w);
}
void scale(std::string filename){
  int h, w;
  int image[MAX_H][MAX_W];
  int outimage[MAX_H][MAX_W];
  readImage(filename, image, h, w);
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
          outimage[i*2][j*2] = image[i][j];
          outimage[i*2][j*2+1] = image[i][j];
          outimage[i*2+1][j*2] = image[i][j];
          outimage[i*2 + 1][j*2+1] = image[i][j];
     }//end inner for loop
  }//end for loop
  h = h * 2;
  w = w * 2;
  writeImage("taskE.pgm", outimage, h, w);
}

void pixelate(std::string input)
{
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int out[MAX_H][MAX_W];
  int avg;
  int sum;
  for(int i = 0; i < h; i+=2){
     for(int j = 0; j < w; j+=2){
          sum = img[i][j] + img[i][j+1] + img[i+1][j] + img[i+1][j+1];
          avg = sum/4;
          out[i][j] = avg;
          out[i][j+1] = avg;
          out[i+1][j] = avg;
          out[i+1][j+1] = avg;
     }
  }
    writeImage("taskF.pgm", out, h, w);
}