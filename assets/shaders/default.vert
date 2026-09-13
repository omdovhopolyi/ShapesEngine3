#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProjection;

out vec3 vFragPos;
out vec2 vUV;
out vec3 vNormal;

void main() {
    vFragPos = vec3(uModel * vec4(position, 1.0));
    vUV = uv;
    // TODO calculate on cpu
    vNormal = vec3(transpose(inverse(uModel)) * vec4(normal, 1.0));
    gl_Position = uProjection * uView * uModel * vec4(position, 1.0);
}