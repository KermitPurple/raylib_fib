#include"DrawType.h"

void DrawType::set_lines(bool b){
    lines = b;
}

void DrawType::set_curves(bool b){
    b = curves;
}

void DrawType::toggle_lines(){
    lines = !lines;
}

void DrawType::toggle_curves(){
    curves = !curves;
}

bool DrawType::get_lines(){
    return lines;
}

bool DrawType::get_curves(){
    return curves;
}
