#include <ez/imgui/VecFunctions.hpp>

namespace ImGui {
	bool InputVec(const char* label, const float& v, const char* format, ImGuiInputTextFlags flags) {
		float arr[1]{ v };
		flags |= ImGuiInputTextFlags_CharsScientific;
		return InputScalar(label, ImGuiDataType_Float, (void*)arr, NULL, NULL, format, flags);
	}
	bool InputVec(const char* label, const glm::vec2& v, const char* format, ImGuiInputTextFlags flags) {
		float arr[2]{ v.x, v.y };
		return InputFloat2(label, arr, format, flags);
	}
	bool InputVec(const char* label, const glm::vec3& v, const char* format, ImGuiInputTextFlags flags) {
		float arr[3]{ v.x, v.y, v.z };
		return InputFloat3(label, arr, format, flags);
	}
	bool InputVec(const char* label, const glm::vec4& v, const char* format, ImGuiInputTextFlags flags) {
		float arr[4]{ v.x, v.y, v.z, v.w };
		return InputFloat4(label, arr, format, flags);
	}

	bool InputVec(const char* label, float& v, const char* format, ImGuiInputTextFlags flags) {
		flags |= ImGuiInputTextFlags_CharsScientific;
		return InputScalar(label, ImGuiDataType_Float, (void*)&v, NULL, NULL, format, flags);
	}
	bool InputVec(const char* label, glm::vec2& v, const char* format, ImGuiInputTextFlags flags) {
		return InputFloat2(label, &v.x, format, flags);
	}
	bool InputVec(const char* label, glm::vec3& v, const char* format, ImGuiInputTextFlags flags) {
		return InputFloat3(label, &v.x, format, flags);
	}
	bool InputVec(const char* label, glm::vec4& v, const char* format, ImGuiInputTextFlags flags) {
		return InputFloat4(label, &v.x, format, flags);
	}


	bool InputVec(const char* label, const int& v, ImGuiInputTextFlags flags) {
		int arr[1]{ v };
		flags |= ImGuiInputTextFlags_CharsScientific;
		return InputScalar(label, ImGuiDataType_S32, (void*)arr, NULL, NULL, nullptr, flags);
	}
	bool InputVec(const char* label, const glm::ivec2& v, ImGuiInputTextFlags flags) {
		int arr[2]{ v.x, v.y };
		return InputInt2(label, arr, flags);
	}
	bool InputVec(const char* label, const glm::ivec3& v, ImGuiInputTextFlags flags) {
		int arr[3]{ v.x, v.y, v.z };
		return InputInt3(label, arr, flags);
	}
	bool InputVec(const char* label, const glm::ivec4& v, ImGuiInputTextFlags flags) {
		int arr[4]{ v.x, v.y, v.z, v.w };
		return InputInt4(label, arr, flags);
	}

	bool InputVec(const char* label, int& v, ImGuiInputTextFlags flags) {
		flags |= ImGuiInputTextFlags_CharsScientific;
		return InputScalar(label, ImGuiDataType_S32, (void*)&v, NULL, NULL, nullptr, flags);
	}
	bool InputVec(const char* label, glm::ivec2& v, ImGuiInputTextFlags flags) {
		return InputInt2(label, &v.x, flags);
	}
	bool InputVec(const char* label, glm::ivec3& v, ImGuiInputTextFlags flags) {
		return InputInt3(label, &v.x, flags);
	}
	bool InputVec(const char* label, glm::ivec4& v, ImGuiInputTextFlags flags) {
		return InputInt4(label, &v.x, flags);
	}



	bool InputVec(const char* label, double& v, const char* format, ImGuiInputTextFlags flags) {
		flags |= ImGuiInputTextFlags_CharsScientific;
		return InputScalar(label, ImGuiDataType_Double, &v, 0, 0, format, flags);
	}
	bool InputVec(const char* label, glm::dvec2& v, const char* format, ImGuiInputTextFlags flags) {
		flags |= ImGuiInputTextFlags_CharsScientific;
		return InputScalarN(label, ImGuiDataType_Double, &v.x, 2, 0, 0, format, flags);
	}
	bool InputVec(const char* label, glm::dvec3& v, const char* format, ImGuiInputTextFlags flags) {
		flags |= ImGuiInputTextFlags_CharsScientific;
		return InputScalarN(label, ImGuiDataType_Double, &v.x, 3, 0, 0, format, flags);
	}
	bool InputVec(const char* label, glm::dvec4& v, const char* format, ImGuiInputTextFlags flags) {
		flags |= ImGuiInputTextFlags_CharsScientific;
		return InputScalarN(label, ImGuiDataType_Double, &v.x, 4, 0, 0, format, flags);
	}

