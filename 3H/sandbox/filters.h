#include <stdio.h>
#include "source.h"
#include "sink.h"
#include "filter.h"

#ifndef FILTERS_H
#define FILTERS_H

class filter : public filters
{
};
class Shrinker : public filter
{
public:
    const char *FilterName() { return "Shrinker"; };
    void Execute();
};
class LRConcat : public filter
{
public:
    const char *FilterName() { return "LRConcat"; };
    void Execute();
};
class TBConcat : public filter
{
public:
    const char *FilterName() { return "TBConcat"; };
	void Execute();
};
class Blender : public filter
{
protected:
    float factor;
public:
    const char *FilterName() { return "Blender"; };
	void SetFactor(float factor);
	void Execute();
};
class Crop : public filter
{
public:
    Crop()  { Istart = Istop = Jstart = Jstop = -1; };
    virtual const char *FilterName() { return "Crop"; };
    void   Execute();
    void   SetRegion(int Istart_, int Istop_, int Jstart_, int Jstop_)
    {
        Istart = Istart_;
        Istop  = Istop_;
        Jstart = Jstart_;
        Jstop  = Jstop_;
    }
    
private:
    int Istart, Istop, Jstart, Jstop;
};
class Invert : public filter
{
public:
    const char *FilterName() { return "Invert"; };
    void Execute();
};
class Transpose : public filter
{
public:
    const char *FilterName() { return "Transpose"; };
    void Execute();
};

class Color : public source
{
public:
    const char *SourceName() { return "Color"; };
    void Execute();
    virtual void Update();
    Color(int w, int h, unsigned char r, unsigned char g, unsigned char b)
    {
        width = w;
        height = h;
        red = r;
        green = g;
        blue = b;
    }
protected:
    int width, height;
    unsigned char red, green, blue;
};

class CheckSum : public sink
{
public:
    const char *SinkName() { return "CheckSum"; };
    void OutputCheckSum(const char *filename);
};


#endif




