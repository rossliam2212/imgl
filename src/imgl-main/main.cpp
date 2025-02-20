#include <imgl/RenderContext.hpp>
#include <imgl/CLIParser.hpp>
#include <spdlog/spdlog.h>

int main(int argc, char** argv) {
	try {
		imgl::RenderContext renderContext;
		renderContext.init();

		imgl::CLIParser parser;
		parser.parse(argc, argv);
	} catch (const std::exception& ex) {
		spdlog::error(ex.what());
	}
}