#pragma once


// Application
#define TITLE "Snake Game"
#define TILE_SIZE 32
#define TILE_COUNT_X 32
#define TILE_COUNT_Y 16
#define SC_WIDTH TILE_SIZE * TILE_COUNT_X
#define SC_HEIGHT TILE_SIZE * TILE_COUNT_Y
#define TILE_AREA TILE_COUNT_X * TILE_COUNT_Y


// Gameplay
#define DIR_NONE Vector2{0, 0}
#define DIR_UP Vector2{0, -1}
#define DIR_DOWN Vector2{0, 1}
#define DIR_LEFT Vector2{-1, 0}
#define DIR_RIGHT Vector2{1, 0}


// System
#define dt GetFrameTime()
#define FIXED_UPDATE_INTERVAL 5.0 / 32.0
#define FIXED_DELTA_TIME 1.0 / FIXED_UPDATE_INTERVAL


// FileIO
#define APP_PATH GetApplicationDirectory()
#define SETTINGS_PATH TextFormat("%s%s", APP_PATH, "settings.ses")


// Colors
#define SNAKE_COLOR Color{64, 224, 64, 255}
#define FOOD_COLOR Color{224, 224, 64, 255}
#define BG_COLOR Color{32, 32, 64}
