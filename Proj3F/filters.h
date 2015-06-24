#include <stdio.h>
#include "source.h"
#include "sink.h"

#ifndef FILTERS_H
#define FILTERS_H

class filter : public source, public sink
{
public:
    virtual const char * FilterName() = 0;
    virtual const char * SourceName();
    virtual const char * SinkName();
    void Update();
};
class Shrinker : public filter
{
public:
    const char * FilterName() { return "Shrinker"; };
    void Execute();
};
class LRConcat : public filter
{
public:
    const char * FilterName() { return "LRConcat"; };
    void Execute();
};
class TBConcat : public filter
{
public:
    const char * FilterName() { return "TBConcat"; };
	void Execute();
};
class Blender : public filter
{
protected:
    float factor;
public:
    const char * FilterName() { return "Blender"; };
	void SetFactor(float factor);
	void Execute();
};

#endif