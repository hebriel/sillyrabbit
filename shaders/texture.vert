#version 120

#extension GL_ARB_explicit_attrib_location : require

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 texCoord;

out vec4 theTexCoord;

uniform mat4 pr_matrix;
uniform mat4 vw_matrix = mat4(1.0);
uniform mat4 ml_matrix = mat4(1.0);

uniform vec3 lightPos;
out vec3 FragPos;
out vec4 Normal;

void main()
{
    vec3 N = gl_Normal.xyz;

    mat4 modelView = vw_matrix * ml_matrix;
    mat4 modelViewProjection = pr_matrix * modelView;

    gl_Position = modelViewProjection * position;
    FragPos = vec3(ml_matrix * position);
    Normal = modelView * vec4(N, 0.0);

    gl_TexCoord[0] = gl_TextureMatrix[0] * texCoord;
}
