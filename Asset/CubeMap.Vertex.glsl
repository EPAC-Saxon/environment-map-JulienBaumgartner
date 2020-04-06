#version 330 core
layout (location = 0) in vec3 in_position;

out vec3 out_texcoord;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
    out_texcoord = vec3(1.0);
    gl_Position = vec4(1.0);
}  