#include "filter.h"
#include "logging.h"

int james;

void filters::Update()
{
    james++;
    if(james > 1000)
    {
        char msg[1024];
        sprintf(msg, "%s: too many updates!\n", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }
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

const char * filters::SourceName() { return FilterName(); }

const char * filters::SinkName() { return FilterName(); }