/*
** EPITECH PROJECT, 2022
** AbstractVM
** File description:
** ErrorHandling.cpp
*/

#include "ErrorHandling.hpp"

ErrorHandling::ErrorHandling()
{
}

ErrorHandling::~ErrorHandling()
{
}

bool ErrorHandling::IsNumber(const std::string &s)
{
    for (char const &ch : s) {
        if (std::isdigit(ch) == 1 || ch == '.')
            return true;
    }
    return false;
}

void ErrorHandling::errornb(std::string _nb)
{
    if (!IsNumber(_nb) && !_nb.empty())
        throw Stacker::Error("Error: invalid number");
}

void ErrorHandling::errorcmd(std::string _cmd, std::string _nb) {
    if (_cmd == "push" && _nb == "")
        throw Stacker::Error("Error: invalid argument");
    if (_cmd == "assert" && _nb == "")
        throw Stacker::Error("Error: invalid argument");
    if (_cmd == "load" && _nb == "")
        throw Stacker::Error("Error: invalid argument");
    if (_cmd == "store" && _nb == "")
        throw Stacker::Error("Error: invalid argument");
}

void ErrorHandling::errortype(std::string _type)
{
    if (_type != "int8" && _type != "int16" && _type != "int32" && _type != "float" && _type != "double" && _type != "bigdecimal" && _type != "")
        throw Stacker::Error("Error: invalid type");
}
