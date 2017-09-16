//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//******Hernández Gómez Mauricio Alejandro (Mago Da Maus)******//
//*************		Visual studio 2017					******//
//************************************************************//

/*
CONTROLES


FLECHAS = CAMARA
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


float angleX = 0.0f;
float angleY = 0.0f;
float transZ = -10.0f;
float transY = 0.0f;
float transX = 0.0f;
int screenW = 0.0;
int screenH = 0.0;



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


//************************************


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


		//cabeza
		glPushMatrix();
		glColor3f(1.0, 0.0, 0.0);										//0,0,0 (pivote)
		prisma();
		glPopMatrix();


		//cuello
		glPushMatrix();
		glTranslatef(0.0, -0.75, 0.0);
		glScalef(0.5, 0.5, 1.0);
		glColor3f(0.0, 1.0, 0.0);
		prisma();													//0,-0.75,0 (pivote)
		glPopMatrix();


		//cuerpo
		glPushMatrix();
		glTranslatef(0.0, -2.5, 0.0);
		glScalef(3.0, 3.0, 1.0);
		glColor3f(0.0, 0.0, 1.0);									//0,-2.5,0 (pivote)
		prisma();
		glPopMatrix();


		//Brazo izquierdo
		glPushMatrix();
		glTranslatef(-2.0, -1.5, 0.0);
		glScalef(2.0, 2.0, 1.0);

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


			//anular

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


		//Brazo derecho
		glPushMatrix();
		glTranslatef(3.0, -2.0, 0.0);
		glScalef(3.0, 1.0, 1.0);
		glColor3f(1.0, 0.0, 1.0);
		prisma();
		glPopMatrix();


		//Pierna izquierda
		glPushMatrix();
		glTranslatef(-1.0, -6.5, 0.0);
		glScalef(1.0, 5.0, 1.0);
		glColor3f(1.0, 0.0, 1.0);
		prisma();
		glPopMatrix();



		//Pierna derecha
		glPushMatrix();
		glTranslatef(1.0, -6.5, 0.0);
		glScalef(1.0, 5.0, 1.0);
		glColor3f(1.0, 0.0, 1.0);
		prisma();
		glPopMatrix();

		//Pie izquerdo
		glPushMatrix();
		glTranslatef(-1.0, -10.0, 0.0);
		glScalef(2.0, 2.0, 1.0);
		glColor3f(1.0, 1.0, 2.0);
		prisma();
		glPopMatrix();


		//Pie derecho
		glPushMatrix();
		glTranslatef(1.0, -10.0, 0.0);
		glScalef(2.0, 2.0, 1.0);
		glColor3f(0.5, 1.0, 1.0);
		prisma();
		glPopMatrix();





		//mano izq
		glPushMatrix();
		glTranslatef(5.5, -2.0, 0.0);
		glScalef(2.0, 2.0, 1.0);
		glColor3f(0.5, 1.0, 1.0);
		prisma();
		glPopMatrix();

	glPopMatrix();




	glutSwapBuffers();
	// Swap The Buffers
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
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
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


	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX += 2.0f;
		break;
	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -= 2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY += 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 2.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
						   //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	screenW = glutGet(GLUT_SCREEN_WIDTH);
	screenH = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 4"); // Nombre de la Ventana
	printf("Resolution H: %i \n", screenW);
	printf("Resolution V: %i \n", screenH);
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}