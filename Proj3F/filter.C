#include <stdio.h>
#include "source.h"
#include "sink.h"
#include "filters.h"
#include "logging.h"

void filter::Update()
{
    if(input1 != NULL)
    {
        char msg[128];
        sprintf(msg, "%s: about to update input1\n", SourceName());
        Logger::LogEvent(msg);
        input1->Update();
        sprintf(msg, "%s: done updating input1\n", SourceName());
        Logger::LogEvent(msg);
    }
    if(input2 != NULL)
    {
        char msg[128];
        sprintf(msg, "%s: about to update input2\n", SourceName());
        Logger::LogEvent(msg);
        input2->Update();
        sprintf(msg, "%s: done updating input2\n", SourceName());
        Logger::LogEvent(msg);
    }
    char msg[1024];
    sprintf(msg, "%s: about to execute\n", SourceName());
    Logger::LogEvent(msg);
    Execute();
    sprintf(msg, "%s: done executing\n", SourceName());
    Logger::LogEvent(msg);
}

const char * filter::SourceName() { return FilterName(); }

const char * filter::SinkName() { return FilterName(); }