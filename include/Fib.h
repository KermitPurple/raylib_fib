#ifndef FIB_H
#define FIB_H

#include<raylib.h>

class Fib{
private:
    static constexpr Vector2 DEFAULT_WINDOW_SIZE{1440, 760};
    static constexpr Vector2 MINIMUM_WINDOW_SIZE{720, 380};
    Vector2 window_size;
    Vector2 center;
    int fps = 30;
    void set_window_size();
    void set_window_size(int x, int y);
    void set_window_size(float x, float y);
    void set_window_size(Vector2 size);
public:
    Fib(); // default construtor
    void run(); // run the program
};

#endif // FIB_H
