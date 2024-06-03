#pragma once
#include "../types.hh"


typedef struct SettingsData {
    // Application
    c_string title;
    i32 tileSize;
    i32 tileCountX;
    i32 tileCountY;
    i32 screenWidth;
    i32 screenHeight;
    i32 tileArea;


    // Gameplay
    Vector2 directionNONE;
    Vector2 directionUP;
    Vector2 directionDOWN;
    Vector2 directionLEFT;
    Vector2 directionRIGHT;


    // System
    f32 fixedUpdateInterval;
    f32 fixedDeltaTime;


    // FileIO
    c_string appPath;
    c_string settingsPath;


    // Colors
    Color snakeColor;
    Color foodColor;
    Color backgroundColor;

} SettingsData;
