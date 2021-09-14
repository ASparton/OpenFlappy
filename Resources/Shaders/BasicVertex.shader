#version 450 core

layout(location = 0) in vec2 position;
layout(location = 1) in vec2 v_textureCoords;

out vec2 f_textureCoords;

void main()
{
	gl_Position = vec4(position.x, position.y, 0.f, 1.f);
	f_textureCoords = v_textureCoords;
}