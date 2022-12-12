/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-florian.gibault
** File description:
** Factory
*/

#include "Factory.hpp"

Factory::Factory()
{
    _creators["int8"] = &Factory::createInt8;
    _creators["int16"] = &Factory::createInt16;
    _creators["int32"] = &Factory::createInt32;
    _creators["float"] = &Factory::createFloat;
    _creators["double"] = &Factory::createDouble;
    _creators["bigdecimal"] = &Factory::createBigdecimal;
}

Factory::~Factory()
{
}

IOperand *Factory::createOperand(std::string type, const std::string &value)
{
    FactoryFunc ptr = NULL;

    if (_creators.find(type) != _creators.end())
        ptr = _creators[type];
    else
        std::cout << "dodo" << std::endl;
    return (this->*ptr)(value);
}

IOperand *Factory::createInt8(const std::string &value)
{
    return new Int8(value);
}

IOperand *Factory::createInt16(const std::string &value)
{
    return new Int16(value);
}

IOperand *Factory::createInt32(const std::string &value)
{
    return new Int32(value);
}

IOperand *Factory::createFloat(const std::string &value)
{
    return new Float(value);
}

IOperand *Factory::createDouble(const std::string &value)
{
    return new Double(value);
}

IOperand *Factory::createBigdecimal(const std::string &value)
{
    return new Bigdecimal(value);
}