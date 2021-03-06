
#include "Math.hpp"

Float lerp(Float from, Float to, Float t)
{
	return (from * (1 - t)) + (to * t);
}
float randomFloat()
{
	return randomFloat(0, 1);
}
float randomFloat(Float low, Float high)
{
	return low + static_cast <Float> (rand()) / (static_cast <Float> (RAND_MAX / (high - low)));
}
bool isFloatNearOther(Float a, Float b, Float error) {
	return fabsf(a - b) < error;
}

Rotation getRotationBetweenVectors(Vec3 start, Vec3 dest) { //copy of opengl tutorial
	start = normalize(start);
	dest = normalize(dest);

	float cosTheta = dot(start, dest);
	Vec3 rotationAxis;

	if (cosTheta < -1 + 0.001f) {
		// special case when vectors in opposite directions:
		// there is no "ideal" rotation axis
		// So guess one; any will do as long as it's perpendicular to start
		rotationAxis = glm::cross(Vec3(0.0f, 0.0f, 1.0f), start);
		if (glm::length2(rotationAxis) < 0.01) // bad luck, they were parallel, try again!
			rotationAxis = glm::cross(Vec3(1.0f, 0.0f, 0.0f), start);

		rotationAxis = normalize(rotationAxis);
		return glm::angleAxis(glm::radians(180.0f), rotationAxis);
	}

	rotationAxis = cross(start, dest);

	float s = sqrt((1 + cosTheta) * 2);
	float invs = 1 / s;

	return Rotation(
		s * 0.5f,
		rotationAxis.x * invs,
		rotationAxis.y * invs,
		rotationAxis.z * invs
	);
}


UInt nextPowerOfTwo(UInt& value)
{
	UInt powerOfTwo = 1;
	while (powerOfTwo < value) powerOfTwo <<= 1;
	return powerOfTwo;
}