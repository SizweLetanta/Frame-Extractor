#ifndef HELPER_H_
#define HELPER_H_

#include <fstream>
#include "image.h"
#include "frame_sequence.h"
#include "useful_structs.h"

namespace LTNSIZ001
{
    parameters get_parameters(const char* args[], int argc);

    dimension get_dimensions(std::ifstream* infile);

    std::vector<position> get_coordinates(position start, position end);

    int find(const char** arr,int size, std::string elem);

    void write_image(std::string file_name, u_char** pixels, dimension dimensions);
} // namespace LTNSIZ001


#endif