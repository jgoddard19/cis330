#include "image.h"

#ifndef SOURCE_H
#define SOURCE_H

class source
{
protected:
    Image image;
public:
    Image * GetOutput();
    virtual void Execute() = 0;
    source();
};

#endif