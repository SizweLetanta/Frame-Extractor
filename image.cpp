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
	// delete[] pixels;
}

u_char** IMG::get_frame(position start, dimension dims, bool invert) {
	u_char** frame = new u_char*[dims.height];

	for (int y = 0; y < dims.height; y++) {
		u_char* row = new u_char[dims.width];
		for (int x = 0; x < dims.width; x++) {
			bool over_bounds = start.y+y >= image_dims.height || start.x+x >= image_dims.width;
			row[x] = (over_bounds ? 0 :(invert ? 255 - (*this)[start.y+y][start.x+x] : (*this)[start.y+y][start.x+x]));
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
