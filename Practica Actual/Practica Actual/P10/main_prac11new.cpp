//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito


//NEW// Keyframes
//Variables de dibujo y manipulacion
float posX =0, posY = 2.5, posZ =-3.5, rotRodIzq = 0, rotBraIzq =0, rotBraDer = 0, rotRodDer = 0, rotcabeza = 0;
float giroMonito = 0;

#define MAX_FRAMES 100
int i_max_steps = 90;
int i_curr_steps = 0;

typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float rotRodIzq;
	float rotInc;
	float giroMonito;
	float giroMonitoInc;

	float rotBraIzq;
	float rotBraIzqInc;

	float rotBraDer;
	float rotBraDerInc;

	float rotRodDer;
	float rotDerInc;

	float rotcabeza;
	float rotcabezainc;
	
}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex=0;			//introducir datos
bool play=false;
int playIndex=0;


int w = 500, h = 500;
int frame=0,time,timebase=0;
char s[30];

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;


//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = {18};

GLfloat m_dif2[] = { 0.8f, 0.2f, 0.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec2[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb2[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s2[] = {22};



float angHombro = 0.0f;
float angCodo = 0.0f;
float angMano = 0.0f;
float angPulgar1 = 0.0f;
float angPulgar2 = 0.0f;

float angIndice1 = 0.0f;
float angIndice2 = 0.0f;
float angIndice3 = 0.0f;

float angAnu1 = 0.0f;
float angAnu2 = 0.0f;
float angAnu3 = 0.0f;

float angMe1 = 0.0f;
float angMe2 = 0.0f;
float angMe3 = 0.0f;


float angMenique1 = 0.0f;
float angMenique2 = 0.0f;
float angMenique3 = 0.0f;

void prisma(void)
{
	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
							//glColor3f(1.0,0.0,0.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor3f(0.0, 0.0, 1.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glColor3f(0.4, 0.2, 0.6);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glColor3f(0.8, 0.2, 0.4);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void saveFrame ( void )
{
	
	printf("frameindex %d\n",FrameIndex);			

	KeyFrame[FrameIndex].posX=posX;
	KeyFrame[FrameIndex].posY=posY;
	KeyFrame[FrameIndex].posZ=posZ;

	KeyFrame[FrameIndex].rotRodIzq=rotRodIzq;
	KeyFrame[FrameIndex].giroMonito=giroMonito;

	KeyFrame[FrameIndex].rotBraIzq = rotBraIzq;

	KeyFrame[FrameIndex].rotBraDer = rotBraDer;

	KeyFrame[FrameIndex].rotRodDer = rotRodDer;

	KeyFrame[FrameIndex].rotcabeza = rotcabeza;
			
	FrameIndex++;
}

void resetElements( void )
{
	posX=KeyFrame[0].posX;
	posY=KeyFrame[0].posY;
	posZ=KeyFrame[0].posZ;

	rotRodIzq=KeyFrame[0].rotRodIzq;
	giroMonito=KeyFrame[0].giroMonito;
	rotBraIzq = KeyFrame[0].rotBraIzq;
	rotBraDer = KeyFrame[0].rotBraDer;
	rotRodDer = KeyFrame[0].rotRodDer;
	rotcabeza = KeyFrame[0].rotcabeza;

}

void interpolation ( void )
{
	KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;	
	KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;	
	KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;	

	KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;	
	KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;
	KeyFrame[playIndex].rotBraIzqInc = (KeyFrame[playIndex + 1].rotBraIzq - KeyFrame[playIndex].rotBraIzq) / i_max_steps;

	KeyFrame[playIndex].rotBraDerInc = (KeyFrame[playIndex + 1].rotBraDer - KeyFrame[playIndex].rotBraDer) / i_max_steps;

	KeyFrame[playIndex].rotDerInc = (KeyFrame[playIndex + 1].rotRodDer - KeyFrame[playIndex].rotRodDer) / i_max_steps;

	KeyFrame[playIndex].rotcabezainc = (KeyFrame[playIndex + 1].rotcabeza - KeyFrame[playIndex].rotcabeza) / i_max_steps;

}


void brazo()
{
	glPushMatrix();
		glScalef(2.0, 2.0, 0.3);
		glPushMatrix();	
		
			//hombro
			glRotatef(angHombro, 0.0, 0.0, 1.0);

			glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glScaled(0.5, 0.5, 1.0);
				prisma();
			glPopMatrix();
			
			//bicep
			glPushMatrix();
				glColor3f(0.0, 0.0, 1.0);
				glTranslatef(-0.75, -0.0, 0.0);
				glScalef(1.0, 0.5, 1.0);
				prisma();
			glPopMatrix();
			
			//codo
			glTranslatef(-0.75, 0.0, 0.0);
			glRotatef(angCodo, 0.0, 0.0, 1.0);
			glPushMatrix();
			glColor3f(1.0, 0.0, 0.0);
			glTranslatef(-0.75, 0.0, 0.0);
			glScalef(0.5, 0.5, 1.0);
			prisma();
			glPopMatrix();//antebrazo
			glTranslatef(-0.75, 0.0, 0.0);
			glPushMatrix();
			glColor3f(0.0, 0.0, 1.0);
			glTranslatef(-0.75, 0.0, 0.0);
			glScalef(1.0, 0.5, 1.0);
			prisma();
			glPopMatrix();//mano
			glTranslatef(-0.75, 0.0, 0.0);
			glRotatef(angMano, 0.0, 0.0, 1.0);
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslatef(-0.75, 0.0, 0.0);
			glScalef(0.5, 0.5, 1.0);
			prisma();
			glPopMatrix();//pulgar			parte 1
			glPushMatrix();
			glTranslatef(-0.75, 0.15, 0.0);
			glRotatef(angPulgar1, 0.0, 0.0, 1.0);
			glTranslatef(0.0, 0.15, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();//parte 2
			glTranslatef(0.0, 0.1, 0.0);
			glRotatef(angPulgar2, 0.0, 0.0, 1.0);
			glTranslatef(0.0, 0.1, 0.0);
			glColor3f(1.0, 0.0, 1.0);
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();//indice

			glTranslatef(-0.75, -0.0, 0.0);
			glPushMatrix();
			glTranslatef(-0.175, -0.1, 0.0);
			glRotatef(angIndice1, 0.0, 1.0, 0.0);
			glTranslatef(-0.175, -0.1, 0.0);
			glColor3f(1.0, 0.0, 0.0);
			glPushMatrix();
			glScalef(0.2, 0.1, 1.0);
			prisma();
			glPopMatrix();

			glTranslatef(-0.1, -0.0, 0.0);
			glRotatef(angIndice2, 0.0, 1.0, 0.0);
			glTranslatef(-0.1, -0.0, 0.0);
			glColor3f(0.0, 0.0, 1.0);
			glPushMatrix();
			glScalef(0.2, 0.1, 1.0);
			prisma();
			glPopMatrix();

			glTranslatef(-0.1, -0.0, 0.0);
			glRotatef(angIndice3, 0.0, 1.0, 0.0);
			glTranslatef(-0.1, -0.0, 0.0);
			glColor3f(1.0, 0.0, 1.0);
			glPushMatrix();
			glScalef(0.2, 0.1, 1.0);
			prisma();
			glPopMatrix();

			glPopMatrix();//medio

			glPushMatrix();
			glTranslatef(-0.175, -0.035, 0.0);
			glRotatef(angMe1, 0.0, 1.0, 0.0);
			glTranslatef(-0.175, -0.035, 0.0);
			glColor3f(1.0, 0.0, 0.0);
			glPushMatrix();
			glScalef(0.2, 0.1, 1.0);
			prisma();
			glPopMatrix();

			glTranslatef(-0.1, -0.0, 0.0);
			glRotatef(angMe2, 0.0, 1.0, 0.0);
			glTranslatef(-0.1, -0.0, 0.0);
			glColor3f(0.0, 0.0, 1.0);
			glPushMatrix();
			glScalef(0.2, 0.1, 1.0);
			prisma();
			glPopMatrix();

			glTranslatef(-0.1, -0.0, 0.0);
			glRotatef(angMe3, 0.0, 1.0, 0.0);
			glTranslatef(-0.1, -0.0, 0.0);
			glColor3f(1.0, 0.0, 1.0);
			glPushMatrix();
			glScalef(0.2, 0.1, 1.0);
			prisma();
			glPopMatrix();

			glPopMatrix();//anular

			glPushMatrix();
			glTranslatef(-0.175, 0.035, 0.0);
			glRotatef(angAnu1, 0.0, 1.0, 0.0);
			glTranslatef(-0.175, 0.035, 0.0);
			glColor3f(1.0, 0.0, 0.0);
			glPushMatrix();
			glScalef(0.2, 0.1, 1.0);
			prisma();
			glPopMatrix();

			glTranslatef(-0.1, -0.0, 0.0);
			glRotatef(angAnu2, 0.0, 1.0, 0.0);
			glTranslatef(-0.1, -0.0, 0.0);
			glColor3f(0.0, 0.0, 1.0);
			glPushMatrix();
			glScalef(0.2, 0.1, 1.0);
			prisma();
			glPopMatrix();

			glTranslatef(-0.1, -0.0, 0.0);
			glRotatef(angAnu3, 0.0, 1.0, 0.0);
			glTranslatef(-0.1, -0.0, 0.0);
			glColor3f(1.0, 0.0, 1.0);
			glPushMatrix();
			glScalef(0.2, 0.1, 1.0);
			prisma();
			glPopMatrix();

			glPopMatrix();//anular

			glPushMatrix();
			glTranslatef(-0.175, 0.1, 0.0);
			glRotatef(angMenique1, 0.0, 1.0, 0.0);
			glTranslatef(-0.175, 0.1, 0.0);
			glColor3f(1.0, 0.0, 0.0);
			glPushMatrix();
			glScalef(0.2, 0.1, 1.0);
			prisma();
			glPopMatrix();

			glTranslatef(-0.1, -0.0, 0.0);
			glRotatef(angMenique2, 0.0, 1.0, 0.0);
			glTranslatef(-0.1, -0.0, 0.0);
			glColor3f(0.0, 0.0, 1.0);
			glPushMatrix();
			glScalef(0.2, 0.1, 1.0);
			prisma();
			glPopMatrix();

			glTranslatef(-0.1, -0.0, 0.0);
			glRotatef(angMenique3, 0.0, 1.0, 0.0);
			glTranslatef(-0.1, -0.0, 0.0);
			glColor3f(1.0, 0.0, 1.0);
			glPushMatrix();
			glScalef(0.2, 0.1, 1.0);
			prisma();
			glPopMatrix();

		glPopMatrix();

		glPopMatrix();	


	glPopMatrix();

}
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);

	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);


	//NEW Iniciar variables de KeyFrames
	for(int i=0; i<MAX_FRAMES; i++)
	{
		KeyFrame[i].posX =0;
		KeyFrame[i].posY =0;
		KeyFrame[i].posZ =0;
		KeyFrame[i].incX =0;
		KeyFrame[i].incY =0;
		KeyFrame[i].incZ =0;
		KeyFrame[i].rotRodIzq =0;
		KeyFrame[i].rotInc =0;
		KeyFrame[i].giroMonito =0;
		KeyFrame[i].giroMonitoInc =0;
		KeyFrame[i].rotBraIzq = 0;
		KeyFrame[i].rotBraIzqInc = 0;
		KeyFrame[i].rotBraDer = 0;
		KeyFrame[i].rotBraDerInc = 0;
		KeyFrame[i].rotRodDer = 0;
		KeyFrame[i].rotDerInc = 0;
		KeyFrame[i].rotcabeza = 0;
		KeyFrame[i].rotcabezainc = 0;
	}
	//NEW//////////////////NEW//////////////////NEW///////////

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	glPushMatrix();
	

	glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			glPushMatrix(); //Creamos brazo
				glDisable(GL_LIGHTING);
				brazo();
				glEnable(GL_LIGHTING);
			glPopMatrix();
	


			glEnable(GL_LIGHTING);
			glPopMatrix();
					

			glColor3f(1.0,1.0,1.0);

		glPopMatrix();
	glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
			glColor3f(1.0,0.0,0.0);
			pintaTexto(-11,12.0,-14.0,(void *)font,"Practica 11");
			pintaTexto(-11,8.5,-14,(void *)font,s);
			glColor3f(1.0,1.0,1.0);
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

}

void animacion()
{
	if(play)
	{		
		
		if(	i_curr_steps >= i_max_steps) //end of animation between frames?
		{			
			playIndex++;		
			if(playIndex>FrameIndex-2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex=0;
				play=false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
				//Interpolation
				interpolation();

			}
		}
		else
		{
			//Draw animation
			posX+=KeyFrame[playIndex].incX;
			posY+=KeyFrame[playIndex].incY;
			posZ+=KeyFrame[playIndex].incZ;

			rotRodIzq+=KeyFrame[playIndex].rotInc;
			giroMonito+=KeyFrame[playIndex].giroMonitoInc;


			rotBraIzq += KeyFrame[playIndex].rotBraIzqInc;

			rotBraDer += KeyFrame[playIndex].rotBraDerInc;

			rotRodDer += KeyFrame[playIndex].rotDerInc;

			rotcabeza += KeyFrame[playIndex].rotcabezainc;

			i_curr_steps++;
		}
		
	}


	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'k':		//
		case 'K':
			if(FrameIndex<MAX_FRAMES)
			{
				saveFrame();
			}

			break;

		case 'l':						
		case 'L':
			if(play==false && (FrameIndex>1))
			{

				resetElements();
				//First Interpolation				
				interpolation();

				play=true;
				playIndex=0;
				i_curr_steps = 0;
			}
			else
			{
				play=false;
			}
			break;

		case 'y':						
		case 'Y':
			posZ++;
			printf("%f \n", posZ);
			break;

		case 'g':						
		case 'G':
			posX--;
			printf("%f \n", posX);
			break;

		case 'h':						
		case 'H':
			posZ--;
			printf("%f \n", posZ);
			break;

		case 'j':						
		case 'J':
			posX++;
			printf("%f \n", posX);
			break;

		case 'b':						
			rotRodIzq--;
			printf("%f \n", rotRodIzq);
			break;

		case 'B':						
			rotRodIzq++;
			printf("%f \n", rotRodIzq);
			break;

		case 'p':						
			giroMonito++;
			break;

		case 'P':						
			giroMonito--;
			break;

		case 'n':
			rotBraIzq--;
			break;

		case 'N':
			rotBraIzq++;
			break;

		case 'm':
			rotBraDer++;
			break;

		case 'M':
			rotBraDer--;
			break;


		case 'v':
			rotRodDer--;
			break;

		case 'V':
			rotRodDer++;
			break;

		case 'c':
			rotcabeza--;
			break;

		case 'C':
			rotcabeza++;
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

void menuKeyFrame( int id)
{
	switch (id)
	{
		case 0:	//Save KeyFrame
			if(FrameIndex<MAX_FRAMES)
			{
				saveFrame();
			}
			break;

		case 1:	//Play animation
			if(play==false && FrameIndex >1)
			{

				resetElements();
				//First Interpolation
				interpolation();

				play=true;
				playIndex=0;
				i_curr_steps = 0;
			}
			else
			{
				play=false;
			}
			break;


	}
}


void menu( int id)
{
	
}



int main ( int argc, char** argv )   // Main Function
{
  int submenu;
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 11"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );

  submenu = glutCreateMenu	  ( menuKeyFrame );
  glutAddMenuEntry	  ("Guardar KeyFrame", 0);
  glutAddMenuEntry	  ("Reproducir Animacion", 1);
  glutCreateMenu	  ( menu );
  glutAddSubMenu	  ("Animacion Monito", submenu);
 
  glutAttachMenu	  (GLUT_RIGHT_BUTTON);


  glutMainLoop        ( );          // 

  return 0;
}