#version 450 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 tex_coord;
layout (location = 3) in float aa_low;
layout (location = 4) in float aa_high;

out vec4 v_color;
out vec2 v_tex_coord;
out float v_aa_low;
out float v_aa_high;

uniform mat4 u_MVP;


void main() {
	v_tex_coord = tex_coord;
	v_color = color;
	v_aa_low = aa_low;
	v_aa_high = aa_high;
	gl_Position = u_MVP * vec4(pos.x, pos.y, pos.z, 1.0);
};
