/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-florian.gibault
** File description:
** Int8
*/

#include "Int8.hpp"

Int8::Int8(const std::string &value)
{
    verifyOverflow(std::stoi(value));
    _value = std::stoi(value);
}

Int8::~Int8()
{
}

std::string Int8::toString() const
{
    return std::to_string(_value);
}

eOperandType Int8::getType() const
{
    return eOperandType::INT8;
}

bool Int8::verifyOverflow(int value) const
{
    if (value > INT8_MAX) {
        throw Error("Error: value overflow");
    } else if (value < INT8_MIN) {
        throw Error("Error: value underflow");
    }
    return true;
}

IOperand *Int8::operator+(const IOperand &rhs) const
{
    // std::cout << "Int8 + addition" << std::endl;
    if (rhs.getType() > INT8) {
        return rhs + *this;
    } else {
        auto value = std::stoi(rhs.toString()) + _value;
        verifyOverflow(value);
        return new Int8(std::to_string(value));
    }
}

IOperand *Int8::operator-(const IOperand &rhs) const
{
    // std::cout << "Int8 - substraction" << std::endl;
    if (rhs.getType() > INT8) {
        return rhs - *this;
    } else {
        auto value = std::stoi(rhs.toString()) - _value;
        verifyOverflow(value);
        return new Int8(std::to_string(value));
    }
}

IOperand *Int8::operator*(const IOperand &rhs) const
{
    // std::cout << "Int8 * multiplication" << std::endl;
    if (rhs.getType() > INT8) {
        return rhs * *this;
    } else {
        auto value = std::stoi(rhs.toString()) * _value;
        verifyOverflow(value);
        return new Int8(std::to_string(value));
    }
}

IOperand *Int8::operator/(const IOperand &rhs) const
{
    // std::cout << "Int8 / division" << std::endl;
    if (rhs.getType() > INT8) {
        return rhs / *this;
    } else {
        if (std::stoi(rhs.toString()) == 0)
            throw Error("Error: division by 0");
        auto value = _value / std::stoi(rhs.toString());
        return new Int8(std::to_string(value));
    }
}

IOperand *Int8::operator%(const IOperand &rhs) const
{
    // std::cout << "Int8 % modulo" << std::endl;
    if (rhs.getType() > INT8) {
        return rhs % *this;
    } else {
        if (_value == 0)
            throw Error("Error: Modulo by 0");
        auto value = std::stoi(rhs.toString()) % _value;
        return new Int8(std::to_string(value));
    }
}

const char *Int8::Error::what() const noexcept
{
    return this->message.c_str();
}
