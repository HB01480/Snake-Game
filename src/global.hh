#pragma once
#include <raylib.h>
#include <raymath.h>

#include <cstdbool>
#include <cstdint>
#include <deque>


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


// Type definition
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float_t f32;
typedef double_t f64;

typedef const char *c_string;
