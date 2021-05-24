#pragma once

#include <iostream>
#include <Util/Input.h>
#include "Dict.h"

template<class T>
class Array {
private:
  T* _elements;
  int _size;

public:
  Array() = default;

  Array(int size) :
    _elements(new T[size]()),
    _size(size)
  {}

  Array(Array<T>&& other) :
    Array(other._size)
  {
    for (int i = 0; i < _size; i++) {
      _elements[i] = other._elements[i];
    }
  }

  Array(std::initializer_list<T> args) :
    Array(args.size())
  {
    // initialize with zeros
    if (args.size() == 0) {
      return;
    }

    int i = 0;
    for (const auto& itemptr : args) {
      _elements[i] = itemptr;
      i++;
    }
  }

  ~Array() { delete[] _elements; }

  T findMostFrequentElement() const {
    Dict<T, int> dict{_size};
    for (int i = 0; i < _size; ++i) {
      T currentElement = _elements[i];
      if (dict.keyIndex(currentElement) == -1) {
        dict.write(currentElement, 1);
      } else {
        dict[currentElement] += 1;
      }
    }

    T maxElement = dict.keyByIndex(0);
    for (int i = 0; i < dict.size(); ++i) {
      T currentElement = dict.keyByIndex(i);
      if (dict[currentElement] > dict[maxElement]) {
        maxElement = currentElement;
      }
    }

    return maxElement;
  }

  int size() const { return _size; }

  T& operator[](int i) const { return _elements[i]; }

  template<int s, typename Type>
  friend std::ostream& operator<< (std::ostream& out, const Array<Type>& arr);

  template<int s, typename Type>
  friend std::istream& operator>>(std::istream& in, Array<Type>& arr);

  T* begin() const { return _elements; }
  T* end() const { return _elements + _size; }
};


template<typename Type>
std::ostream& operator<<(std::ostream& out, const Array<Type>& arr) {
  out << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    out << arr[i];
    if (i != arr.size() - 1)
      out << ", ";
  }
  out << " ]";
  return out;
}


template<typename Type>
std::istream& operator>>(std::istream& in, Array<Type>& arr) {
  try {
    Type* elements = Input::read<Type>(arr.size(), in);
  } catch (std::runtime_error& e) {
    throw e;
  }

  for (int i = 0; i < arr.size(); i++) {
    arr[i] = elements[i];
  }

  delete[] elements;

  return in;
}
