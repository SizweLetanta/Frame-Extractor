#include "image.h"
#define IMG LTNSIZ001::Image

IMG::Image(dimension dimensions)
	: image_dims(dimensions), pixels(nullptr) {}

u_char* IMG::operator[](int y) {
	return (u_char*) (pixels + (y * image_dims.width));
}

LTNSIZ001::dimension IMG::get_dimensions(){
	return image_dims;
}

IMG::~Image() {
	delete[] pixels;
}

u_char** IMG::get_frame(position start, dimension dims) {
	u_char** frame = new u_char*[dims.height];

	for (int y = 0; y < dims.height; y++) {
		u_char* row = new u_char[dims.width];
		for (int x = 0; x < dims.width; x++) {
			row[x] = (*this)[start.y+y][start.x+x];
		}

		frame[y] = row;
	}

	return frame;
}

void IMG::load_image(std::ifstream* file) {
	int pixel_count = image_dims.width * image_dims.height;
	pixels = new char[pixel_count];
	file->read(pixels, pixel_count);
}
