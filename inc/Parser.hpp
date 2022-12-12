/*
** EPITECH PROJECT, 2022
** AbstractVM
** File description:
** Parser.hpp
*/

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Stacker.hpp"

class Parser {
    public:
        Parser(Stacker &stack);
        ~Parser();

        void ParseString(Parser &_parser);
        std::string removecomments(std::string &str);
        void getCmd();
        std::vector<std::tuple<std::string, std::string, std::string>> getInstructions();

    private:
        Stacker &_memory;

        std::vector<std::tuple<std::string, std::string, std::string>> _commands;

        std::string _input;
        std::string _cmd;
        std::string _type;
        std::string _nb;

};

#endif /* !PARSER_H */
