#version 330 core

in vec2 vUV;
uniform sampler2D baseTex;
out vec4 FragColor;

void main() {
    FragColor = texture(baseTex, vUV);
    //FragColor = vec4(vColor, 1.0) * uColor;
    //FragColor = vec4(uColor, 1.0);
}