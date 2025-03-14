set(LIB_HEADERS
        ../../include/imgl/ICommand.hpp
        ../../include/imgl/FilterCommand.hpp
        ../../include/imgl/CLIParser.hpp
        ../../include/imgl/CommandData.hpp
        ../../include/imgl/FilterCommandHandler.hpp
        ../../include/imgl/Defines.hpp
        ../../include/imgl/TransformCommand.hpp
        ../../include/imgl/TransformCommandHandler.hpp
        ../../include/imgl/FileUtils.hpp
        ../../include/imgl/Image.hpp
        ../../include/imgl/ImageProcessor.hpp
        ../../include/imgl/RenderContext.hpp
        ../../include/imgl/FrameBuffer.hpp
        ../../include/imgl/Shader.hpp
        ../../include/imgl/RenderUtils.hpp
        ../../include/imgl/MetadataCommand.hpp
        ../../include/imgl/MetadataCommandHandler.hpp
)

set(LIB_SOURCES
        FilterCommand.cpp
        CLIParser.cpp
        FilterCommandHandler.cpp
        TransformCommand.cpp
        TransformCommandHandler.cpp
        FileUtils.cpp
        Image.cpp
        ImageProcessor.cpp
        RenderContext.cpp
        FrameBuffer.cpp
        Shader.cpp
        RenderUtils.cpp
        MetadataCommand.cpp
        MetadataCommandHandler.cpp

        ../../lib/stb-image/stb_image.cpp
        ../../lib/stb-image/stb_image_write.cpp
)

set(LIB_INCLUDES
        ../../include/
        ../../lib/
        ${CMAKE_BINARY_DIR}/configured_files/include
)

add_library(${LIB_NAME} STATIC
        ${LIB_SOURCES}
)
target_link_libraries(${LIB_NAME} PUBLIC
        OpenGL::GL
        glfw
        GLEW::GLEW
        spdlog::spdlog
        CLI11::CLI11
)
target_include_directories(${LIB_NAME} PUBLIC ${LIB_INCLUDES})

if(${ENABLE_WARNINGS})
    target_set_warnings(${LIB_NAME} ${ENABLE_WARNINGS} ${ENABLE_WARNINGS_AS_ERRORS})
endif()
