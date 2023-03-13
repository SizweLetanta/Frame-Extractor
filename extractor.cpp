#include <iostream>
#include <cstring>
#include "frame_sequence.h"
#include "helpers.h"
#include "image.h"

int main(int argc, char const* argv[]) {
	LTNSIZ001::parameters params = LTNSIZ001::get_parameters(argv, argc);
	std::cout << params.size.width << " " << params.size.height << "\n";
	// LTNSIZ001::parameters args = LTNSIZ001::get_parameters(argv, argc);
	std::ifstream image_file(params.in_file, std::ios::binary);

    if (!image_file)
    {
        std::cout << "Could not find the image" << "\n";
        return 1;
    }
    

	LTNSIZ001::dimension dimensions = LTNSIZ001::get_dimensions(&image_file);

	LTNSIZ001::Image main_image(dimensions);
	main_image.load_image(&image_file);

	std::vector<LTNSIZ001::position> path = LTNSIZ001::get_coordinates(params.origin, params.destination);
        std::cout << path.size() << "\n";

	LTNSIZ001::FrameSequence frames;
	frames.set_size(params.size);

	for (LTNSIZ001::options& opt : params.opts) {
		bool invert = std::strcmp(opt.opt, "invert") == 0 || std::strcmp(opt.opt,"revinvert") == 0;
		bool reverse = std::strcmp(opt.opt, "reverse") == 0 || std::strcmp(opt.opt,"revinvert") == 0;

        std::cout << invert << " " << reverse <<'\n';
		for (LTNSIZ001::position& pos : path) {
			frames += main_image.get_frame(pos, params.size, invert);
		}

		std::string file_n = opt.out_file;
		int l = file_n.length();

		char* outbuff = new char[l + 10];

		for (int i = 0; i < path.size(); i++) {
			std::snprintf(outbuff, l + 10, "%s%05d.pgm", opt.out_file, i);
			LTNSIZ001::write_image(outbuff, reverse ? frames[path.size()-i-1] : frames[i], params.size);
		}
        delete[] outbuff;
	}

	return 0;
}
