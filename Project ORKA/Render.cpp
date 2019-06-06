
#include "Program.hpp"

void renderWindow(Window & window) {
	int vWidth, vHeight;
	glfwGetFramebufferSize(window.glfwWindow, &vWidth, &vHeight);
	renderFrame(*window.renderingSystem, vWidth, vHeight);
	glfwSwapBuffers(window.glfwWindow);
}

void renderFrame(RenderingSystem & renderingSystem, int width, int height) {
	glViewport(0, 0, width, height);
	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	//projection matrix
	renderingSystem.projectionMatrix = glm::perspective(glm::radians(75.0f), (float)width / (float)height, 0.1f, 1000.0f);

	renderWorld(renderingSystem.gameServer->worldSystem, renderingSystem);
	glUseProgram(0); // somehow gets rid of shader recompilation on nvidia cards
}

void renderWorld(WorldSystem & worldSystem, RenderingSystem & renderingSystem) {
	renderSky(worldSystem.sky);
	renderChunk(worldSystem.chunk, renderingSystem);
}

void renderSky(Sky & sky) {
	glClearColor(sky.skyColor.r, sky.skyColor.g, sky.skyColor.b, 0.75f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void renderChunk(Chunk & chunk, RenderingSystem & renderingSystem) {

	//view matrix
	renderingSystem.viewMatrix = glm::lookAt(
		glm::vec3(+0.0f, -3.0f, +0.5f),	//position
		glm::vec3(+0.0f, +0.0f, +0.0f),		//looking at
		glm::vec3(+0.0f, +0.0f, +1.0f)		//up vector
	);

	renderEntities(chunk.entityComponentSystem, renderingSystem);

}

void renderEntities(ECS & entityComponentSystem, RenderingSystem & renderingSystem) {
	for (unsigned int i = 0; i < entityComponentSystem.transformationSystem.transformations.size(); i++) {
		//model matrix
		renderingSystem.modelMatrix = entityComponentSystem.transformationSystem.transformations[i].modelMatrix();
		useShader(renderingSystem.primitiveShader);
		glUniformMatrix4fv(renderingSystem.primitiveShader.projectionMatrixID, 1, GL_FALSE, &renderingSystem.projectionMatrix[0][0]);
		glUniformMatrix4fv(renderingSystem.primitiveShader.viewMatrixID, 1, GL_FALSE, &renderingSystem.viewMatrix[0][0]);
		glUniformMatrix4fv(renderingSystem.primitiveShader.modelMatrixID, 1, GL_FALSE, &renderingSystem.modelMatrix[0][0]);
		renderMesh(*renderingSystem.meshHandler.meshMap["triangle"]);
	}
}


RenderingSystem::RenderingSystem(GameServer & gameServer)
{
	this->gameServer = &gameServer;
	projectionMatrix = glm::mat4(1);
	viewMatrix = glm::mat4(1);
	modelMatrix = glm::mat4(1);

	debugPrint("|---RenderingSystem was created!");
}
RenderingSystem::~RenderingSystem()
{
	debugPrint("|---RenderingSystem was destroyed!");
}