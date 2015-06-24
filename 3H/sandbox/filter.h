#include <stdio.h>
#include "source.h"
#include "sink.h"

#ifndef FILTER_H
#define FILTER_H

class filters : public source, public sink
{
public:
    virtual const char *FilterName() = 0;
    virtual const char *SourceName();
    virtual const char *SinkName();
    virtual void Update();
};

#endif