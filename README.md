# PARSEGAR

This is another and worse C++ parser for the command line arguments.
I have done this so simple and basic because I need it for other
projects, therefore it lacks some features, but it may be updated in
the future.

## Usage

Include the `parsegar.hpp` header file. To set your arguments or flags
create a argsConfig object and use addFlag or addArgument to add them.  
Next create a argsParser object with the config object, argc and argv.
**This can throw exceptions** (std::runtime_error) if the input has errors.

A simple example:

```c++
#include "arg-parser.hpp"
#include <iostream>

int main(int argc, const char** argv) {
    argsConfig config;
    config.addFlag("-a");
    config.addFlag("-h");
    config.addArgument("-o");

    argsParser parser(config, argc, argv);

    std::cout << "-a: " << parser.getFlag("-a") << std::endl;
    std::cout << "-h: " << parser.getFlag("-h") << std::endl;
    std::cout << "-o: " << parser.getArgument("-o") << std::endl;
}
```

## Compiling

Requires **c++11** at least. You have to also compile `parsegar.cpp`.  
For example the above example is compiled with the following command:  
`clang++ -std=c++11 parsegar.cpp main.cpp`
