#version 330 core

in vec3 vColor;
uniform vec3 uColor;
out vec4 FragColor;

void main() {
    //FragColor = vec4(vColor, 1.0) * uColor;
    FragColor = vec4(uColor, 1.0);
}