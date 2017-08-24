//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Hernández Gómez Mauricio Alejandro		******//
//*************Version de Visual Studio 2017			******//
//************************************************************//
#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();							// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar
	glPointSize(20.0f);							//vamos a hacer que se vea mas grande el punto (pixel no es lo mismo que un punto)
	//glBegin(GL_POINTS);
	//glBegin(GL_LINES);						//Desde aqui vamos a indicar de donde a donde vamos a dibujar (Modo de dibujo) gl POINTS,LINES (lines va por pares)
	//glBegin(GL_LINE_LOOP);					//UNir todos los vertices
	//glBegin(GL_TRIANGLES);					//Toma 3 puntos y genera un triangulo, solo usa 3 vertices
	//glBegin(GL_POLYGON);						//Dibuja un poligono con todos los puntos, si quiero mas poligonos necesito mas begins y ends
	//glColor3f(1.0f,0.0f,0.0f);					//Añado color al poligono
	//glVertex3f(0.0f,0.0f,-1.2f);				//Dibujo un vertice un punto pues
	//glColor3f(1.0f, 1.0f, 0.0f);
	//glVertex3f(-3.0f, 3.0f, -1.2f);
	//glColor3f(0.0f, 0.0f, 1.0f);
	//glVertex3f(3.5f, 4.0f, -1.2f);
	//glColor3f(0.0f, 1.0f, 0.0f);
	//glVertex3f(4.0f, -1.0f, -1.2f);
	//glColor3f(1.0f, 0.0f, 1.0f);
	//glVertex3f(2.0f, -4.0f, -1.2f);
	//glVertex3f(13.5f, -3.0f, -1.2f);
	/*glBegin(GL_LINES);
	glVertex3f(1.0f, 1.0f, -1.2f);
	glVertex3f(1.0f, 9.0f, -1.2f);


	glVertex3f(1.0f, 9.0f, -1.2f);
	glVertex3f(9.0f, 9.0f, -1.2f);


	glVertex3f(9.0f, 9.0f, -1.2f);
	glVertex3f(9.0f, 7.0f, -1.2f);



	glVertex3f(9.0f, 7.0f, -1.2f);
	glVertex3f(3.0f, 7.0f, -1.2f);


	glVertex3f(3.0f, 7.0f, -1.2f);
	glVertex3f(3.0f, 3.0f, -1.2f);


	glVertex3f(3.0f, 3.0f, -1.2f);
	glVertex3f(9.0f, 3.0f, -1.2f);


	glVertex3f(9.0f, 3.0f, -1.2f);
	glVertex3f(9.0f, 1.0f, -1.2f);


	glVertex3f(9.0f, 1.0f, -1.2f);
	glVertex3f(1.0f, 1.0f, -1.2f);

	*/


	glBegin(GL_POLYGON);

	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(4.0f, 8.0f, -1.2f);
	glVertex3f(8.0f, 0.0f, -1.2f);
	glVertex3f(0.0f, -8.0f, -1.2f);
	glVertex3f(-8.0f, -0.0f, -1.2f);
	glVertex3f(-4.0f, 8.0f, -1.2f);
	glEnd();									//Aqui digo que aqui termina lo que voy a dibujar

	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-4.0f, 8.0f, -1.2f);
	glVertex3f(0.0f, 24.0f, -1.2f);
	glVertex3f(4.0f, 8.0f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(4.0f, 8.0f, -1.2f);
	glVertex3f(20.0f, 12.0f, -1.2f);
	glVertex3f(8.0f, 0.0f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(8.0f, 0.0f, -1.2f);
	glVertex3f(16.0f, -16.0f, -1.2f);
	glVertex3f(0.0f, -8.0f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, -8.0f, -1.2f);
	glVertex3f(-16.0f, -16.0f, -1.2f);
	glVertex3f(-8.0f, 0.0f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-8.0f, 0.0f, -1.2f);
	glVertex3f(-20.0f, 12.0f, -1.2f);
	glVertex3f(-4.0f, 8.0f, -1.2f);
	glEnd();


	/*Aqui inicia mi nombre HGMA*/
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-50.0f, -50.0f, -1.2f);
	glVertex3f(-50.0f, -34.0f, -1.2f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-50.0f, -34.0f, -1.2f);
	glVertex3f(-42.0f, -42.0f, -1.2f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-42.0f, -42.0f, -1.2f);
	glVertex3f(-34.0f, -34.0f, -1.2f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-34.0f, -34.0f, -1.2f);
	glVertex3f(-34.0f, -50.0f, -1.2f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-34.0f, -50.0f, -1.2f);
	glVertex3f(-36.0f, -50.0f, -1.2f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-36.0f, -50.0f, -1.2f);
	glVertex3f(-36.0f, -40.0f, -1.2f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-36.0f, -40.0f, -1.2f);
	glVertex3f(-42.0f, -46.0f, -1.2f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-42.0f, -46.0f, -1.2f);
	glVertex3f(-48.0f, -40.0f, -1.2f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-48.0f, -40.0f, -1.2f);
	glVertex3f(-48.0f, -50.0f, -1.2f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-48.0f, -50.0f, -1.2f);
	glVertex3f(-50.0f, -50.0f, -1.2f);
	glEnd();



	/*Hasta aqui la M*/

	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-24.0f, -50.0f, -1.2f);
	glVertex3f(-16.0f, -34.0f, -1.2f);
	glVertex3f(-16.0f, -40.0f, -1.2f);
	glVertex3f(-20.0f, -50.0f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-16.0f, -40.0f, -1.2f);
	glVertex3f(-16.0f, -34.0f, -1.2f);
	glVertex3f(-8.0f, -50.0f, -1.2f);
	glVertex3f(-12.0f, -50.0f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-18.0f, -45.0f, -1.2f);
	glVertex3f(-14.0f, -45.0f, -1.2f);
	glVertex3f(-13.2f, -47.0f, -1.2f);
	glVertex3f(-18.8f, -47.0f, -1.2f);
	glEnd();


	/*Hasta aqui la A*/

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f);

	glVertex3f(6.0f, -50.0f, -1.2f);
	glVertex3f(6.0f, -34.0f, -1.2f);

	glVertex3f(6.0f, -34.0f, -1.2f);
	glVertex3f(8.0f, -34.0f, -1.2f);

	glVertex3f(8.0f, -34.0f, -1.2f);
	glVertex3f(8.0f, -41.0f, -1.2f);

	glVertex3f(8.0f, -41.0f, -1.2f);
	glVertex3f(20.0f, -41.0f, -1.2f);

	glVertex3f(20.0f, -41.0f, -1.2f);
	glVertex3f(20.0f, -34.0f, -1.2f);

	glVertex3f(20.0f, -34.0f, -1.2f);
	glVertex3f(22.0f, -34.0f, -1.2f);

	glVertex3f(22.0f, -34.0f, -1.2f);
	glVertex3f(22.0f, -50.0f, -1.2f);

	glVertex3f(22.0f, -50.0f, -1.2f);
	glVertex3f(20.0f, -50.0f, -1.2f);

	glVertex3f(20.0f, -50.0f, -1.2f);
	glVertex3f(20.0f, -43.0f, -1.2f);

	glVertex3f(20.0f, -43.0f, -1.2f);
	glVertex3f(8.0f, -43.0f, -1.2f);

	glVertex3f(8.0f, -43.0f, -1.2f);
	glVertex3f(8.0f, -50.0f, -1.2f);

	glVertex3f(8.0f, -50.0f, -1.2f);
	glVertex3f(6.0f, -50.0f, -1.2f);

	glEnd();

	/*Hasta aqui la H*/


	glBegin(GL_POLYGON);

	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(32.0f, -50.0f, -1.2f);
	glVertex3f(32.0f, -34.0f, -1.2f);
	glVertex3f(36.0f, -38.0f, -1.2f);
	glVertex3f(36.0f, -50.0f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(32.0f, -34.0f, -1.2f);
	glVertex3f(36.0f, -38.0f, -1.2f);
	glVertex3f(48.0f, -38.0f, -1.2f);
	glVertex3f(48.0f, -34.0f, -1.2f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(32.0f, -50.0f, -1.2f);
	glVertex3f(36.0f, -46.0f, -1.2f);
	glVertex3f(40.0f, -46.0f, -1.2f);
	glVertex3f(48.0f, -50.0f, -1.2f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(40.0f, -46.0f, -1.2f);
	glVertex3f(40.0f, -42.0f, -1.2f);
	glVertex3f(48.0f, -42.0f, -1.2f);
	glVertex3f(48.0f, -50.0f, -1.2f);


	glEnd();




	glFlush();
}

void reshape ( int width , int height )			// Creamos funcion Reshape
{
	if (height==0)								// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal
	glOrtho(-60,60,-60,60,0.1,2);						//definen limites superiores inferiores (horizontal, vertical, profundidad)

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									//para no modificar lo que ya teniamos cargo la matriz identidad
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

