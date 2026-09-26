#version 330 core

uniform vec3 uColor;

out vec4 FragColor;

void main() {
    vec3 result = uColor;
    FragColor = vec4(result, 1.0);
}