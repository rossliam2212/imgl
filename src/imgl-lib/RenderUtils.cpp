/**
 * @file RenderUtils.cpp
 * @author liam 
 * @date 04/02/2025
 */

#include "imgl/RenderUtils.hpp"

namespace imgl {
	static unsigned int VAO{0};
	static unsigned int VBO{0};

	void RenderUtils::render() {
		if (VAO == 0) {
			constexpr float vertices[] = {
				-1.0f,  1.0f,  0.0f, 1.0f,
				-1.0f, -1.0f,  0.0f, 0.0f,
				 1.0f, -1.0f,  1.0f, 0.0f,

				-1.0f,  1.0f,  0.0f, 1.0f,
				 1.0f, -1.0f,  1.0f, 0.0f,
				 1.0f,  1.0f,  1.0f, 1.0f
			};

			glGenVertexArrays(1, &VAO);
			glBindVertexArray(VAO);

			glGenBuffers(1, &VBO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);

			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
			glEnableVertexAttribArray(1);
		}
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
	}

	void RenderUtils::cleanup() {
		if (VAO != 0) {
			glDeleteVertexArrays(1, &VAO);
		}
		if (VBO != 0) {
			glDeleteBuffers(1, &VBO);
		}
	}
} // namespace imgl