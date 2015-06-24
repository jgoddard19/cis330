#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"
#include "functions.h"

void ReadImage(char* filename, Image &output)
{
	FILE *f = fopen(filename, "rb");
	char magicNum[128];
	int  width, height, maxval;

	if (f == NULL)
	{
		fprintf(stderr, "Unable to open file %s\n", filename);
	}

	fscanf(f, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);

	if (strcmp(magicNum, "P6") != 0)
	{
		fprintf(stderr, "Unable to read from file %s, because it is not a PNM file of type P6\n", filename);
	}
	
	output.setValues(width, height);
    	output.setBuffer();
	fread(output.getBuffer(), sizeof(unsigned char), 3*output.getWidth()*output.getHeight(), f);
	fclose(f);
}

void WriteImage(char* filename, Image &img)
{
	FILE *f = fopen(filename, "wb");
	fprintf(f, "P6\n%d %d\n255\n", img.getWidth(), img.getHeight());
	fwrite(img.getBuffer(), sizeof(unsigned char), 3*img.getHeight()*img.getWidth(), f);
	fclose(f);
}

void HalveInSize(Image &input, Image &output)
{
	int width_ = input.getWidth()/2;
	int height_ = input.getHeight()/2;
	output.setValues(width_, height_);
	output.setBuffer();

	for(int i = 0; i < output.getHeight(); i++)
	{
		for(int j = 0; j < output.getWidth(); j++)
		{
			int index = 3*(i*output.getWidth()+j);
			int index_ori = 3*(i*2*input.getWidth()+j*2);
			output.getBuffer()[index] = input.getBuffer()[index_ori];
			output.getBuffer()[index+1] = input.getBuffer()[index_ori+1];
			output.getBuffer()[index+2] = input.getBuffer()[index_ori+2];
		}
	}
}

void LeftRightConcatenate(Image &left, Image &right, Image &output)
{
	int width_ = left.getWidth() + right.getWidth();
	int height_ = 0;
	
	if(left.getHeight() > right.getHeight())
	{
		height_ = left.getHeight();
	} else {
		height_ = right.getHeight();
	}
	
	output.setValues(width_, height_);
	output.setBuffer();	

	for(int i = 0; i < output.getHeight(); i++)
	{
		for(int j = 0; j < output.getWidth(); j++)
		{
			int index = 3*(i*output.getWidth()+j);
			if(j < left.getWidth())
			{
				int index_ori = 3*(i*left.getWidth()+j);
				output.getBuffer()[index] = left.getBuffer()[index_ori];
				output.getBuffer()[index+1] = left.getBuffer()[index_ori+1];
				output.getBuffer()[index+2] = left.getBuffer()[index_ori+2];
			} else {
				int index_ori = 3*(i*right.getWidth()+j);
				output.getBuffer()[index] = right.getBuffer()[index_ori];
				output.getBuffer()[index+1] = right.getBuffer()[index_ori+1];
				output.getBuffer()[index+2] = right.getBuffer()[index_ori+2];
			}
		}
	}
}

void TopBottomConcatenate(Image &top, Image &bottom, Image &output)
{	
	int width_ = 0;
	int height_ = top.getHeight() + bottom.getHeight();
	
	if(top.getWidth() > bottom.getWidth())
	{
		width_ = top.getWidth();
	} else {
		width_ = bottom.getWidth();
	}
	
	output.setValues(width_, height_);
	output.setBuffer();	

	for(int j = 0; j < output.getWidth(); j++)
	{
		for(int i = 0; i < top.getHeight(); i++)
		{
            int index = 3*(i*output.getWidth()+j);
            int index_ori = 3*(i*output.getWidth()+j);
            output.getBuffer()[index] = top.getBuffer()[index_ori];
            output.getBuffer()[index+1] = top.getBuffer()[index_ori+1];
            output.getBuffer()[index+2] = top.getBuffer()[index_ori+2];
        }
    }
    for(int j = 0; j < output.getWidth(); j++)
    {
        for(int i = 0; i < bottom.getHeight(); i++)
        {
            int index = 3*((i+top.getHeight())*output.getWidth()+j);
            int index_ori = 3*(i*output.getWidth()+j);
            output.getBuffer()[index] = bottom.getBuffer()[index_ori];
            output.getBuffer()[index+1] = bottom.getBuffer()[index_ori+1];
            output.getBuffer()[index+2] = bottom.getBuffer()[index_ori+2];
        }
	}
}

void Blend(Image &left, Image &right, float factor, Image &output)
{
	output.setValues(left.getWidth(), left.getHeight());
	output.setBuffer();
    
	for(int i = 0; i < output.getHeight(); i++)
	{
		for(int j = 0; j < output.getWidth(); j++)
		{
			int index = 3*(i*output.getWidth()+j);
            int index_ori = 3*(i*left.getWidth()+j);
            output.getBuffer()[index] = left.getBuffer()[index_ori]*(factor) + right.getBuffer()[index_ori]*(1-factor);
            output.getBuffer()[index+1] = left.getBuffer()[index_ori+1]*(factor) + right.getBuffer()[index_ori+1]*(1-factor);
            output.getBuffer()[index+2] = left.getBuffer()[index_ori+2]*(factor) + right.getBuffer()[index_ori+2]*(1-factor);
		}
	}
}