
#include "WindowAPI.hpp"

void apiWindowRestore(APIWindow apiWindow)
{
	glfwRestoreWindow(apiWindow);
}
void apiWindowDecorate(APIWindow apiWindow)
{
	glfwSetWindowAttrib(apiWindow, GLFW_DECORATED, 1);
}
void apiWindowUndecorate(APIWindow apiWindow)
{
	glfwSetWindowAttrib(apiWindow, GLFW_DECORATED, 0);
}
void apiWindowSwapBuffers(APIWindow apiWindow)
{
	glfwSwapBuffers(apiWindow);
}
Bool apiWindowIsFullscreen(APIWindow apiWindow)
{
	return glfwGetWindowMonitor(apiWindow) != NULL;
}
void apiWindowEnableCursor(APIWindow apiWindow)
{
	glfwSetInputMode(apiWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}
void apiWindowDisableCursor(APIWindow apiWindow)
{
	glfwSetInputMode(apiWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}
void apiWindowSetExclusiveFullscreen(APIWindow apiWindow)
{
	glfwSetWindowMonitor(apiWindow, glfwGetPrimaryMonitor(), 0, 0, glfwGetVideoMode(glfwGetPrimaryMonitor())->width, glfwGetVideoMode(glfwGetPrimaryMonitor())->height, GLFW_DONT_CARE);
}
void apiWindowSetVisibility(APIWindow apiWindow, Bool visible) {
	if (visible)glfwShowWindow(apiWindow);
	else glfwHideWindow(apiWindow);
}
void apiWindowSetCursorPosition(APIWindow apiWindow, Vec2 position)
{
	glfwSetCursorPos(apiWindow, position.x, position.y);
}
void apiWindowSetWindowedMode(APIWindow apiWindow, TiledRectangle monitorArea)
{
	glfwSetWindowMonitor(apiWindow, nullptr, monitorArea.position.x, monitorArea.position.y, monitorArea.size.x, monitorArea.size.y, GLFW_DONT_CARE);
}

Bool apiWindowShouldClose(APIWindow apiWindow)
{
	return glfwWindowShouldClose(apiWindow);
}
Bool apiWindowIsCapturing(APIWindow apiWindow)
{
	return glfwGetInputMode(apiWindow, GLFW_CURSOR) == GLFW_CURSOR_DISABLED;
}
Bool apiWindowIsDecorated(APIWindow apiWindow)
{
	return glfwGetWindowAttrib(apiWindow, GLFW_DECORATED);
}
Bool apiWindowCursorIsCaptured(APIWindow apiWindow)
{
	return glfwGetInputMode(apiWindow, GLFW_CURSOR) == GLFW_CURSOR_DISABLED;
}
Bool apiWindowKeyIsPressed(APIWindow apiWindow, KeyID keyID)
{
	return glfwGetKey(apiWindow, keyID) == GLFW_PRESS;
}

Int apiWindowGetFramebufferWidth(APIWindow apiWindow)
{
	Int width, height;
	glfwGetFramebufferSize(apiWindow, &width, &height);
	return width;
}
Int apiWindowGetFramebufferHeight(APIWindow apiWindow)
{
	Int width, height;
	glfwGetFramebufferSize(apiWindow, &width, &height);
	return height;
}

DVec2 apiWindowGetCursorPosition(APIWindow apiWindow)
{
	DVec2 cursorPosition;
	glfwGetCursorPos(apiWindow, &cursorPosition.x, &cursorPosition.y);
	return cursorPosition;
}
Area apiWindowGetFramebufferSize(APIWindow apiWindow)
{
	IVec2 size;
	glfwGetFramebufferSize(apiWindow, &size.x, &size.y);
	return size;
}
Area apiWindowGetWindowFrameSize(APIWindow apiWindow)
{
	Area area;
	glfwGetWindowSize(apiWindow, &area.x, &area.y);
	return area;
}
TiledRectangle apiWindowGetWorkableArea(APIWindow apiWindow)
{
	TiledRectangle rect;
	glfwGetMonitorWorkarea(glfwGetPrimaryMonitor(), &rect.position.x, &rect.position.y, &rect.size.x, &rect.size.y);
	return rect;
}

void whenWindowAPIThrowsError(Int error, const char* description)
{
	logError(description);
}