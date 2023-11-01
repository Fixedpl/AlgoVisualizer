#version 450 core


out vec4 FragColor;

uniform float iTime;
uniform vec2 iResolution;
uniform vec2 botLeft;

float sdfRect(vec2 uv, vec2 r)
{
	return length(max(abs(uv) - r, 0.));
}

float sdfRectRounded(vec2 uv, vec2 r, float p)
{
	return length(max(abs(uv) - r, 0.)) - p;
}

vec4 borderedRect(vec2 uv)
{
	float rect1 = sdfRect(uv, vec2(.2, .1));
	float rect2 = sdfRect(uv, vec2(.22, .12));

	vec4 col = smoothstep(vec4(1., 0., 0., 1.), vec4(0., 0., 0., 1.), vec4(rect1 * 100, 0., 0., 1.));
	col.a = smoothstep(1., 0., rect2 * 100);

	return col;
}
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

vec4 borderedRectRounded(vec2 uv)
{
	float rect1 = sdfRectRounded(uv, vec2(.3, .2), .05);

	vec4 col = smoothstep(vec4(0., 0., 1., 0.), vec4(0., 0., 0., 1.), vec4(0., 0., rect1 * 100, 1.));
	col.a = smoothstep(1., 0., (rect1 - .05) * 100);

	return col;
}

void main() {
	vec2 uv = (gl_FragCoord.xy - botLeft) / iResolution;
	uv -= 0.5;
	uv.x *= iResolution.x / iResolution.y;

	vec2 offset = vec2(sin(iTime) * 0.2, cos(iTime) * 0.2);

	vec4 col = borderedRectRounded(uv);

	FragColor = col;
};
