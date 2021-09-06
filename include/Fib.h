#ifndef FIB_H
#define FIB_H

#include<raylib.h>

class Fib{
private:
    static constexpr Vector2 DEFAULT_WINDOW_SIZE{1440, 760};
    static constexpr Vector2 MINIMUM_WINDOW_SIZE{720, 380};
    static constexpr float STARTING_SIZE = 0.01;
    static constexpr float STARTING_SIZE_ROLLOVER = 3.3229712;
    static constexpr float STARTING_SIZE_SPEED = 1.01;
    Vector2 window_size;
    Vector2 center;
    int fps = 30;
    float starting_size = STARTING_SIZE;
    void update_starting_size();
    void set_window_size();
    void set_window_size(int x, int y);
    void set_window_size(float x, float y);
    void set_window_size(Vector2 size);
    void draw_spiral();
    Vector2 vec_floor(Vector2 vec);
public:
    Fib(); // default construtor
    void run(); // run the program
};

#endif // FIB_H