	bool InputVec(const char* label, const double& v, const char* format, ImGuiInputTextFlags flags) {
		double arr[1]{ v };
		flags |= ImGuiInputTextFlags_CharsScientific;
		return InputScalar(label, ImGuiDataType_Double, arr, 0, 0, format, flags);
	}
	bool InputVec(const char* label, const glm::dvec2& v, const char* format, ImGuiInputTextFlags flags) {
		double arr[2]{ v.x, v.y };
		flags |= ImGuiInputTextFlags_CharsScientific;
		return InputScalarN(label, ImGuiDataType_Double, arr, 2, 0, 0, format, flags);
	}
	bool InputVec(const char* label, const glm::dvec3& v, const char* format, ImGuiInputTextFlags flags) {
		double arr[3]{ v.x, v.y, v.z };
		flags |= ImGuiInputTextFlags_CharsScientific;
		return InputScalarN(label, ImGuiDataType_Double, arr, 3, 0, 0, format, flags);
	}
	bool InputVec(const char* label, const glm::dvec4& v, const char* format, ImGuiInputTextFlags flags) {
		double arr[4]{ v.x, v.y, v.z, v.w };
		flags |= ImGuiInputTextFlags_CharsScientific;
		return InputScalarN(label, ImGuiDataType_Double, arr, 4, 0, 0, format, flags);
	}



	bool DragVec(const char* label, const float& v, float speed, float min, float max, const char* format, ImGuiSliderFlags flags) {
		float arr[]{ v };
		return DragScalar(label, ImGuiDataType_Float, arr, speed, &min, &max, format, flags);
	}
	bool DragVec(const char* label, const glm::vec2& v, float speed, float min, float max, const char* format, ImGuiSliderFlags flags) {
		float arr[]{ v.x, v.y };
		return DragScalarN(label, ImGuiDataType_Float, arr, 2, speed, &min, &max, format, flags);
	}
	bool DragVec(const char* label, const glm::vec3& v, float speed, float min, float max, const char* format, ImGuiSliderFlags flags) {
		float arr[]{ v.x, v.y, v.z };
		return DragScalarN(label, ImGuiDataType_Float, arr, 3, speed, &min, &max, format, flags);
	}
	bool DragVec(const char* label, const glm::vec4& v, float speed, float min, float max, const char* format, ImGuiSliderFlags flags) {
		float arr[]{ v.x, v.y, v.z, v.w };
		return DragScalarN(label, ImGuiDataType_Float, arr, 4, speed, &min, &max, format, flags);
	}

	bool DragVec(const char* label, float& v, float speed, float min, float max, const char* format, ImGuiSliderFlags flags) {
		return DragScalar(label, ImGuiDataType_Float, &v, speed, &min, &max, format, flags);
	}
	bool DragVec(const char* label, glm::vec2& v, float speed, float min, float max, const char* format, ImGuiSliderFlags flags) {
		return DragScalarN(label, ImGuiDataType_Float, &v.x, 2, speed, &min, &max, format, flags);
	}
	bool DragVec(const char* label, glm::vec3& v, float speed, float min, float max, const char* format, ImGuiSliderFlags flags) {
		return DragScalarN(label, ImGuiDataType_Float, &v.x, 3, speed, &min, &max, format, flags);
	}
	bool DragVec(const char* label, glm::vec4& v, float speed, float min, float max, const char* format, ImGuiSliderFlags flags) {
		return DragScalarN(label, ImGuiDataType_Float, &v.x, 4, speed, &min, &max, format, flags);
	}



	bool DragVec(const char* label, const int& v, float speed, int min, int max, const char* format, ImGuiSliderFlags flags) {
		int arr[]{ v };
		return DragScalar(label, ImGuiDataType_S32, arr, speed, &min, &max, format, flags);
	}
	bool DragVec(const char* label, const glm::ivec2& v, float speed, int min, int max, const char* format, ImGuiSliderFlags flags) {
		int arr[]{ v.x, v.y };
		return DragScalarN(label, ImGuiDataType_S32, arr, 2, speed, &min, &max, format, flags);
	}
	bool DragVec(const char* label, const glm::ivec3& v, float speed, int min, int max, const char* format, ImGuiSliderFlags flags) {
		int arr[]{ v.x, v.y, v.z };
		return DragScalarN(label, ImGuiDataType_S32, arr, 3, speed, &min, &max, format, flags);
	}
	bool DragVec(const char* label, const glm::ivec4& v, float speed, int min, int max, const char* format, ImGuiSliderFlags flags) {
		int arr[]{ v.x, v.y, v.z, v.w };
		return DragScalarN(label, ImGuiDataType_S32, arr, 4, speed, &min, &max, format, flags);
	}

