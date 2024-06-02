#include "global.hh"

#include "food/food.hh"
#include "snake/snake.hh"


i32 main() {
    // Initialization
    InitWindow(SC_WIDTH, SC_HEIGHT, TITLE);
    SetWindowState(FLAG_VSYNC_HINT);
    f32 fixedUpdateTimer = 0;

    // Game initialization
    Food food{3, 5, FOOD_COLOR};
    Snake snake{
        { {9, 7}, {9, 8}, {9, 9}, {10, 9} },
        SNAKE_COLOR, DIR_UP
    };

    // Game loop
    while (!WindowShouldClose()) {
        // Updating
        fixedUpdateTimer += dt;
        snake.update();
        if (snake.isInBody(food.getPosition())) {
            snake.addBodySegment();
            food.reset();
            while (snake.isInBody(food.getPosition()) && snake.getSize() < TILE_AREA)
                food.reset();
        }


        if (fixedUpdateTimer >= FIXED_UPDATE_INTERVAL) {
            // Fixed updating
            snake.fixedUpdate();

            fixedUpdateTimer = 0;
        }


        // Drawing
        BeginDrawing();

        ClearBackground(BG_COLOR);
        food.draw();
        snake.draw();

        EndDrawing();

    }

    // Deinitialization
    CloseWindow();

    return EXIT_SUCCESS;

}
