#include "fmodule.h"
#define FMOD LTNSIZ001::FModule

u_char** FMOD::operator[](int frameNo){
    return imageSequence[frameNo];
}

FMOD::FModule(){}

FMOD::~FModule(){
    for (size_t i = 0; i < imageSequence.size(); i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            delete[] imageSequence[i][j];
        }
        
    }
    
}