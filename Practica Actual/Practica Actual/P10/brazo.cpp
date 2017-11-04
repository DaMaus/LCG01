
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//******Hernández Gómez Mauricio Alejandro (Mago Da Maus)******//
//*************	Visual studio 2017	Iniciar animación con tecla 2******//
//************************************************************//

/*
CONTROLES
Iniciar animación con tecla 2
W,S,A,D = POSICION EN x Y y DE LA FIGURA
Q,E = POSICION EN EJE Z DE LA FIGURA
R = MOV DE BRAZO
T = MOV DE CODO
y = MOV MANO
I = PULGAR 1
O = PULGAR 2
P = INDICE 1
F = INDICE 2
G = INDICE 3
H = MEDIO 1
J = MEDIO 2
K = MEDIO 3
L = ANULAR 1
Ñ = ANULAR 2
Z = ANULAR 3
X = MEÑIQUE 1
C = MEÑIQUE 2
V = MEÑIQUE 3
NOTA IMPORTANTE CADA MOVIMIENTO TIENE UNA LETRA ASOCIADA Y LA PARTE NEGATIVA DEL MOVIMIENTO ES CON LA MISMA TECLA EN MAYUSCULAS
*/


#include "Main.h"

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito


#define MAX_FRAMES 100
int i_max_steps = 90;
int i_curr_steps = 0;

//Variables para el brazo izquierdo

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


typedef struct _frame
{
	float angHombro;
	float angHombroInc;

	float angCodo;
	float angCodoInc;

	float angMano;
	float angManoInc;

	float angPulgar1;
	float angPulgar1Inc;

	float angPulgar2;
	float angPulgar2Inc;

	float angIndice1;
	float angIndice1Inc;

	float angIndice2;
	float angIndice2Inc;

	float angIndice3;
	float angIndice3Inc;

	float angAnu1;
	float angAnu1Inc;

	float angAnu2;
	float angAnu2Inc;

	float angAnu3;
	float angAnu3Inc;

	float angMe1;
	float angMe1Inc;

	float angMe2;
	float angMe2Inc;

	float angMe3;
	float angMe3Inc;

	float angMenique1;
	float angMenique1Inc;

	float angMenique2;
	float angMenique2Inc;

	float angMenique3;
	float angMenique3Inc;



}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos
bool play = false;
int playIndex = 0;


int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font = (int)GLUT_BITMAP_HELVETICA_18;


//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = { 18 };

