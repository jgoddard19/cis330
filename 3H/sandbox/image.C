#include <stdio.h>
#include <stdlib.h>
#include "source.h"
#include "image.h"

Image::Image(void)
{
    int width = 0;
    int height = 0;
    int maxval =0;
    unsigned char * buffer = NULL;
}

void Image::setSource(source *s)
{
    source_ = s;
}

void Image::Update() const
{
    if(source_ != NULL)
    {
        source_->Update();
    }
}

void Image::setValues(int x, int y)
{
    width = x;
    height = y;
}
void Image::setBuffer()
{
    buffer = (unsigned char*) malloc(sizeof(unsigned char)*3*height*width);
}

int Image::getWidth() const
{
    return width;
}
int Image::getHeight() const
{
    return height;
}
int Image::getMaxVal() const
{
    return maxval;
}
unsigned char* Image::getBuffer() const
{
    return buffer;
}
