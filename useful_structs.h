#ifndef USEFUL_STRUCTS_H_
#define USEFUL_STRUCTS_H_

#include <vector>
#include <string>

namespace LTNSIZ001
{
    struct position{
        int x, y;
    };

    struct dimension{
        int width, height;
    };

    struct options{
        const char *opt, *out_file;
    };

    struct parameters{
        const char* in_file;
        position origin, destination;
        dimension size;
        std::vector<options> opts;
    };

} // namespace LTNSIZ001

#endif