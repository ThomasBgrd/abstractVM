/*
** EPITECH PROJECT, 2022
** AbstractVM
** File description:
** Parserfile.cpp
*/

#include "Parserfile.hpp"
#include "Command.hpp"

Parserfile::Parserfile(Stacker &stack, std::string filename) : _memory(stack), _filename(filename)
{
}

Parserfile::~Parserfile()
{
    _filename.clear();
}

std::vector<std::tuple<std::string, std::string, std::string>> Parserfile::getInstructions()
{
    return _cmdTypeNb;
}

std::string Parserfile::removecomments(std::string &str)
{
    std::size_t found = str.find(";");
    if (found != std::string::npos) {
        if (str.at(found - 1) == ' ')
            str = str.erase(found - 1, str.length());
        else
            str.erase(found, str.length());
    }
    return str;
}

std::string Parserfile::removespace(const std::string &str)
{
    size_t start = str.find_first_not_of(" ");
    return (start == std::string::npos ? "" : str.substr(start));
}

void Parserfile::getCmd()
{
    if (line.find(delim) == std::string::npos) {
        _cmd = line.substr(0, line.find(delim));
        line = line.erase(0, line.find(delim) + 1);
    }
    else {
        _cmd = line.substr(0, line.find(' '));
        line = line.erase(0, line.find(' ') + 1);
        line = removespace(line);
        if (line.find("(") == std::string::npos || line.find(")") == std::string::npos) {
            throw Stacker::Error("Error: invalid argument");
        }
        else {
            _type = line.substr(0, line.find("("));
            line = line.erase(0, line.find("(") + 1);
            line = removespace(line);
            _nb = line.substr(0, line.find(")"));
            line = line.erase(0, line.length() + 1);
        }
    }
}

void Parserfile::ParseStringfile(Parserfile &parserfile)
{
    std::ifstream file(_filename);

    if (!file.is_open())
        throw Stacker::Error("Error: File not found");
    else {
        while(!file.eof() && line != "exit") {
            getline(file, line);
            std::replace(std::begin(line),std::end(line),'\t',' ');
            line = removespace(line);
            if (line.empty())
                continue;
            if (line.length() >=2) {
                if (line.at(0) == ';' && line.at(1) != ';')
                    continue;
            }
            line = removecomments(line);
            getCmd();
            _cmdTypeNb.emplace_back(std::make_tuple(_cmd, _type, _nb));
        }
    }
    file.close();
    Command command(_memory);
    command.commandmngfile(parserfile);

}
