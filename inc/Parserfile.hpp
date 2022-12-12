/*
** EPITECH PROJECT, 2022
** AbstractVM
** File description:
** Parserfile.hpp
*/

#ifndef PARSERFILE_H
    #define PARSERFILE_H
    #include <string>
    #include <iostream>
    #include <sstream>
    #include <vector>
    #include <fstream>
    #include "Stacker.hpp"

class Parserfile {
    public:
        Parserfile(Stacker &stack, std::string filename);
        ~Parserfile();

        void ParseStringfile(Parserfile &parserfile);
        std::string removecomments(std::string &str);
        void getCmd();
        std::string removespace(const std::string &str);
        std::vector<std::tuple<std::string, std::string, std::string>> getInstructions();

    private:
        Stacker &_memory;

        std::vector<std::tuple<std::string, std::string, std::string>> _cmdTypeNb;

        std::string line;
        std::string delim = " ";
        std::string _filename;

        std::string _cmd;
        std::string _type;
        std::string _nb;
};

#endif /* !PARSERFILE_H */
