#ifndef IMAGE_H_
#define IMAGE_H_

#include <fstream>
#include "useful_structs.h"
typedef unsigned char u_char;

namespace LTNSIZ001 {
	class Image {
	private:
		char* pixels;
		dimension image_dims;

	public:
		/*
		 * Creates an image object without any pixels
		 */
		Image(dimension dimensions);

		/*
		 * loads pixel data into the image from an ifstream object. Assumes that the
		 * ifstream only has image pixels and the header has been removed.
		 */
		void load_image(std::ifstream* file);

		/*
		 * Returns a width * height unsigned char array of an image starting from
		 * (start_x, start_y)
		 */
		u_char** get_frame(position start, dimension dims);

		/*
		 * Returns a pointer to a pixel at the first column of the given row.
		 */
		u_char* operator[](int row_no);

		/*
		 * Returns the width of the image
		 */
		dimension get_dimensions();

		~Image();
	};

}  // namespace LTNSIZ001

#endif