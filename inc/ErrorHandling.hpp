/*
** EPITECH PROJECT, 2022
** AbstractVM
** File description:
** ErrorHandling.hpp
*/

#ifndef ERRORHANDLING
    #define ERRORHANDLING
    #include <string>
    #include "Stacker.hpp"
    #include "Command.hpp"

class ErrorHandling {
    public:
        ErrorHandling();
        ~ErrorHandling();

        bool IsNumber(const std::string &s);
        void errornb(std::string _nb);
        void errortype(std::string _type);
        void errorcmd(std::string _cmd, std::string _nb);

    private:
};

#endif /* !ERRORHANDLING */
