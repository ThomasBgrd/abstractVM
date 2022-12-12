/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-florian.gibault
** File description:
** Int32
*/

#ifndef INT32_HPP_
#define INT32_HPP_

#include "IOperand.hpp"

class Int32 : public IOperand {
    public:
        class Error : public std::exception {
            public:
                Error(const std::string &message) {this->message = std::string(message);};
                ~Error() {};
                const char *what() const noexcept override;
            private:
                std::string message;
        };
        Int32(const std::string &value);
        ~Int32();
        std::string toString() const;
        eOperandType getType() const;
        bool verifyOverflow(int value) const;
        IOperand *operator+(const IOperand &rhs) const;
        IOperand *operator-(const IOperand &rhs) const;
        IOperand *operator*(const IOperand &rhs) const;
        IOperand *operator/(const IOperand &rhs) const;
        IOperand *operator%(const IOperand &rhs) const;
    private:
        int32_t _value;
};

#endif /* !INT32_HPP_ */
