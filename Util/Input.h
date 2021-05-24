#pragma once
#include <iostream>
#include <string>
#include <limits>

class Input {
private:
  static inline std::string errorMessage = "INPUT ERROR";

public:
	template<typename T>
	static T* read(int inputCount, std::istream& in = std::cin) {
    T* inputs = new T[inputCount]{};

    for (int i = 0; i < inputCount; i++) {
      in >> inputs[i];
      if (in.fail()) {
        in.clear();
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw (std::runtime_error(errorMessage));
      }
      in.clear();
    }

    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return inputs;
	}

  template<typename T>
	static T readOne(std::istream& in = std::cin) {
	  T value = 0;
    in >> value;

    if (in.fail()) {
      in.clear();
      in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      throw (std::runtime_error(errorMessage));
    }

    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
	}
};
