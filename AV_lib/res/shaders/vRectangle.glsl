#version 450 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 bot_left_corner;
layout (location = 2) in vec4 color;
layout (location = 3) in vec2 size;
layout (location = 4) in float radius;
layout (location = 5) in float border_width;
layout (location = 6) in vec4 border_color;
layout (location = 7) in float sharpness;

out VS_OUT 
{
	vec4 v_color;
	vec2 v_bot_left_corner;
	vec2 v_size;
	float v_radius;
	float v_border_width;
	vec4 v_border_color;
	float v_sharpness;
} vs_out;


uniform mat4 u_MVP;

void main() {
	vs_out.v_color = color;
	vs_out.v_bot_left_corner = bot_left_corner;
	vs_out.v_size = size;
	vs_out.v_radius = radius;
	vs_out.v_border_width = border_width;
	vs_out.v_border_color = border_color;
	vs_out.v_sharpness = sharpness;

	gl_Position = u_MVP * vec4(pos, 1.0);
};
