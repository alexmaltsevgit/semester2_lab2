#pragma once

#include "Dict.h"
#include "stdexcept"


template<class Key, class Value>
class Dict {
private:
  Key* _keys;
  Value* _values;
  int _size;
  int _capacity;

private:
  void _push(const Key& key, const Value& value) {
    _keys[_size] = key;
    _values[_size] = value;
    _size++;
  }

  void _replace(int index, const Key& key, const Value& value) {
    _keys[index] = key;
    _values[index] = value;
  }

public:
  explicit Dict(int capacity) :
          _keys(new Key[capacity]{}),
          _values(new Value[capacity]{}),
          _capacity(capacity),
          _size(0) {}

  ~Dict() {
    delete[] _keys;
    delete[] _values;
  }

  int keyIndex(const Key& key) const {
    for (int i = 0; i < _size; i++) {
      if (key == _keys[i])
        return i;
    }
    return -1;
  }

  Key& keyByIndex(int index) const {
    if (index >= _size)
      throw (std::invalid_argument("keyByIndex ERROR: INDEX OUT OF BOUNDS"));
    return _keys[index];
  }

  void write(const Key& key, const Value& value) {
    int keyIdx = keyIndex(key);
    if (keyIdx == -1) {
      _push(key, value);
    } else {
      _replace(keyIdx, key, value);
    }
  }

  void write(Key&& key, Value&& value) {
    int keyIdx = keyIndex(key);
    if (keyIdx == -1) {
      _push(std::move(key), std::move(value));
    } else {
      _replace(keyIdx, std::move(key), std::move(value));
    }
  }

  int size() const {
    return _size;
  }

  Value& operator[](const Key& key) const {
    for (int i = 0; i < _size; ++i) {
      if (_keys[i] == key) {
        return _values[i];
      }
    }
    throw (std::invalid_argument("Dict::operator[](key) ERROR: KEY WAS NOT FOUND"));
  }

  void debug() {
    for (int i = 0; i < _size; i++) {
      std::cout << "K: " << _keys[i] << " -------- V: " << _values[i] << "\n";
    }
  }
};
