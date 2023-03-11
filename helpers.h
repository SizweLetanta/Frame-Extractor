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

} // namespace LTNSIZ001


#endif