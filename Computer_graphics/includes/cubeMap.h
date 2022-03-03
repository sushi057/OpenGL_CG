#pragma once
#include <vector>
#include <string>
#include <texture.h>


struct CubeMap {
	unsigned int textureID;
	Texture texture;

	CubeMap(std::vector<std::string> faces);

	void bind() const;
};