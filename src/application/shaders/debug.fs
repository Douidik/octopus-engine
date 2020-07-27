#version 460 core

out vec4 color;

in vec2 fs_uv;
uniform sampler2D u_texture;

void main() {
    color = texture(u_texture, fs_uv);
}