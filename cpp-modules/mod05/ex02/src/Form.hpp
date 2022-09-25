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
    const int grade_to_sign_;
    const int grade_to_execute_;
    bool is_signed_;

    bool isGradeTooHigh(int grade);
    bool isGradeTooLow(int grade);

 public:
    explicit Form(const std::string name, int grade_to_sign, int grade_to_execute);
    virtual ~Form(void);
    Form(const Form& other);
    Form& operator=(const Form& other);

    const std::string &getName(void) const;
    int getGradeToSign(void) const;
    int getGradeToExec(void) const;
    void beSigned(const Bureaucrat& b);
    virtual void execute(Bureaucrat const & executor) const = 0;
    bool getIsSigned(void) const;
    bool canSign(const Bureaucrat& b) const;
    bool canExec(const Bureaucrat& b) const;

    class GradeTooHighException : public std::exception {
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        virtual const char* what() const throw();
    };
    class AlreadyBeSigedException : public std::exception {
        virtual const char* what() const throw();
    };
    class NotSignedException : public std::exception {
        virtual const char* what() const throw();
    };
    class CannotSignedException : public std::exception {
        virtual const char* what() const throw();
    };
    class CannotExecException : public std::exception {
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& lhs, const Form& rhs);

#endif
