#include "frame_module.h"
#define FMOD LTNSIZ001::FrameSequence

FMOD::FrameSequence(void): width(0), height(0){}

u_char** FMOD::operator[](int frameNo){
    return imageSequence[frameNo];
}

FMOD FMOD::operator+=(u_char** frame){
    imageSequence.push_back(frame);
    return *this;
}

void FMOD::set_size(int width, int height){
    this->width = width;
    this->height = height;
}

FMOD::~FrameSequence(){
    for (size_t i = 0; i < imageSequence.size(); i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            delete[] imageSequence[i][j];
        }
        delete[] imageSequence[i];
    }
}