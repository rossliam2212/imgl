/**
 * @file Shader.cpp
 * @author liam 
 * @date 04/02/2025
 */

#include "imgl/Shader.hpp"

namespace imgl {
	Shader::Shader(const char* fragmentPath) {
		compile(fragmentPath);
	}

	Shader::~Shader() {
		glUseProgram(0);
		glDeleteProgram(id);
	}

	void Shader::enable() const {
		glUseProgram(id);
	}

	void Shader::disable() const {
		glUseProgram(0);
	}

	unsigned int Shader::getId() const {
		return id;
	}

	void Shader::setInt(const char* name, const int value) const {
		int location{glGetUniformLocation(id, name)};
		glUniform1i(location, value);
	}

	void Shader::setFloat(const char* name, const float value) const {
		int location{glGetUniformLocation(id, name)};
		glUniform1f(location, value);
	}

	void Shader::setVec3(const char* name, const glm::vec3& vec) const {
		int location{glGetUniformLocation(id, name)};
		glUniform3f(location, vec.x, vec.y, vec.z);
	}

	void Shader::setMat4(const char* name, const glm::mat4& mat) const {
		int location{glGetUniformLocation(id, name)};
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
	}

	void Shader::compile(const char* fragmentPath) {
		id = glCreateProgram();
		if (!id) {
			std::cerr << "Failed to create shader program\n";
			return;
		}
		const std::string fragmentSrc{utils::readFile(fragmentPath)};
		create(fragmentSrc.c_str());

		int result{0};
		char log[1024] {};

		glLinkProgram(id);
		glGetProgramiv(id, GL_LINK_STATUS, &result);
		if (!result) {
			glGetProgramInfoLog(id, sizeof(log), nullptr, log);
			std::cerr << "Error linking program :: " << log;
			return;
		}
		glValidateProgram(id);
	}

	void Shader::create(const char* code) const {
		unsigned int shader{glCreateShader(GL_FRAGMENT_SHADER)};

		const char* codePtr[1];
		codePtr[0] = code;

		int codeLength[1];
		codeLength[0] = strlen(code);

		glShaderSource(shader, 1, codePtr, codeLength);
		glCompileShader(shader);

		int result{0};
		char log[1024]{0};

		glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
		if (!result) {
			glGetShaderInfoLog(shader, sizeof(log), nullptr, log);
			std::cerr << "Error compiling shader :: " << log;
			glDetachShader(id, shader);
			glDeleteShader(shader);

			return;
		}
		glAttachShader(id, shader);
	}
} // namespace imgl
