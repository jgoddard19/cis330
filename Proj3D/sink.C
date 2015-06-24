#include "image.h"
#include "sink.h"

void sink::SetInput(Image * input1)
{
    this->input1 = input1;
}
void sink::SetInput2(Image * input2)
{
    this->input2 = input2;
}

sink::sink()
{
};