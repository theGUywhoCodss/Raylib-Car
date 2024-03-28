#include "player.h"
#include "defines.h"

float _playerXPosition=SCREEN_WIDTH/2;
extern Texture2D _atlasPlayer;

Vector2 GetPlayerPosition(void){
    return (Vector2){_playerXPosition, SCREEN_HEIGHT - PLAYER_SOURCE_HEIGHT * PLAYER_SOURCE_MULIPLIER * 2};
}

void MovePlayer(Direction input){
    if (input == LEFT){
        _playerXPosition -= PLAYER_SPEED * GetFrameTime();
    }else if (input == RIGHT){
        _playerXPosition += PLAYER_SPEED * GetFrameTime();
    }
}

void UpdatePlayer(void){

}

void DrawPlayer(void){
	Vector2 position = GetPlayerPosition();

	position.x -= PLAYER_SOURCE_MULIPLIER * PLAYER_SOURCE_WIDTH/ 2;
	position.y -= PLAYER_SOURCE_MULIPLIER * PLAYER_SOURCE_HEIGHT / 2;
    
    DrawText(TextFormat( "%d : %d" , _atlasPlayer.width * PLAYER_SOURCE_MULIPLIER,
    _atlasPlayer.height * PLAYER_SOURCE_MULIPLIER), 0, 50, 20, RED);
    DrawTextureEx( _atlasPlayer,position, 0, 4, RAYWHITE);
}