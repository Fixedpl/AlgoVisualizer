#version 450 core

in VS_OUT 
{
	vec4 v_color;
	vec2 v_center;
	float v_radius;
	float v_border_width;
	vec4 v_border_color;
} fs_in;

out vec4 FragColor;

float hermite_dist = 2.0f;

void main() {
	float distance_from_center = distance(fs_in.v_center, gl_FragCoord.xy);

	float outer_border_hermite_value = 1.0 - 
		smoothstep(fs_in.v_radius - hermite_dist, fs_in.v_radius, distance_from_center);

	float inner_border_hermite_value = 1.0 - 
		smoothstep(fs_in.v_radius - hermite_dist - fs_in.v_border_width, fs_in.v_radius - fs_in.v_border_width, distance_from_center);

	FragColor = mix(
		vec4(fs_in.v_border_color.xyz, max(0.0, outer_border_hermite_value - (1.0 - fs_in.v_border_color.w))), 
		vec4(fs_in.v_color.xyz, max(0.0, outer_border_hermite_value - (1.0 - fs_in.v_color.w))), 
		inner_border_hermite_value
	);
};
