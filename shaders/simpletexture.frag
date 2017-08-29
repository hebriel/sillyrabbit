#version 120

#extension GL_ARB_explicit_attrib_location : require

uniform sampler2D tex;

void main()
{
    vec4 color = texture2D(tex,gl_TexCoord[0].st);



    gl_FragColor = color;
}
