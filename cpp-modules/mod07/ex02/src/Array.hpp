#ifndef ARRAY_HPP
# define ARRAY_HPP

template<class T>
class Array {
 private:
  unsigned int size_;
  T *data_;

 public:
  Array();
  explicit Array(const unsigned int n);
  ~Array();
  Array(const Array& other);
  Array& operator=(const Array& other);

  unsigned int size() const;
  T& operator[](const unsigned int idx);
  const T& operator[](const unsigned int idx) const ;

  class IndexIsOutOfBoundsException : public std::exception {
      virtual const char *what() const throw();
  };
};

template<class T>
std::ostream& operator<<(std::ostream& lhs, const Array<T>& rhs);
// template<class T>
// std::ostream& operator<<(std::ostream& lhs, Array<T>& rhs);

# endif
