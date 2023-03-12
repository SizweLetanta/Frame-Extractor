#include "frame_sequence.h"
#define FMOD LTNSIZ001::FrameSequence

FMOD::FrameSequence(void): size{0,0}{}

u_char** FMOD::operator[](int frameNo){
    return imageSequence[frameNo];
}

FMOD& FMOD::operator+=(u_char** frame){
    imageSequence.push_back(frame);
    return *this;
}

void FMOD::set_size(dimension& size){
    this->size = size;
}

FMOD::~FrameSequence(){
    for (size_t i = 0; i < imageSequence.size(); i++)
    {
        for (size_t j = 0; j < size.width; j++)
        {
            delete[] imageSequence[i][j];
        }
        delete[] imageSequence[i];
    }
}