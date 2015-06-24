#include <stdio.h>
#include <math.h>

struct Triangle;
struct Circle;
struct Rectangle;

typedef struct
{
	double pt1X, pt2X, minY, maxY;
}Triangle;
typedef struct
{
	double radius, origin, originY;
}Circle;
typedef struct
{
	double minX, maxX, minY, maxY;
}Rectangle;

void InitializeTriangle(Triangle *t, double pt1X, double pt2X, double minY, double maxY)
{
	t->pt1X=pt1X;
	t->pt2X=pt2X;
	t->minY=minY;
	t->maxY=maxY;
}
void InitializeCircle(Circle *c, double radius, double origin, double originY)
{
	c->radius=radius;
	c->origin=origin;
	c->originY=originY;
}
void InitializeRectangle(Rectangle *r, double minX, double maxX, double minY, double maxY)
{
	r->minX=minX;
	r->maxX=maxX;
	r->minY=minY;
	r->maxY=maxY;
}

double GetTriangleArea(Triangle *t)
{
	return ((t->pt2X-t->pt1X)*(t->maxY-t->minY))/2;
}
double GetCircleArea(Circle *c)
{
	return (3.14159*c->radius*c->radius);
}
double GetRectangleArea(Rectangle *r)
{
	return (r->maxX-r->minX)*(r->maxY-r->minY);
}

void GetTriangleBoundingBox(Triangle *t, double *bbox)
{
	bbox[0]=t->pt1X;
	bbox[1]=t->pt2X;
	bbox[2]=t->minY;
	bbox[3]=t->maxY;	
}
void GetCircleBoundingBox(Circle *c, double *bbox)
{
	bbox[0]=(c->origin-c->radius);
	bbox[1]=(c->origin+c->radius);
	bbox[2]=(c->originY-c->radius);
	bbox[3]=(c->originY+c->radius);
}
void GetRectangleBoundingBox(Rectangle *r, double *bbox)
{
	bbox[0]=r->minX;
	bbox[1]=r->maxX;
	bbox[2]=r->minY;
	bbox[3]=r->maxY;
}
