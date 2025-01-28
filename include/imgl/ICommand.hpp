/**
 * @file ICommand.hpp
 * @author liam 
 * @date 28/01/2025
 */

#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP

namespace imgl {
    class ICommand {
    public:
        ICommand() = default;
        virtual ~ICommand() = default;

        virtual void execute() = 0;
    };
} // namespace imgl


#endif //ICOMMAND_HPP
