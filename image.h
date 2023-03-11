#ifndef IMAGE_H_
#define IMAGE_H_

#include <fstream>
typedef unsigned char u_char;

namespace LTNSIZ001
{
    class Image{
    private:
        u_char* pixels;
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
        u_char** get_frame(int start_x, int start_y, int width, int height);

        /*
         * Returns a pointer to a pixel at position
         */
        u_char* operator[](int row_no);

        int get_width();
        int get_height();

        ~Image();
    };
    
    
} // namespace LTNSIZ001



#endif