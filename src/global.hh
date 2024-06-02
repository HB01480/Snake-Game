#pragma once
#include <raylib.h>
#include <raymath.h>

#include <cstdbool>
#include <cstdint>
#include <deque>

// Application
#define TITLE "Snake Game"
#define TILE_SIZE 32
#define TILE_COUNT_X 24
#define TILE_COUNT_Y 16
#define SC_WIDTH TILE_SIZE * TILE_COUNT_X
#define SC_HEIGHT TILE_SIZE * TILE_COUNT_Y

// System
#define dt GetFrameTime()
#define FIXED_UPDATE_INTERVAL 1.0 / 4.0
#define FIXED_DELTA_TIME 1.0 / FIXED_UPDATE_INTERVAL

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
