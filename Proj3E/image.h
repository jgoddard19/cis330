#include <stdio.h>

#ifndef IMAGE_H
#define IMAGE_H

class source;
class Image
{
public:
    Image(void);
    void setValues(int, int);
    int getHeight() const;
    int getWidth() const;
    unsigned char* getBuffer() const;
    int getMaxVal() const;
    void setBuffer();
    void Update() const;
    void setSource(source *s);
	
private:
    unsigned char *buffer;
    int width, height, maxval;
    source *source_;
};

#endif