	bool DragVec(const char* label, int& v, float speed, int min, int max, const char* format, ImGuiSliderFlags flags) {
		return DragScalar(label, ImGuiDataType_S32, &v, speed, &min, &max, format, flags);
	}
	bool DragVec(const char* label, glm::ivec2& v, float speed, int min, int max, const char* format, ImGuiSliderFlags flags) {
		return DragScalarN(label, ImGuiDataType_S32, &v.x, 2, speed, &min, &max, format, flags);
	}
	bool DragVec(const char* label, glm::ivec3& v, float speed, int min, int max, const char* format, ImGuiSliderFlags flags) {
		return DragScalarN(label, ImGuiDataType_S32, &v.x, 3, speed, &min, &max, format, flags);
	}
	bool DragVec(const char* label, glm::ivec4& v, float speed, int min, int max, const char* format, ImGuiSliderFlags flags) {
		return DragScalarN(label, ImGuiDataType_S32, &v.x, 4, speed, &min, &max, format, flags);
	}



	bool DragVec(const char* label, const double& v, float speed, double min, double max, const char* format, ImGuiSliderFlags flags) {
		double arr[]{ v };
		return DragScalar(label, ImGuiDataType_Double, arr, speed, &min, &max, format, flags);
	}
	bool DragVec(const char* label, const glm::dvec2& v, float speed, double min, double max, const char* format, ImGuiSliderFlags flags) {
		double arr[]{ v.x, v.y };
		return DragScalarN(label, ImGuiDataType_Double, arr, 2, speed, &min, &max, format, flags);
	}
	bool DragVec(const char* label, const glm::dvec3& v, float speed, double min, double max, const char* format, ImGuiSliderFlags flags) {
		double arr[]{ v.x, v.y, v.z };
		return DragScalarN(label, ImGuiDataType_Double, arr, 3, speed, &min, &max, format, flags);
	}
	bool DragVec(const char* label, const glm::dvec4& v, float speed, double min, double max, const char* format, ImGuiSliderFlags flags) {
		double arr[]{ v.x, v.y, v.z, v.w };
		return DragScalarN(label, ImGuiDataType_Double, arr, 4, speed, &min, &max, format, flags);
	}

	bool DragVec(const char* label, double& v, float speed, double min, double max, const char* format, ImGuiSliderFlags flags) {
		return DragScalar(label, ImGuiDataType_Double, &v, speed, &min, &max, format, flags);
	}
	bool DragVec(const char* label, glm::dvec2& v, float speed, double min, double max, const char* format, ImGuiSliderFlags flags) {
		return DragScalarN(label, ImGuiDataType_Double, &v.x, 2, speed, &min, &max, format, flags);
	}
	bool DragVec(const char* label, glm::dvec3& v, float speed, double min, double max, const char* format, ImGuiSliderFlags flags) {
		return DragScalarN(label, ImGuiDataType_Double, &v.x, 3, speed, &min, &max, format, flags);
	}
	bool DragVec(const char* label, glm::dvec4& v, float speed, double min, double max, const char* format, ImGuiSliderFlags flags) {
		return DragScalarN(label, ImGuiDataType_Double, &v.x, 4, speed, &min, &max, format, flags);
	}



	bool SliderVec(const char* label, const float& v, float min, float max, const char* format, ImGuiSliderFlags flags) {
		float arr[]{ v };
		return SliderScalar(label, ImGuiDataType_Float, arr, &min, &max, format, flags);
	}
	bool SliderVec(const char* label, const glm::vec2& v, float min, float max, const char* format, ImGuiSliderFlags flags) {
		float arr[]{ v.x, v.y };
		return SliderScalarN(label, ImGuiDataType_Float, arr, 2, &min, &max, format, flags);
	}
	bool SliderVec(const char* label, const glm::vec3& v, float min, float max, const char* format, ImGuiSliderFlags flags) {
		float arr[]{ v.x, v.y, v.z };
		return SliderScalarN(label, ImGuiDataType_Float, arr, 3, &min, &max, format, flags);
	}
	bool SliderVec(const char* label, const glm::vec4& v, float min, float max, const char* format, ImGuiSliderFlags flags) {
		float arr[]{ v.x, v.y, v.z, v.w };
		return SliderScalarN(label, ImGuiDataType_Float, arr, 4, &min, &max, format, flags);
	}

