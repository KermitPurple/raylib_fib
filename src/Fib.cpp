#include "raylib.h"
#include<Fib.h>

/*************
*  private  *
*************/
void Fib::set_window_size(){
    // this sets the window size varaible,
    // does not change the actual size of the window
    set_window_size(GetScreenWidth(), GetScreenHeight());
}

void Fib::set_window_size(int x, int y){
    // this sets the window size varaible,
    // does not change the actual size of the window
    set_window_size(
        static_cast<float>(x),
        static_cast<float>(y)
    );
}

void Fib::set_window_size(float x, float y){
    // this sets the window size varaible,
    // does not change the actual size of the window
    set_window_size(Vector2{x, y});
}

void Fib::set_window_size(Vector2 size){
    // this sets the window size varaible,
    // does not change the actual size of the window
    window_size = size;
    center = Vector2{size.x / 2, size.y / 2};
}

void Fib::draw_spiral(){
    Vector2 pos = center; // start at the center of the screen
    int prev_size = 0;
    int size = STARTING_SIZE;
    for(int i = 0; i < 100; i++){ // TODO Make this more effiecient by adding bounds checking
        int next_size = prev_size + size;
        DrawRectangleLines(pos.x, pos.y, size, size, WHITE);
        switch(i % 4){
            case 0:
                DrawLineBezierQuad(
                        Vector2{pos.x, pos.y + size},
                        Vector2{pos.x + size, pos.y},
                        pos,
                        1,
                        WHITE
                        );
                pos.x += size;
                break;
            case 1:
                DrawLineBezierQuad(
                        pos,
                        Vector2{pos.x + size, pos.y + size},
                        Vector2{pos.x + size, pos.y},
                        1,
                        WHITE
                        );
                pos.x -= prev_size;
                pos.y += size;
                break;
            case 2:
                DrawLineBezierQuad(
                        Vector2{pos.x + size, pos.y},
                        Vector2{pos.x, pos.y + size},
                        Vector2{pos.x + size, pos.y + size},
                        1,
                        WHITE
                        );
                pos.x -= next_size;
                pos.y -= prev_size;
                break;
            case 3:
                DrawLineBezierQuad(
                        pos,
                        Vector2{pos.x + size, pos.y + size},
                        Vector2{pos.x, pos.y + size},
                        1,
                        WHITE
                        );
                pos.y -= next_size;
                break;
        }
        prev_size = size;
        size = next_size;
    }
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
        draw_spiral(); // draw the main spiral
        EndDrawing(); // finish the raylib drawing process
    }
}
