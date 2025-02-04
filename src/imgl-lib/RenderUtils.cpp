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
			// Define the vertices of a full-screen quad (two triangles)
			constexpr float vertices[] = {
				// Positions   // Texture Coords
				-1.0f,  1.0f,  0.0f, 1.0f, // Top-left
				-1.0f, -1.0f,  0.0f, 0.0f, // Bottom-left
				 1.0f, -1.0f,  1.0f, 0.0f, // Bottom-right

				-1.0f,  1.0f,  0.0f, 1.0f, // Top-left
				 1.0f, -1.0f,  1.0f, 0.0f, // Bottom-right
				 1.0f,  1.0f,  1.0f, 1.0f  // Top-right
			};

			// Generate VAO & VBO
			glGenVertexArrays(1, &VAO);
			glBindVertexArray(VAO);

			glGenBuffers(1, &VBO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			// Position attribute
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);

			// Texture coordinate attribute
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
			glEnableVertexAttribArray(1);
		}

		// Bind VAO and draw quad
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
	}
} // namespace imgl