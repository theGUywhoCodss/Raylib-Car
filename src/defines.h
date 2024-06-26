#ifndef DEFINES_H_
#define DEFINES_H_

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
#define SCREEN_SIZE CLITERAL(Vector2){SCREEN_WIDTH, SCREEN_HEIGHT}

#define PLAYER_SPEED 150
#define PLAYER_SOURCE_WIDTH 26
#define PLAYER_SOURCE_HEIGHT 21
#define PLAYER_SOURCE_RECTANGLE CLITERAL(Rectangle){0,0,PLAYER_SOURCE_WIDTH,PLAYER_SOURCE_HEIGHT}
#define PLAYER_SOURCE_MULIPLIER 4

#define ROAD_SEGMENT_WIDTH 30
#define CORNER_VIEW_DISTENCE 30
#define ROAD_ADVANCE_TIME 0.1
#define ROAD_CAMERA_SMOOTHING 5
#define ROAD_OFFSET_WIDTH SCREEN_WIDTH/2
#define ROAD_OFFSET_HEIGHT SCREEN_HEIGHT/2

#endif