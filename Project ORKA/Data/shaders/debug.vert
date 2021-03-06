#version 450
layout(location = 0) in vec3 vertex;
layout(location = 1) in vec2 uvs;
layout(location = 2) in vec3 normals;
out vec4 vertexColor;
out vec2 textureCoordinate; 

layout(std140, binding = 0) uniform GlobalUniforms
{
	mat4 mMatrix;
	mat4 vpMatrix;
	
	vec4 worldOffset;
	vec4 cameraVector;		 //its vec3 but treated as vec4 in memory
	vec4 chunkOffsetVector;	 //its vec3 but treated as vec4 in memory
	vec4 customColor;

	float time;
	float custom1;
	float custom2;
	float custom3;

	bool distortion;
};

uniform sampler2D texture0;

void main() {

	vec3 positionInChunk = (mMatrix * vec4(vertex, 1)).xyz;
	vec3 cameraRelativePosition = chunkOffsetVector.xyz + positionInChunk;

	//planet curvature

	if(distortion){
		if(worldOffset.w < 13){

			float radius = pow(2,worldOffset.w-2);
			
			float height = cameraRelativePosition.z;

			float dist = length(vec2(cameraRelativePosition.xy));
			
			if(cameraRelativePosition.xy != vec2(0)){
				vec2 direction = normalize(cameraRelativePosition.xy);
				cameraRelativePosition.xy = direction * (height + radius + cameraHeight) * sin(dist/radius);
			}
			cameraRelativePosition.z = (height + radius + cameraHeight) * cos(dist/radius)-radius-cameraHeight;
		}
	}

	vec3 levelColor = vec3(mod(worldOffset.w / 5.0f,0.9) + 0.1);
	vec3 worldColor = ((vertex) + worldOffset.xyz)/vec3(pow(2,worldOffset.w));
	//outputs
	gl_Position  = vpMatrix * vec4(cameraRelativePosition.xyz,1);

	vertexColor = vec4(vec3((worldColor+0.5*vec3(uvs,1))/1.5),1.0f);
	textureCoordinate = uvs;
};