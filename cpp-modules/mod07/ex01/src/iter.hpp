#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void iter(T *arr, const size_t len, void (&func)(const T &e)) {
  if (arr == NULL) return;

  for (size_t i = 0; i < len; i++) {
    func(arr[i]);
  }
}

#endif
