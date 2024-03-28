#ifndef PLAYER_H_
#define PLAYER_H_

#include "raylib.h"

typedef enum Direction{
    LEFT,
    RIGHT
} Direction;

Vector2 GetPlayerPosition();
void MovePlayer(Direction input);
void DrawPlayer(void);
void UpdatePlayer(void);

#endif