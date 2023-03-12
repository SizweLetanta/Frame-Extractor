#ifndef HELPER_H_
#define HELPER_H_

#include <fstream>
#include "image.h"
#include "frame_sequence.h"

namespace LTNSIZ001
{
    struct position{
        int x, y;
    };

    struct dims{
        int width, height;
    };

    dims get_dimensions(std::ifstream* infile);

    std::vector<position> get_coordinates(position start, position end);

    void write_image(std::string file_name, u_char** pixels, dims dimensions);
} // namespace LTNSIZ001


#endif