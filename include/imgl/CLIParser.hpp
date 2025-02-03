/**
 * @file CLIParser.hpp
 * @author liam 
 * @date 28/01/2025
 */

#ifndef CLIPARSER_HPP
#define CLIPARSER_HPP

#include <CLI/CLI.hpp>

#include "FilterCommand.hpp"
#include "TransformCommand.hpp"
#include "FilterCommandHandler.hpp"
#include "TransformCommandHandler.hpp"

namespace imgl {
    class CLIParser {
    public:
        CLIParser();
        ~CLIParser() = default;

        void parse(int argc, char** argv);

    private:
        CLI::App app;
        FilterCommandHandler filterHandler;
        TransformCommandHandler transformHandler;
    };
} // namespace imgl

#endif //CLIPARSER_HPP
