#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <exception>

class Bureaucrat;

class Form {
 private:
    static const int kMaxGrade = 1;
    static const int kMinGrade = 150;
    const std::string name_;
    bool is_signed_;
    const int grade_to_sign_;
    const int grade_to_execute_;

    Form();
    bool isGradeTooHigh(int grade);
    bool isGradeTooLow(int grade);

 public:
    explicit Form(const std::string name, int grade_to_sign, int grade_to_execute);
    ~Form();
    Form(const Form& other);
    Form& operator=(const Form& other);

    const std::string &getName() const;
    void beSigned(const Bureaucrat& b);
    int getGradeToSign() const;
    int getGradeToExec() const;
    bool getIsSigned() const;

    class GradeTooHighException : public std::exception {
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        virtual const char* what() const throw();
    };
    class AlreadyBeSigedException : public std::exception {
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& lhs, const Form& rhs);

#endif
