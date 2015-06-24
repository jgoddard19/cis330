#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "PNMreaderCPP.h"

PNMreaderCPP::PNMreaderCPP(char *file)
{
    this->file = file;
}

void PNMreaderCPP::Execute()
{
    std::ifstream f;
    f.open(this->file, std::ios::in);
	char magicNum[128];
	int  width, height, maxval;
    
	if (f == NULL)
	{
        std::cerr << "Unable to open file %s\n" << this->file;
	}
    
    std::cin >> magicNum;
    std::cin >> width;
    std::cin >> height;
    std::cin >> maxval;
    
	if (strcmp(magicNum, "P6") != 0)
	{
        std::cerr << "Unable to read from file %s, because it is not a PNM file of type P6\n" << this->file;
	}
	
	image.setValues(width, height);
    image.setBuffer();
    std::cout << image.getBuffer() << f;
    std::cout << sizeof(unsigned char) << f;
    std::cout << 3*image.getWidth()*image.getHeight() << f;
	f.close();
}
