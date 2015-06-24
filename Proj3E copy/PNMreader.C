#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PNMreader.h"

PNMreader::PNMreader(char *file)
{
    this->file = file;
}

void PNMreader::Update()
{
    Execute();
}

void PNMreader::Execute()
{
	FILE *f = fopen(this->file, "rb");
	char magicNum[128];
	int  width, height, maxval;
    
	if (f == NULL)
	{
		fprintf(stderr, "Unable to open file %s\n", this->file);
	}
    
	fscanf(f, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
    
	if (strcmp(magicNum, "P6") != 0)
	{
		fprintf(stderr, "Unable to read from file %s, because it is not a PNM file of type P6\n", this->file);
	}
	
	image.setValues(width, height);
    image.setBuffer();
	fread(image.getBuffer(), sizeof(unsigned char), 3*image.getWidth()*image.getHeight(), f);
	fclose(f);
}
