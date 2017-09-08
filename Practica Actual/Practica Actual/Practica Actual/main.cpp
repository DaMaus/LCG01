//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//******Hernández Gómez Mauricio Alejandro (Mago Da Maus)******//
//*************		Visual Studio 2017					******//
//Controles:
//Q - Alejar
//E- Acercar
//W,S Rotar en eje Y
//A,D Rotar en eje X
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float transY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;


void InitGL ( void )     // Inicializamos parametros
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
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			//glColor3f(1.0,0.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3f(0.0,0.0,1.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3f(0.0,1.0,0.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(1.0,1.0,1.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glColor3f(0.4,0.2,0.6);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(1.0,1.0,0.0);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		/*
		glTranslatef(0.0f, 0.0f, transZ);

		glPushMatrix();
			glTranslatef(-2.0, 1.0, 1.0);
			prisma();
		glPopMatrix();


		
		glScalef(3.0, 5.0, 2.0);
		glTranslated(0.0, 0.0, 0.0);
		glRotatef(50 * transZ, 0.0, 1.0, 0.0);
		prisma();
		*/



	/*										
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
			glColor3f(0.0,1.0,0.0);
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
			glTranslatef(-3.0,-2.0, 0.0);
			glScalef(3.0, 1.0, 1.0);
			glColor3f(1.0, 0.0, 1.0);									
			prisma();
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
			glScalef(2.0, 2.0, 2.0);
			glColor3f(0.5, 1.0, 1.0);
			prisma();
		glPopMatrix();



		//mano izq
		glPushMatrix();
			glTranslatef(-5.5, -2.0, 0.0);
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

	*/

/*
	glTranslatef(0.0f, 0.0f, transZ);
	glRotatef(50 * transX, 2.0, 1.0, 0.0);
*/

	glTranslatef(0.0f, 0.0f, transZ);
	glRotatef(50 * transY, 1.0, 0.0, 0.0);
	glRotatef(50 * transX, 0.0, 1.0, 0.0);


	glPushMatrix();


		glPushMatrix();								//Cuerpo
			glScalef(5.0, 3.0, 3.0);
			glColor3f(1.0, 0.0, 0.0);
			prisma();	
		glPopMatrix();

		glPushMatrix();								//Pierna izquierda delantera
		glTranslatef(2.0, -2.5, 1.0);
		glScalef(1.0, 2.0, 1.0);
		glColor3f(1.0, 0.0, 0.0);
		prisma();
		glPopMatrix();

		glPushMatrix();								//Pierna derecha delantera
		glTranslatef(2.0, -2.5, -1.0);
		glScalef(1.0, 2.0, 1.0);
		glColor3f(1.0, 0.0, 0.0);
		prisma();
		glPopMatrix();

		glPushMatrix();								//Pierna derecha trasera
		glTranslatef(-2.0, -2.5, -1.0);
		glScalef(1.0, 2.0, 1.0);
		glColor3f(1.0, 0.0, 0.0);
		prisma();
		glPopMatrix();

		glPushMatrix();								//Pierna izquierda trasera
		glTranslatef(-2.0, -2.5, 1.0);
		glScalef(1.0, 2.0, 1.0);
		glColor3f(1.0, 0.0, 0.0);
		prisma();
		glPopMatrix();

		glPushMatrix();								//Cola
		glTranslatef(-3.5, 0.0, 0.0);
		glScalef(2.0, 1.0, 1.0);
		glColor3f(1.0, 0.0, 0.0);
		prisma();
		glPopMatrix();

		glPushMatrix();								//Cola parte 2
		glTranslatef(-4.0, 1.0, 0.0);
		glScalef(1.0, 3.0, 1.0);
		glColor3f(1.0, 0.0, 0.0);
		prisma();
		glPopMatrix();

		glPushMatrix();								//Cola parte 3
		glTranslatef(-5.0 ,2.0, 0.0);
		glScalef(1.0, 1.0, 1.0);
		glColor3f(1.0, 0.0, 0.0);
		prisma();
		glPopMatrix();

		glPushMatrix();								//cabeza principal
		glTranslatef(3.0, 2.5, 0.0);
		glScalef(3.0, 2.0, 2.0);
		glColor3f(1.0, 0.0, 0.0);
		prisma();
		glPopMatrix();

		glPushMatrix();								//oreja izquierda
		glTranslatef(2.0, 4.0, 0.75);
		glScalef(1.0, 1.0, 0.5);
		glColor3f(1.0, 0.0, 0.0);
		prisma();
		glPopMatrix();

		glPushMatrix();								//oreja derecha
		glTranslatef(2.0, 4.0, -0.75);
		glScalef(1.0, 1.0, 0.5);
		glColor3f(1.0, 0.0, 0.0);
		prisma();
		glPopMatrix();

		glPushMatrix();								//bigotitoooooo
		glTranslatef(4.75, 2.0, 0.0);
		glScalef(0.5, 0.5, 1.0);
		glColor3f(1.0, 0.0, 0.0);
		prisma();
		glPopMatrix();

		glPushMatrix();								//Nariz :3
		glTranslatef(4.625, 2.25, 0.0);
		glScalef(0.25, 0.25, 0.5);
		glColor3f(1.0, 0.0, 0.0);
		prisma();
		glPopMatrix();


		
	glPopMatrix();


		
  											
  glutSwapBuffers ( );
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
	//glOrtho(-5,5,-5,5,0.2,20);
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'e':
		case 'E':
			transZ +=0.3f;
			break;
		case 'q':
		case 'Q':
			transZ -= 0.3f;
			break;


		case 'w':
		case 'W':
			transY += 0.3f;
			break;
		case 's':
		case 'S':
			transY -= 0.3f;
			break;

		case 'd':
		case 'D':
			transX += 0.3f;
			break;


		case 'a':
		case 'A':
			transX -= 0.3f;
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
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		break;
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:
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
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}