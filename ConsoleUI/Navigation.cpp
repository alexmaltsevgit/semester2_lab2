#include <conio.h> // for _getch()
#include <functional>

#include "Navigation.h"
#include "Util/ConsoleState.h"


void ConsoleUI::Navigation::_updateNavigationInfo(const Options& opt) {
	_choice = 0;
	_choiceCount = opt.getLength();
	_isSelecting = false;
	_isUpdated = false;
}



void ConsoleUI::Navigation::_watchUserControl(const std::function<void (void)>& onUpdate) {
	while (_isSelecting) {
		switch (_getch()) {
		case KEY_UP:
			if (_choice > 0) {
				_choice--;
				_isUpdated = true;
			}
			break;

		case KEY_DOWN:
			if (_choice < _choiceCount - 1) {
				_choice++;
				_isUpdated = true;
			}
			break;

		case KEY_ENTER:
			ConsoleState::clear();
			_isSelecting = false;
			break;

		default:
			break;
		}


		if (_isUpdated) {
			onUpdate();
			_isUpdated = false;
		}
	}
}
