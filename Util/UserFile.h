#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#include "Util/ConsoleState.h"


class UserFile {
private:
	static bool _isRegularFile(const std::filesystem::path& path) {
		try {
			return std::filesystem::is_regular_file(path);
		} catch (std::exception&) {
			return false;
		}
	}
	
	static std::string _initInput() {
		namespace fs = std::filesystem;

		std::string tmp = {};

		std::cout << " Введите абсолютный или относительный путь к файлу\n";
		std::cout << " Текущий путь: " << fs::current_path() << '\n' << std::endl;
		std::getline(std::cin, tmp);

		return tmp;
	}

	static std::string _retryAfterInvalidInput() {
		namespace fs = std::filesystem;

		std::string tmp = {};

		std::cout << "\n Некорректный путь к файлу. Попробуйте снова:" << std::endl;
		std::getline(std::cin, tmp);

		return tmp;
	}

	static std::filesystem::path _getPath() {
		namespace fs = std::filesystem;

		std::string tmp = _initInput();
		if (tmp == "0")
			return "";

		fs::path path = tmp;

		while (!_isRegularFile(path)) {
			tmp = _retryAfterInvalidInput();
			if (tmp == "0")
				return "";

			path = tmp;
		}

		return path;
	}

	static void _onSuccess(const std::filesystem::path& path) {
		namespace fs = std::filesystem;

		ConsoleState::setColor(ConsoleState::Color::Green, ConsoleState::Color::Black);
		std::cout <<
			"\n Файл открыть успешно!.\n" \
			" Текущий путь  ---  " << fs::canonical(fs::absolute(path)) << std::endl;
		ConsoleState::setColor(ConsoleState::Color::White, ConsoleState::Color::Black);
	}

	static void _onFail() {
		ConsoleState::setColor(ConsoleState::Color::Red, ConsoleState::Color::Black);
		std::cout << "\n Ошибка открытия файла, проверьте свойства файла." << std::endl;
		ConsoleState::setColor(ConsoleState::Color::White, ConsoleState::Color::Black);
	}

public:
	static std::fstream* get(std::ios_base::openmode mode) {
		namespace fs = std::filesystem;

		auto* fileStream = new std::fstream;
		fs::path path = _getPath();

		if (path == "")
			return 0;

		fileStream->open(path, mode);
		if (fileStream->is_open()) {
			_onSuccess(path);
		} else {
			_onFail();
		}

		return fileStream;
	}

	static void close(std::ostream* file) {
		if (file != &std::cout) {
			dynamic_cast<std::fstream*>(file)->close();
		}
	}

	static void close(std::istream* file) {
		if (file != &std::cin) {
			dynamic_cast<std::fstream*>(file)->close();
		}
	}
};