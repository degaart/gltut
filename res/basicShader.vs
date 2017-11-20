#version 120

// vim: set ft=glsl:

attribute vec3 position;

void main()
{
    gl_Position = vec4(position, 1.0);
}

