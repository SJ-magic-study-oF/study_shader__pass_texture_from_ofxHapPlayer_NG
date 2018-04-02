#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

uniform sampler2DRect texture0;

uniform vec2 u_resolution;

/********************
0:none.
1:LR
2:UpDown
3:Diag
********************/
uniform int mirror = 0;

vec2 get_mirrored(vec2 st);

void main(){
	vec2 st = gl_TexCoord[0].xy;
	vec4 color = texture2DRect(texture0, st);
	gl_FragColor = color;
	
	/*
	
	
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
	st -= CoordOffset;
	
    st = fract(st * Zoom);
	st = get_mirrored(st);
	
	vec4 color = texture2DRect(texture0, st * u_resolution);
	
	gl_FragColor = color;
	*/
}

vec2 get_mirrored(vec2 st)
{
	if(mirror == 0)			{/* none. */}
	else if(mirror == 1)	{st.x = 1.0 - st.x;}
	else if(mirror == 2)	{st.y = 1.0 - st.y;}
	else if(mirror == 3)	{st = 1.0 - st;}
	
	return st;
}
