#pragma once

#include "Algorithm/Algorithm.h"
#include "Util/ConsoleState.h"
#include "cases.h"


class Test {
private:
	const TestSuite<int>* _suites = Tcase::suites;

private:
	static void _alertGoodResult(int suiteCount) {
		ConsoleState::setColor(ConsoleState::Color::Green, ConsoleState::Color::Black);
		std::cout << ' ' << suiteCount << '.' << " Тест пройден.\n";
		ConsoleState::setColor(ConsoleState::Color::LightGray, ConsoleState::Color::Black);
	}

	static void _alertBadResult(int suiteCount, int result, int expected) {
		ConsoleState::setColor(ConsoleState::Color::Red, ConsoleState::Color::Black);
		std::cout << ' ' << suiteCount << '.' << " Ошибка. Ожидаемый результат: ";
		Algorithm::printResult(expected, std::cout);
		std::cout << "   " << " Полученный результат: ";
		Algorithm::printResult(result, std::cout);
		ConsoleState::setColor(ConsoleState::Color::LightGray, ConsoleState::Color::Black);
	}

public:
	void runTest() {
		std::cout << "\n\tТЕСТИРОВАНИЕ\n" << std::endl;

		for (int i = 0; i < TESTS_COUNT; i++) {
		const TestSuite<int>& currentSuite = _suites[i];
			int result = currentSuite.array.findMostFrequentElement();
			if (result == currentSuite.result) {
				_alertGoodResult(i + 1);
			} else {
				_alertBadResult(i + 1, result, currentSuite.result);
			}
		}

		std::cout << '\n' << std::endl;
	}
};
