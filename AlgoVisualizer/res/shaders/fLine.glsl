#version 450 core

in VS_OUT
{
	vec4 v_color;
	vec2 v_norm;
	vec2 v_size;
	float v_border_width;
	vec4 v_border_color;
	float v_sharpness;
} fs_in;

out vec4 FragColor;


void main() {
	vec2 size = (fs_in.v_size / 2.0f);
	vec2 local = abs(fs_in.v_norm * size);
	vec2 outer_border_alpha = 1.0 - smoothstep(size - fs_in.v_sharpness, size, local);
	vec2 inner_border_alpha = 1.0 - smoothstep(size - fs_in.v_border_width - fs_in.v_sharpness, size - fs_in.v_border_width, local);
	float inner_border_alpha_x = 1.0 - smoothstep(size.y - fs_in.v_border_width - fs_in.v_sharpness, size.y - fs_in.v_border_width, local.y);

	FragColor = mix(
	vec4(fs_in.v_border_color.xyz, min(outer_border_alpha.x, outer_border_alpha.y) - (1.0 - fs_in.v_border_color.w)),
	vec4(fs_in.v_color.xyz, min(outer_border_alpha.x, outer_border_alpha.y) - (1.0 - fs_in.v_color.w)),
	min(inner_border_alpha.x, inner_border_alpha.y)
	);
};
