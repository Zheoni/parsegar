#include "parsegar.hpp"

argsParser::argsParser(const argsConfig& config, int argc, const char** argv) {
    const std::set<std::string>& cflags = config.getAllFlags();
    const std::set<std::string>& carguments = config.getAllArguments();

    for (int i = 0; i < argc; ++i) {
        if (argv[i][0] != '-') continue;

        bool isArgument = false;
        std::set<std::string>::const_iterator it = cflags.find(argv[i]);
        if (it == cflags.cend()) {
            it = carguments.find(argv[i]);
            if (it == carguments.cend()) {
                throw std::runtime_error(std::string("Unknown argument: ") +
                                         argv[i]);
            } else {
                isArgument = true;
            }
        }

        if (isArgument) {
            if ((i + 1) < argc && argv[i + 1][0] != '-') {
                arguments.insert(std::make_pair(std::string(argv[i]),
                                              std::string(argv[i + 1])));
            } else {
                throw std::runtime_error(
                    std::string("Argument argument with no data"));
            }
        } else {
            flags.insert(argv[i]);
        }
    }
}

std::string argsParser::getArgument(const std::string& name) const noexcept {
    std::map<std::string, std::string>::const_iterator it = arguments.find(name);
    if (it == arguments.cend()) {
        return std::string();
    } else {
        return it->second;
    }
}