GLfloat m_dif2[] = { 0.8f, 0.2f, 0.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec2[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb2[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s2[] = { 22 };


float angleX = 0.0f;
float angleY = 0.0f;
float transZ = -10.0f;
float transY = 0.0f;
float transX = 0.0f;
int screenW = 0.0;
int screenH = 0.0;



//************************************


void saveFrame(void)
{
	FILE *f;
	f = fopen("frames.txt", "a+");
	KeyFrame[FrameIndex].angAnu3 = angAnu3;
		fprintf(f, "%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n", angHombro, angCodo, angMano,angPulgar1,angPulgar2,angIndice1,angIndice2,angIndice3, angAnu1, angAnu2, angAnu3,angMe1,angMe2,angMe3,angMenique1,angMenique2,angMenique3);
	fclose(f);

	printf("frameindex %d\n", FrameIndex);

	KeyFrame[FrameIndex].angHombro = angHombro;
	KeyFrame[FrameIndex].angCodo = angCodo;
	KeyFrame[FrameIndex].angMano = angMano;
	KeyFrame[FrameIndex].angPulgar1 = angPulgar1;
	KeyFrame[FrameIndex].angPulgar2 = angPulgar2;
	KeyFrame[FrameIndex].angIndice1 = angIndice1;
	KeyFrame[FrameIndex].angIndice2 = angIndice2;
	KeyFrame[FrameIndex].angIndice3 = angIndice3;
	KeyFrame[FrameIndex].angAnu3 = angAnu3;
	KeyFrame[FrameIndex].angAnu2 = angAnu2;
	KeyFrame[FrameIndex].angAnu1 = angAnu1;
	KeyFrame[FrameIndex].angMe3 = angMe3;
	KeyFrame[FrameIndex].angMe2 = angMe2;
	KeyFrame[FrameIndex].angMe1 = angMe1;
	KeyFrame[FrameIndex].angMenique3 = angMenique3;
	KeyFrame[FrameIndex].angMenique2 = angMenique2;
	KeyFrame[FrameIndex].angMenique1 = angMenique1;


	FrameIndex++;
}

void resetElements(void)
{
	angHombro = KeyFrame[0].angHombro;
	angCodo = KeyFrame[0].angCodo;
	angMano = KeyFrame[0].angMano;

	angPulgar1 = KeyFrame[0].angPulgar1;
	angPulgar2 = KeyFrame[0].angPulgar2;

	angIndice1 = KeyFrame[0].angIndice1;
	angIndice2 = KeyFrame[0].angIndice2;
	angIndice3 = KeyFrame[0].angIndice3;

	angAnu1 = KeyFrame[0].angAnu1;
	angAnu2 = KeyFrame[0].angAnu2;
	angAnu3 = KeyFrame[0].angAnu3;

	angMe1 = KeyFrame[0].angMe1;
	angMe2 = KeyFrame[0].angMe2;
	angMe3 = KeyFrame[0].angMe3;

	angMenique1 = KeyFrame[0].angMenique1;
	angMenique2 = KeyFrame[0].angMenique2;
	angMenique3 = KeyFrame[0].angMenique3;

}

void interpolation(void)
{
	KeyFrame[playIndex].angHombroInc = (KeyFrame[playIndex + 1].angHombro - KeyFrame[playIndex].angHombro) / i_max_steps;
	KeyFrame[playIndex].angCodoInc = (KeyFrame[playIndex + 1].angCodo - KeyFrame[playIndex].angCodo) / i_max_steps;
	KeyFrame[playIndex].angManoInc = (KeyFrame[playIndex + 1].angMano - KeyFrame[playIndex].angMano) / i_max_steps;

	KeyFrame[playIndex].angPulgar1Inc = (KeyFrame[playIndex + 1].angPulgar1 - KeyFrame[playIndex].angPulgar1) / i_max_steps;
	KeyFrame[playIndex].angPulgar2Inc = (KeyFrame[playIndex + 1].angPulgar2 - KeyFrame[playIndex].angPulgar2) / i_max_steps;

	KeyFrame[playIndex].angIndice1Inc = (KeyFrame[playIndex + 1].angIndice1 - KeyFrame[playIndex].angIndice1) / i_max_steps;
	KeyFrame[playIndex].angIndice2Inc = (KeyFrame[playIndex + 1].angIndice2 - KeyFrame[playIndex].angIndice2) / i_max_steps;
	KeyFrame[playIndex].angIndice3Inc = (KeyFrame[playIndex + 1].angIndice3 - KeyFrame[playIndex].angIndice3) / i_max_steps;

	KeyFrame[playIndex].angAnu1Inc = (KeyFrame[playIndex + 1].angAnu1 - KeyFrame[playIndex].angAnu1) / i_max_steps;
	KeyFrame[playIndex].angAnu2Inc = (KeyFrame[playIndex + 1].angAnu2 - KeyFrame[playIndex].angAnu2) / i_max_steps;
	KeyFrame[playIndex].angAnu3Inc = (KeyFrame[playIndex + 1].angAnu3 - KeyFrame[playIndex].angAnu3) / i_max_steps;

	KeyFrame[playIndex].angMe1Inc = (KeyFrame[playIndex + 1].angMe1 - KeyFrame[playIndex].angMe1) / i_max_steps;
	KeyFrame[playIndex].angMe2Inc = (KeyFrame[playIndex + 1].angMe2 - KeyFrame[playIndex].angMe2) / i_max_steps;
	KeyFrame[playIndex].angMe3Inc = (KeyFrame[playIndex + 1].angMe3 - KeyFrame[playIndex].angMe3) / i_max_steps;

	KeyFrame[playIndex].angMenique1Inc = (KeyFrame[playIndex + 1].angMenique1 - KeyFrame[playIndex].angMenique1) / i_max_steps;
	KeyFrame[playIndex].angMenique2Inc = (KeyFrame[playIndex + 1].angMenique2 - KeyFrame[playIndex].angMenique2) / i_max_steps;
	KeyFrame[playIndex].angMenique3Inc = (KeyFrame[playIndex + 1].angMenique3 - KeyFrame[playIndex].angMenique3) / i_max_steps;


}

void cargadatos()
{
	FILE *f;
	f = fopen("frames.txt", "r");
	FrameIndex = 0;
	int fin = 0;
	while (fin != EOF) {
		fin=fscanf(f, "%f	%f	%f	%f	%f	%f	%f	%f	%f	%f	%f	%f	%f	%f	%f	%f	%f", &KeyFrame[FrameIndex].angHombro, &KeyFrame[FrameIndex].angCodo, &KeyFrame[FrameIndex].angMano, &KeyFrame[FrameIndex].angPulgar1, &KeyFrame[FrameIndex].angPulgar2, &KeyFrame[FrameIndex].angIndice1, &KeyFrame[FrameIndex].angIndice2, &KeyFrame[FrameIndex].angIndice3, &KeyFrame[FrameIndex].angAnu1, &KeyFrame[FrameIndex].angAnu2, &KeyFrame[FrameIndex].angAnu3, &KeyFrame[FrameIndex].angMe1, &KeyFrame[FrameIndex].angMe2, &KeyFrame[FrameIndex].angMe3, &KeyFrame[FrameIndex].angMenique1, &KeyFrame[FrameIndex].angMenique2, &KeyFrame[FrameIndex].angMenique3);
		FrameIndex++;
	}
	fclose(f);
	

}

void InitGL(void)     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
														//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
														//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

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
	glColor3f(0.0, 0.0, 0.0);
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

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
														//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	// codigo aqui


	glPushMatrix();


		//Brazo izquierdo
		glPushMatrix();
		glTranslatef(2.0, -1.5, 0.0);
		glScalef(2.0, 2.0, 0.1);

		glPushMatrix();		////////////////////////////////////

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
			glPopMatrix();

			//antebrazo
			glTranslatef(-0.75,0.0, 0.0);
			glPushMatrix();
				glColor3f(0.0, 0.0, 1.0);
				glTranslatef(-0.75, 0.0, 0.0);
				glScalef(1.0, 0.5, 1.0);
				prisma();
			glPopMatrix();


			//mano
			glTranslatef(-0.75, 0.0, 0.0);
			glRotatef(angMano, 0.0, 0.0, 1.0);
			glPushMatrix();
				glColor3f(1.0, 1.0, 0.0);
				glTranslatef(-0.75, 0.0, 0.0);
				glScalef(0.5, 0.5, 1.0);
				prisma();
			glPopMatrix();


			//pulgar

			//parte 1
			glPushMatrix();
				glTranslatef(-0.75, 0.15, 0.0);
				glRotatef(angPulgar1, 0.0, 0.0, 1.0);
				glTranslatef(0.0, 0.15, 0.0);
				glColor3f(1.0, 1.0, 1.0);
				glPushMatrix();
					glScalef(0.1, 0.2, 1.0);
					prisma();
				glPopMatrix();

			//parte 2
				glTranslatef(0.0, 0.1, 0.0);
				glRotatef(angPulgar2, 0.0, 0.0, 1.0);
				glTranslatef(0.0, 0.1, 0.0);
				glColor3f(1.0, 0.0, 1.0);
				glScalef(0.1, 0.2, 1.0);
				prisma();
			glPopMatrix();


			//indice

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

			glPopMatrix();

			//medio

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

			glPopMatrix();


			//anular

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

			glPopMatrix();


			//menique

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

		glPopMatrix();		//////////////////////////////////////

		glPopMatrix();

		glPopMatrix();




	glutSwapBuffers();
	// Swap The Buffers
}

void animacion()
{
	if (play)
	{

		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)	//end of total animation?
			{
				playIndex = 0;
				play = false;
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
			angHombro += KeyFrame[playIndex].angHombroInc;
			angCodo += KeyFrame[playIndex].angCodoInc;
			angMano += KeyFrame[playIndex].angManoInc;

			angPulgar1 += KeyFrame[playIndex].angPulgar1Inc;
			angPulgar2 += KeyFrame[playIndex].angPulgar2Inc;

			angIndice1 += KeyFrame[playIndex].angIndice1Inc;
			angIndice2 += KeyFrame[playIndex].angIndice2Inc;
			angIndice3 += KeyFrame[playIndex].angIndice3Inc;

			angAnu1 += KeyFrame[playIndex].angAnu1Inc;
			angAnu2 += KeyFrame[playIndex].angAnu2Inc;
			angAnu3 += KeyFrame[playIndex].angAnu3Inc;

			angMe1 += KeyFrame[playIndex].angMe1Inc;
			angMe2 += KeyFrame[playIndex].angMe2Inc;
			angMe3 += KeyFrame[playIndex].angMe3Inc;

			angMenique1 += KeyFrame[playIndex].angMenique1Inc;
			angMenique2 += KeyFrame[playIndex].angMenique2Inc;
			angMenique3 += KeyFrame[playIndex].angMenique3Inc;


			i_curr_steps++;
		}

	}


	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}


void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':
	case 'W':
		transY += 0.2f;
		break;
	case 's':
	case 'S':
		transY -= 0.2f;
		break;
	case 'a':
	case 'A':
		transX -= 0.2f;
		break;
	case 'd':
	case 'D':
		transX += 0.2f;
		break;
	case 'q':
	case 'Q':
		transZ += 0.3f;
		break;
	case 'e':
	case 'E':
		transZ -= 0.3f;
		break;

	//movimiento del brazo izquierdo

	case 'r':
		if (angHombro<80)
		angHombro += 0.8f;
		break;
	case 'R':
		if (angHombro>-80)
		angHombro -= 0.8f;
		break;
	case 't':
		if (angCodo<5)
		angCodo += 0.8f;
		break;
	case 'T':
		if (angCodo>-80)
		angCodo -= 0.8f;
		break;
	case 'y':
		if (angMano<30)
		angMano += 0.8f;
		break;
	case 'Y':
		if (angMano>-30)
		angMano -= 0.8f;
		break;

	case 'i':
		if (angPulgar1<30)
		angPulgar1 += 0.8f;
		break;
	case 'I':
		if (angPulgar1>-10)
		angPulgar1 -= 0.8f;
		break;
	case 'o':
		if (angPulgar2<30)
		angPulgar2 += 0.8f;
		break;
	case 'O':
		if (angPulgar2>-10)
		angPulgar2 -= 0.8f;
		break;

	case 'p':
		if (angIndice1<30)
		angIndice1 += 0.8f;
		break;
	case 'P':
		if (angIndice1>0)
		angIndice1 -= 0.8f;
		break;

	case 'f':
		if (angIndice2<30)
		angIndice2 += 0.8f;
		break;
	case 'F':
		if (angIndice2>0)
		angIndice2 -= 0.8f;
		break;

	case 'g':
		if (angIndice3<30)
		angIndice3 += 0.8f;
		break;
	case 'G':
		if (angIndice3>0)
		angIndice3 -= 0.8f;
		break;

	case 'h':
		if (angMe1<30)
		angMe1 += 0.8f;
		break;
	case 'H':
		if (angMe1>0)
		angMe1 -= 0.8f;
		break;

	case 'j':
		if (angMe2<30)
		angMe2 += 0.8f;
		break;
	case 'J':
		if (angMe2>0)
		angMe2 -= 0.8f;
		break;

	case 'k':
		if (angMe3<30)
		angMe3 += 0.8f;
		break;
	case 'K':
		if (angMe3>0)
		angMe3 -= 0.8f;
		break;

	case 'l':
		if (angAnu1<30)
		angAnu1 += 0.8f;
		break;
	case 'L':
		if (angAnu1>0)
		angAnu1 -= 0.8f;
		break;

	case 'ñ':
		if (angAnu2<30)
		angAnu2 += 0.8f;
		break;
	case 'Ñ':
		if (angAnu2>0)
		angAnu2 -= 0.8f;
		break;

	case 'z':
		if (angAnu3<30)
		angAnu3 += 0.8f;
		break;
	case 'Z':
		if (angAnu3>0)
		angAnu3 -= 0.8f;
		break;

	case 'x':
		if (angMenique1<30)
		angMenique1 += 0.8f;
		break;
	case 'X':
		if (angMenique1>0)
		angMenique1 -= 0.8f;
		break;

	case 'c':
		if (angMenique2<30)
		angMenique2 += 0.8f;
		break;
	case 'C':
		if (angMenique2>0)
		angMenique2 -= 0.8f;
		break;

	case 'v':
		if (angMenique3<30)
		angMenique3 += 0.8f;
		break;
	case 'V':
		if (angMenique3>0)
		angMenique3 -= 0.8f;
		break;

	case '1':		//
		if (FrameIndex<MAX_FRAMES)
		{
			printf("%f, %f, %f \n", angHombro,angCodo,angMano);
			printf("%f, %f \n", angPulgar1,angPulgar2);
			printf("%f, %f, %f \n", angIndice1, angIndice2, angIndice3);
			printf("%f, %f, %f \n", angAnu1, angAnu2, angAnu3);
			printf("%f, %f, %f \n", angMe1, angMe2, angMe3);
			printf("%f, %f, %f \n", angMenique1, angMenique2, angMenique3);
			saveFrame();
		}

		break;

	case '2':
		if (play == false && (FrameIndex>1))
		{

			resetElements();

			//First Interpolation				
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;


	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}


void menuKeyFrame(int id)
{
	switch (id)
	{
	case 0:	//Save KeyFrame
		if (FrameIndex<MAX_FRAMES)
		{
			saveFrame();
		}
		break;

	case 1:	//Play animation
		if (play == false && FrameIndex >1)
		{

			resetElements();
			//First Interpolation
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;


	}
}


int main(int argc, char** argv)   // Main Function
{
	int submenu;
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 11"); // Nombre de la Ventana
									 //glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	cargadatos();
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutIdleFunc(animacion);

	submenu = glutCreateMenu(menuKeyFrame);
	glutAddMenuEntry("Guardar KeyFrame", 0);
	glutAddMenuEntry("Reproducir Animacion", 1);
	glutAddSubMenu("Animacion Monito", submenu);

	glutAttachMenu(GLUT_RIGHT_BUTTON);


	glutMainLoop();          // 

	return 0;
}