#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {
 private:
    static const int kNumberOfIdeas = 100;
    std::string ideas_[kNumberOfIdeas];

 public:
    Brain(void);
    Brain(const Brain& other);
    ~Brain(void);
    Brain& operator=(const Brain& other);
};

#endif
