#pragma once

#include "ConsoleUI/Menu.h"
#include "Util/UserFile.h"
#include "Util/Input.h"


namespace settingsOpt {

	const ConsoleUI::Callback callbacks[] = {

		// output
		[](ConsoleUI::State& state) {
			std::cout << std::endl <<
			  " Введите абсолютный или относительный путь к Вашему файлу\n" \
				" Вы можете ввести 0 чтобы вернуться в главное меню\n" \
				" Если файл не пуст, он будет дополнен текстом результата в конце" << std::endl;

			UserFile::close(state.output);

			state.output = UserFile::get(std::ios::app);
			state.output = state.output ? state.output : &std::cout;

			system("PAUSE");
			return MENU_SECTION::SETTINGS;
		},

		// input
		[](ConsoleUI::State& state) {
			std::cout << std::endl <<
        " Введите абсолютный или относительный путь к Вашему файлу\n" \
        " Первое, что должно быть написано в файле - размер массива"
				" Вы можете ввести 0 чтобы вернуться в главное меню" << std::endl;

			UserFile::close(state.input);

			state.input = UserFile::get(std::ios::in);
			if (state.input) {
			  state.inputMode = ConsoleUI::InputMode::FILE;
			} else {
        state.input = &std::cin;
        state.inputMode = ConsoleUI::InputMode::STD;
      }

			system("PAUSE");
			return MENU_SECTION::SETTINGS;
		},

		// random
		[](ConsoleUI::State& state) {
      std::cout << std::endl <<
        " Введите размер массива, который будет заполнен случайными числами\n" \
		    " Вы можете ввести 0 чтобы отменить действие" << std::endl;

      int size = Input::readOne<int>();
      while (size < 0) {
        std::cout << " Некорректный ввод. Повторите попытку:" << std::endl;
        size = Input::readOne<int>();
      }

      if (size > 0) {
        state.inputMode = ConsoleUI::InputMode::RANDOM;
        state.randomArraySize = size;
      }

      return MENU_SECTION::SETTINGS;
		},

		// back
		[](ConsoleUI::State& state) {
			return MENU_SECTION::MAIN;
		}

	};

}
