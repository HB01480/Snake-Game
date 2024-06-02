#include "global.hh"

#include "food/food.hh"


int main() {
    // Initialization
    InitWindow(SC_WIDTH, SC_HEIGHT, TITLE);
    SetWindowState(FLAG_VSYNC_HINT);

    // Game initialization
    Food food{3, 5, FOOD_COLOR};

    // Game loop
    while (!WindowShouldClose()) {
        // Updating


        // Drawing
        BeginDrawing();

        ClearBackground(BG_COLOR);
        food.draw();

        EndDrawing();

    }

    // Deinitialization
    CloseWindow();

    return EXIT_SUCCESS;

}
