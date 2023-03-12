#include "image.h"
#define IMG LTNSIZ001::Image

IMG::Image(int width, int height)
	: width(width), height(height), pixels(nullptr) {}

u_char* IMG::operator[](int y) {
	return (u_char*) (pixels + (y * width));
}

int IMG::get_height() {
	return height;
}

int IMG::get_width() {
	return width;
}

IMG::~Image() {
	delete[] pixels;
}

u_char** IMG::get_frame(int start_r, int start_c, int f_width, int f_height) {
	u_char** frame = new u_char*[f_height];

	for (int y = 0; y < f_height; y++) {
		u_char* row = new u_char[f_width];
		for (int x = 0; x < f_width; x++) {
			row[x] = (*this)[start_r+y][start_c+x];
		}

		frame[y] = row;
	}

	return frame;
}

void IMG::load_image(std::ifstream* file) {
	pixels = new char[width * height];
	file->read(pixels, width * height);
}
