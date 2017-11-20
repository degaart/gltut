#version 120

// vim: set ft=glsl:

varying vec2 texCoord0;
uniform sampler2D diffuse;

void main()
{
    gl_FragColor = texture2D(diffuse, texCoord0);
}

