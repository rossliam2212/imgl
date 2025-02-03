/**
 * @file RenderContext.hpp
 * @author liam 
 * @date 03/02/2025
 */

#ifndef RENDERCONTEXT_HPP
#define RENDERCONTEXT_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace imgl {
    class RenderContext {
    public:
        RenderContext() = default;
        ~RenderContext();

        void init();

    private:
        int width{100};
        int height{100};
        GLFWwindow* window{nullptr};
    };
} // namespace imgl

#endif //RENDERCONTEXT_HPP
