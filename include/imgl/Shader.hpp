/**
 * @file Shader.hpp
 * @author liam 
 * @date 04/02/2025
 */

#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <iostream>

#include "FileUtils.hpp"

namespace imgl {
	class Shader {
	public:
		Shader(const char* vertexPath, const char* fragmentPath);
		~Shader();

		void enable() const;
		void disable() const;
		unsigned int getId() const;

		void setInt(const char* name, int value) const;
		void setFloat(const char* name, float value) const;
		void setVec3(const char* name, const glm::vec3& vec) const;
		void setMat4(const char* name, const glm::mat4& mat) const;

	private:
		unsigned int id;
		const char* vertexCode;
		const char* fragmentCode;

		void compile(const char* vertexPath, const char* fragmentPath);
		void create(const char* code, unsigned int type) const;
	};
} // namespace imgl

#endif //SHADER_HPP
