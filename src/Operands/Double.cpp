/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-florian.gibault
** File description:
** Double
*/

#include "Double.hpp"
#include <cmath>

Double::Double(const std::string &value)
{
    _value = std::stod(value);
}

Double::~Double()
{
}

std::string Double::toString() const
{
    return std::to_string(_value);
}

eOperandType Double::getType() const
{
    return eOperandType::DOUBLE;
}

bool Double::verifyOverflow(int value) const
{
    // if (value > 1.7976931348623158e+308) {
    //     throw Error("Error: value overflow");
    // } else if (value < 2.2250738585072014e-308) {
    //     throw Error("Error: value underflow");
    // }
    (void)value;
    return true;
}

IOperand *Double::operator+(const IOperand &rhs) const
{
    // std::cout << "Double + addition" << std::endl;
    if (rhs.getType() > DOUBLE) {
        return rhs + *this;
    } else {
        auto value = std::stod(rhs.toString()) + _value;
        verifyOverflow(value);
        return new Double(std::to_string(value));
    }
}

IOperand *Double::operator-(const IOperand &rhs) const
{
    // std::cout << "Double - substraction" << std::endl;
    if (rhs.getType() > DOUBLE) {
        return rhs - *this;
    } else {
        auto value = std::stod(rhs.toString()) - _value;
        verifyOverflow(value);
        return new Double(std::to_string(value));
    }
}

IOperand *Double::operator*(const IOperand &rhs) const
{
    // std::cout << "Double * multiplication" << std::endl;
    if (rhs.getType() > DOUBLE) {
        return rhs * *this;
    } else {
        auto value = std::stod(rhs.toString()) * _value;
        verifyOverflow(value);
        return new Double(std::to_string(value));
    }
}

IOperand *Double::operator/(const IOperand &rhs) const
{
    // std::cout << "Double / division" << std::endl;
    if (rhs.getType() > DOUBLE) {
        return rhs / *this;
    } else {
        if (std::stod(rhs.toString()) == 0)
            throw Error("Error: division by 0");
        auto value = _value / std::stod(rhs.toString());
        return new Double(std::to_string(value));
    }
}

IOperand *Double::operator%(const IOperand &rhs) const
{
    throw Error("Error: Modulo on float");
}

const char *Double::Error::what() const noexcept
{
    return this->message.c_str();
}
