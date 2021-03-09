#pragma once

#include <glm/vec4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <GL/glew.h>
#include <span>
#include <vector>

struct Vertex {
    glm::vec3 point;
    glm::vec2 tex;
    glm::u8vec4 color;
    glm::u8vec4 light;
};

struct Mesh {
    GLuint vao = GL_NONE;
    GLuint vbo = GL_NONE;
    GLuint ibo = GL_NONE;
    GLsizeiptr vbo_size{0};
    GLsizeiptr ibo_size{0};
    int index_count{0};
    int vertex_count{0};

    Mesh() {
        glCreateVertexArrays(1, &vao);
        glCreateBuffers(1, &vbo);
        glCreateBuffers(1, &ibo);

        glVertexArrayElementBuffer(vao, ibo);
        glVertexArrayVertexBuffer(vao, 0, vbo, 0, sizeof(Vertex));

        glEnableVertexArrayAttrib(vao, 0);
        glEnableVertexArrayAttrib(vao, 1);
        glEnableVertexArrayAttrib(vao, 2);
        glEnableVertexArrayAttrib(vao, 3);

        glVertexArrayAttribFormat(vao, 0, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, point));
        glVertexArrayAttribFormat(vao, 1, 2, GL_FLOAT, GL_FALSE, offsetof(Vertex, tex));
        glVertexArrayAttribFormat(vao, 2, 4, GL_UNSIGNED_BYTE, GL_TRUE, offsetof(Vertex, color));
        glVertexArrayAttribFormat(vao, 3, 4, GL_UNSIGNED_BYTE, GL_TRUE, offsetof(Vertex, light));

        glVertexArrayAttribBinding(vao, 0, 0);
        glVertexArrayAttribBinding(vao, 1, 0);
        glVertexArrayAttribBinding(vao, 2, 0);
        glVertexArrayAttribBinding(vao, 3, 0);
    }

    ~Mesh() {
        glDeleteBuffers(1, &ibo);
        glDeleteBuffers(1, &vbo);
        glDeleteVertexArrays(1, &vao);
    }

    void SetVertices(std::span<const Vertex> vertices) {
        vertex_count = vertices.size();
        if (vertices.size_bytes() > vbo_size) {
            vbo_size = vertices.size_bytes();
            glNamedBufferData(vbo, vertices.size_bytes(), vertices.data(), GL_DYNAMIC_DRAW);
        } else {
            glNamedBufferSubData(vbo, 0, vertices.size_bytes(), vertices.data());
        }
    }

    void SetIndicesCount(int32_t count) {
    	const GLsizeiptr buf_size = sizeof(int32_t) * count;

        index_count = count;
    	if (buf_size > ibo_size) {
            ibo_size = buf_size;
            glNamedBufferData(ibo, buf_size, nullptr, GL_DYNAMIC_DRAW);
        }
    }

    void SetIndicesData(std::span<const int32_t> indices, int32_t offset) {
		glNamedBufferSubData(ibo, offset * sizeof(int32_t), indices.size_bytes(), indices.data());
    }

    void SetIndices(std::span<const int32_t> indices) {
        index_count = indices.size();
        if (indices.size_bytes() > ibo_size) {
            ibo_size = indices.size_bytes();
            glNamedBufferData(ibo, indices.size_bytes(), indices.data(), GL_DYNAMIC_DRAW);
        } else {
            glNamedBufferSubData(ibo, 0, indices.size_bytes(), indices.data());
        }
    }
};
