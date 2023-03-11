#ifndef IMAGE_H_
#define IMAGE_H_

#include <fstream>
typedef unsigned char u_char;

namespace LTNSIZ001 {
	class Image {
	private:
		char* pixels;
		int width, height;

	public:
		/*
		 * Creates an image object without any pixels
		 */
		Image(int width, int height);

		/*
		 * loads pixel data into the image from an ifstream object. Assumes that the
		 * ifstream only has image pixels and the header has been removed.
		 */
		void load_image(std::ifstream* file);

		/*
		 * Returns a width * height unsigned char array of an image starting from
		 * (start_x, start_y)
		 */
		u_char** get_frame(int start_x, int start_y, int width, int height);

		/*
		 * Returns a pointer to a pixel at the first column of the given row.
		 */
		u_char* operator[](int row_no);

		/*
		 * Returns the width of the image
		 */
		int get_width();

		/*
		 * Returns the width of the image
		 */
		int get_height();

		~Image();
	};

}  // namespace LTNSIZ001

#endif