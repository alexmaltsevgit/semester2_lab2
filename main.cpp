#include "Options/allOptions.h"

int main() {
  std::string header =
          "\tЛабораторная работа №2\n" \
          "\tВариант 9\n" \
          "\tМальцев Александр";

	ConsoleUI::Menu menu(header, opt::allOptions);
	menu.startSelectionLoop();

	return 0;
}
