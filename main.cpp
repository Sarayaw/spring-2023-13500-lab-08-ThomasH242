#include <iostream>
#include "imageio.h"
#include "funcs.h"

int main(){
    invert("inImage.pgm");
    inverthalf("inImage.pgm");
    box("inImage.pgm");
    frame("inImage.pgm");
    scale("inImage.pgm");
    pixelate("inImage.pgm");

    return 0;
}