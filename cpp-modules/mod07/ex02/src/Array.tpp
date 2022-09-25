#include "Array.hpp"
#include <iostream>

template<class T>
Array<T>::Array() : size_(0), data_(new T[0]) {
  data_[0] = T();
}

template<class T>
Array<T>::Array(const unsigned int n) : size_(n), data_(new T[n]) {
  for (unsigned int i = 0; i < n; ++i) {
    data_[i] = T();
  }
}

template<class T>
Array<T>::~Array() {
  delete [] data_;
}

template<class T>
Array<T>& Array<T>::operator=(const Array& other) {
  if (this == &other) return *this;

  T *tmp = new T[other.size_];
  delete [] this->data_;
  this->data_ = tmp;
  this->size_ = other.size_;
  for (unsigned int i = 0; i < other.size_; i++) {
    this->data_[i] = other.data_[i];
  }
  return *this;
}

template<class T>
Array<T>::Array(const Array& other) : data_(NULL) {
  *this = other;
}

template<class T>
T& Array<T>::operator[](const unsigned int idx) {
  if (idx >= size_) {
    throw IndexIsOutOfBoundsException();
  }
  return data_[idx];
}

template<class T>
const T& Array<T>::operator[](const unsigned int idx) const {
  if (idx >= size_) {
    throw IndexIsOutOfBoundsException();
  }
  return data_[idx];
}

template<class T>
unsigned int Array<T>::size() const {
  return size_;
}

template<class T>
std::ostream& operator<<(std::ostream& lhs, const Array<T>& rhs) {
  unsigned int size = rhs.size();
  for (unsigned int i = 0; i < size; i++) {
    lhs << "Array[" << i << "] = " << rhs[i] << "\n";
  }
  return lhs;
}

// template<class T>
// std::ostream& operator<<(std::ostream& lhs, Array<T>& rhs) {
//   unsigned int size = rhs.size();
//   for (unsigned int i = 0; i < size; i++) {
//     lhs << "Array[" << i << "] = " << rhs[i] << "\n";
//   }
//   return lhs;
// }

template<class T>
const char *Array<T>::IndexIsOutOfBoundsException::what() const throw() {
  return "IndexIsOutOfBoundsException";
}
