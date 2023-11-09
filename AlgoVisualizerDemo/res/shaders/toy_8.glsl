#version 450 core


out vec4 FragColor;

uniform float iTime;
uniform vec2 iResolution;
uniform vec2 botLeft;

float sdfCircle(vec2 uv, float r, vec2 offset)
{
	vec2 uv_moved = uv - offset;

	return length(uv_moved) - r;
}

vec4 borderedCircle(vec2 uv)
{
	float circle1 = sdfCircle(uv, .2, vec2(0.));
	float circle2 = sdfCircle(uv, .22, vec2(0.));

	vec4 col = smoothstep(vec4(1., 0., 0., 1.), vec4(0., 0., 0., 1.), vec4(circle1 * 100, 0., 0., 1.));
	col.a = smoothstep(1. , 0., circle2 * 100);

	return col;
}

void main() {
	vec2 uv = (gl_FragCoord.xy - botLeft) / iResolution;
	uv -= 0.5;
	uv.x *= iResolution.x / iResolution.y;

	vec2 offset = vec2(sin(iTime) * 0.2, cos(iTime) * 0.2);

	vec4 col = borderedCircle(uv);

	FragColor = vec4(col);
};
