/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-florian.gibault
** File description:
** Stacker
*/

#ifndef STACKER_HPP_
#define STACKER_HPP_

#include "IOperand.hpp"
#include "Factory.hpp"

class Stacker {
    public:

        class Error : public std::exception {
            public:
                Error(const std::string &message) {this->message = std::string(message);};
                ~Error() {};
                const char *what() const noexcept override;
            private:
                std::string message;
        };

        Stacker();
        ~Stacker();

        void push(std::string type, std::string value);
        void pop();
        void clear();
        void dup();
        void swap();
        void dump() const;
        void assert(std::string type, std::string value);
        void add();
        void sub();
        void mul();
        void div();
        void mod();
        void load(std::string &value);
        void store(std::string &value);
        void print(std::string type);
        void exit();
        eOperandType convertType(std::string str);

    private:
        std::vector<IOperand *> _stack;
        std::vector<IOperand *> _register;
        Factory _factory;
};

#endif /* !STACK_HPP_ */
