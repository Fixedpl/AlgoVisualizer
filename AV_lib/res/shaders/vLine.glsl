#version 450 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 norm;
layout (location = 3) in vec2 size;
layout (location = 4) in float border_width;
layout (location = 5) in vec4 border_color;


out VS_OUT 
{
	vec4 v_color;
	vec2 v_norm;
	vec2 v_size;
	float v_border_width;
	vec4 v_border_color;
} vs_out;


uniform mat4 u_MVP;

void main() {
	vs_out.v_color = color;
	vs_out.v_norm = norm;
	vs_out.v_size = size;
	vs_out.v_border_width = border_width;
	vs_out.v_border_color = border_color;

	gl_Position = u_MVP * vec4(pos, 1.0);
};