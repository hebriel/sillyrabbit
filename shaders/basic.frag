#version 120

#extension GL_ARB_explicit_attrib_location : require

in vec4 theColor;

void main()
{
    gl_FragColor = theColor;
}
