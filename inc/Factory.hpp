/*
** EPITECH PROJECT, 2022
** AbstractVM
** File description:
** Factory.hpp
*/

#ifndef FACTORY_H
#define FACTORY_H

#include "IOperand.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include "Bigdecimal.hpp"


class Factory;
using FactoryFunc = IOperand *(Factory::*)(const std::string &);

class Factory
{
    public:
        Factory();
        ~Factory();

        IOperand *createOperand(std::string type, const std::string &value);

    private:
        std::unordered_map<std::string, FactoryFunc> _creators;
        IOperand *createInt8(const std ::string &value);
        IOperand *createInt16(const std ::string &value);
        IOperand *createInt32(const std ::string &value);
        IOperand *createFloat(const std ::string &value);
        IOperand *createDouble(const std ::string &value);
        IOperand *createBigdecimal(const std ::string &value);
};

#endif /* !FACTORY_H */
