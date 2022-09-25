#ifndef SPAN_HPP
# define SPAN_HPP

#include <set>
#include <climits>

class Span {
 private:
  typedef unsigned int                               size_type;
  typedef int                                        value_type;
  typedef std::multiset<Span::value_type>::iterator  iterator;
  static const size_type kSizeMax = UINT_MAX;
  static const size_type kSizeMin = 0;
  size_type N_;
  std::multiset<value_type> data_;

  void checkLegalSize();

 public:
  Span();
  explicit Span(size_type N);
  ~Span();
  Span(const Span& other);
  Span& operator=(const Span& other);

  void addNumber(value_type n);
  template<typename Iterator>
  void addNumbers(Iterator begin , Iterator end) {
    for (; begin != end; begin++) {
      data_.insert(*begin);
    }
  }
  size_type shortestSpan();
  size_type longestSpan();
};

#endif
