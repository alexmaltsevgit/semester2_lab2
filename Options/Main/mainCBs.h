#pragma once

#include "ConsoleUI/Menu.h"
#include "Test/Test.h"
#include "Util/UserFile.h"



namespace mainOpt {

	const ConsoleUI::Callback callbacks[] = {

		// run algorithm
		[](ConsoleUI::State& state) {
			int size = 0;
			switch (state.inputMode) {
      case ConsoleUI::InputMode::STD:
			  std::cout << " Введите размер массива: ";
        size = Input::readOne<int>();
        while (size < 1) {
          std::cout << " Некорректный ввод. Повторите попытку:" << std::endl;
          size = Input::readOne<int>();
        }
        break;

      case ConsoleUI::InputMode::FILE:
        state.input->seekg(0);
        *(state.input) >> size;
        break;

      case ConsoleUI::InputMode::RANDOM:
        size = state.randomArraySize;
        break;
      }

      std::cout << '\n';
      Algorithm::runUserInteraction<double>(size, state);
			std::cout << std::endl;

			system("PAUSE");
			return MENU_SECTION::MAIN;
		},

		// run tests
		[](ConsoleUI::State& state) {
			Test test = {};
			test.runTest();

			system("PAUSE");
			return MENU_SECTION::MAIN;
		},

		// go to settings
		[](ConsoleUI::State& state) {
			return MENU_SECTION::SETTINGS;
		},

		// information
		[](ConsoleUI::State& state) {
			using std::cout, std::endl, std::string_view;

			cout << "\n\tИНФОРМАЦИЯ О РАБОТЕ\n";

			string_view name = " Александр Мальцев";
			string_view workName = " Лабораторная работа №2";
			int variant = 9;
			string_view taskDescription = " Напишите программу, находящую в массиве значение, встречающееся чаще всего.";

			cout << '\n' <<
				name << '\n' <<
				workName << '\n' <<
				" Вариант " << variant << '\n' <<
				taskDescription << '\n' << endl;

			system("PAUSE");
			return MENU_SECTION::MAIN;
		},

		// exit
		[](ConsoleUI::State& state) {
			UserFile::close(state.output);
			UserFile::close(state.input);

			return MENU_SECTION::EXIT;
		}

	};

}