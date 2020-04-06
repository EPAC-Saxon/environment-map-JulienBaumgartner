#include "Image.h"
#include <algorithm>
#include <fstream>
#include <vector>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace sgl {

	Image::Image(
		const std::string& file, 
		const PixelElementSize pixel_element_size /*= PixelElementSize::BYTE*/, 
		const PixelStructure pixel_structure /*= PixelStructure::RGB_ALPHA*/) :
		pixel_element_size_(pixel_element_size),
		pixel_structure_(pixel_structure)
	{
#pragma message ("You have to complete this code!")
	}

	Image::~Image()
	{
		stbi_image_free(image_);
	}

}	// End namespace sgl.
