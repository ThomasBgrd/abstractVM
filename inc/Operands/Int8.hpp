/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-florian.gibault
** File description:
** Int8
*/

#ifndef INT8_HPP_
#define INT8_HPP_

#include "IOperand.hpp"

class Int8 : public IOperand {
    public:
        class Error : public std::exception {
            public:
                Error(const std::string &message) {this->message = std::string(message);};
                ~Error() {};
                const char *what() const noexcept override;
            private:
                std::string message;
        };
        Int8(const std::string &value);
        ~Int8();
        std::string toString() const;
        eOperandType getType() const;
        bool verifyOverflow(int value) const;
        IOperand *operator+(const IOperand &rhs) const;
        IOperand *operator-(const IOperand &rhs) const;
        IOperand *operator*(const IOperand &rhs) const;
        IOperand *operator/(const IOperand &rhs) const;
        IOperand *operator%(const IOperand &rhs) const;
    private:
        int8_t _value;
};

#endif /* !INT8_HPP_ */
