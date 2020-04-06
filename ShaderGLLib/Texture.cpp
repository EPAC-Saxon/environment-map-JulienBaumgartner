#include "Texture.h"
#include <GL/glew.h>
#include "Image.h"

namespace sgl {

	Texture::Texture(
		const std::string& file, 
		const PixelElementSize pixel_element_size /*= PixelElementSize::BYTE*/, 
		const PixelStructure pixel_structure /*= PixelStructure::RGB_ALPHA*/) :
		pixel_element_size_(pixel_element_size),
		pixel_structure_(pixel_structure)
	{
#pragma message ("You have to complete this code!")
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &texture_id_);
	}

	void Texture::Bind(const unsigned int slot /*= 0*/) const
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, texture_id_);
	}

	void Texture::UnBind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	TextureManager::~TextureManager()
	{
		DisableAll();
	}

	bool TextureManager::AddTexture(
		const std::string& name, 
		const std::shared_ptr<sgl::Texture>& texture)
	{
		auto ret = name_texture_map_.insert({ name, texture });
		return ret.second;
	}

	bool TextureManager::RemoveTexture(const std::string& name)
	{
		auto it = name_texture_map_.find(name);
		if (it == name_texture_map_.end())
		{
			return false;
		}
		name_texture_map_.erase(it);
		return true;
	}

	const int TextureManager::EnableTexture(const std::string& name) const
	{
		auto it1 = name_texture_map_.find(name);
		if (it1 == name_texture_map_.end())
		{
			throw std::runtime_error("try to enable a texture: " + name);
		}
		for (int i = 0; i < name_array_.size(); ++i)
		{
			if (name_array_[i].empty())
			{
				name_array_[i] = name;
				it1->second->Bind(i);
				return i;
			}
		}
		throw std::runtime_error("No free slots!");
	}

	void TextureManager::DisableTexture(const std::string& name) const
	{
		auto it1 = name_texture_map_.find(name);
		if (it1 == name_texture_map_.end())
		{
			throw std::runtime_error("no texture named: " + name);
		}
		auto it2 = std::find_if(
			name_array_.begin(),
			name_array_.end(),
			[name](const std::string& value)
		{
			return value == name;
		});
		if (it2 != name_array_.end())
		{
			*it2 = "";
			it1->second->UnBind();
		}
		else
		{
			throw std::runtime_error("No slot bind to: " + name);
		}
	}

	void TextureManager::DisableAll() const
	{
		for (int i = 0; i < 32; ++i)
		{
			if (!name_array_[i].empty())
			{
				DisableTexture(name_array_[i]);
			}
		}
	}

	TextureCubeMap::TextureCubeMap(
		const std::array<std::string, 6>& cube_file, 
		const PixelElementSize pixel_element_size /*= PixelElementSize::BYTE*/, 
		const PixelStructure pixel_structure /*= PixelStructure::RGB_ALPHA*/) :
		Texture(pixel_element_size, pixel_structure)
	{
#pragma message ("You have to complete this code!")
	}

	void TextureCubeMap::CreateCubeMap()
	{
#pragma message ("You have to complete this code!")
	}

} // End namespace sgl.
