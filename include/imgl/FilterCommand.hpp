/**
 * @file FilterCommand.hpp
 * @author liam 
 * @date 28/01/2025
 */

#ifndef FILTERCOMMAND_HPP
#define FILTERCOMMAND_HPP

#include "ICommand.hpp"

namespace imgl {
    class FilterCommand : public ICommand {
    public:
        FilterCommand();
        ~FilterCommand() override = default;

        void execute() override;
    };
} // namespace imgl

#endif //FILTERCOMMAND_HPP