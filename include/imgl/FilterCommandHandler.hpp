/**
 * @file FilterCommandHandler.hpp
 * @author liam 
 * @date 30/01/2025
 */

#ifndef FILTERCOMMANDHANDLER_HPP
#define FILTERCOMMANDHANDLER_HPP

#include <CLI/CLI.hpp>

#include "CommandData.hpp"

namespace imgl {
	class FilterCommandHandler {
	public:
    	FilterCommandHandler() = default;
    	~FilterCommandHandler() = default;

		void setup(CLI::App& app);
		explicit operator bool() const;

		FilterCommandData getData() const;

	private:
		CLI::App* filterHandler{nullptr};
		FilterCommandData data;
	};
} // namespace imgl

#endif //FILTERCOMMANDHANDLER_HPP
