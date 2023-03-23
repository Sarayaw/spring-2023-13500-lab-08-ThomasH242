#include <iostream>
#include "imageio.h"
void inverthalf(int img[MAX_H][MAX_W],int h,int w){
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
    writeImage("inverthalf.pgm",imga,h,w);
}