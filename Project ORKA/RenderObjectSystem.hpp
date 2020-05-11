#pragma once

#include "Basics.hpp"
#include "ShaderSystem.hpp"
#include "MeshSystem.hpp"
#include "TextureSystem.hpp"

struct RenderObject {
	Index meshID;
	Index shaderID;
	Index textureID;
};

struct RenderObjectSystem {
	MeshSystem meshSystem;
	ShaderSystem shaderSystem;
	TextureSystem textureSystem;

	Map<String, Index> nameToIndex;
	Vector<RenderObject> renderObjects;

	void create();
	void addRenderObject(String name, String meshName, String textureName, String shaderName);
	void render(String name);
	void destroy();
};