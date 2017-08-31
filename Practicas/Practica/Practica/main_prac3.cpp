//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Hernández Gómez Mauricio alejandro		******//
//*************	Programado en Visual Studio 2017		******//
//************************************************************//

//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;


void InitGL ( GLvoid )     // Inicializamos parametros
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


//	se usaron 3 variables para cada color
/*
las variables van de tres en tres en el orden RGB y el roden de las caras es: Superior, Inferior, Izquierda, Derecha, Frontal, Trasera
por ultimo la variable 19 es base y la 20 es altura
*/
void prisma(float RS, float GS, float BS, float RI, float GI, float BI, float RIz, float GIz, float BIz, float RD, float GD, float BD, float RF, float GF, float BF, float RA, float GA, float BA, float b, float a)
{
	GLfloat vertice [8][3] = {
				{0.5*b ,-0.5*a, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5*b ,-0.5*a, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5*b ,-0.5*a, -0.5},    //Coordenadas Vértice 2 V2
				{0.5*b ,-0.5*a, -0.5},    //Coordenadas Vértice 3 V3
				{0.5*b ,0.5*a, 0.5},    //Coordenadas Vértice 4 V4
				{0.5*b ,0.5*a, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5*b ,0.5*a, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5*b ,0.5*a, 0.5},    //Coordenadas Vértice 7 V7
				};


		glBegin(GL_POLYGON);	//Front
			glColor3f(RF,GF,BF);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3f(RD, GD, BD);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3f(RA, GA, BA);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(RIz, GIz, BIz);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
	
			glColor3f(RI, GI, BI);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(RS, GS, BS);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		//Poner Código Aquí.
	glTranslatef(0.0+transX, 0.0+transY, -5.0+transZ);  //negativo veo el objeto, sale del pizarron
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleZ, 0.0, 0.0, 1.0);

	prisma(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 2, 1);

	//Lo siguiente comentado es el ejercicio en clase, ahi prisma no tiene parametros, no descomentar
/*
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(1.0, 0.0, -0.0);
	prisma();
	glTranslatef(1.0, 0.0, -0.0);
	prisma();
	glTranslatef(0.0, -1.0, -0.0);
	prisma();
	glTranslatef(0.0, -1.0, -0.0);
	prisma();
	glTranslatef(1.0, 2.0, -0.0);
	prisma();
	glTranslatef(1.0, 0.0, -0.0);
	prisma();
	glTranslatef(0.0, -1.0, -0.0);
	prisma();
	glTranslatef(0.0, -1.0, -0.0);
	prisma();
	glTranslatef(0.0, -1.0, -0.0);
	prisma();
	glTranslatef(0.0, -1.0, -0.0);
	prisma();

	glTranslatef(2.0, 0.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(1.0, 0.0, -0.0);
	prisma();
	glTranslatef(1.0, 0.0, -0.0);
	prisma();
	glTranslatef(1.0, 0.0, -0.0);
	prisma();
	glTranslatef(0.0, -1.0, -0.0);
	prisma();
	glTranslatef(0.0, -1.0, -0.0);
	prisma();
	glTranslatef(-1.0, 0.0, -0.0);
	prisma();
	glTranslatef(-1.0, 0.0, -0.0);
	prisma();
	glTranslatef(2.0, -1.0, -0.0);
	prisma();
	glTranslatef(0.0, -1.0, -0.0);
	prisma();

	glTranslatef(2.0, 0.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(1.0, -4.0, -0.0);
	prisma();
	glTranslatef(1.0, 0.0, -0.0);
	prisma();
	glTranslatef(1.0, 0.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();

	glTranslatef(2.0, -4.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(1.0, 0.0, -0.0);
	prisma();
	glTranslatef(1.0, 0.0, -0.0);
	prisma();
	glTranslatef(1.0, 0.0, -0.0);
	prisma();
	glTranslatef(0.0, -1.0, -0.0);
	prisma();
	glTranslatef(0.0, -1.0, -0.0);
	prisma();
	glTranslatef(-1.0, 0.0, -0.0);
	prisma();
	glTranslatef(-1.0, 0.0, -0.0);
	prisma();
	glTranslatef(1.0, -1.0, -0.0);
	prisma();
	glTranslatef(1.0, -1.0, -0.0);
	prisma();

	glTranslatef(2.0, 0.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();

	glTranslatef(2.0, -4.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(1.0, 0.0, -0.0);
	prisma();
	glTranslatef(1.0, 0.0, -0.0);
	prisma();
	glTranslatef(1.0, 0.0, -0.0);
	prisma();
	glTranslatef(0.0, -4.0, -0.0);
	prisma();
	glTranslatef(-1.0, 0.0, -0.0);
	prisma();
	glTranslatef(-1.0, 0.0, -0.0);
	prisma();
	glTranslatef(-1.0, 0.0, -0.0);
	prisma();

	glTranslatef(5.0, 0.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();

	glTranslatef(2.0, -4.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(0.0, 1.0, -0.0);
	prisma();
	glTranslatef(1.0, 0.0, -0.0);
	prisma();
	glTranslatef(1.0, 0.0, -0.0);
	prisma();
	glTranslatef(1.0, 0.0, -0.0);
	prisma();
	glTranslatef(0.0, -1.0, -0.0);
	prisma();
	glTranslatef(0.0, -1.0, -0.0);
	prisma();
	glTranslatef(0.0, -1.0, -0.0);
	prisma();
	glTranslatef(0.0, -1.0, -0.0);
	prisma();
	glTranslatef(-1.0, 0.0, -0.0);
	prisma();
	glTranslatef(-1.0, 0.0, -0.0);
	prisma();

	*/






		
  											

    glutSwapBuffers ( );
    //glFlush();
    // Swap The Buffers
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
	//glOrtho(-5,5,-5,5,0.1,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50);
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transY +=0.2f;
			printf("Posicion en Z: %f\n", transY);
			break;
		case 's':
		case 'S':
			transY -=0.2f;
			printf("Posicion en Z: %f\n", transY);
			break;
		case 'a':
		case 'A':
			transX -=0.2f;
			break;
		case 'd':
		case 'D':
			transX +=0.2f;
			break;
		case 'Q':
		case 'q':
			transZ -= 0.2f;
			break;
		case 'E':
		case 'e':
			transZ += 0.2f;
			break;

		case 'G':
		case 'g':
			angleX += 1.2f;
			break;

		case 'J':
		case 'j':
			angleX -= 1.2f;
			break;

		case 'Y':
		case 'y':
			angleY += 1.2f;
			break;

		case 'H':
		case 'h':
			angleY -= 1.2f;
			break;

		case 'T':
		case 't':
			angleZ += 1.2f;
			break;

		case 'U':
		case 'u':
			angleZ -= 1.2f;
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
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
      //glutFullScreen ( ); // Full Screen Mode
      //break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
      //glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
      //break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 3"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



