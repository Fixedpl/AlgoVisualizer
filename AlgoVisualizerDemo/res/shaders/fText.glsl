#version 450 core

in vec4 v_color;
in vec2 v_tex_coord;
in float v_aa_low;
in float v_aa_high;

out vec4 FragColor;

uniform sampler2D u_texture;


void main() {
	float sdf = texture(u_texture, v_tex_coord).r;

	float alpha = smoothstep(v_aa_low, v_aa_high, sdf);
	FragColor = vec4(v_color.rgb, alpha);
};
