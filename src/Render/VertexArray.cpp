#include"VertexArray.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "../Debug.h"


VertexArray::VertexArray()
{
	// 创建VAO
	GLCall(glGenVertexArrays(1, &m_RendererID) );
}

VertexArray::~VertexArray()
{
	// 删除VAO
	GLCall(glDeleteVertexArrays(1, &m_RendererID));
}

void VertexArray::Bind() const
{
	// 绑定VAO
	GLCall(glBindVertexArray(m_RendererID));
}

void VertexArray::Unbind() const
{
	// 解除绑定VAO
	GLCall(glBindVertexArray(0));
}
