#include <pch.h>
#include "injected.h"

namespace IJ {

	void OnAttach(HMODULE hModule) {
		std::cout << "Here I am" << std::endl;

	}

	void OnDetach(HMODULE hModule) {

	}
}