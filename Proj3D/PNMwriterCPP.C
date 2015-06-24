#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "PNMwriterCPP.h"

void PNMwriterCPP::Write(char *filename)
{
    std::ofstream f;
    f.open(filename, std::ios::out);
    std::cout << f;
    std::cout << "P6\n%d %d\n255\n" << f;
    std::cout << input1->getWidth() << f;
    std::cout << input1->getHeight() << f;
	f << (input1->getBuffer(), sizeof(unsigned char), 3*input1->getHeight()*input1->getWidth());
	f.close();
}