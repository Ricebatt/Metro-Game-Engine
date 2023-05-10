#include "pch.h"
#include "OpenGLImage.h"
#include "glad/glad.h"
#include "stb_image.h"


namespace Metro
{
	

	OpenGLImage::OpenGLImage(const std::string& imageFile) {
		unsigned int texture1;
		// texture 1
		// ---------
		glGenTextures(1, &texture1);
		glBindTexture(GL_TEXTURE_2D, texture1);
		// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to 
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		mData = stbi_load(imageFile.c_str(), &mWidth, &mHeight, &mnrChannels, 0);

		if (mData == nullptr)
			std::cout << "ERROR: image reading has failed" << std::endl;

	}

	OpenGLImage::OpenGLImage(std::string&& imageFile) {
		unsigned int texture1;
		// texture 1
		// ---------
		glGenTextures(1, &texture1);
		glBindTexture(GL_TEXTURE_2D, texture1);
		// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to 
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		mData = stbi_load(imageFile.c_str(), &mWidth, &mHeight, &mnrChannels, 0);

		if (mData == nullptr)
			std::cout << "ERROR: image reading has failed" << std::endl;

	}

	OpenGLImage::~OpenGLImage()
	{
		delete mData;
		mData = nullptr;
	}

	void OpenGLImage::Activate()
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, mData);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(mData);
	}

	int OpenGLImage::GetWidth()
	{
		return mWidth;
	}

	int OpenGLImage::GetHeight()
	{
		return mHeight;
	}

}