/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-florian.gibault
** File description:
** Int16
*/

#ifndef INT16_HPP_
#define INT16_HPP_

#include "IOperand.hpp"

class Int16 : public IOperand {
    public:
        class Error : public std::exception {
            public:
                Error(const std::string &message) {this->message = std::string(message);};
                ~Error() {};
                const char *what() const noexcept override;
            private:
                std::string message;
        };
        Int16(const std::string &value);
        ~Int16();
        std::string toString() const;
        eOperandType getType() const;
        bool verifyOverflow(int value) const;
        IOperand *operator+(const IOperand &rhs) const;
        IOperand *operator-(const IOperand &rhs) const;
        IOperand *operator*(const IOperand &rhs) const;
        IOperand *operator/(const IOperand &rhs) const;
        IOperand *operator%(const IOperand &rhs) const;
    private:
        int16_t _value;
};

#endif /* !INT16_HPP_ */
