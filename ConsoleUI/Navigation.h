#pragma once

#include "Options.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER '\r'

namespace ConsoleUI {

	class Navigation {
	protected:
		int _choice = 0;							// current choice
		int _choiceCount = 0;					// number of choices

		bool _isSelecting = false;		// flag for selection loop
		bool _isUpdated = false;			// flag for update loop

	protected:
		void _watchUserControl(const std::function<void(void)>& onUpdate);
		void _updateNavigationInfo(const Options& opt);
	};

}
