#include "helpers.h"
#include <sstream>

#define POS LTNSIZ001::position


LTNSIZ001::dims LTNSIZ001::get_dimensions(std::ifstream* infile) {
	std::string y;

	char *p5 = new char[4], *c2 = (char*)malloc(1);
	infile->read(p5, 3);

	int width, height;

	while (infile) {
		if (*c2 == '\n' && y[0] != '#') {
			std::stringstream ss(y);
			ss >> height >> width;
			infile->read(p5, 4);
			y = "";
			break;

		} else if (*c2 == '\n') {
			y = "";
		}
		infile->read(c2, 1);
		y += *c2;
	}
    delete c2; delete[] p5; // free the memory
    dims dimensions{width, height};
    return dimensions;
}


