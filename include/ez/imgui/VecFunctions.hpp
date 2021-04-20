#pragma once
#include <imgui.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

namespace ImGui {
	bool InputVec(const char* label, const float& v, const char* format = "%.3f", ImGuiInputTextFlags flags = 0);
	bool InputVec(const char* label, const glm::vec2& v, const char* format = "%.3f", ImGuiInputTextFlags flags = 0);
	bool InputVec(const char* label, const glm::vec3& v, const char* format = "%.3f", ImGuiInputTextFlags flags = 0);
	bool InputVec(const char* label, const glm::vec4& v, const char* format = "%.3f", ImGuiInputTextFlags flags = 0);

	bool InputVec(const char* label, float& v, const char* format = "%.3f", ImGuiInputTextFlags flags = 0);
	bool InputVec(const char* label, glm::vec2& v, const char* format = "%.3f", ImGuiInputTextFlags flags = 0);
	bool InputVec(const char* label, glm::vec3& v, const char* format = "%.3f", ImGuiInputTextFlags flags = 0);
	bool InputVec(const char* label, glm::vec4& v, const char* format = "%.3f", ImGuiInputTextFlags flags = 0);

	bool InputVec(const char* label, const int& v, ImGuiInputTextFlags flags = 0);
	bool InputVec(const char* label, const glm::ivec2& v, ImGuiInputTextFlags flags = 0);
	bool InputVec(const char* label, const glm::ivec3& v, ImGuiInputTextFlags flags = 0);
	bool InputVec(const char* label, const glm::ivec4& v, ImGuiInputTextFlags flags = 0);

	bool InputVec(const char* label, int& v, ImGuiInputTextFlags flags = 0);
	bool InputVec(const char* label, glm::ivec2& v, ImGuiInputTextFlags flags = 0);
	bool InputVec(const char* label, glm::ivec3& v, ImGuiInputTextFlags flags = 0);
	bool InputVec(const char* label, glm::ivec4& v, ImGuiInputTextFlags flags = 0);


	bool InputVec(const char* label, double& v, const char* format = "%.6f", ImGuiInputTextFlags flags = 0);
	bool InputVec(const char* label, glm::dvec2& v, const char* format = "%.6f", ImGuiInputTextFlags flags = 0);
	bool InputVec(const char* label, glm::dvec3& v, const char* format = "%.6f", ImGuiInputTextFlags flags = 0);
	bool InputVec(const char* label, glm::dvec4& v, const char* format = "%.6f", ImGuiInputTextFlags flags = 0);

	bool InputVec(const char* label, const double& v, const char* format = "%.6f", ImGuiInputTextFlags flags = 0);
	bool InputVec(const char* label, const glm::dvec2& v, const char* format = "%.6f", ImGuiInputTextFlags flags = 0);
	bool InputVec(const char* label, const glm::dvec3& v, const char* format = "%.6f", ImGuiInputTextFlags flags = 0);
	bool InputVec(const char* label, const glm::dvec4& v, const char* format = "%.6f", ImGuiInputTextFlags flags = 0);


