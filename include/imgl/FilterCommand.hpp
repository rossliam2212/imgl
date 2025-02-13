/**
 * @file FilterCommand.hpp
 * @author liam 
 * @date 28/01/2025
 */

#ifndef FILTERCOMMAND_HPP
#define FILTERCOMMAND_HPP

#include <unordered_set>

#include "ICommand.hpp"
#include "CommandData.hpp"
#include "Defines.hpp"
#include "FileUtils.hpp"
#include "ImageProcessor.hpp"

namespace imgl {
    class FilterCommand : public ICommand {
    public:
        FilterCommand(const FilterCommandData& data);
        ~FilterCommand() override = default;

        void execute() override;

    private:
        FilterCommandData data;

        bool validFilterType() const;
        bool validInputPath() const;
    };
} // namespace imgl

#endif //FILTERCOMMAND_HPP