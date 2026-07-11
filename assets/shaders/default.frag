#version 330 core

in vec3 vColor;
uniform vec4 uColor;
out vec4 FragColor;

void main() {
    FragColor = vec4(vColor, 1.0) * uColor;
}