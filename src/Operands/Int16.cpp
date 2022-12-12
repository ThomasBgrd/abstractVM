/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-florian.gibault
** File description:
** Int16
*/

#include "Int16.hpp"

Int16::Int16(const std::string &value)
{
    verifyOverflow(std::stoi(value));
    _value = std::stoi(value);
}

Int16::~Int16()
{
}

std::string Int16::toString() const
{
    return std::to_string(_value);
}

eOperandType Int16::getType() const
{
    return eOperandType::INT16;
}

bool Int16::verifyOverflow(int value) const
{
    if (value > INT16_MAX) {
        throw Error("Error: value overflow");
    } else if (value < INT16_MIN) {
        throw Error("Error: value underflow");
    }
    return true;
}

IOperand *Int16::operator+(const IOperand &rhs) const
{
    // std::cout << "Int16 + addition" << std::endl;
    if (rhs.getType() > INT16) {
        return rhs + *this;
    } else {
        auto value = std::stoi(rhs.toString()) + _value;
        verifyOverflow(value);
        return new Int16(std::to_string(value));
    }
}

IOperand *Int16::operator-(const IOperand &rhs) const
{
    // std::cout << "Int16 - substraction" << std::endl;
    if (rhs.getType() > INT16) {
        return rhs - *this;
    } else {
        auto value = std::stoi(rhs.toString()) - _value;
        verifyOverflow(value);
        return new Int16(std::to_string(value));
    }
}

IOperand *Int16::operator*(const IOperand &rhs) const
{
    // std::cout << "Int16 * multiplication" << std::endl;
    if (rhs.getType() > INT16) {
        return rhs * *this;
    } else {
        auto value = std::stoi(rhs.toString()) * _value;
        verifyOverflow(value);
        return new Int16(std::to_string(value));
    }
}

IOperand *Int16::operator/(const IOperand &rhs) const
{
    // std::cout << "Int16 / division" << std::endl;
    if (rhs.getType() > INT16) {
        return rhs / *this;
    } else {
        if (std::stoi(rhs.toString()) == 0)
            throw Error("Error: division by 0");
        auto value = _value / std::stoi(rhs.toString());
        return new Int16(std::to_string(value));
    }
}

IOperand *Int16::operator%(const IOperand &rhs) const
{
    // std::cout << "Int16 % modulo" << std::endl;
    if (rhs.getType() > INT16) {
        return rhs % *this;
    } else {
        if (_value == 0)
            throw Error("Error: Modulo by 0");
        auto value = std::stoi(rhs.toString()) % _value;
        return new Int16(std::to_string(value));
    }
}

const char *Int16::Error::what() const noexcept
{
    return this->message.c_str();
}
