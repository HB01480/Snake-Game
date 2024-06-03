#include <raylib.h>
#include <raymath.h>

#include "settings.hh"
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

    return settings;
}
