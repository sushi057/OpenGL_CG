#pragma once
#include <GL/glew.h>

struct IndexBuffer {
	unsigned int rendererID;
	int count;
	IndexBuffer(const void* data, unsigned int size);

	~IndexBuffer();

	void bind()const;

	void unbind();
};