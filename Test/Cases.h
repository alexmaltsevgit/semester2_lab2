#pragma once

#include <utility>

#include "Algorithm/Algorithm.h"

#define TESTS_COUNT 5


template<typename T>
class TestSuite {
	friend class Test;

private:
	Array<T> array;
	T result;

public:
  TestSuite(Array<T>&& array, T&& result) :
    array(std::move(array)),
    result(std::move(result))
  {}
};



namespace Tcase {

	const TestSuite<int> suites[TESTS_COUNT] = {

		TestSuite {
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
            1
      },

		TestSuite {
            {1, 1, 1, 2, 2, 2, 2, 2},
            2
      },

		TestSuite {
            {6, 5, 6},
            6
      },

		TestSuite {
            {1000, 6000, 3, 3},
            3
      },

		TestSuite {
            {5, 0, 0, 0, 0, 5},
            0
		  },

	};

}