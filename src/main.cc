#include "global.hh"


int main() {
    // Initialization
    InitWindow(SC_WIDTH, SC_HEIGHT, TITLE);
    SetWindowState(FLAG_VSYNC_HINT);

    // Game initialization


    // Game loop
    while (!WindowShouldClose()) {
        // Updating


        // Drawing
        BeginDrawing();

        ClearBackground(BG_COLOR);
        
        EndDrawing();

    }

    // Deinitialization
    CloseWindow();

    return EXIT_SUCCESS;

}
