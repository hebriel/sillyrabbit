#version 120

#extension GL_ARB_explicit_attrib_location : require

uniform sampler2D tex;
in vec4 Normal;

in vec3 FragPos;

uniform vec3 viewPos;

uniform vec4 lightColor;
uniform vec3 lightPos;

void main()
{
    vec4 color = texture2D(tex,gl_TexCoord[0].st);

    float specularStrength = 0.5;
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * vec3(lightColor);

    vec3 norm = normalize(vec3(Normal));
    vec3 lightDir = normalize(lightPos - FragPos);

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * vec3(lightColor);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * vec3(color);

    vec3 result = (ambient + diffuse + specular) * vec3(color);
    gl_FragColor = vec4(result, 1.0);

}
