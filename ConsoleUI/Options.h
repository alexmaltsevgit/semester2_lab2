#pragma once

#include <functional>
#include <string>

#include "State.h"

namespace ConsoleUI {

	// Returned value - index of the options we have to display
	using Callback = std::function<MENU_SECTION(State& state)>;

	class Options {
	private:
		const int _length;
		const std::string* _items;
		const Callback* _callbacks;
		const std::string _message;

	public:
		Options(int length, const std::string* options, const Callback* callbacks, std::string message = "");

		int getLength() const;
		std::string getMessage() const;

		MENU_SECTION invokeCallback(int i, State& state) const;

		std::string operator[] (int i) const;
	};

}
