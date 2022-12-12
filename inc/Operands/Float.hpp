/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-florian.gibault
** File description:
** Float
*/

#ifndef FLOAT_HPP_
#define FLOAT_HPP_

#include "IOperand.hpp"

class Float : public IOperand {
    public:
        class Error : public std::exception {
            public:
                Error(const std::string &message) {this->message = std::string(message);};
                ~Error() {};
                const char *what() const noexcept override;
            private:
                std::string message;
        };
        Float(const std::string &value);
        ~Float();
        std::string toString() const;
        eOperandType getType() const;
        bool verifyOverflow(int value) const;
        IOperand *operator+(const IOperand &rhs) const;
        IOperand *operator-(const IOperand &rhs) const;
        IOperand *operator*(const IOperand &rhs) const;
        IOperand *operator/(const IOperand &rhs) const;
        IOperand *operator%(const IOperand &rhs) const;
    private:
        float _value;
};

#endif /* !FLOAT_HPP_ */
