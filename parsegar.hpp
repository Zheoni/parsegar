#ifndef _PARSEGAR_H_
#define _PARSEGAR_H_

#include <map>
#include <set>
#include <string>

class argsConfig {
   public:
    // adds a flag (like -h), with no expected input after
    void addFlag(const std::string& name) noexcept;

    // adds an argument (like -n 4), with expected input after
    void addArgument(const std::string& name) noexcept;

    // returns all the flags the config object has
    const std::set<std::string>& getAllFlags() const noexcept;

    // returns all the arguments the config object has
    const std::set<std::string>& getAllArguments() const noexcept;

   private:
    std::set<std::string> flags;
    std::set<std::string> arguments;
};

class argsParser {
   public:
    // the config object has the flags and arguments the parser will look for
    argsParser(const argsConfig& config, int argc, const char** argv);

    // returns true if argv has the flag
    bool getFlag(const std::string& name) const noexcept;

    // returs the input for an argument if its in argv
    //(if its not returns an empty string)
    std::string getArgument(const std::string& name) const noexcept;

    // returns a set with all the flags argv has
    const std::set<std::string>& getAllFlags() const noexcept;

    // returns a map with all the arguments and its input argv has
    const std::map<std::string, std::string>& getAllArguments() const noexcept;

   private:
    std::set<std::string> flags;
    std::map<std::string, std::string> arguments;
};

#include "inline-parsegar.cpp"

#endif