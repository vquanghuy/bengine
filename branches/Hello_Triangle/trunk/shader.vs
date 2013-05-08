attribute vec4 vPosition;
attribute vec4 vColor;
varying vec4 fColor;

uniform mat4 mModel;
uniform mat4 mView;
uniform mat4 mProj;

void main()
{
	fColor = vColor;
	
	mat4 MV = mView * mModel;
	mat4 MVP = mProj * MV;
	
	vec4 pos = MVP * vPosition;
	//vec4 pos = vPosition;
	
	gl_Position = pos;
}