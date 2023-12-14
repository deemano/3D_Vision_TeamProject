#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform sampler2D texture1;
uniform vec3 material_diffuse;
uniform bool hasTexture; // Uniform to indicate if texture is applied

void main() {
    // Ambient lighting
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // Diffuse lighting
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // Combine the lighting components
    vec3 result = (ambient + diffuse);

    // Check if a texture is applied
    if (hasTexture) {
        vec4 texColor = texture(texture1, TexCoords);
        FragColor = vec4(result * texColor.rgb, 1.0);
    } else {
        // Apply the material diffuse color directly
        FragColor = vec4(result * material_diffuse, 1.0);
    }
}
