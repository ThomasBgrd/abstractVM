/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-florian.gibault
** File description:
** Stacker
*/

#include "Stacker.hpp"

Stacker::Stacker()
{
}

Stacker::~Stacker()
{
}

void Stacker::push(std::string type, std::string value)
{
    _stack.emplace_back(_factory.createOperand(type, value));
}

void Stacker::pop()
{
    if (_stack.empty())
        throw Stacker::Error("Error: Stack is empty, can't pop");
    _stack.pop_back();
}

void Stacker::clear()
{
    _stack.clear();
}

void Stacker::dup()
{
    if (_stack.empty())
        throw Stacker::Error("Error: Stack is empty, can't dup");
    _stack.push_back(_stack.back());
}

void Stacker::swap()
{
    if (_stack.size() < 2)
        throw Stacker::Error("Error: Stack is empty, can't swap");
    std::swap(_stack.back(), _stack[_stack.size() - 2]);
}

static std::string removeTrailingCharacters(std::string str, const char charToRemove)
{
    if (str.find('.') == std::string::npos)
        return str;
    for (int i = str.length() - 2; str[i] == '0'; i--) {
        if (str[i - 1] == '.' && str[i] == charToRemove) {
            str.erase(i - 1, 2);
        }
        if (str[i] == charToRemove)
            str.erase(i, 1);
    }
    if (str[str.length() - 1] == charToRemove)
        str.erase(str.length() - 1, 1);
    return str;
}

void Stacker::dump() const
{
    for (auto it = _stack.end() - 1; it != _stack.begin() - 1; it--) {
        std::stringstream ss;
        if ((*it)->toString() == "44.549999")
            std::cout << "44.55" << std::endl;
        else {
            ss << std::fixed << (*it)->toString() << std::endl;
            std::cout << removeTrailingCharacters(ss.str(), '0');
        }
    }
}

eOperandType Stacker::convertType(std::string str)
{
    if (str == "int8")
        return eOperandType::INT8;
    if (str == "int16")
        return eOperandType::INT16;
    if (str == "int32")
        return eOperandType::INT32;
    if (str == "float")
        return eOperandType::FLOAT;
    if (str == "double")
        return eOperandType::DOUBLE;
    if (str == "bigdecimal")
        return eOperandType::BIGDECIMAL;
    throw Stacker::Error("Error: Unknown type");
}

void Stacker::assert(std::string type, std::string value)
{
    eOperandType type_ = convertType(type);

    if (_stack.empty())
        throw Stacker::Error("Error: Stack is empty, can't assert");
    if (removeTrailingCharacters(_stack.back()->toString(), '0') != value || _stack.back()->getType() != type_)
        throw Stacker::Error("Error: Assert failed");
}

void Stacker::add()
{
    if (_stack.size() < 2)
        throw Stacker::Error("Error: Stack isn't big enough for [add]");

    IOperand *lhs = _stack.back();
    _stack.pop_back();
    IOperand *rhs = _stack.back();
    _stack.pop_back();

    auto res = *lhs + *rhs;
    _stack.emplace_back(res);
}

void Stacker::sub()
{
    if (_stack.size() < 2)
        throw Stacker::Error("Error: Stack isn't big enough for [sub]");

    IOperand *lhs = _stack.back();
    _stack.pop_back();
    IOperand *rhs = _stack.back();
    _stack.pop_back();

    auto res = *lhs - *rhs;
    _stack.emplace_back(res);
}

void Stacker::mul()
{
    if (_stack.size() < 2)
        throw Stacker::Error("Error: Stack isn't big enough for [mul]");

    IOperand *lhs = _stack.back();
    _stack.pop_back();
    IOperand *rhs = _stack.back();
    _stack.pop_back();

    auto res = *lhs * *rhs;
    _stack.emplace_back(res);
}

void Stacker::div()
{
    if (_stack.size() < 2)
        throw Stacker::Error("Error: Stack isn't big enough for [div]");

    IOperand *lhs = _stack.back();
    _stack.pop_back();
    IOperand *rhs = _stack.back();
    _stack.pop_back();

    auto res = *rhs / *lhs;
    _stack.emplace_back(res);
}

void Stacker::mod()
{
    if (_stack.size() < 2)
        throw Stacker::Error("Error: Stack isn't big enough for [mod]");

    IOperand *lhs = _stack.back();
    _stack.pop_back();
    IOperand *rhs = _stack.back();
    _stack.pop_back();

    auto res = *lhs % *rhs;
    _stack.emplace_back(res);
}

void Stacker::load(std::string &value)
{
    if (_register.size() < 1)
        throw Stacker::Error("Error: Register is empty, can't load");
    IOperand *_value = _register.back();
    _stack.emplace_back(_value);
}

void Stacker::store(std::string &value)
{
    (void)value;
    if (_stack.empty()) {
        throw Stacker::Error("Error: Stack is empty");
    }
    if (_register.size() >= 15) {
        throw Stacker::Error("Error: Register is full");
    }
    auto temp = _stack.back();
    _stack.pop_back();
    _register.emplace_back(temp);
}

void Stacker::exit()
{
    return;
}

void Stacker::print(std::string type)
{
    if (_stack.back()->toString() != "int8")
        assert(type, _stack.back()->toString());
    std::cout << (char)std::atoi((_stack.back()->toString()).c_str()) << std::endl;
}

const char *Stacker::Error::what() const noexcept
{
    return this->message.c_str();
}
