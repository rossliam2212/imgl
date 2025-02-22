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
        void execute() const;

    private:
        CLI::App app;
        FilterCommandHandler filterHandler;
        TransformCommandHandler transformHandler;
        bool debug{false};

        void setup();
    };
} // namespace imgl

#endif //CLIPARSER_HPP
