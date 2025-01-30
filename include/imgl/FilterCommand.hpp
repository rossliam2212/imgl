/**
 * @file FilterCommand.hpp
 * @author liam 
 * @date 28/01/2025
 */

#ifndef FILTERCOMMAND_HPP
#define FILTERCOMMAND_HPP

#include <iostream>
#include "ICommand.hpp"
#include "CommandData.hpp"

namespace imgl {
    class FilterCommand : public ICommand {
    public:
        FilterCommand(const FilterCommandData& data);
        ~FilterCommand() override = default;

        void execute() override;

    private:
        FilterCommandData data;
    };
} // namespace imgl

#endif //FILTERCOMMAND_HPP