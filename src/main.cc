#include "global.hh"

#include "food/food.hh"
#include "snake/snake.hh"


int main() {
    // Initialization
    InitWindow(SC_WIDTH, SC_HEIGHT, TITLE);
    SetWindowState(FLAG_VSYNC_HINT);

    // Game initialization
    Food food{3, 5, FOOD_COLOR};
    Snake snake{
        { {9, 7}, {9, 8}, {9, 9}, {10, 9} },
        SNAKE_COLOR, DIR_UP
    };

    // Game loop
    while (!WindowShouldClose()) {
        // Updating
        snake.update();

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
