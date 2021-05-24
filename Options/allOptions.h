#pragma once

#include "Options/Main/mainOptions.h"
#include "Options/Settings/settingsOptions.h"


namespace opt {

	ConsoleUI::Options allOptions[] = {
		mainOpt::options,
		settingsOpt::options
	};

}