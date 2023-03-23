#include <iostream>
#include "imageio.h"

void invert(int img[MAX_H][MAX_W],int h,int w){
  int imga[MAX_H][MAX_W];
  for(int i = 0; i< h;i++){
    for(int j = 0;j< w;j++){
        imga[i][j] = 255 - img[i][j];
    }
  }
  writeImage("invert.pgm",imga,h,w);
}