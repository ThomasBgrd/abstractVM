/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-florian.gibault
** File description:
** Bigdecimal
*/

#include "Bigdecimal.hpp"
#include <cmath>

Bigdecimal::Bigdecimal(const std::string &value)
{
    _value = std::stold(value);
}

Bigdecimal::~Bigdecimal()
{
}

std::string Bigdecimal::toString() const
{
    return std::to_string(_value);
}

eOperandType Bigdecimal::getType() const
{
    return eOperandType::BIGDECIMAL;
}

bool Bigdecimal::verifyOverflow(int value) const
{
    // if (value > Bigdecimal) {
    //     throw Error("Error: value overflow");
    // } else if (value < ) {
    //     throw Error("Error: value underflow");
    // }
    (void)value;
    return true;
}

IOperand *Bigdecimal::operator+(const IOperand &rhs) const
{
    // std::cout << "Bigdecimal + addition" << std::endl;
    if (rhs.getType() > BIGDECIMAL) {
        return rhs + *this;
    } else {
        auto value = std::stold(rhs.toString()) + _value;
        verifyOverflow(value);
        return new Bigdecimal(std::to_string(value));
    }
}

IOperand *Bigdecimal::operator-(const IOperand &rhs) const
{
    // std::cout << "Bigdecimal - substraction" << std::endl;
    if (rhs.getType() > BIGDECIMAL) {
        return rhs - *this;
    } else {
        auto value = std::stold(rhs.toString()) - _value;
        verifyOverflow(value);
        return new Bigdecimal(std::to_string(value));
    }
}

IOperand *Bigdecimal::operator*(const IOperand &rhs) const
{
    // std::cout << "Bigdecimal * multiplication" << std::endl;
    if (rhs.getType() > BIGDECIMAL) {
        return rhs * *this;
    } else {
        auto value = std::stold(rhs.toString()) * _value;
        verifyOverflow(value);
        return new Bigdecimal(std::to_string(value));
    }
}

IOperand *Bigdecimal::operator/(const IOperand &rhs) const
{
    // std::cout << "Bigdecimal / division" << std::endl;
    if (rhs.getType() > BIGDECIMAL) {
        return rhs / *this;
    } else {
        if (std::stold(rhs.toString()) == 0)
            throw Error("Error: division by 0");
        auto value = _value / std::stold(rhs.toString());
        return new Bigdecimal(std::to_string(value));
    }
}

IOperand *Bigdecimal::operator%(const IOperand &rhs) const
{
    throw Error("Error: Modulo on float");
}

const char *Bigdecimal::Error::what() const noexcept
{
    return this->message.c_str();
}
