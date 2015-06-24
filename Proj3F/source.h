#include "image.h"

#ifndef SOURCE_H
#define SOURCE_H

class source
{
protected:
    Image image;
    virtual void Execute() = 0;
public:
    virtual const char * SourceName() = 0;
    virtual void Update() = 0;
    Image * GetOutput();
    source();
};

#endif