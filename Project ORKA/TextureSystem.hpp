#pragma once

#include "GPUTexture.hpp"

struct TextureSystem {
	Index currentTextureID = 0;
	Map<Name, Index> textureNames;
	Vector<GPUTexture> gpuTextures;

	void create();
	void destroy();
	void use(Name name);
	void use(Index textureID);
	void use(Name name, Index slot);
	void add(CPUTexture& cpuTexture);
	void resize(Int width, Int height);

	Index getTextureID(Name name);
	GPUTexture& currentTexture();
};