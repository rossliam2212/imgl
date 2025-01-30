/**
 * @file CLIParser.hpp
 * @author liam 
 * @date 28/01/2025
 */

#ifndef CLIPARSER_HPP
#define CLIPARSER_HPP

#include <CLI/CLI.hpp>

#include "FilterCommand.hpp"
#include "FilterCommandHandler.hpp"

namespace imgl {
    class CLIParser {
    public:
        CLIParser();
        ~CLIParser() = default;

        void parse(int argc, char** argv);

    private:
        CLI::App app;
        FilterCommandHandler filterHandler;
    };
} // namespace imgl

#endif //CLIPARSER_HPP
