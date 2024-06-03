#pragma once
#include <raylib.h>
#include <raymath.h>

#include "fileIO/settingsData.hh"
#include "types.hh"


SettingsData getSettings() {
    SettingsData settings;

    // Application
    settings.title = "Snake Game";
    settings.tileSize = 32;
    settings.tileCountX = 32;
    settings.tileCountY = 16;
    settings.screenWidth = settings.tileSize * settings.tileCountX;
    settings.screenHeight = settings.tileSize * settings.tileCountY;
    settings.tileArea = settings.tileCountX * settings.tileCountY;


    // Gameplay
    settings.directionNONE = Vector2{0, 0};
    settings.directionUP = Vector2{0, -1};
    settings.directionDOWN = Vector2{0, 1};
    settings.directionLEFT = Vector2{-1, 0};
    settings.directionRIGHT = Vector2{1, 0};


    // System
    settings.fixedUpdateInterval = 5.0 / 32.0;
    settings.fixedDeltaTime = 1.0 / settings.fixedUpdateInterval;


    // FileIO
    settings.appPath = GetApplicationDirectory();
    settings.settingsPath = TextFormat("%s%s", settings.appPath, "settings.ses");


    // Colors
    settings.snakeColor = Color{64, 224, 64, 255};
    settings.foodColor = Color{224, 224, 64, 255};
    settings.backgroundColor = Color{32, 32, 64};
}


const static SettingsData settings = getSettings();

/*
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
#define FIXED_UPDATE_INTERVAL 5.0 / 32.0
#define FIXED_DELTA_TIME 1.0 / FIXED_UPDATE_INTERVAL


// FileIO
#define APP_PATH GetApplicationDirectory()
#define SETTINGS_PATH TextFormat("%s%s", APP_PATH, "settings.ses")


// Colors
#define SNAKE_COLOR Color{64, 224, 64, 255}
#define FOOD_COLOR Color{224, 224, 64, 255}
#define BG_COLOR Color{32, 32, 64}
*/
