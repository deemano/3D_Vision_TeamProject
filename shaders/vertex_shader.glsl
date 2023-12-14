#version 330 core

layout (location = 0) in vec3 aPos;       // Position of the vertex
layout (location = 1) in vec3 aNormal;    // Normal of the vertex
layout (location = 2) in vec2 aTexCoords; // Texture coordinates

out vec3 FragPos;         // Position of the fragment for lighting in the fragment shader
out vec3 Normal;          // Normal of the fragment for lighting in the fragment shader
out vec2 TexCoords;       // For fragment shader

uniform mat4 model;       // Model matrix
uniform mat4 view;        // View matrix
uniform mat4 projection;  // Projection matrix

void main() {
    FragPos = vec3(model * vec4(aPos, 1.0));

    gl_Position = projection * view * model * vec4(aPos, 1.0);
    Normal = aNormal;
    TexCoords = aTexCoords;
}
