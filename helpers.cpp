#include "helpers.h"
#include <fstream>
#include <sstream>
#include <iostream>
#define POS LTNSIZ001::position

LTNSIZ001::dims LTNSIZ001::get_dimensions(std::ifstream* infile) {
	std::string y;

	char *p5 = new char[4], *c2 = (char*)malloc(1);
	infile->read(p5, 3);

	int width, height;

	while (infile) {
		if (*c2 == '\n' && y[0] != '#') {
			std::stringstream ss(y);
			ss >> width >> height;
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


void LTNSIZ001::write_image(std::string file_name, u_char** pixels, LTNSIZ001::dims dimensions){
	std::ofstream image_file(file_name, std::ios::binary);
	std::string outs = ("P5\n# This is a comment, made by LTNSIZ001\n" 
					+ std::to_string(dimensions.width) + " " + std::to_string(dimensions.height) +
					 "\n255\n");
	const char* outstr = outs.c_str(); // No need to delete
	image_file.write(outstr, outs.length());
	for (int row = 0; row < dimensions.height; row++)
	{
		image_file.write((char*) pixels[row], dimensions.width);
		for (int i = 0; i < dimensions.width; ++i){
			std::cout << (int) pixels[row][i] << " ";
		}
		std::cout << "\n";
	}
	image_file.close();
}
