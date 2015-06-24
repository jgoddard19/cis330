#include <stdio.h>
#include <math.h>

struct Triangle;
struct Circle;
struct Rectangle;
struct Shape;
struct FunctionTable;
union  ShapeUnion;
enum   ShapeType;

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

typedef union
{
	Triangle t;
	Circle c;
	Rectangle r;
}ShapeUnion;

typedef enum
{
	Tr,
	Ci,
	Re
}ShapeType;

typedef struct
{
	double(*GetArea)(struct Shape *);
	void(*GetBoundingBox)(struct Shape *, double *);
}FunctionTable;

struct Shape
{
	ShapeUnion sUnion;
	ShapeType type;
	FunctionTable ft;
};

double GetTriangleArea(struct Shape *t)
{
	double area = ((t->sUnion.t.pt2X-t->sUnion.t.pt1X)*(t->sUnion.t.maxY-t->sUnion.t.minY))/2;
	return area;
}
double GetCircleArea(struct Shape *c)
{
	double area = (3.14159*c->sUnion.c.radius*c->sUnion.c.radius);
	return area;
}
double GetRectangleArea(struct Shape *r)
{
	double area = (r->sUnion.r.maxX-r->sUnion.r.minX)*(r->sUnion.r.maxY-r->sUnion.r.minY);
	return area;
}

void GetTriangleBoundingBox(struct Shape *t, double *bbox)
{
	bbox[0]=t->sUnion.t.pt1X;
	bbox[1]=t->sUnion.t.pt2X;
	bbox[2]=t->sUnion.t.minY;
	bbox[3]=t->sUnion.t.maxY;	
}
void GetCircleBoundingBox(struct Shape *c, double *bbox)
{
	bbox[0]=(c->sUnion.c.origin-c->sUnion.c.radius);
	bbox[1]=(c->sUnion.c.origin+c->sUnion.c.radius);
	bbox[2]=(c->sUnion.c.originY-c->sUnion.c.radius);
	bbox[3]=(c->sUnion.c.originY+c->sUnion.c.radius);
}
void GetRectangleBoundingBox(struct Shape *r, double *bbox)
{
	bbox[0]=r->sUnion.r.minX;
	bbox[1]=r->sUnion.r.maxX;
	bbox[2]=r->sUnion.r.minY;
	bbox[3]=r->sUnion.r.maxY;
}

void InitializeTriangle(struct Shape *t, double pt1X, double pt2X, double minY, double maxY)
{
	t->type = Tr;
	t->ft.GetArea = GetTriangleArea;
	t->ft.GetBoundingBox = GetTriangleBoundingBox;
	t->sUnion.t.pt1X=pt1X;
	t->sUnion.t.pt2X=pt2X;
	t->sUnion.t.minY=minY;
	t->sUnion.t.maxY=maxY;
}
void InitializeCircle(struct Shape *c, double radius, double origin, double originY)
{
	c->type = Ci;
	c->ft.GetArea = GetCircleArea;
	c->ft.GetBoundingBox = GetCircleBoundingBox;
	c->sUnion.c.radius=radius;
	c->sUnion.c.origin=origin;
	c->sUnion.c.originY=originY;
}
void InitializeRectangle(struct Shape *r, double minX, double maxX, double minY, double maxY)
{
	r->type = Re;
	r->ft.GetArea = GetRectangleArea;
	r->ft.GetBoundingBox = GetRectangleBoundingBox;
	r->sUnion.r.minX=minX;
	r->sUnion.r.maxX=maxX;
	r->sUnion.r.minY=minY;
	r->sUnion.r.maxY=maxY;
}
