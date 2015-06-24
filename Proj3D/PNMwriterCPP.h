#include <stdio.h>
#include "sink.h"

#ifndef PNMWRITERCPP_H
#define PNMWRITERCPP_H

class PNMwriterCPP : public sink
{
public:
    void Write(char *filename);
};

#endif