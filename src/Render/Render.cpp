#include"Render.h"
#include "../Debug.h"

void Render::Clear() {
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
};
void Render::Draw() {};