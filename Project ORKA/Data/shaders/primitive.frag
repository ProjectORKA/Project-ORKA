#version 330 core

out vec4 color;

in vec4 vertexColor;
in vec2 textureCoordinate; 

uniform sampler2D texture0;

void main(){
	color = vec4(texture(texture0, textureCoordinate).rgb,1.0);
};