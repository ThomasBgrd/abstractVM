/*
** EPITECH PROJECT, 2022
** AbstractVM
** File description:
** Parser.cpp
*/

#include "Parser.hpp"
#include "Command.hpp"

Parser::Parser(Stacker &stack) : _memory(stack)
{
}

Parser::~Parser()
{
    _cmd.clear();
    _type.clear();
    _nb.clear();
}

std::vector<std::tuple<std::string, std::string, std::string>> Parser::getInstructions()
{
    return _commands;
}

std::string Parser::removecomments(std::string &str)
{
    if (str.length() > 2) {
        std::size_t found = str.find(";");
        if (found != std::string::npos) {
            if (str.at(found - 1) == ' ')
                str = str.erase(found - 1, str.length());
            else
                str.erase(found, str.length());
        }
    }
    return str;
}

std::string removespace(const std::string &str)
{
    size_t start = str.find_first_not_of(" ");
    return (start == std::string::npos ? "" : str.substr(start));
}

void Parser::getCmd()
{
    if (_input.find(' ') == std::string::npos) {
        _cmd = _input.substr(0, _input.find(' '));
        _input = _input.erase(0, _input.find(' ') + 1);
    }
    else {
        _cmd = _input.substr(0, _input.find(' '));
        _input = _input.erase(0, _input.find(' ') + 1);
        _input = removespace(_input);
        if (_input.find("(") == std::string::npos || _input.find(")") == std::string::npos) {
            throw Stacker::Error("Error: invalid argument");
        }
        else {
            _type = _input.substr(0, _input.find("("));
            _input = _input.erase(0, _input.find("(") + 1);
            _input = removespace(_input);
            _nb = _input.substr(0, _input.find(")"));
            _input = _input.erase(0, _input.length() + 1);
        }
    }
}

void Parser::ParseString(Parser &parser)
{
    std::string delim = " ";
    while(_input != ";;") {
        getline(std::cin, _input);
        std::replace(std::begin(_input),std::end(_input),'\t',' ');
        _input = removespace(_input);
        if (_input.length() >=2) {
            if (_input.at(0) == ';' && _input.at(1) != ';')
                continue;
            if (_input.at(0) == ';' && _input.at(1) == ';' && !_cmd.empty())
                continue;
        }
        _input = removecomments(_input);
        getCmd();
        _commands.emplace_back(std::make_tuple(_cmd, _type, _nb));
    }
    Command command(_memory);
    command.commandmng(parser);
}