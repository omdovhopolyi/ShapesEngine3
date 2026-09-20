#version 330 core

struct Light {
    vec3 position;
    vec3 color;
};

uniform Light uLight;

uniform vec3 ambientLight;

in vec3 vFragPos;
in vec2 vUV;
in vec3 vNormal;

uniform vec3 uCameraPos;

uniform sampler2D baseTex;
uniform sampler2D specularTex;

out vec4 FragColor;

void main() {
    vec3 normal = normalize(vNormal);
    vec4 texColor = texture(baseTex, vUV);

    // ambient
    //vec3 ambientColor = texColor.rgb * ambientLight;
    vec3 ambientColor = texColor.rgb * vec3(0.1, 0.1, 0.1);

    // diffuse
    vec3 lightDir = normalize(uLight.position - vFragPos);
    float diffuseFactor = max(dot(lightDir, vNormal), 0.0);
    vec3 diffuse = uLight.color * diffuseFactor;
    vec3 diffuseColor = texColor.rgb * diffuse;

    // specular
    vec3 cameraDir = normalize(uCameraPos - vFragPos);
    vec3 reflected = reflect(-lightDir, normal);
    float specular = pow(max(dot(reflected, cameraDir), 0.0), 32.0);
    vec3 specularColor = texture(specularTex, vUV).rgb * specular;

    vec3 result = ambientColor + diffuseColor + specularColor;

    FragColor = vec4(result, 1.0);
}