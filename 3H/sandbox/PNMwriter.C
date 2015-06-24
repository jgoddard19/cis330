#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PNMwriter.h"
#include "logging.h"

void PNMwriter::Write(char *filename)
{
	FILE *f = fopen(filename, "wb");
	fprintf(f, "P6\n%d %d\n255\n", input1->getWidth(), input1->getHeight());
	fwrite(input1->getBuffer(), sizeof(unsigned char), 3*input1->getHeight()*input1->getWidth(), f);
	fclose(f);
}

const char * PNMwriter::SinkName()
{
    const char * msg;
    msg = "PNMwriter";
    return msg;
}