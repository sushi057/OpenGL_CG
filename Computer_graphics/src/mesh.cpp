#include "mesh.h"

Mesh::Mesh(std::vector<Vertex> _vertices, std::vector<unsigned int> _indices, std::vector<Texture> _textures, Material _material)
	:vertices(_vertices),
	indices(_indices),
	textures(_textures),
	vbo(&vertices[0], vertices.size() * sizeof(Vertex)),
	ibo(&indices[0], indices.size() * sizeof(uint32_t)),
	material(_material)
{
	setupMesh();
}

void Mesh::setupMesh() {
	VertexBufferLayout layout;

	//for vertex buffer
	layout.AddFloat(3);

	//normal coordinates
	layout.AddFloat(3);

	//tex coordinate
	layout.AddFloat(2);

	// For Vertex Tangent
	layout.AddFloat(3);

	// For Vertex Bitangent
	layout.AddFloat(3);

	vao.addBuffer(vbo, layout);
}


void Mesh::draw(Shader& shader, bool isTextureModel) const {
	// bind appropriate textures
	unsigned int diffuseNr = 1;
	unsigned int specularNr = 1;
	unsigned int heightNr = 1;
	unsigned int normalNr = 1;

	shader.Bind();
	std::string type;
	if (!isTextureModel) {
		shader.setUniform("material.ambient", material.ambient);
		shader.setUniform("material.diffuse", material.diffuse);
		shader.setUniform("material.specular", material.specular);
		shader.setUniform("material.shininess", 32.0f);
	}
	else {
		for (unsigned int i = 0; i < textures.size(); ++i) {
			glActiveTexture(GL_TEXTURE0 + i);
			// retrieve texture number (the N in diffuse_textureN)
			std::string number;
			const std::string& textureType = textures[i].getType();
			if (textureType == "texture_diffuse") {
				number = std::to_string(diffuseNr++);
				type = "diffuse";
			}
			else if (textureType == "texture_specular") {
				number = std::to_string(specularNr++); // transfer unsigned int to stream
				type = "specular";
			}
			else if (textureType == "texture_normal") {
				number = std::to_string(normalNr++); // transfer unsigned int to stream
				type = "normal";
			}
			else if (textureType == "texture_height")
				number = std::to_string(heightNr++); // transfer unsigned int to stream
			else
				continue;
			//shader.setUniform((("material." + textureType + number).c_str()), static_cast<int>(i));
			shader.setUniform(("material." + type + number), static_cast<int>(i));
			// shader.setUniform(("material.diffuse" + number), static_cast<int>(i));
			// shader.setUniform(("material.diffuse" + number), static_cast<int>(i));
			// shader.setUniform(("material.diffuse" + number), static_cast<int>(i));
			GLCall(textures[i].bind(i));
		}
	}
	GLCall(vao.bind());
	GLCall(glDrawElements(GL_TRIANGLES, ibo.count, GL_UNSIGNED_INT, NULL));

	glActiveTexture(GL_TEXTURE0);
}