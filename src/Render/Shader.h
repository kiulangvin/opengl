#pragma once
#include <string>

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

enum class ShaderType
{
	NONE = -1, VERTEX = 0, FRAGMENT = 1
};


class Shader
{
public:
	Shader(const std::string& filepath);
	~Shader();
	void Bind() const;
	void Unbind() const;
private:
	unsigned int m_RendererID;
	std::string m_FilePath;
	struct ShaderProgramSource ParseShader(const std::string& filepath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
};