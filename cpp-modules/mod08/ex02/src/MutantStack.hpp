#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template < class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
 public:
  typedef Container                                        container_type;
  typedef typename container_type::value_type              value_type;
  typedef typename container_type::size_type               size_type;
  typedef typename container_type::reference               reference;
  typedef typename container_type::const_reference         const_reference;
  typedef typename container_type::iterator                iterator;
  typedef typename container_type::const_iterator          const_iterator;
  typedef typename container_type::reverse_iterator        reverse_iterator;
  typedef typename container_type::const_reverse_iterator  const_reverse_iterator;

  MutantStack() {}
  virtual ~MutantStack() {}
  MutantStack(const MutantStack& other) { *this = other; }
  MutantStack& operator=(const MutantStack& other) {
    (void)(other);
    return *this;
  }

  iterator               begin() { return this->c.begin(); }
  iterator               end()   { return this->c.end(); }
  const_iterator         begin() const { return this->c.begin(); }
  const_iterator         end() const { return this->c.end(); }
  reverse_iterator       rbegin() { return this->c.rbegin(); }
  reverse_iterator       rend() { return this->c.rend(); }
  const_reverse_iterator rbegin() const { return this->c.rbegin(); }
  const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
