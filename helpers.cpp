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
	delete c2;
	delete[] p5;  // free the memory
	dims dimensions{width, height};
	return dimensions;
}

std::vector<POS> LTNSIZ001::get_coordinates(POS start, POS end) {
	std::vector<POS> coordinates;
	double m;
	if (start.x == end.x) {
		for (int y = start.y; y <= end.y; (start.y < end.y ? ++y : --y)) {
			coordinates.push_back(POS{start.x, y});
		}

	} else {
		m = (double(start.y - end.y)) / (double(start.x - end.x));

		if (m >= 1) {
			for (int y = start.y; y <= end.y; (start.y < end.y ? ++y : --y)) {
				coordinates.push_back(POS{int (start.x+(y-start.y)/m), y});
			}
		} else
        {   
			for (int x = start.x; x <= end.x; (start.x < end.x ? ++x : --x)) {
				coordinates.push_back(POS{int (m*(x-start.x)+start.y), x});
			}
        }
	}

    return coordinates;
}
