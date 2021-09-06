#ifndef DRAWTYPE_H
#define DRAWTYPE_H

class DrawType{
private:
    bool lines = true;
    bool curves = true;
public:
    void set_lines(bool b);
    void set_curves(bool b);
    void toggle_lines();
    void toggle_curves();
    bool get_lines();
    bool get_curves();
};

#endif // DRAWTYPE_H
