/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-florian.gibault
** File description:
** Double
*/

#ifndef BIGDECIMAL_HPP_
#define BIGDECIMAL_HPP_

#include "IOperand.hpp"

class Bigdecimal : public IOperand {
    public:
        class Error : public std::exception {
            public:
                Error(const std::string &message) {this->message = std::string(message);};
                ~Error() {};
                const char *what() const noexcept override;
            private:
                std::string message;
        };
        Bigdecimal(const std::string &value);
        ~Bigdecimal();
        std::string toString() const;
        eOperandType getType() const;
        bool verifyOverflow(int value) const;
        IOperand *operator+(const IOperand &rhs) const;
        IOperand *operator-(const IOperand &rhs) const;
        IOperand *operator*(const IOperand &rhs) const;
        IOperand *operator/(const IOperand &rhs) const;
        IOperand *operator%(const IOperand &rhs) const;
    private:
        long double _value;
};

#endif /* !BIGDECIMAL_HPP_ */