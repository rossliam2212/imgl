include(cmake/CPM.cmake)

function(setup_dependencies)
    message(STATUS "Using CPM to fetch deps")

    find_package(OpenGL REQUIRED)
    find_package(glfw3 REQUIRED)
    find_package(GLEW REQUIRED)
    find_package(glm REQUIRED)
    find_package(spdlog REQUIRED)
    find_package(cli11 REQUIRED)

    # Catch2
    CPMAddPackage(
            NAME Catch2
            GITHUB_REPOSITORY catchorg/Catch2
            VERSION 3.0.1
    )
    if (Catch2_ADDED)
        list(APPEND CMAKE_MODULE_PATH "${Catch2_SOURCE_DIR}/extras")
    endif()
endfunction()
