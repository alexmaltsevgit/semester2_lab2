#pragma once

#include <ctime>
#include <ConsoleUI/State.h>
#include "Array.h"


class Algorithm {
private:
  template<typename T>
  static void _readFromConsole(Array<T>& array);

  template<typename T>
  static std::ostream& _printFooter(const Array<T>& array, const T& result, std::ostream& out);

  template<typename T>
  static std::ostream& _printUserData(const Array<T>& array, std::ostream& out);

  static void _fillRandom(Array<double>& array, int min, int max) {
    std::srand(std::time(nullptr));

    for (int i = 0; i < array.size(); ++i) {
      array[i] = rand() % (max - min) + min;
    }
  };

public:
  template<typename T>
  static std::ostream& printResult(const T& result, std::ostream& out);

  template<typename T>
  static void runUserInteraction(int arraySize, ConsoleUI::State& state);
};


template<typename T>
void Algorithm::_readFromConsole(Array<T>& array) {
  std::cout << " Введите массив (" << array.size() << " чисел):\n " << std::endl;
  std::cin >> array;
}


template<typename T>
std::ostream& Algorithm::_printUserData(const Array<T>& array, std::ostream& out) {
  out << " Исходный массив:\n";
  out << array;

  return out;
}


template<typename T>
std::ostream& Algorithm::_printFooter(const Array<T>& array, const T& result, std::ostream& out) {
  out << "\tВХОДНЫЕ ДАННЫЕ\n\n";
  _printUserData(array, out) << "\n\n";
  out << "\tРЕЗУЛЬТАТ:\n\n";
  printResult(result, out) << std::endl;

  return out;
}


template<typename T>
std::ostream& Algorithm::printResult(const T& result, std::ostream& out) {
  out << " Самое частое число в массиве - " <<
    result <<
    std:: endl;

  return out;
}


template<typename T>
void Algorithm::runUserInteraction(int arraySize, ConsoleUI::State& state) {
  Array<T> array(arraySize);
  constexpr double MIN_RAND = -5;
  constexpr double MAX_RAND = 5;

  switch (state.inputMode) {
    case ConsoleUI::InputMode::STD:
      _readFromConsole(array);
      break;

    case ConsoleUI::InputMode::FILE:
      *(state.input) >> array;
      break;

    case ConsoleUI::InputMode::RANDOM:
      _fillRandom(array, MIN_RAND, MAX_RAND);
      break;
  }

  T result = array.findMostFrequentElement();
  _printFooter(array, result, *(state.output));

  if (state.output != &std::cout)
    _printFooter(array, result, std::cout);
}
