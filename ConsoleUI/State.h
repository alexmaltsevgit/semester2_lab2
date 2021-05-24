#pragma once

#include <iostream>
#include "Options/menuSectionCodes.h"


namespace ConsoleUI {

  enum class InputMode {
    STD,
    FILE,
    RANDOM
  };

	class State {
  friend class Menu;

	private:
		int _currentOptionsIndex = 0;

	public:
		std::istream* input = &std::cin;
		std::ostream* output = &std::cout;
    InputMode inputMode = InputMode::STD;
    int randomArraySize = 0; // random array, not random size
	};

}