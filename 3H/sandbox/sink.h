#include "image.h"

#ifndef SINK_H
#define SINK_H

class sink
{
protected:
    const Image *input1;
    const Image *input2;
public:
    virtual const char * SinkName() = 0;
    void SetInput(const Image *input1);
    void SetInput2(const Image *input2);
    sink();
};

#endif