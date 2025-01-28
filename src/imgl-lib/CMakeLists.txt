set(LIB_HEADERS
        ../../include/imgl/ICommand.hpp
        ../../include/imgl/FilterCommand.hpp
)

set(LIB_SOURCES
        FilterCommand.cpp
)

set(LIB_INCLUDES
        ../../include/
        ${CMAKE_BINARY_DIR}/configured_files/include
)

add_library(${LIB_NAME} STATIC
        ${LIB_SOURCES}
)
target_link_libraries(${LIB_NAME} PUBLIC
        OpenGL::GL
        glfw
        GLEW::GLEW
        glm::glm
        spdlog::spdlog
        cli11
)
target_include_directories(${LIB_NAME} PUBLIC ${LIB_INCLUDES})
target_link_directories(${LIB_NAME} PUBLIC ${CURLPP_LIBRARY_DIRS})

if(${ENABLE_WARNINGS})
    target_set_warnings(${LIB_NAME} ${ENABLE_WARNINGS} ${ENABLE_WARNINGS_AS_ERRORS})
endif()
