#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <exception>

class Bureaucrat {
 private:
    static const int kMaxGrade = 1;
    static const int kMinGrade = 150;
    const std::string name_;
    int grade_;

    Bureaucrat();
    bool isGradeTooHigh();
    bool isGradeTooLow();

 public:
    explicit Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);

    const std::string &getName() const;
    int getGrade() const;
    void increGrade();
    void decreGrade();
    class GradeTooHighException : public std::exception {
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& lhs, const Bureaucrat& rhs);

#endif
