#include <iostream>
#include <cmath>
#include "imageio.h"  // for readImage and writeImage functions
#include <cstdlib>
#include "funcs.h"

// This function reads an image from a file, inverts its colors, and writes the inverted image to a new file
void invert(std::string input){

  int img[MAX_H][MAX_W];  // 2D array to store the image data
  int h, w;  // variables to store the height and width of the image
  readImage(input, img, h, w);  // read the image data from the input file into the img array

  int image[MAX_H][MAX_W];  // 2D array to store the inverted image data
  // Iterate over the image pixels and invert their colors
  for(int i = 0; i< h;i++){
    for(int j = 0;j< w;j++){
        image[i][j] = 255 - img[i][j];
    }
  }
  writeImage("taskA.pgm",image,h,w);  // write the inverted image data to a new file
}

// This function reads an image from a file, inverts the colors of the right half of the image, and writes the modified image to a new file
void inverthalf(std::string input){
  int img[MAX_H][MAX_W];  // 2D array to store the image data
  int h, w;  // variables to store the height and width of the image
  readImage(input, img, h, w);  // read the image data from the input file into the img array

  int imga[MAX_H][MAX_W];  // 2D array to store the modified image data
  // Iterate over the image pixels and invert the colors of the right half of the image
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
    writeImage("taskB.pgm",imga,h,w);  // write the modified image data to a new file
}

// This function reads an image from a file, draws a white box in the center of the image, and writes the modified image to a new file
void box(std::string input){
  int img[MAX_H][MAX_W];  // 2D array to store the image data
  int h, w;  // variables to store the height and width of the image
  readImage(input, img, h, w);  // read the image data from the input file into the img array

  int imga[MAX_H][MAX_W];  // 2D array to store the modified image data
  int hmid = h/2;  // calculate the vertical midpoint of the image
  int wmid = w/2;  // calculate the horizontal midpoint of the image
  // Iterate over the image pixels and draw a white box in the center of the image
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
// This function takes an input filename, reads in a PGM image, 
// creates a new PGM image with a 1-pixel wide black frame around it, 
// and writes the new image to a file named "taskD.pgm".
void frame(std::string input){
  int img[MAX_H][MAX_W];
  int h, w;
  
  readImage(input, img, h, w);
  int wmid = w/2;
  int hmid = h/2;
  int imga[MAX_H][MAX_W];
  for(int i = 0; i< h;i++){
    for(int j = 0;j< w;j++){
        // If the current pixel is on the frame, set it to white (255)
        if((((i == h/4 || i == (h - h/4)) && (j > w/4 && j < (w - w/4)))) || ((j == w/4 || j == (w - w/4)) && (i > h/4 && i < (h - h/4)))){
            imga[i][j] = 255;
        }
        // Otherwise, set it to the original pixel value
        else{
            imga[i][j] = img[i][j];
        } 
    }
  }
  // Write the output image to a file named "taskD.pgm"
  writeImage("taskD.pgm",imga,h,w);
}

// This function takes an input filename, reads in a PGM image, 
// scales it up by a factor of 2 (doubling its width and height),
// and writes the new image to a file named "taskE.pgm".
void scale(std::string filename){
  int h, w;
  int image[MAX_H][MAX_W];
  int outimage[MAX_H][MAX_W];
  readImage(filename, image, h, w);
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
          // Copy each pixel to four adjacent pixels in the output image
          outimage[i*2][j*2] = image[i][j];
          outimage[i*2][j*2+1] = image[i][j];
          outimage[i*2+1][j*2] = image[i][j];
          outimage[i*2 + 1][j*2+1] = image[i][j];
     }
  }
  // Update the height and width to reflect the new size, and write the output image to a file named "taskE.pgm"
  h = h * 2;
  w = w * 2;
  writeImage("taskE.pgm", outimage, h, w);
}

// This function takes an input filename, reads in a PGM image,
// pixelates the image by replacing each 2x2 block of pixels with 
// a single pixel whose value is the average of the 4 pixels,
// and writes the new image to a file named "taskF.pgm".
// Pixelate the input image by averaging the colors of 2x2 blocks of pixels
void pixelate(std::string input)
{
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int out[MAX_H][MAX_W];
  int avg;
  int sum;
  
  // Iterate over 2x2 blocks of pixels and compute their average color
  for(int i = 0; i < h; i+=2){
     for(int j = 0; j < w; j+=2){
          sum = img[i][j] + img[i][j+1] + img[i+1][j] + img[i+1][j+1];
          avg = sum/4;
          
          // Set the color of the 2x2 block to the computed average
          out[i][j] = avg;
          out[i][j+1] = avg;
          out[i+1][j] = avg;
          out[i+1][j+1] = avg;
     }
  }
  
  // Write the pixelated image to a new file
  writeImage("taskF.pgm", out, h, w);
}
