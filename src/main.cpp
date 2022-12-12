/*
** EPITECH PROJECT, 2022
** AbstractVM
** File description:
** main.cpp
*/

#include "Parser.hpp"
#include "Parserfile.hpp"

int main(int argc, char **argv)
{
    Stacker memory;
    try
    {
        if (argc == 2) {
            Parserfile parserfile(memory, argv[1]);
            parserfile.ParseStringfile(parserfile);
        }
        if (argc == 1) {
            Parser parser(memory);
            parser.ParseString(parser);
        }
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}
