#include <stdio.h>
#include "source.h"
#include "sink.h"
#include "filters.h"

void Shrinker::Execute()
{
	int width_ = input1->getWidth()/2;
	int height_ = input1->getHeight()/2;
	image.setValues(width_, height_);
	image.setBuffer();
    
	for(int i = 0; i < image.getHeight(); i++)
	{
		for(int j = 0; j < image.getWidth(); j++)
		{
			int index = 3*(i*image.getWidth()+j);
			int index_ori = 3*(i*2*input1->getWidth()+j*2);
			image.getBuffer()[index] = input1->getBuffer()[index_ori];
			image.getBuffer()[index+1] = input1->getBuffer()[index_ori+1];
			image.getBuffer()[index+2] = input1->getBuffer()[index_ori+2];
		}
	}
}

void LRConcat::Execute()
{
	int width_ = input1->getWidth() + input2->getWidth();
	int height_ = 0;
	
	if(input1->getHeight() > input2->getHeight())
	{
		height_ = input1->getHeight();
	} else {
		height_ = input2->getHeight();
	}
	
	image.setValues(width_, height_);
	image.setBuffer();
    
	for(int i = 0; i < image.getHeight(); i++)
	{
		for(int j = 0; j < image.getWidth(); j++)
		{
			int index = 3*(i*image.getWidth()+j);
			if(j < input1->getWidth())
			{
				int index_ori = 3*(i*input1->getWidth()+j);
				image.getBuffer()[index] = input1->getBuffer()[index_ori];
				image.getBuffer()[index+1] = input1->getBuffer()[index_ori+1];
				image.getBuffer()[index+2] = input1->getBuffer()[index_ori+2];
			} else {
				int index_ori = 3*(i*input2->getWidth()+j);
				image.getBuffer()[index] = input2->getBuffer()[index_ori];
				image.getBuffer()[index+1] = input2->getBuffer()[index_ori+1];
				image.getBuffer()[index+2] = input2->getBuffer()[index_ori+2];
			}
		}
	}
}

void TBConcat::Execute()
{
	int width_ = 0;
	int height_ = input1->getHeight() + input2->getHeight();
	
	if(input1->getWidth() > input2->getWidth())
	{
		width_ = input1->getWidth();
	} else {
		width_ = input2->getWidth();
	}
	
	image.setValues(width_, height_);
	image.setBuffer();
    
	for(int j = 0; j < image.getWidth(); j++)
	{
		for(int i = 0; i < input1->getHeight(); i++)
		{
            int index = 3*(i*image.getWidth()+j);
            int index_ori = 3*(i*image.getWidth()+j);
            image.getBuffer()[index] = input1->getBuffer()[index_ori];
            image.getBuffer()[index+1] = input1->getBuffer()[index_ori+1];
            image.getBuffer()[index+2] = input1->getBuffer()[index_ori+2];
        }
    }
	for(int j = 0; j < image.getWidth(); j++)
    {
        for(int i = 0; i < input2->getHeight(); i++)
        {
            int index = 3*((i+input1->getHeight())*image.getWidth()+j);
            int index_ori = 3*(i*image.getWidth()+j);
            image.getBuffer()[index] = input2->getBuffer()[index_ori];
            image.getBuffer()[index+1] = input2->getBuffer()[index_ori+1];
            image.getBuffer()[index+2] = input2->getBuffer()[index_ori+2];
        }
	}
}

void Blender::SetFactor(float factor)
{
    this->factor = factor;
}

void Blender::Execute()
{
	image.setValues(input1->getWidth(), input1->getHeight());
	image.setBuffer();
    
	for(int i = 0; i < image.getHeight(); i++)
	{
		for(int j = 0; j < image.getWidth(); j++)
		{
            int index = 3*(i*image.getWidth()+j);
            int index_ori = 3*(i*input1->getWidth()+j);
            image.getBuffer()[index] = input1->getBuffer()[index_ori]*(factor) + input2->getBuffer()[index_ori]*(1-factor);
            image.getBuffer()[index+1] = input1->getBuffer()[index_ori+1]*(factor) + input2->getBuffer()[index_ori+1]*(1-factor);
            image.getBuffer()[index+2] = input1->getBuffer()[index_ori+2]*(factor) + input2->getBuffer()[index_ori+2]*(1-factor);
		}
	}
}
