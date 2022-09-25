#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void swap(T &n1, T &n2) {
  T tmp = n1;

  n1 = n2;
  n2 = tmp;
}

template<typename T>
const T& min(const T& a, const T& b) {
  return (a <= b) ? a : b;
}

template<typename T>
const T& max(const T& a, const T& b) {
  return (a >= b) ? a : b;
}

template<typename T>
T& min(T& a, T& b) {
  return (a <= b) ? a : b;
}

template<typename T>
T& max(T& a, T& b) {
  return (a >= b) ? a : b;
}

#endif