	bool DragVec(const char* label, const float& v, float speed, float min, float max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
	bool DragVec(const char* label, const glm::vec2& v, float speed, float min, float max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
	bool DragVec(const char* label, const glm::vec3& v, float speed, float min, float max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
	bool DragVec(const char* label, const glm::vec4& v, float speed, float min, float max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);

	bool DragVec(const char* label, float& v, float speed, float min, float max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
	bool DragVec(const char* label, glm::vec2& v, float speed, float min, float max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
	bool DragVec(const char* label, glm::vec3& v, float speed, float min, float max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
	bool DragVec(const char* label, glm::vec4& v, float speed, float min, float max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);

	bool DragVec(const char* label, const int& v, float speed, int min, int max, const char* format = "%d", ImGuiSliderFlags flags = 0);
	bool DragVec(const char* label, const glm::ivec2& v, float speed, int min, int max, const char* format = "%d", ImGuiSliderFlags flags = 0);
	bool DragVec(const char* label, const glm::ivec3& v, float speed, int min, int max, const char* format = "%d", ImGuiSliderFlags flags = 0);
	bool DragVec(const char* label, const glm::ivec4& v, float speed, int min, int max, const char* format = "%d", ImGuiSliderFlags flags = 0);

	bool DragVec(const char* label, int& v, float speed, int min, int max, const char* format = "%d", ImGuiSliderFlags flags = 0);
	bool DragVec(const char* label, glm::ivec2& v, float speed, int min, int max, const char* format = "%d", ImGuiSliderFlags flags = 0);
	bool DragVec(const char* label, glm::ivec3& v, float speed, int min, int max, const char* format = "%d", ImGuiSliderFlags flags = 0);
	bool DragVec(const char* label, glm::ivec4& v, float speed, int min, int max, const char* format = "%d", ImGuiSliderFlags flags = 0);


	bool DragVec(const char* label, const double& v, float speed, double min, double max, const char* format = "%.6f", ImGuiSliderFlags flags = 0);
	bool DragVec(const char* label, const glm::dvec2& v, float speed, double min, double max, const char* format = "%.6f", ImGuiSliderFlags flags = 0);
	bool DragVec(const char* label, const glm::dvec3& v, float speed, double min, double max, const char* format = "%.6f", ImGuiSliderFlags flags = 0);
	bool DragVec(const char* label, const glm::dvec4& v, float speed, double min, double max, const char* format = "%.6f", ImGuiSliderFlags flags = 0);

	bool DragVec(const char* label, double& v, float speed, double min, double max, const char* format = "%.6f", ImGuiSliderFlags flags = 0);
	bool DragVec(const char* label, glm::dvec2& v, float speed, double min, double max, const char* format = "%.6f", ImGuiSliderFlags flags = 0);
	bool DragVec(const char* label, glm::dvec3& v, float speed, double min, double max, const char* format = "%.6f", ImGuiSliderFlags flags = 0);
	bool DragVec(const char* label, glm::dvec4& v, float speed, double min, double max, const char* format = "%.6f", ImGuiSliderFlags flags = 0);



	bool SliderVec(const char* label, const float& v, float min, float max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
	bool SliderVec(const char* label, const glm::vec2& v, float min, float max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
	bool SliderVec(const char* label, const glm::vec3& v, float min, float max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
	bool SliderVec(const char* label, const glm::vec4& v, float min, float max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);

	bool SliderVec(const char* label, float& v, float min, float max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
	bool SliderVec(const char* label, glm::vec2& v, float min, float max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
	bool SliderVec(const char* label, glm::vec3& v, float min, float max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
	bool SliderVec(const char* label, glm::vec4& v, float min, float max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);


	bool SliderVec(const char* label, const double& v, double min, double max, const char* format = "%.6f", ImGuiSliderFlags flags = 0);
	bool SliderVec(const char* label, const glm::dvec2& v, double min, double max, const char* format = "%.6f", ImGuiSliderFlags flags = 0);
	bool SliderVec(const char* label, const glm::dvec3& v, double min, double max, const char* format = "%.6f", ImGuiSliderFlags flags = 0);
	bool SliderVec(const char* label, const glm::dvec4& v, double min, double max, const char* format = "%.6f", ImGuiSliderFlags flags = 0);

	bool SliderVec(const char* label, double& v, double min, double max, const char* format = "%.6f", ImGuiSliderFlags flags = 0);
	bool SliderVec(const char* label, glm::dvec2& v, double min, double max, const char* format = "%.6f", ImGuiSliderFlags flags = 0);
	bool SliderVec(const char* label, glm::dvec3& v, double min, double max, const char* format = "%.6f", ImGuiSliderFlags flags = 0);
	bool SliderVec(const char* label, glm::dvec4& v, double min, double max, const char* format = "%.6f", ImGuiSliderFlags flags = 0);

	bool SliderVec(const char* label, const int& v, int min, int max, const char* format = "%d", ImGuiSliderFlags flags = 0);
	bool SliderVec(const char* label, const glm::ivec2& v, int min, int max, const char* format = "%d", ImGuiSliderFlags flags = 0);
	bool SliderVec(const char* label, const glm::ivec3& v, int min, int max, const char* format = "%d", ImGuiSliderFlags flags = 0);
	bool SliderVec(const char* label, const glm::ivec4& v, int min, int max, const char* format = "%d", ImGuiSliderFlags flags = 0);

	bool SliderVec(const char* label, int& v, int min, int max, const char* format = "%d", ImGuiSliderFlags flags = 0);
	bool SliderVec(const char* label, glm::ivec2& v, int min, int max, const char* format = "%d", ImGuiSliderFlags flags = 0);
	bool SliderVec(const char* label, glm::ivec3& v, int min, int max, const char* format = "%d", ImGuiSliderFlags flags = 0);
	bool SliderVec(const char* label, glm::ivec4& v, int min, int max, const char* format = "%d", ImGuiSliderFlags flags = 0);
}