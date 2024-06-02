#include "global.hh"

#include "food/food.hh"
#include "snake/snake.hh"


bool canExitGame(Snake snake) {
    return snake.checkCollisionWalls() || snake.isInBody(snake.getHeadPosition(), 1);
}
bool canEat(Snake snake, Food food) {
    return snake.isInBody(food.getPosition());
}

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
        snake.input();
        // Checks if can exit
        if (canExitGame(snake))
            break;

        if (canEat(snake, food)) {
            snake.addBodySegment();

            while (snake.isInBody(food.getPosition()) && snake.getSize() < TILE_AREA)
                food.reset();
        }

        if (fixedUpdateTimer >= FIXED_UPDATE_INTERVAL) {
            // Fixed updating
            snake.fixedMove();

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
