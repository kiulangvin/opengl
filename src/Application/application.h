#pragma once
#include<iostream>

// 宏
#define app Application::getInstance()

class GLFWwindow;

// 函数指针类型
using ResizeCallback = void(*)(int width, int height);

using KeyBoardCallback = void(*)(int key, int action, int mods);


/*
* 单例类
*/

class Application {
public:
	// 构造函数，会初始化实例的时候，会自动调用
	Application();
	// 析构函数，无参数，不能重载，对象销毁前会自动调用。
	 ~Application();
	static Application* getInstance();

	void test() {
		std::cout << "test app" << std::endl;
	}

	bool init(const int & width=800, const int& height = 600);
	bool update();
	void destroy();
	
	uint32_t getWidth() const {
		return mWidth;
	};
	uint32_t getHeight() const {
		return mHeight;
	};

	void setResizeCallback(ResizeCallback callback) {
		mResizeCallback = callback;
	}

	void setKeyBoardCallback(KeyBoardCallback callback) {
		mKeyBoardCallback = callback;
	}

private:
	// c++类 内函数指针
	static void frameBufferSizeCllBack(GLFWwindow* window, int w, int h);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
	// 有访问权限
	static Application* mInstance;

	// gl的对象
	uint32_t mWidth{ 0 };
	uint32_t mHeight{ 0 };
	GLFWwindow* mWindow{ nullptr };

	ResizeCallback mResizeCallback{ nullptr };

	KeyBoardCallback mKeyBoardCallback{ nullptr };

};