#version 450 core


out vec4 FragColor;

uniform float iTime;
uniform vec2 iResolution;
uniform vec2 botLeft;

void main() {
	vec2 uv = (gl_FragCoord.xy - botLeft) / iResolution;
	
	vec3 col = 0.5 + 0.5 * cos(iTime + uv.xyx + vec3(0, 2, 4));

	FragColor = vec4(col, 1.0);
};
