#include "global.hh"

#include "food/food.hh"
#include "snake/snake.hh"
#include "fileIO/fileIO.hh"


bool canExitGame(Snake snake) {
    return snake.checkCollisionWalls() || snake.isInBody(snake.getHeadPosition(), 1);
}
bool canEat(Snake snake, Food food) {
    return snake.isInBody(food.getPosition());
}

i32 main() {
    // Initialization
    SetTraceLogLevel(LOG_DEBUG); // To get DEBUG and higher leveled logs
    #ifdef SG_RELEASE
    SetTraceLogLevel(LOG_ERROR); // To get rid of INFO
    #endif
    InitWindow(settings.screenWidth, settings.screenHeight, settings.title);
    SetWindowState(FLAG_VSYNC_HINT);
    f32 fixedUpdateTimer = 0;
    u32 score = 0;

    // Game initialization
    Food food{3, 5, settings.foodColor};
    Snake snake{
        { {9, 7}, {9, 8}, {9, 9}, {10, 9} },
        settings.snakeColor, settings.directionUP
    };

    i32 initialSnakeSize = snake.getSize();
    // Game loop
    while (!WindowShouldClose()) {
        // Updating
        fixedUpdateTimer += GetFrameTime();
        score = snake.getSize() - initialSnakeSize;
        snake.input();

        // Checks if can exit
        if (canExitGame(snake))
            break;

        // Checks if snake can eat food
        if (canEat(snake, food)) {
            snake.addBodySegment();
    
            // Make sure that food doesn't spawn on snake
            while (snake.isInBody(food.getPosition()) && snake.getSize() < settings.tileArea)
                food.reset();
        }
        #ifdef SG_DEBUG
        if (IsKeyDown(KEY_LEFT_SHIFT)) {
            TraceLog(LOG_DEBUG, "Food: %.0f %.0f", food.getPosition().x, food.getPosition().y);
            TraceLog(LOG_DEBUG, "Snake head position: %.0f %.0f", snake.getHeadPosition().x, snake.getHeadPosition().y);
            TraceLog(LOG_DEBUG, "Snake length: %i", snake.getSize());
        }
        #endif

        // Fixed updating
        if (fixedUpdateTimer >= settings.fixedUpdateInterval) {
            snake.fixedMove();

            fixedUpdateTimer = 0;
        }


        // Drawing
        BeginDrawing();

        ClearBackground(settings.backgroundColor);
        DrawText(
            TextFormat("%i", score), 
            settings.screenWidth * 1/2 - MeasureText(TextFormat("%i", score), 48) * 1/2,
            settings.screenHeight * 1/16 - 24,
            48, RAYWHITE
        );

        food.draw();
        snake.draw();

        EndDrawing();

    }

    // Deinitialization
    CloseWindow();

    return EXIT_SUCCESS;

}
