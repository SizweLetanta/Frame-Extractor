#include "frame_sequence.h"
#include "image.h"
#include "helpers.h"
#include <iostream>

int main(int argc, char const *argv[])
{

    LTNSIZ001::parameters params = LTNSIZ001::get_parameters(argv, argc);
    std::cout << params.size.width << " " << params.size.height << "\n";
    // LTNSIZ001::parameters args = LTNSIZ001::get_parameters(argv, argc);
    std::ifstream image_file(params.in_file, std::ios::binary);

    LTNSIZ001::dimension dimensions = LTNSIZ001::get_dimensions(&image_file);

    LTNSIZ001::Image main_image(dimensions);
    main_image.load_image(&image_file);
    
    std::vector<LTNSIZ001::position> path = LTNSIZ001::get_coordinates(params.origin, params.destination);

    LTNSIZ001::FrameSequence frames;
    frames.set_size(params.size);

    for (LTNSIZ001::position &i : path)
    {
        frames += main_image.get_frame(i, params.size);
    }


    std::string file_n = params.opts[0].out_file;
    int l = file_n.length();

    char *outbuff = new char[l+10];
    for (int i = 0; i < path.size(); i++)
    {
        std::snprintf(outbuff, l+10, "%s-%04d.pgm",params.opts[0].out_file, i);
        LTNSIZ001::write_image(outbuff, frames[i], params.size);
    }
    


    return 0;
}

