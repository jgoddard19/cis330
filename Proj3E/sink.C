#include "image.h"
#include "sink.h"

void sink::SetInput(const Image * input1)
{
    this->input1 = input1;
}
void sink::SetInput2(const Image * input2)
{
    this->input2 = input2;
}

sink::sink()
{
    input1 = NULL;
    input2 = NULL;
};