#version 450 core


out vec4 FragColor;

uniform float iTime;
uniform vec2 iResolution;
uniform vec2 botLeft;

vec3 sdfCircle(vec2 uv, float r)
{
	float d = length(uv) - r;

	return d > 0. ? vec3(0.) : 0.5 + 0.5 * cos(iTime + uv.xyx + vec3(0, 1, 2));
}

void main() {
	vec2 uv = (gl_FragCoord.xy - botLeft) / iResolution;
	uv -= 0.5;
	uv.x *= iResolution.x / iResolution.y;

	vec3 col = sdfCircle(uv, .2);

	FragColor = vec4(col, 1.0);
};
