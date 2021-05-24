#include "Options.h"

#include <utility>

ConsoleUI::Options::Options(int length, const std::string* options, const Callback* callbacks, std::string message) :
	_length(length),
	_items(options),
	_callbacks(callbacks),
	_message(std::move(message))
{}

int ConsoleUI::Options::getLength() const {
	return _length;
}

std::string ConsoleUI::Options::getMessage() const {
	return _message;
}

MENU_SECTION ConsoleUI::Options::invokeCallback(int i, State& state) const {
	return _callbacks[i](state);
}

std::string ConsoleUI::Options::operator[](int i) const {
	return _items[static_cast<int>(i)];
}
