/*
** EPITECH PROJECT, 2022
** AbstractVM
** File description:
** Command.cpp
*/

#include "Command.hpp"

Command::Command(Stacker &stack) : _memory(stack)
{
}

Command::~Command()
{
}

void Command::checkcmd()
{
    if (_cmd == "push") {
        _memory.push(_type, _nb);
        return;
    }
    if (_cmd == "pop") {
        _memory.pop();
        return;
    }
    if (_cmd == "clear") {
        _memory.clear();
        return;
    }
    if (_cmd == "dup") {
        _memory.dup();
        return;
    }
    if (_cmd == "swap") {
        _memory.swap();
        return;
    }
    if (_cmd == "dump") {
        _memory.dump();
        return;
    }
    if (_cmd == "assert") {
        _memory.assert(_type, _nb);
        return;
    }
    if (_cmd == "add") {
        _memory.add();
        return;
    }
    if (_cmd == "sub") {
        _memory.sub();
        return;
    }
    if (_cmd == "mul") {
        _memory.mul();
        return;
    }
    if (_cmd == "div") {
        _memory.div();
        return;
    }
    if (_cmd == "mod") {
        _memory.mod();
        return;
    }
    if (_cmd == "load") {
        _memory.load(_nb);
        return;
    }
    if (_cmd == "store") {
        _memory.store(_nb);
        return;
    }
    if (_cmd == "print") {
        _memory.print(_type);
        return;
    }
    if (_cmd == "exit") {
        _memory.exit();
        return;
    }
    if (_cmd == ";;")
        return;

    throw Stacker::Error("Error: invalid command");
}

void Command::commandmng(Parser &parser)
{
    ErrorHandling errorhdl;
    for (auto &it : parser.getInstructions()) {
        _cmd = std::get<0>(it);
        _type = std::get<1>(it);
        _nb = std::get<2>(it);
        errorhdl.errornb(_nb);
        errorhdl.errorcmd(_cmd, _nb);
        errorhdl.errortype(_type);
        if (!_cmd.empty() && _type.empty() && !_nb.empty())
            throw Stacker::Error("Error: invalid argument");
        checkcmd();
        _cmd.clear();
        _type.clear();
        _nb.clear();
    }
    if ((std::get<0>((parser.getInstructions()).front()) == ";;") || (std::get<0>(parser.getInstructions().back()) != "exit"))
        throw Stacker::Error("Error: no exit command");
}

void Command::commandmngfile(Parserfile &parserfile)
{
    ErrorHandling errorhdl;
    for (auto &it : parserfile.getInstructions()) {
        _cmd = std::get<0>(it);
        _type = std::get<1>(it);
        _nb = std::get<2>(it);
        errorhdl.errornb(_nb);
        errorhdl.errorcmd(_cmd, _nb);
        errorhdl.errortype(_type);
        if (!_cmd.empty() && _type.empty() && !_nb.empty())
            throw Stacker::Error("Error: invalid argument");
        checkcmd();
        _cmd.clear();
        _type.clear();
        _nb.clear();
    }
    if (std::get<0>(parserfile.getInstructions().back()) != "exit")
        throw Stacker::Error("Error: no exit command");
}