#include "Span.hpp"

#include <iostream>
#include <stdexcept>

Span::Span() {}

Span::Span(size_type N) : N_(N) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
  if (this == &other) return *this;

  this->N_ = other.N_;
  this->data_ = other.data_;
  return *this;
}

Span::Span(const Span& other) {
  *this = other;
}

void Span::addNumber(Span::value_type n) {
  if (data_.size() == N_) {
    throw std::logic_error("Span is full");
  }
  data_.insert(n);
}

void Span::checkLegalSize() {
  if (data_.size() == 0 || data_.size() == 1) {
    throw std::logic_error("size is too small");
  }
}

Span::size_type Span::shortestSpan() {
  checkLegalSize();

  Span::iterator head = data_.begin(), end = data_.end();
  Span::iterator prev = head;
  size_type min = kSizeMax;

  for (Span::iterator itr = ++head; itr != end; itr++) {
    if (min > static_cast<Span::size_type>(*itr - *prev)) {
      min = static_cast<Span::size_type>(*itr - *prev);
    }
    prev = itr;
  }
  return min;
}

Span::size_type Span::longestSpan() {
  checkLegalSize();

  Span::iterator start = data_.begin(), end = data_.end();
  end--;

  return static_cast<size_type>(*end - *start);
}
