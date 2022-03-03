#pragma once
#include <shader.h>
#include <vector>
#include "texture.h"
#include <vertexarray.h>
#include <renderer.h>
#include <unordered_map>
#include "framebuffer.h"
#include "indexbuffer.h"

struct Vertex {
    glmath::vec3 position;
    glmath::vec3 normal;
    glmath::vec2 texCoords;
    // tangent
    glmath::vec3 tangent;
    // bitangent
    glmath::vec3 bitangent;
};

struct Material {
    glmath::vec3 diffuse;
    glmath::vec3 ambient;
    glmath::vec3 specular;
};

struct Mesh {
    const std::vector<Vertex> vertices;
    const std::vector<uint32_t> indices;
    const std::vector<Texture> textures;
    Material material;
    //const std::unordered_map<std::string, Texture>& texturesLoaded;

    VertexArray vao;
    VertexBuffer vbo;
    IndexBuffer ibo;

    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures, Material _material);

    void setupMesh();

    void draw(Shader& shader, bool isTextureModel = true) const;
};