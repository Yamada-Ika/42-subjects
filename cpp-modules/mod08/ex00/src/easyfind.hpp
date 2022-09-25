#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

template <class T>
typename T::const_iterator easyfind(const T &v, int val) {
  return std::find(v.begin(), v.end(), val);
}

template <class T>
typename T::iterator easyfind(T &v, int val) {
  return std::find(v.begin(), v.end(), val);
}

#endif
