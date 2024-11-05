#include <stdio.h>
#include <math.h>
typedef struct point{
    int x;
    int y;
} POINT;

typedef struct{
    POINT center;       //원의 중심
    double radius;      //반지름
}CIRCLE;
typedef struct rect{
    POINT lb;           //left bottom
    POINT rt;           //right top 
}RECT;

double dist(POINT p1, struct point p2){
    return sqrt(pow((p2.x - p1.x),2)+pow((p2.y - p1.y),2));
}
   
