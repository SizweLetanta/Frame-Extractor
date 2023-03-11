#include "image.h"
#define IMG LTNSIZ001::Image

IMG::Image(int width, int height)
    : width(width), height(height), pixels(nullptr){}

u_char* IMG::operator[](int y){
    return pixels+(y*width);
}

int IMG::get_height(){ return height;}

int IMG::get_width(){ return width;}

IMG::~Image(){
    delete[] pixels;
}

