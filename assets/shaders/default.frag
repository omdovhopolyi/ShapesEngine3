#version 330 core

struct Light {
    vec3 position;
    vec3 color;
};

uniform Light uLight;

in vec3 vFragPos;
in vec2 vUV;
in vec3 vNormal;

uniform sampler2D baseTex;
out vec4 FragColor;

void main() {
    vec3 normal = normalize(vNormal);
    vec3 lightDir = normalize(uLight.position - vFragPos);
    float diffuseFactor = max(dot(lightDir, vNormal), 0.0);
    vec3 diffuse = uLight.color * diffuseFactor;
    vec4 texColor = texture(baseTex, vUV);
    vec3 result = texColor.rgb * diffuse;
    FragColor = vec4(result, 1.0);
}