#version 460 core

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec2 a_uv;

out vec2 fs_uv;

void main() {
    fs_uv = a_uv;
    gl_Position = vec4(a_position, 1.0);
}