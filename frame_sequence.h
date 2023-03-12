#ifndef FRAME_MODULE_H_
#define FRAME_MODULE_H_
#include <vector>
#include "image.h"

namespace LTNSIZ001 {

	class FrameSequence {
	private:
		std::vector<u_char**> imageSequence;
		dimension size;
	public:
		FrameSequence(void);

		/*
		 * For accessing a frame from the vector.
		 */
        u_char** operator[](int frameNo);

		/*
		 * For adding a frame to the vector.
		 */
		FrameSequence& operator+=(u_char** frame);

		/*
		 * Sets the width and height of the frames
		 */
		void set_size(dimension &size);

		/*
		 * Destroys the object and frees up memory.
		 */
		~FrameSequence();
	};

}  // namespace LTNSIZ001
#endif