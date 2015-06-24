#include <stdio.h>
#include "source.h"
#include "sink.h"

#ifndef FILTERS_H
#define FILTERS_H

class filter : public source, public sink
{
};
class Shrinker : public filter
{
public:
    void Execute();
};
class LRConcat : public filter
{
public:
    void Execute();
};
class TBConcat : public filter
{
public:
	void Execute();
};
class Blender : public filter
{
protected:
    float factor;
public:
	void SetFactor(float factor);
	void Execute();
};

#endif