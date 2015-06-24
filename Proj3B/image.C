#include <stdio.h>
#include <stdlib.h>
#include "image.h"

void Image::setValues(int x, int y)
{
    width = x;
    height = y;
}
void Image::setBuffer()
{
    buffer = (unsigned char*) malloc(sizeof(unsigned char)*3*height*width);
}

int Image::getWidth()
{
    return width;
}
int Image::getHeight()
{
    return height;
}
int Image::getMaxVal()
{
    return maxval;
}
unsigned char* Image::getBuffer()
{
    return buffer;
}
