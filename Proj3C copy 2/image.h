#include <stdio.h>

#ifndef IMAGE_H
#define IMAGE_H

class Image
{
public:
    Image(void);
    void setValues(int, int);
    int getHeight();
    int getWidth();
    unsigned char* getBuffer();
    int getMaxVal();
    void setBuffer();
	
private:
    unsigned char *buffer;
    int width, height, maxval;
};

#endif
