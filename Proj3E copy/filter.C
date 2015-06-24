#include <stdio.h>
#include "source.h"
#include "sink.h"
#include "filters.h"

void filter::Update()
{
    if(input1 != NULL)
    {
        input1->Update();
        Execute();
    }
    if(input2 != NULL)
    {
        input2->Update();
        Execute();
    }
}