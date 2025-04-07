#ifndef MPAGS_CUSTOMEXCEPTIONS_HPP
#define MPAGS_CUSTOMEXCEPTIONS_HPP

#include <stdexcept>

class MissingArgument : public std::invalid_argument {
    public:
        MissingArgument( const std::string& msg ) :
            std::invalid_argument{msg}{}
};

class UnknownArgument : public std::invalid_argument {
    public:
        UnknownArgument( const std::string& msg ) :
            std::invalid_argument{msg}{}
};

class InvalidArgument : public std::invalid_argument {
    public:
        InvalidArgument( const std::string& msg ) :
            std::invalid_argument{msg}{}
};

class InconsistentArguments : public std::invalid_argument {
    public:
        InconsistentArguments( const std::string& msg ) :
            std::invalid_argument{msg}{}
};


#endif