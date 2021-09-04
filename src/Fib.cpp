#include "raylib.h"
#include<Fib.h>

/*************
*  private  *
*************/
void Fib::set_window_size(){
    set_window_size(GetScreenWidth(), GetScreenHeight());
}

void Fib::set_window_size(int x, int y){
    set_window_size(
        static_cast<float>(x),
        static_cast<float>(y)
    );
}

void Fib::set_window_size(float x, float y){
    set_window_size(Vector2{x, y});
}

void Fib::set_window_size(Vector2 size){
    window_size = size;
    center = Vector2{size.x / 2, size.y / 2};
}

/************
*  public  *
************/
Fib::Fib(){
    set_window_size(DEFAULT_WINDOW_SIZE);
}

void Fib::run(){
    // SetTraceLogLevel(LOG_NONE); // no output to console
    SetConfigFlags(FLAG_WINDOW_RESIZABLE); // resizable window
    InitWindow(DEFAULT_WINDOW_SIZE.x, DEFAULT_WINDOW_SIZE.y, "Fibonacci Spiral"); // create window
    SetWindowMinSize(MINIMUM_WINDOW_SIZE.x, MINIMUM_WINDOW_SIZE.y); // set minimum size
    SetWindowPosition(0, 0); // put window in top left corner
    SetTargetFPS(fps); // set the target fps
    while(!WindowShouldClose()){
        if(IsWindowResized()) // if the size of the window changed
            set_window_size(),
        BeginDrawing(); // start the raylib drawing process
        ClearBackground(BLACK); // clear the screen
        EndDrawing(); // finish the raylib drawing process
    }
}
