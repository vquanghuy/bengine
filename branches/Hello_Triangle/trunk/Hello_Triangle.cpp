//
// Book:      OpenGL(R) ES 2.0 Programming Guide
// Authors:   Aaftab Munshi, Dan Ginsburg, Dave Shreiner
// ISBN-10:   0321502795
// ISBN-13:   9780321502797
// Publisher: Addison-Wesley Professional
// URLs:      http://safari.informit.com/9780321563835
//            http://www.opengles-book.com
//

// Hello_Triangle.c
//
//    This is a simple example that draws a single triangle with
//    a minimal vertex/fragment shader.  The purpose of this 
//    example is to demonstrate the basic concepts of 
//    OpenGL ES 2.0 rendering.
#include <stdlib.h>
#include <stdio.h>
#include "esUtil.h"

#include "Camera.h"

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 320

typedef struct
{
   // Handle to a program object
   GLuint programObject;

   // handle to attrib
   GLuint attribPosition;
   GLuint attribColor;
   GLuint uniMatModelLoc;
   GLuint uniMatViewLoc;
   GLuint uniMatProjLoc;

} UserData;

ESMatrix matView;		//also camera mat
ESMatrix matModel;
ESMatrix matProj;

//add camera
Camera gCam;
///
// Create a shader object, load the shader source, and
// compile the shader.
//
GLuint LoadShader ( GLenum type, const char *shaderSrc )
{
   GLuint shader;
   GLint compiled;
   
   // Create the shader object
   shader = glCreateShader ( type );

   if ( shader == 0 )
   	return 0;

   // Load the shader source
   glShaderSource ( shader, 1, &shaderSrc, NULL );
   
   // Compile the shader
   glCompileShader ( shader );

   // Check the compile status
   glGetShaderiv ( shader, GL_COMPILE_STATUS, &compiled );

   if ( !compiled ) 
   {
      GLint infoLen = 0;

      glGetShaderiv ( shader, GL_INFO_LOG_LENGTH, &infoLen );
      
      if ( infoLen > 1 )
      {
         char* infoLog = new char[infoLen];

         glGetShaderInfoLog ( shader, infoLen, NULL, infoLog );
         esLogMessage ( "Error compiling shader:\n%s\n", infoLog );            
         
         delete []infoLog;
      }

      glDeleteShader ( shader );
      return 0;
   }

   return shader;

}

GLuint LoadShaderFromFile( GLenum type, const char *fileSrc )
{
	FILE* f = fopen(fileSrc, "rb");

	if(!f)
	{
		esLogMessage( "Error: Can't load shader file: %s", fileSrc);
		return 0;
	}

	char *shaderBuffer;
	int lSize;

	// obtain file size:
	fseek (f , 0 , SEEK_END);
	lSize = ftell(f);
	rewind(f);

	// allocate memory to contain the whole file:
	shaderBuffer = new char[lSize+1];
	if (shaderBuffer == NULL) 
	{
		esLogMessage("Memory error !");
		return 0;
	}
	memset(shaderBuffer, 0, sizeof(char)*(lSize+1));

	// copy the file into the buffer:
	int result = fread(shaderBuffer, sizeof(char), lSize, f);
	if (result != lSize)
	{
		esLogMessage("Reading error");
		return 0;
	}

	//load shader
	GLuint shader = LoadShader(type, shaderBuffer);

	//clean up
	delete[] shaderBuffer;
	fclose(f);

	//return shader
	return shader;
}

///
// Reset MVP matrix
//
void ResetMVPMatrix()
{
	esMatrixLoadIdentity(&matModel);
	esMatrixLoadIdentity(&matView);
	esMatrixLoadIdentity(&matProj);
}

