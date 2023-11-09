#version 450 core


out vec4 FragColor;

uniform float iTime;
uniform vec2 iResolution;
uniform vec2 botLeft;

float sdfSquare(vec2 uv, float r, vec2 offset)
{
	return max(abs(uv.x - offset.x), abs(uv.y - offset.y)) - r;
}

float sdfCircle(vec2 uv, float r, vec2 offset)
{
	vec2 uv_moved = uv - offset;
	return length(uv_moved) - r;
}

vec3 getBackgroundColor(vec2 uv)
{
	uv += 0.5;
	vec3 gradientStartColor = vec3(1., 0., 1.);
	vec3 gradientEndColor = vec3(0., 1., 1.);
	return mix(gradientStartColor, gradientEndColor, uv.y);
}

vec3 drawScene(vec2 uv)
{
	vec3 col = getBackgroundColor(uv);
	float circle = sdfCircle(uv, 0.1, vec2(0, 0));
	float square = sdfSquare(uv, 0.07, vec2(0.1, 0));

	col = mix(vec3(0., 0., 1.), col, step(0., circle));
	col = mix(vec3(1., 0., 0.), col, step(0., square));

	return col;
}

void main() {
	vec2 uv = (gl_FragCoord.xy - botLeft) / iResolution;
	uv -= 0.5;
	uv.x *= iResolution.x / iResolution.y;

	vec3 col = drawScene(uv);

	FragColor = vec4(col, 1.0);
};
