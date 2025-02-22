/**
 * @file CLIParser.cpp
 * @author liam 
 * @date 28/01/2025
 */

#include "imgl/CLIParser.hpp"

namespace imgl {
	CLIParser::CLIParser()
		: app{"[imgl] A cli tool for manipulating images"} {
		setup();
	}

	void CLIParser::parse(int argc, char** argv) {
		try {
			app.require_subcommand(1);
			app.parse(argc, argv);

			if (debug) {
				spdlog::set_level(spdlog::level::debug);
				spdlog::debug("Debug logging enabled.");
			}
		} catch (const CLI::ParseError& err) {
			app.exit(err);
		} catch (const std::exception& err) {
			throw std::runtime_error(err.what());
		}
	}

	void CLIParser::execute() const {
		if (filterHandler) {
			FilterCommand cmd{filterHandler.getData()};
			cmd.execute();
			return;
		}

		if (transformHandler) {
			TransformCommand cmd{transformHandler.getData()};
			cmd.execute();
		}
	}

	void CLIParser::setup() {
		app.usage("Usage: ./imgl [OPTIONS] SUBCOMMAND [SUB_OPTIONS]");
		app.add_flag(DEBUG_OPTION, debug, "Enable debugging logs");

		filterHandler.setup(app);
		transformHandler.setup(app);
	}
} // namespace imgl