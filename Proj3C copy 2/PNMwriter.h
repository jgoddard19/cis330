#include <stdio.h>
#include "sink.h"

#ifndef PNMWRITER_H
#define PNMWRITER_H

class PNMwriter : public sink
{
public:
    void Write(char *filename);
};

#endif