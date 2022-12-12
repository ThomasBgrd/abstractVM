/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-florian.gibault
** File description:
** Int32
*/

#include "Int32.hpp"

Int32::Int32(const std::string &value)
{
    verifyOverflow(std::stoi(value));
    _value = std::stoi(value);
}

Int32::~Int32()
{
}

std::string Int32::toString() const
{
    return std::to_string(_value);
}

eOperandType Int32::getType() const
{
    return eOperandType::INT32;
}

bool Int32::verifyOverflow(int value) const
{
    if (value > INT32_MAX) {
        throw Error("Error: value overflow");
    } else if (value < INT32_MIN) {
        throw Error("Error: value underflow");
    }
    return true;
}

IOperand *Int32::operator+(const IOperand &rhs) const
{
    // std::cout << "Int32 + addition" << std::endl;
    if (rhs.getType() > INT32) {
        return rhs + *this;
    } else {
        auto value = std::stoi(rhs.toString()) + _value;
        verifyOverflow(value);
        return new Int32(std::to_string(value));
    }
}

IOperand *Int32::operator-(const IOperand &rhs) const
{
    // std::cout << "Int32 - substraction" << std::endl;
    if (rhs.getType() > INT32) {
        return rhs - *this;
    } else {
        auto value = std::stoi(rhs.toString()) - _value;
        verifyOverflow(value);
        return new Int32(std::to_string(value));
    }
}

IOperand *Int32::operator*(const IOperand &rhs) const
{
    // std::cout << "Int32 * multiplication" << std::endl;
    if (rhs.getType() > INT32) {
        return rhs * *this;
    } else {
        auto value = std::stoi(rhs.toString()) * _value;
        verifyOverflow(value);
        return new Int32(std::to_string(value));
    }
}

IOperand *Int32::operator/(const IOperand &rhs) const
{
    // std::cout << "Int32 / division" << std::endl;
    if (rhs.getType() > INT32) {
        return rhs / *this;
    } else {
        if (std::stoi(rhs.toString()) == 0)
            throw Error("Error: division by 0");
        auto value = _value / std::stoi(rhs.toString());
        return new Int32(std::to_string(value));
    }
}

IOperand *Int32::operator%(const IOperand &rhs) const
{
    // std::cout << "Int32 % modulo" << std::endl;
    if (rhs.getType() > INT32) {
        return rhs % *this;
    } else {
        if (_value == 0)
            throw Error("Error: Modulo by 0");
        auto value = std::stoi(rhs.toString()) % _value;
        return new Int32(std::to_string(value));
    }
}

const char *Int32::Error::what() const noexcept
{
    return this->message.c_str();
}
