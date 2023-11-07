#version 450 core

in VS_OUT
{
	vec4 v_color;
	vec2 v_bot_left_corner;
	vec2 v_size;
	float v_radius;
	float v_border_width;
	vec4 v_border_color;
	float v_sharpness;
} fs_in;


out vec4 FragColor;

/*
 Ladne
vec4 borderedRectRounded(vec2 uv)
{
	float rect1 = sdfRectRounded(uv, vec2(.3, .2), .05);

	vec4 col = smoothstep(vec4(0., 0., 1., 0.), vec4(0., 0., 0., 1.), vec4(0., 0., rect1 * 100, 1.));
	col.a = smoothstep(1., 0., (rect1 + .05) * 8);

	return col;
}
*/

float sdfRectRounded(vec2 uv, float radius)
{
	return min(max(uv.x, uv.y), 0.0) + length(max(uv, 0.0)) - radius;
}

void main() {
	vec2 rect_size = (fs_in.v_size / 2.0f);
	vec2 uv = abs(gl_FragCoord.xy - fs_in.v_bot_left_corner - rect_size);

	vec4 col = fs_in.v_color;

	float sdf_outer = sdfRectRounded(
		uv - rect_size + fs_in.v_radius + fs_in.v_sharpness,
		fs_in.v_radius
	);

	if (fs_in.v_border_width != 0.0f) {
		col = mix(
			fs_in.v_color, 
			fs_in.v_border_color, 
			1.0 - smoothstep(fs_in.v_border_width, fs_in.v_border_width + fs_in.v_sharpness, abs(sdf_outer))
		);
	} 
	col.a = col.a - smoothstep(0.0f, fs_in.v_sharpness, sdf_outer);
	FragColor = col;
};
