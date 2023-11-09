#version 450 core


out vec4 FragColor;

uniform float iTime;
uniform vec2 iResolution;
uniform vec2 botLeft;

vec3 sdfCircle(vec2 uv, float r, vec2 offset)
{
	vec2 uv_moved = uv - offset;

	float d = length(uv_moved) - r;

	return d > 0. ? vec3(0.) : 0.5 + 0.5 * cos(iTime + uv.xyx + vec3(0, 1, 2));
}

void main() {
	vec2 uv = (gl_FragCoord.xy - botLeft) / iResolution;
	uv -= 0.5;
	uv.x *= iResolution.x / iResolution.y;

	vec2 offset = vec2(sin(iTime) * 0.2, cos(iTime) * 0.2);

	vec3 col = sdfCircle(uv, .2, offset);

	FragColor = vec4(col, 1.0);
};
