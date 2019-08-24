// inline definitions of functions

inline void argsConfig::addFlag(const std::string& name) noexcept {
    flags.insert(name);
}

inline void argsConfig::addArgument(const std::string& name) noexcept {
    arguments.insert(name);
}

inline const std::set<std::string>& argsConfig::getAllFlags() const noexcept {
    return flags;
}

inline const std::set<std::string>& argsConfig::getAllArguments() const noexcept {
    return arguments;
}

inline const std::set<std::string>& argsParser::getAllFlags() const noexcept {
    return flags;
}

inline const std::map<std::string, std::string>& argsParser::getAllArguments() const noexcept {
    return arguments;
}

inline bool argsParser::getFlag(const std::string& name) const noexcept {
    return flags.find(name) != flags.cend();
}