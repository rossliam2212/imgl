/**
 * @file CLIParser.cpp
 * @author liam 
 * @date 28/01/2025
 */

#include "imgl/CLIParser.hpp"

namespace imgl {
	CLIParser::CLIParser()
		: app{"[imgl] A cli tool for manipulating images"} {
	 	filterHandler.setup(app);
		transformHandler.setup(app);
	}

	void CLIParser::parse(int argc, char** argv) {
		try {
			app.require_subcommand(1);
			app.parse(argc, argv);

			if (filterHandler) {
				FilterCommand cmd{filterHandler.getData()};
				cmd.execute();
				std::exit(EXIT_SUCCESS);
			}

			if (transformHandler) {
				TransformCommand cmd{transformHandler.getData()};
				cmd.execute();
				std::exit(EXIT_SUCCESS);
			}

		} catch (const CLI::ParseError& err) {
			app.exit(err);
		}
	}
} // namespace imgl