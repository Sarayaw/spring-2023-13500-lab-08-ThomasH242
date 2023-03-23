#pragma once

const int MAX_H = 512;
const int MAX_W = 512;

void readImage(std::string filename, int image[MAX_H][MAX_W], int &height, int &width);
void writeImage(std::string filename, int image[MAX_H][MAX_W], int height, int width); 
void invert(int img[MAX_H][MAX_W],int h,int w);
void inverthalf(int img[MAX_H][MAX_W],int h, int w);