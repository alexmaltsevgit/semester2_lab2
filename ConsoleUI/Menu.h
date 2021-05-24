#pragma once
#include <string>
#include <functional>

#include "Navigation.h"
#include "State.h"


namespace ConsoleUI {

	class Menu : private Navigation {
	private:
		const std::string_view _header;
		const Options* _options;

		State _state;

	private:
		void _setCurrentOptionsIndex(int i);

		void _reprint() const;
		void _printHeader() const;
		void _printMessage() const;
		void _printCurrentOptions() const;

	public:
		Menu(std::string_view workName, Options* options);

		void startSelectionLoop();
	};

}
