#version 120

#extension GL_ARB_explicit_attrib_location : require

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;

out vec4 theColor;

uniform mat4 pr_matrix;
uniform mat4 vw_matrix = mat4(1.0);
uniform mat4 ml_matrix = mat4(1.0);

void main()
{
    gl_Position = pr_matrix * vw_matrix * ml_matrix * position;
    theColor = color;
}
