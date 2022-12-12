/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-florian.gibault
** File description:
** Float
*/

#include "Float.hpp"
#include <cmath>

Float::Float(const std::string &value)
{
    verifyOverflow(std::stof(value));
    _value = std::stof(value);
}

Float::~Float()
{
}

std::string Float::toString() const
{
    return std::to_string(_value);
}

eOperandType Float::getType() const
{
    return eOperandType::FLOAT;
}

bool Float::verifyOverflow(int value) const
{
    // if (value > 3.4e38) {
    //     throw Error("Error: value overflow");
    // } else if (value < 1.175494351e-38) {
    //     throw Error("Error: value underflow");
    // }
    (void)value;
    return true;
}

IOperand *Float::operator+(const IOperand &rhs) const
{
    // std::cout << "Float + addition" << std::endl;
    if (rhs.getType() > FLOAT) {
        return rhs + *this;
    } else {
        auto value = std::stof(rhs.toString()) + _value;
        verifyOverflow(value);
        return new Float(std::to_string(value));
    }
}

IOperand *Float::operator-(const IOperand &rhs) const
{
    // std::cout << "Float - substraction" << std::endl;
    if (rhs.getType() > FLOAT) {
        return rhs - *this;
    } else {
        auto value = std::stof(rhs.toString()) - _value;
        verifyOverflow(value);
        return new Float(std::to_string(value));
    }
}

IOperand *Float::operator*(const IOperand &rhs) const
{
    // std::cout << "Float * multiplication" << std::endl;
    if (rhs.getType() > FLOAT) {
        return rhs * *this;
    } else {
        auto value = std::stof(rhs.toString()) * _value;
        verifyOverflow(value);
        return new Float(std::to_string(value));
    }
}

IOperand *Float::operator/(const IOperand &rhs) const
{
    // std::cout << "Float / division" << std::endl;
    if (rhs.getType() > FLOAT) {
        return rhs / *this;
    } else {
        if (std::stof(rhs.toString()) == 0)
            throw Error("Error: division by 0");
        auto value = _value / std::stof(rhs.toString());
        return new Float(std::to_string(value));
    }
}

IOperand *Float::operator%(const IOperand &rhs) const
{
    throw Error("Error: Modulo on float");
}

const char *Float::Error::what() const noexcept
{
    return this->message.c_str();
}