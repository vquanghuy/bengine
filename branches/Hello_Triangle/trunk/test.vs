attribute vec4 vPosition;
attribute vec4 vColor;
varying vec4 v_Color;
uniform mat4 _WVP;
uniform mat4 _W;
uniform mat4 _V;
uniform mat4 _P;


void main()
{
	v_Color = vColor;
	gl_Position = _WVP * vPosition;

}