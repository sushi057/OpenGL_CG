#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <unordered_map>
#include <matrix.h>

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

class Shader
{
private:
    unsigned int m_RendererID;
    std::string m_FilePath;
    std::unordered_map<std::string, int> m_UniformLocationCache;

public:
    Shader(const std::string& filepath);
    ~Shader();

    void Bind() const;
    void Unbind() const;

    // Set uniforms
    void setUniform(std::string name, float value);
    void setUniform(std::string name, int value);
    void setUniform(std::string name, float v0, float v1, float v2, float v3);
    void setUniform(std::string name, float v0, float v1, float v2);
    void setUniform(std::string name, glmath::vec3 vec);
    void setUniform(std::string name, glmath::mat4 transform);

private:
    int GetUniformLocation(const std::string& name);
    struct ShaderProgramSource ParseShader(const std::string& filepath);
    unsigned int CompileShader(unsigned int type, const std::string& source);
    unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

};
#endif