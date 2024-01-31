#include<iostream>

#include<glad/glad.h>
#include<GLFW/glfw3.h>

//#define STB_IMAGE_IMPLEMENTATION
//#include<stb/stb_image.h>

#include "src/Application/application.h"

#include "src/Render/VertexArray.h"
#include "src/Render/VertexBuffer.h"
#include "src/Render/Shader.h"


#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

void onResize(int w, int h) {
	glViewport(0, 0, w, h);
}

void onKey(int key, int action, int mods) {
	std::cout << key << std::endl;
}

void initImgui() {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext(); //创建上下文

	// 设置渲染器后端
	ImGui_ImplGlfw_InitForOpenGL(app->GetWindow(), true);
	ImGui::StyleColorsDark();
	ImGui_ImplOpenGL3_Init();
}


int main() {
	app->test();
	// 初始化基本环境
	if (!app->init(800, 600)) {
		return -1;
	}
	// 窗口变化响应
	app->setResizeCallback(onResize);

	// 键盘响应
	app->setKeyBoardCallback(onKey);

	glViewport(0, 0, 800, 600);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	// 测试
	float vertices[] = {
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
		 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
	};
	VertexArray va;
	va.Bind();
	VertexBuffer vb(vertices, 3 * 6 * sizeof(float));

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// todo
	Shader shader("D:/03_Developer/01_My_Github/opengl/res/shaders/Basic.shader");
	shader.Bind();


	initImgui();
	

	//执行窗体循环
	while (app->update())
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::ShowDemoWindow();

		// 执行画布清理操作
		glClear(GL_COLOR_BUFFER_BIT);
		va.Bind();
		shader.Bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);
		

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
	// 退出程序
	glfwTerminate();

	return 0;
}