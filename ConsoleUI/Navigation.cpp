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
    int key = _getch();
		switch (key) {
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

		// interpret as 1-9 digit
		default:
			key = key - static_cast<int>('0');
			if (key >= 1 && key <= _choiceCount) {
				_choice = key - 1;
				ConsoleState::clear();
				_isSelecting = false;
			}
			break;
		}

		if (_isUpdated) {
			onUpdate();
			_isUpdated = false;
		}
  }
}
