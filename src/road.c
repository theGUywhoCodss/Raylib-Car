#include "road.h"
#include "defines.h"
#include <stdio.h>
#include <math.h>

Corner _Road[] = {
    {10,0},
    {6,-1},
    {8,0},
    {4,1.5},
    {10,0.2},
    {4,0},
    {5,-1}
};
int _roadSize = 7; //VERY IMPORTANT

static int CurrentCorner = 0;
static int CurrentSegment = 1;

static double cameraX = 0, cameraY = 0, cameraZ = 0; // Camera position.
static double cameraAngle = 0; // Angle smoothing.

static double x = 0, y = 0, z = 0; // Road cursor starting position.

static void ProjectCorner(double *px, double *py, double *pz){
    int multiplier=8;
    double scale = multiplier / z;
    *px = x * scale * multiplier;
    *py = y * scale * multiplier;
    *pz = scale;
}

static void AdvanceCorner(int *pntrCorner, int *pntrSegment){
    *pntrSegment += 1;
    if (*pntrSegment > _Road[*pntrCorner].segments){
        *pntrSegment = 1;
        *pntrCorner += 1;

        if(*pntrCorner > _roadSize) *pntrCorner = 0;
    }
}

static void skew(double dx, double dy){
    double newX = cameraX+cameraZ*dx;
    double newY = cameraY+cameraZ*dy;
    x = -newX;
    y = -newY+2;
    z = -cameraZ+2;
}

static void DrawTrapezium(double x1, double y1, double w1, double x2, double y2, double w2, double col){
    double height = y2 - y1;
    float xd = (x2 - x1) / height, wd = (w2 - w1) / height;
    double localX = x1, localY = y1, localW = w1;

    double yadj = ceil(localY) - localY;
    localX += yadj * xd;
    localY += yadj;
    localW += yadj * wd;

    while (localY < y2)
    {
        DrawLine(localX - localW + ROAD_OFFSET_WIDTH, localY + ROAD_OFFSET_HEIGHT, 
        localX + localW + ROAD_OFFSET_WIDTH, localY + ROAD_OFFSET_HEIGHT, RED);
        localX += xd;
        localY += 1;
        localW += wd;
    }
} 

static void DrawConcrete(double x1, double y1, double scale1, double x2, double y2, double scale2, double sumct){
    if (floor(y2) < ceil(y1)) return;
    double w1 = ROAD_SEGMENT_WIDTH * scale1, w2 = ROAD_SEGMENT_WIDTH * scale2;
    DrawTrapezium(x1, y1, w1, x2, y2, w2, 5);
}
   
void DrawRoad(void){
    cameraAngle = cameraZ * _Road[CurrentCorner].direction;

    double dx=-cameraAngle, dy=0, dz=1;
    skew(dx, dy);

    double px=0, py=0, pz=0;
    double ppx=0, ppy=0, ppz=0;
    ProjectCorner(&ppx, &ppy, &ppz);

    int localCorner = CurrentCorner;
    int localSegment = CurrentSegment;
    
    for(int i = 0; i < CORNER_VIEW_DISTENCE; i++){
        ProjectCorner(&px, &py, &pz);

        double width = ROAD_SEGMENT_WIDTH * pz;
        DrawLine(px - width + ROAD_OFFSET_WIDTH, py + ROAD_OFFSET_HEIGHT, px + width + ROAD_OFFSET_WIDTH, 
        py + ROAD_OFFSET_HEIGHT, RAYWHITE);

        x += dx;
        y += dy;//dsadsadasd
        z += dz;

        DrawConcrete(px, py, pz, ppx, ppy, ppz,5);

        dx += _Road[localCorner].direction;

        AdvanceCorner(&localCorner, &localSegment);
        ppx=px;
        ppy=py;
        ppz=pz;
    }

    cameraZ += ROAD_CAMERA_SMOOTHING * GetFrameTime();

    if (cameraZ > 1){
        cameraZ = 0;
        AdvanceCorner(&CurrentCorner, &CurrentSegment);
    }
}
