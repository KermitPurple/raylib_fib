#include"raylib.h"
#include<Fib.h>
#include<math.h>

/*************
*  private  *
*************/

void Fib::update_starting_size(){
    //increase the starting size but reset it back 
    starting_size *= STARTING_SIZE_SPEED;
    if(starting_size >= STARTING_SIZE_ROLLOVER)
        starting_size = STARTING_SIZE;
}

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
    float prev_size = 0;
    float size = starting_size;
    const int CURVE_POINTS_SIZE = 3; // number of points in curve
    Vector2 curve_points[CURVE_POINTS_SIZE]; // store points for drawing curve
    for(int i = 0; i < 100; i++){ // TODO Make this more effiecient by adding bounds checking
        float next_size = prev_size + size;
        DrawRectangleLines(pos.x, pos.y, size, size, WHITE);
        switch(i % 4){
            case 0:
                curve_points[0] = Vector2{pos.x, pos.y + size};
                curve_points[1] = Vector2{pos.x + size, pos.y};
                curve_points[2] = pos;
                pos.x += size;
                break;
            case 1:
                curve_points[0] = pos;
                curve_points[1] = Vector2{pos.x + size, pos.y + size};
                curve_points[2] = Vector2{pos.x + size, pos.y};
                pos.x -= prev_size;
                pos.y += size;
                break;
            case 2:
                curve_points[0] = Vector2{pos.x + size, pos.y};
                curve_points[1] = Vector2{pos.x, pos.y + size};
                curve_points[2] = Vector2{pos.x + size, pos.y + size};
                pos.x -= next_size;
                pos.y -= prev_size;
                break;
            case 3:
                curve_points[0] = pos;
                curve_points[1] = Vector2{pos.x + size, pos.y + size};
                curve_points[2] = Vector2{pos.x, pos.y + size};
                pos.y -= next_size;
                break;
        }
        DrawLineBezierQuad(
                vec_floor(curve_points[0]),
                vec_floor(curve_points[1]),
                vec_floor(curve_points[2]),
                1,
                WHITE
                );
        prev_size = size;
        size = next_size;
    }
}

Vector2 Fib::vec_floor(Vector2 vec){
    return Vector2{
        floor(vec.x),
        floor(vec.y),
    };
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
            set_window_size(); // set the window_size variable to the current size
        update_starting_size(); // increase starting_size
        BeginDrawing(); // start the raylib drawing process
        ClearBackground(BLACK); // clear the screen
        draw_spiral(); // draw the main spiral
        EndDrawing(); // finish the raylib drawing process
    }
}
