#include "global.hh"

#include "food/food.hh"
#include "snake/snake.hh"


bool canExitGame(Snake snake);
bool canEat(Snake snake, Food food);
void respawnFood(Snake snake, Food food);

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

        // Checks if can exit game
        if (canExitGame(snake))
            break;

        // Checks if snake can eat food
        if (canEat(snake, food)) {
            snake.addBodySegment();
            respawnFood(snake, food);
        }
        
        // Fixed updating
        if (fixedUpdateTimer >= FIXED_UPDATE_INTERVAL) {
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


bool canExitGame(Snake snake) {
    return snake.checkCollisionWalls() || snake.isInBody(snake.getHeadPosition(), 1);
}
bool canEat(Snake snake, Food food) {
    return snake.isInBody(food.getPosition());
}
void respawnFood(Snake snake, Food food) {
    while (snake.isInBody(food.getPosition()) && snake.getSize() < TILE_AREA)
        food.reset();
}
