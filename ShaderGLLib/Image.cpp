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

		int width;
		int height;
		int channel;

		switch (pixel_element_size)
		{
		case PixelElementSize::BYTE:
			image_ = stbi_load(file.c_str(), &width, &height, &channel, static_cast<int>(pixel_structure));
			break;
		case PixelElementSize::SHORT:
			image_ = stbi_load_16(file.c_str(), &width, &height, &channel, static_cast<int>(pixel_structure));
			break;
		case PixelElementSize::LONG:
			image_ = stbi_loadf(file.c_str(), &width, &height, &channel, static_cast<int>(pixel_structure));
			break;
		}
		if (image_ == NULL)
		{
			throw std::runtime_error("Unable to load file: " + file);
		}

		size_.first = width;
		size_.second = height;
	}

	Image::~Image()
	{
		stbi_image_free(image_);
	}

}	// End namespace sgl.
