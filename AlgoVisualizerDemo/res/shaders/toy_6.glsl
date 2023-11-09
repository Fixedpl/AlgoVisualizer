#version 450 core


out vec4 FragColor;

uniform float iTime;
uniform vec2 iResolution;
uniform vec2 botLeft;

vec3 getBackgroundColor(vec2 uv)
{
	uv += 0.5;
	vec3 gradientStartColor = vec3(1., 0., 1.);
	vec3 gradientEndColor = vec3(0., 1., 1.);
	return mix(gradientStartColor, gradientEndColor, uv.y);
}

void main() {
	vec2 uv = (gl_FragCoord.xy - botLeft) / iResolution;
	uv -= 0.5;
	uv.x *= iResolution.x / iResolution.y;

	vec3 col = getBackgroundColor(uv);

	FragColor = vec4(col, 1.0);
};
