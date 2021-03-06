

#include "Debug.hpp"

bool showEvents = true;
bool showDebug = true;
bool showWarning = true;
bool showError = true;

void logEvent(String message)
{
#ifdef DEBUG
	if(showEvents) std::cout <<	"Event: " << message << "\n";
#endif // DEBUG
}
void logDebug(String message)
{
#ifdef DEBUG
	if(showDebug) std::cout <<	"Debug: " << message << "\n";
#endif // DEBUG
}
void logWarning(String message) {
#ifdef DEBUG
	if (showWarning) std::cout << "Warning: " << message << "\n";
	beep();
	pause();
#endif // DEBUG
}
void logError(String message)
{
#ifdef DEBUG
	if(showError) std::cout <<	"Error: " << message << "\n";
	beep();
	pause();
	exit(EXIT_FAILURE);
#endif // DEBUG
}

void beep() {
	std::cout << '\a';
}
void pause() {
#ifdef _WIN32
	system("pause");
#else
	std::cout << "Thread was paused..." << "\n";
	char a;
	std::cin >> a;
#endif
}

void logDebug(ULL t) {
#ifdef DEBUG
	std::cout << " (" << std::bitset<64>(t) << ")" << t << "\n";
#endif // DEBUG
}
void logDebug(Int t)
{
#ifdef DEBUG
	std::cout << t << "\n";
#endif // DEBUG
}
void logDebug(UInt t)
{
#ifdef DEBUG
	std::cout << t << "\n";
#endif // DEBUG
}
void logDebug(Vec2 t)
{
#ifdef DEBUG
	std::cout << "(" << t.x << "|" << t.y << ")" << "\n";
#endif // DEBUG
};
void logDebug(Vec3 t) {
#ifdef DEBUG
	std::cout << "(" << t.x << "|" << t.y << "|" << t.z << ")" << "\n";
#endif // DEBUG
}
void logDebug(Short t)
{
#ifdef DEBUG
	std::cout << t << "\n";
#endif // DEBUG
}
void logDebug(ULLVec2 t)
{
#ifdef DEBUG
	std::cout << "(" << t.x << "|" << t.y << ")" << "\n";
#endif // DEBUG
}
void logDebug(ULLVec3 t) {
#ifdef DEBUG
	std::cout << "(" << t.x << "|" << t.y << "|" << t.z << ")" << "\n";
#endif // DEBUG
}
void logDebug(Matrix matrix) {
#ifdef DEBUG
	std::cout << "[ " << matrix[0][0] << "  " << matrix[0][1] << "  " << matrix[0][2] << "  " << matrix[0][3] << " ]" << "\n";
	std::cout << "[ " << matrix[1][0] << "  " << matrix[1][1] << "  " << matrix[1][2] << "  " << matrix[1][3] << " ]" << "\n";
	std::cout << "[ " << matrix[2][0] << "  " << matrix[2][1] << "  " << matrix[2][2] << "  " << matrix[2][3] << " ]" << "\n";
	std::cout << "[ " << matrix[3][0] << "  " << matrix[3][1] << "  " << matrix[3][2] << "  " << matrix[3][3] << " ]" << "\n";
#endif // DEBUG
}
void logDebug(glm::highp_dvec3 t) {
#ifdef DEBUG
	std::cout << "(" << t.x << "|" << t.y << "|" << t.z << ")" << "\n";
#endif // DEBUG
}