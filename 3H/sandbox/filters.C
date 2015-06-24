#include <stdio.h>
#include <exception>
#include "source.h"
#include "sink.h"
#include "filters.h"
#include "logging.h"

void Shrinker::Execute(void)
{
    if(input1 == NULL)
    {
        char msg[1024];
        sprintf(msg, "%s: no input1!\n", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }
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

void LRConcat::Execute(void)
{
    if(input1 == NULL)
    {
        char msg[1024];
        sprintf(msg, "%s: no input1!\n", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }
    if(input2 == NULL)
    {
        char msg[1024];
        sprintf(msg, "%s: no input2!\n", SinkName());
        DataFlowException e(SinkName(), msg);
             throw e;
    }
    
    if (input1->getHeight() != input2->getHeight())
    {
        char msg[1024];
        sprintf(msg, "%s: heights must match: %d, %d\n", SinkName(), input1->getHeight(),
                input2->getHeight());
        DataFlowException e(SinkName(), msg);
        throw e;
    }
        int height_ = 0;
        if(input1->getHeight() > input2->getHeight())
        {
            height_ = input1->getHeight();
        } else {
            height_ = input2->getHeight();
        }
        int width_ = input1->getWidth() + input2->getWidth();
	
        image.setValues(width_, height_);
        image.setBuffer();
        for(int i = 0; i < input1->getHeight(); i++)
         {
            for(int j = 0; j < image.getWidth(); j++)
            {
                if(j < input1->getWidth())
                {
                    int index = 3*(i * image.getWidth() + j);
                    int index_ori = 3*(i * input1->getWidth() +j);
                    image.getBuffer()[index] = input1->getBuffer()[index_ori];
                    image.getBuffer()[index+1] = input1->getBuffer()[index_ori+1];
                    image.getBuffer()[index+2] = input1->getBuffer()[index_ori+2];
                } else {
                    int index = 3*(i * image.getWidth() + j);
                    int index_ori = 3*((i * input2->getWidth() +j) - input1->getWidth());
                    image.getBuffer()[index] = input2->getBuffer()[index_ori];
                    image.getBuffer()[index+1] = input2->getBuffer()[index_ori+1];
                    image.getBuffer()[index+2] = input2->getBuffer()[index_ori+2];
                }
            }
        }
}

void TBConcat::Execute(void)
{
    if(input1 == NULL)
    {
        char msg[1024];
        sprintf(msg, "%s: no input1!\n", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }
    if(input2 == NULL)
    {
        char msg[1024];
        sprintf(msg, "%s: no input2!\n", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }
    if (input1->getWidth() != input2->getWidth())
    {
        char msg[1024];
        sprintf(msg, "%s: widths must match: %d, %d\n", SinkName(), input1->getWidth(),
                    input2->getWidth());
        DataFlowException e(SinkName(), msg);
        throw e;
    }
	int width_ = 0;
    if(input1->getWidth() > input2->getWidth())
    {
        width_ = input1->getWidth();
    } else {
        width_ = input2->getWidth();
    }
	int height_ = input1->getHeight() + input2->getHeight();
	
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

void Blender::Execute(void)
{
    if(input1 == NULL)
    {
        char msg[1024];
        sprintf(msg, "%s: no input1!\n", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }
    if(input2 == NULL)
    {
        char msg[1024];
        sprintf(msg, "%s: no input2!\n", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }
    if (input1->getWidth() != input2->getWidth())
    {
        char msg[1024];
        sprintf(msg, "%s: widths must match: %d, %d\n", SinkName(), input1->getWidth(),
                input2->getWidth());
        DataFlowException e(SinkName(), msg);
        throw e;
    }
    if (input1->getHeight() != input2->getHeight())
    {
        char msg[1024];
        sprintf(msg, "%s: widths must match: %d, %d\n", SinkName(), input1->getHeight(),
                input2->getHeight());
        DataFlowException e(SinkName(), msg);
        throw e;
    }
    if (factor < 0 || factor > 1)
    {
        char msg[1024];
        sprintf(msg, "%s: factor is invalid: %f\n", SinkName(), factor);
        DataFlowException e(SinkName(), msg);
        throw e;
    }
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

void Crop::Execute(void)
{
    if(input1 == NULL)
    {
        char msg[1024];
        sprintf(msg, "%s: no input1!\n", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }
    if (Istart < 0 || Istop < 0 || Jstart < 0 || Jstop < 0)
    {
        char msg[1024];
        sprintf(msg, "%s: uninitialized region", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    if (Istart >= input1->getWidth() || Istop >= input1->getWidth())
    {
        char msg[1024];
        sprintf(msg, "%s: region outside image width", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    if (Jstart >= input1->getHeight() || Jstop >= input1->getHeight())
    {
        char msg[1024];
        sprintf(msg, "%s: region outside image height", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    if (Istop < Istart || Jstop < Jstart)
    {
        char msg[1024];
        sprintf(msg, "%s: invalid region", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    
    int height = Jstop-Jstart+1;
    int width  = Istop-Istart+1;
    int inputWidth = input1->getWidth();
    image.setValues(width, height);
    image.setBuffer();
    for (int i = Istart ; i <= Istop ; i++)
        for (int j = Jstart ; j <= Jstop ; j++)
        {
            int index_ori = j*inputWidth+i;
            int index = (j-Jstart)*width+(i-Istart);
            image.getBuffer()[3*index]   = input1->getBuffer()[3*index_ori];
            image.getBuffer()[3*index+1] = input1->getBuffer()[3*index_ori+1];
            image.getBuffer()[3*index+2] = input1->getBuffer()[3*index_ori+2];
        }
}

void Invert::Execute(void)
{
    if(input1 == NULL)
    {
        char msg[1024];
        sprintf(msg, "%s: no input1!\n", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }
    image.setValues(input1->getWidth(), input1->getHeight());
    image.setBuffer();
    
    for(int i = 0; i < image.getWidth(); i++)
    {
        for(int j = 0; j < image.getHeight(); j++)
        {
            int index = 3*(j*image.getWidth()+i);
            int index_ori = 3*(j*input1->getWidth()+i);
            image.getBuffer()[index] = 255 - input1->getBuffer()[index_ori];
            image.getBuffer()[index+1] = 255 - input1->getBuffer()[index_ori+1];
            image.getBuffer()[index+2] = 255 - input1->getBuffer()[index_ori+2];
        }
    }
}
    
void Transpose::Execute(void)
{
    if(input1 == NULL)
    {
        char msg[1024];
        sprintf(msg, "%s: no input1!\n", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }
    image.setValues(input1->getHeight(), input1->getWidth());
    image.setBuffer();
    
    for(int i = 0; i < image.getHeight(); i++)
    {
        for(int j = 0; j < image.getWidth(); j++)
        {
            int index = 3*(i*image.getWidth()+j);
            int index_ori = 3*(j*input1->getWidth()+i);
            image.getBuffer()[index] = input1->getBuffer()[index_ori];
            image.getBuffer()[index+1] = input1->getBuffer()[index_ori+1];
            image.getBuffer()[index+2] = input1->getBuffer()[index_ori+2];
        }
    }
}
    
void Color::Execute(void)
{
    image.setValues(width, height);
    image.setBuffer();
    
    for(int i = 0; i < image.getWidth(); i++)
	{
		for(int j = 0; j < image.getHeight(); j++)
		{
            int index = 3*(j*image.getWidth()+i);
            image.getBuffer()[index] = red;
            image.getBuffer()[index+1] = green;
            image.getBuffer()[index+2] = blue;
        }
    }
}

void Color::Update()
{
    Execute();
}

void CheckSum::OutputCheckSum(const char *filename)
{
    FILE *f = fopen(filename, "w");
    unsigned char red = 0;
    unsigned char green = 0;
    unsigned char blue = 0;
    
    for(int j = 0; j < input1->getWidth(); j++)
	{
		for(int i = 0; i < input1->getHeight(); i++)
		{
            int index = 3*(i*input1->getWidth()+j);
            red += input1->getBuffer()[index];
            green += input1->getBuffer()[index+1];
            blue += input1->getBuffer()[index+2];
        }
    }
    fprintf(f, "CHECKSUM: %d, %d, %d\n", red, green, blue);
    fclose(f);
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
