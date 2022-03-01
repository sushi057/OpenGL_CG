#include "vertexarray.h"
#include "renderer.h"


VertexArray::VertexArray() {
	glGenVertexArrays(1, &rendererID);
	glBindVertexArray(rendererID);
}

void VertexArray::bind() const {
	glBindVertexArray(rendererID);
}


void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) {
	bind();
	//vb.bind();
	const std::vector<VertexBufferElement>& elements = layout.GetElements();
	unsigned int offset = 0;
	for (int i = 0; i < elements.size(); i++) {
		const VertexBufferElement element = elements[i];
		glEnableVertexAttribArray(i);
		GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), reinterpret_cast<const void*>(offset)));
		offset += element.count * sizeof(GL_FLOAT);
	}
}

VertexArray::~VertexArray() {
}