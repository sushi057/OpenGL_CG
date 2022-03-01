#pragma once
#include <vertexbuffer.h>
#include <vertexbufferlayout.h>

struct VertexArray {
	unsigned int rendererID;

	VertexArray();

	void bind() const;

	~VertexArray();

	void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
};