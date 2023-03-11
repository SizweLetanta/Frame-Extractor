#include "image.h"
#define IMG LTNSIZ001::Image

IMG::Image(int width, int height)
	: width(width), height(height), pixels(nullptr) {}

u_char* IMG::operator[](int y) {
	return (u_char*)pixels + (y * width);
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

u_char** IMG::get_frame(int start_x, int start_y, int width, int height) {
	u_char** frame = new u_char*[height];

	for (int y = 0; y < height; y++) {
		u_char* row = new u_char[width];
		for (int x = 0; x < width; x++) {
			row[x] = (*this)[y][x];
		}

		frame[y] = row;
	}

	return frame;
}

void IMG::load_image(std::ifstream* file) {
	pixels = new char[width * height];
	file->read(pixels, width * height);
}
