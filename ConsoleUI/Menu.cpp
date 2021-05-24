#include <iostream>
#include <utility>

#include "Menu.h"
#include "Util/ConsoleState.h"



ConsoleUI::Menu::Menu(std::string_view  header, Options* options) :
	Navigation(),
	_header(header),
	_options(options),
	_state()
{
	// don't move this to initializer list - function has side effect!
	_setCurrentOptionsIndex(0);
}



void ConsoleUI::Menu::_reprint() const {
	ConsoleState::clear();
	_printHeader();
	_printMessage();
	_printCurrentOptions();
}



void ConsoleUI::Menu::_printHeader() const {
	std::cout << '\n' << _header << '\n';
	std::cout << std::endl;
}



void ConsoleUI::Menu::_printMessage() const {
	std::cout << _options[_state._currentOptionsIndex].getMessage();
}



void ConsoleUI::Menu::_printCurrentOptions() const {
	std::cout << std::endl;

	for (int i = 0; i < _options[_state._currentOptionsIndex].getLength();
             i++) {
		std::cout << ' ';
		if (_choice == i) {
			ConsoleState::setColor(ConsoleState::Color::Black, ConsoleState::Color::LightGray);
		}
    std::cout << "> " << _options[_state._currentOptionsIndex][i] << std::endl;
		ConsoleState::setColor(ConsoleState::Color::LightGray, ConsoleState::Color::Black);
	}

	std::cout << std::endl;
}



void ConsoleUI::Menu::startSelectionLoop() {
	while (true) {
		if (_choiceCount < 1) {
			throw std::invalid_argument("START_SELECTION_LOOP() FAULT: LESS THAN 1 OPTION PROVIDED");
		}

		_isSelecting = true;
		_reprint();
		_watchUserControl([this]() {
			_reprint();
		});

		// we will come here after ENTER pressed
    MENU_SECTION selectedOptionsIndex =
        _options[_state._currentOptionsIndex].invokeCallback(
            _choice, _state);

		if (static_cast<int>(selectedOptionsIndex) == -1) {
			return;
		}

		_setCurrentOptionsIndex(static_cast<int>(selectedOptionsIndex));
	}
}



void ConsoleUI::Menu::_setCurrentOptionsIndex(int i) {
	_state._currentOptionsIndex = i;
  _updateNavigationInfo(_options[_state._currentOptionsIndex]);
}
