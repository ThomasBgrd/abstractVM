/*
** EPITECH PROJECT, 2022
** AbstractVM
** File description:
** Command.hpp
*/

#ifndef COMMAND_H
    #define COMMAND_H
    #include <string>
    #include <iostream>
    #include "Stacker.hpp"
    #include "Parser.hpp"
    #include "Parserfile.hpp"
    #include "ErrorHandling.hpp"

enum {
    PUSH,
    POP,
    CLEAR,
    DUP,
    SWAP,
    DUMP,
    ASSERT,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    LOAD,
    STORE,
    EXIT,
    PRINT,
} typedef CommandType;

class Command {
    public:
        Command(Stacker &stack);
        ~Command();

        void checkcmd();
        void checktype(std::string type);
        void commandmng(Parser &parser);
        void commandmngfile(Parserfile &parserfile);
        void clearcmd();

    private:
        Stacker &_memory;

        std::string _cmd;
        std::string _type;
        std::string _nb;
};

#endif /* !COMMAND_H */
