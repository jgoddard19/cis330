 struct Triangle;
 struct Circle;
 struct Rectangle;
 
 void InitializeCircle(struct Circle *c, double radius, double origin, double originY);
 void InitializeRectangle(struct Rectangle *r, double minX, double maxX, double minY, double maxY);
 void InitializeTriangle(struct Triangle *t, double pt1X, double pt2X, double minY, double maxY);
 
 double GetCircleArea(struct Circle *c);
 double GetRectangleArea(struct Rectangle *r);
 double GetTriangleArea(struct Triangle *t);
 
 void GetCircleBoundingBox(struct Circle *c, double *bbox);
 void GetRectangleBoundingBox(struct Rectangle *r, double *bbox);
 void GetTriangleBoundingBox(struct Triangle *t, double *bbox);
