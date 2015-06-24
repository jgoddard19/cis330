#include <stdio.h>
#include "source.h"

#ifndef PNMREADERCPP_H
#define PNMREADERCPP_H

class PNMreaderCPP : public source
{
protected:
    char *file;
public:
    virtual void Execute();
    PNMreaderCPP(char *file);
};

#endif