	bool SliderVec(const char* label, float& v, float min, float max, const char* format, ImGuiSliderFlags flags) {
		return SliderScalar(label, ImGuiDataType_Float, &v, &min, &max, format, flags);
	}
	bool SliderVec(const char* label, glm::vec2& v, float min, float max, const char* format, ImGuiSliderFlags flags) {
		return SliderScalarN(label, ImGuiDataType_Float, &v.x, 2, &min, &max, format, flags);
	}
	bool SliderVec(const char* label, glm::vec3& v, float min, float max, const char* format, ImGuiSliderFlags flags) {
		return SliderScalarN(label, ImGuiDataType_Float, &v.x, 3, &min, &max, format, flags);
	}
	bool SliderVec(const char* label, glm::vec4& v, float min, float max, const char* format, ImGuiSliderFlags flags) {
		return SliderScalarN(label, ImGuiDataType_Float, &v.x, 4, &min, &max, format, flags);
	}



	bool SliderVec(const char* label, const double& v, double min, double max, const char* format, ImGuiSliderFlags flags) {
		double arr[]{ v };
		return SliderScalar(label, ImGuiDataType_Double, arr, &min, &max, format, flags);
	}
	bool SliderVec(const char* label, const glm::dvec2& v, double min, double max, const char* format, ImGuiSliderFlags flags) {
		double arr[]{ v.x, v.y };
		return SliderScalarN(label, ImGuiDataType_Double, arr, 2, &min, &max, format, flags);
	}
	bool SliderVec(const char* label, const glm::dvec3& v, double min, double max, const char* format, ImGuiSliderFlags flags) {
		double arr[]{ v.x, v.y, v.z };
		return SliderScalarN(label, ImGuiDataType_Double, arr, 3, &min, &max, format, flags);
	}
	bool SliderVec(const char* label, const glm::dvec4& v, double min, double max, const char* format, ImGuiSliderFlags flags) {
		double arr[]{ v.x, v.y, v.z, v.w };
		return SliderScalarN(label, ImGuiDataType_Double, arr, 4, &min, &max, format, flags);
	}

	bool SliderVec(const char* label, double& v, double min, double max, const char* format, ImGuiSliderFlags flags) {
		return SliderScalar(label, ImGuiDataType_Double, &v, &min, &max, format, flags);
	}
	bool SliderVec(const char* label, glm::dvec2& v, double min, double max, const char* format, ImGuiSliderFlags flags) {
		return SliderScalarN(label, ImGuiDataType_Double, &v.x, 2, &min, &max, format, flags);
	}
	bool SliderVec(const char* label, glm::dvec3& v, double min, double max, const char* format, ImGuiSliderFlags flags) {
		return SliderScalarN(label, ImGuiDataType_Double, &v.x, 3, &min, &max, format, flags);
	}
	bool SliderVec(const char* label, glm::dvec4& v, double min, double max, const char* format, ImGuiSliderFlags flags) {
		return SliderScalarN(label, ImGuiDataType_Double, &v.x, 4, &min, &max, format, flags);
	}


	bool SliderVec(const char* label, const int& v, int min, int max, const char* format, ImGuiSliderFlags flags) {
		int arr[]{ v };
		return SliderScalar(label, ImGuiDataType_S32, arr, &min, &max, format, flags);
	}
	bool SliderVec(const char* label, const glm::ivec2& v, int min, int max, const char* format, ImGuiSliderFlags flags) {
		int arr[]{ v.x, v.y };
		return SliderScalarN(label, ImGuiDataType_S32, arr, 2, &min, &max, format, flags);
	}
	bool SliderVec(const char* label, const glm::ivec3& v, int min, int max, const char* format, ImGuiSliderFlags flags) {
		int arr[]{ v.x, v.y, v.z };
		return SliderScalarN(label, ImGuiDataType_S32, arr, 3, &min, &max, format, flags);
	}
	bool SliderVec(const char* label, const glm::ivec4& v, int min, int max, const char* format, ImGuiSliderFlags flags) {
		int arr[]{ v.x, v.y, v.z, v.w };
		return SliderScalarN(label, ImGuiDataType_S32, arr, 4, &min, &max, format, flags);
	}

	bool SliderVec(const char* label, int& v, int min, int max, const char* format, ImGuiSliderFlags flags) {
		return SliderScalar(label, ImGuiDataType_S32, &v, &min, &max, format, flags);
	}
	bool SliderVec(const char* label, glm::ivec2& v, int min, int max, const char* format, ImGuiSliderFlags flags) {
		return SliderScalarN(label, ImGuiDataType_S32, &v.x, 2, &min, &max, format, flags);
	}
	bool SliderVec(const char* label, glm::ivec3& v, int min, int max, const char* format, ImGuiSliderFlags flags) {
		return SliderScalarN(label, ImGuiDataType_S32, &v.x, 3, &min, &max, format, flags);
	}
	bool SliderVec(const char* label, glm::ivec4& v, int min, int max, const char* format, ImGuiSliderFlags flags) {
		return SliderScalarN(label, ImGuiDataType_S32, &v.x, 4, &min, &max, format, flags);
	}
}