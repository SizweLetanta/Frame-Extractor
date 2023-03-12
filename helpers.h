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

    struct dimension{
        int width, height;
    };

    struct options{
        std::string opt, file_name;
    };

    struct parameters{
        position origin, destination;
        dimension size;
        std::vector<options> opts;
    };

    dimension get_dimensions(std::ifstream* infile);

    std::vector<position> get_coordinates(position start, position end);

    void write_image(std::string file_name, u_char** pixels, dimension dimensions);
} // namespace LTNSIZ001


#endif