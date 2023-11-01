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

float sdfRectRounded(vec2 uv, float radius)
{
	return min(max(uv.x, uv.y), 0.0) + length(max(uv, 0.0)) - radius;
}

void main() {
	vec2 rect_size = (fs_in.v_size / 2.0f);
	vec2 uv = abs(gl_FragCoord.xy - fs_in.v_bot_left_corner - rect_size);

	vec2 helper = (fs_in.v_size / 2.0) - fs_in.v_radius - fs_in.v_sharpness;
	vec2 helper2 = uv - helper;
	float sdf = sdfRectRounded(helper2, fs_in.v_radius);
	float c = smoothstep(2.0f, 0.0f, sdf);
	float e = smoothstep(fs_in.v_border_width + fs_in.v_sharpness, fs_in.v_border_width, abs(min(sdf - 2 * fs_in.v_sharpness, 0.0)));
    FragColor = mix(
		vec4(fs_in.v_color.xyz, max(0.0, c - (1.0 - fs_in.v_color.w))), 
		vec4(fs_in.v_border_color.xyz, max(0.0, c - (1.0 - fs_in.v_border_color.w))), 
		e
	);
};
