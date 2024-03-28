#ifndef ROAD_H_
#define ROAD_H_

#include "raylib.h"

typedef struct Corner
{
    int segments;
    double direction; // Negative goes left. Positive goes right.
}Corner;

void DrawRoad(void);

#endif