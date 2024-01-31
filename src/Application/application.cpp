#include "application.h"
// glad 得 在glfw之前
#include<glad/glad.h>
#include<GLFW/glfw3.h>

// static 成员变量。类内声明。类外初始化
Application* Application::mInstance = nullptr;

// 静态成员函数，只能访问静态成员变量
Application* Application::getInstance() {
	if (mInstance == nullptr) {
		mInstance = new Application();
	}
	return mInstance;
};

// 构造函数 
Application::Application(){}

// 析构函数
Application::~Application(){}


bool Application::init(const int& width, const int& height){
	mWidth = width;
	mHeight = height;
	// 初始化基本环境
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // 主版本号
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); // 次版本号
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 核心模式

	// 创建窗体对象
	mWindow = glfwCreateWindow(mWidth, mHeight, "learnOpengl", NULL, NULL);
	if (mWindow == NULL) {
		return false;
	}
	glfwMakeContextCurrent(mWindow);

	// 使用glad加载所有当前版本得opengl的函数
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return false;
	}

	glfwSetFramebufferSizeCallback(mWindow, frameBufferSizeCllBack);

	// this 就是当前全局的唯一的app对象
	glfwSetWindowUserPointer(mWindow, this);
	
	glfwSetKeyCallback(mWindow, keyCallback);
	
	return true;
}

bool Application::update() {
	if (glfwWindowShouldClose(mWindow)) {
		return false;
	}
	glfwPollEvents(); //接收并分发窗口消息
	// 切换双缓存
	glfwSwapBuffers(mWindow);
	return true;
}

void Application::destroy() {
	// 退出程序
	glfwTerminate();
}

void Application::frameBufferSizeCllBack(GLFWwindow* window, int w, int h) {
	//std::cout << "resize" << std::endl;
	/*if (Application::getInstance()->mResizeCallback !=nullptr) {
		Application::getInstance()->mResizeCallback(w, h);
	}*/

	// 优雅调用
	Application* self = (Application*)glfwGetWindowUserPointer(window);
	if (self->mResizeCallback != nullptr) {
		self->mResizeCallback(w, h);
	}
	
};

void  Application::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	Application* self = (Application*)glfwGetWindowUserPointer(window);
	if (self->mKeyBoardCallback != nullptr) {
		self->mKeyBoardCallback(key,action,mods);
	}
};
