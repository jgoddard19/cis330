#include <stdio.h>
#include "source.h"

#ifndef PNMREADER_H
#define PNMREADER_H

class PNMreader : public source
{
protected:
    char *file;
public:
    virtual void Execute();
    PNMreader(char *file);
};

#endif