///
// Initialize the shader and program object
//
int Init ( ESContext *esContext )
{
   UserData *userData = (UserData*) esContext->userData;
   char vShaderStr[] =  
      "attribute vec4 vPosition;    \n"
      "void main()                  \n"
      "{                            \n"
      "   gl_Position = vPosition;  \n"
      "}                            \n";
   
   char fShaderStr[] =  
      "precision mediump float;\n"\
      "void main()                                  \n"
      "{                                            \n"
      "  gl_FragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );\n"
      "}                                            \n";

   GLuint vertexShader;
   GLuint fragmentShader;
   GLuint programObject;
   GLint linked;

   // Load the vertex/fragment shaders
   //vertexShader = LoadShader ( GL_VERTEX_SHADER, vShaderStr );
   //fragmentShader = LoadShader ( GL_FRAGMENT_SHADER, fShaderStr );
   vertexShader = LoadShaderFromFile ( GL_VERTEX_SHADER, "shader.vs" );
   fragmentShader = LoadShaderFromFile ( GL_FRAGMENT_SHADER, "shader.fs" );

   // Create the program object
   programObject = glCreateProgram ( );
   
   if ( programObject == 0 )
      return 0;

   glAttachShader ( programObject, vertexShader );
   glAttachShader ( programObject, fragmentShader );

   // Bind vPosition to attribute 0
   GLuint attribColor, attribPosition;

	attribPosition = 0;
	attribColor = 1;

   glBindAttribLocation ( programObject, attribPosition, "vPosition" );
   glBindAttribLocation ( programObject, attribColor, "vColor" );   

   // Link the program
   glLinkProgram ( programObject );

   // Check the link status
   glGetProgramiv ( programObject, GL_LINK_STATUS, &linked );

   if ( !linked ) 
   {
      GLint infoLen = 0;

      glGetProgramiv ( programObject, GL_INFO_LOG_LENGTH, &infoLen );
      
      if ( infoLen > 1 )
      {
         char* infoLog = new char[infoLen];

         glGetProgramInfoLog ( programObject, infoLen, NULL, infoLog );
         esLogMessage ( "Error linking program:\n%s\n", infoLog );            
         
         delete []infoLog;
      }

      glDeleteProgram ( programObject );
      return FALSE;
   }

   // Store the program object
   userData->programObject = programObject;
   userData->attribPosition = attribPosition;
   userData->attribColor = attribColor;

   userData->uniMatModelLoc = glGetUniformLocation(programObject, "mModel");
   userData->uniMatProjLoc = glGetUniformLocation(programObject, "mProj");
   userData->uniMatViewLoc = glGetUniformLocation(programObject, "mView");

   glClearColor ( 0.0f, 0.0f, 0.0f, 0.0f );

   // load default matrix value
   ResetMVPMatrix();

   //init camera   
   gCam.Init();

   esPerspective(&matProj, 60, int(SCREEN_WIDTH / SCREEN_HEIGHT), 0.1, 500);

   return TRUE;
}

void Update ( ESContext *esContext, float dt)
{
	// rotate the model	
	matView = gCam.GetCamera();	
}

void Key ( ESContext *esContext, unsigned char key, int x, int y )
{
	switch(key)
	{
	case 'w':
	case 'W': gCam.MoveY(-0.1);		break;
	case 's':
	case 'S': gCam.MoveY(0.1);		break;
	case 'a':
	case 'A': gCam.MoveX(0.1);		break;
	case 'd':
	case 'D': gCam.MoveX(-0.1);		break;
	case 'q':
	case 'Q': gCam.MoveZ(-0.1);		break;
	case 'e':
	case 'E': gCam.MoveZ(0.1);		break;

	case 'i':
	case 'I': gCam.RotX(1);		break;
	case 'k':
	case 'K': gCam.RotX(-1);		break;
	case 'j':
	case 'J': gCam.RotY(1);		break;
	case 'l':
	case 'L': gCam.RotY(-1);		break;
	case 'u':
	case 'U': gCam.RotZ(-1);		break;
	case 'o':
	case 'O': gCam.RotZ(1);		break;
	}
}

///
// Draw a triangle using the shader pair created in Init()
//
void Draw ( ESContext *esContext )
{
   UserData *userData = (UserData*) esContext->userData;
   GLfloat vVertices[] = {  0.0f,  0.5f, -1.5f, 
                           -0.5f, -0.5f, -1.5f,
                            0.5f, -0.5f, -1.5f };

   GLfloat vColor[] = {
						1.0f, 0.0f, 0.0f, 1.0f,
						0.0f, 1.0f, 0.0f, 1.0f,
						0.0f, 0.0f, 1.0f, 1.0f
						};  

   // Set the viewport
   glViewport ( 0, 0, esContext->width, esContext->height );
   
   // Clear the color buffer
   glClear ( GL_COLOR_BUFFER_BIT );

   // Use the program object
   glUseProgram ( userData->programObject );

   // Load the vertex data
   glVertexAttribPointer ( userData->attribPosition, 3, GL_FLOAT, GL_FALSE, 0, vVertices );
   glVertexAttribPointer ( userData->attribColor, 4, GL_FLOAT, GL_FALSE, 0, vColor );

   glEnableVertexAttribArray ( userData->attribPosition );
   glEnableVertexAttribArray ( userData->attribColor );

   // Load the uniform data
   glUniformMatrix4fv( userData->uniMatModelLoc, 1, GL_FALSE, &matModel.m[0][0]);
   glUniformMatrix4fv( userData->uniMatProjLoc, 1, GL_FALSE, &matProj.m[0][0]);
   glUniformMatrix4fv( userData->uniMatViewLoc, 1, GL_FALSE, &matView.m[0][0]);

   glDrawArrays ( GL_TRIANGLES, 0, 3 );

   eglSwapBuffers ( esContext->eglDisplay, esContext->eglSurface );
}


int main ( int argc, char *argv[] )
{
   ESContext esContext;
   UserData  userData;

   esInitContext ( &esContext );
   esContext.userData = &userData;

   esCreateWindow ( &esContext, "Hello Triangle", SCREEN_WIDTH, SCREEN_HEIGHT, ES_WINDOW_RGB );
   
   if ( !Init ( &esContext ) )
      return 0;

   esRegisterDrawFunc ( &esContext, Draw );
   esRegisterUpdateFunc ( &esContext, Update );
   esRegisterKeyFunc ( &esContext, Key );
   
   esMainLoop ( &esContext );
}
