//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int luna = 0;
int marte = 0;
int jupiter = 0;
int saturno = 0;
int urano= 0;
int neptuno= 0;
int luna1 = 0;
int luna2 = 0;
int luna3 = 0;

float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

GLfloat VenusDiffuse[] = { 0.2f, 0.8f, 0.1f, 1.0f };			// Venus
GLfloat VenusSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat VenusShininess[] = { 50.0 };

GLfloat MerDiffuse[] = { 1.0f, 0.1f, 0.1f, 1.0f };			// Mercurio
GLfloat MerSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MerShininess[] = { 50.0 };

GLfloat JuDiffuse[] = { 0.9f, 0.6f, 0.0f, 1.0f };			// Jupiter
GLfloat JuSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat JuShininess[] = { 50.0 };

GLfloat SaDiffuse[] = { 0.957f, 0.857f, 0.876f, 1.0f };			// Saturno
GLfloat SaSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat SaShininess[] = { 50.0 };

GLfloat UrDiffuse[] = { 0.0f, 0.8f, 0.1f, 1.0f };			// Urano
GLfloat UrSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat UrShininess[] = { 50.0 };

GLfloat NepDiffuse[] = { 1.0f, 0.1f, 0.1f, 1.0f };			// Neptuno
GLfloat NepSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat NepShininess[] = { 50.0 };


GLfloat LJDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Lunas Jupiter
GLfloat LJSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat LJShininess[] = { 50.0 };

GLfloat LSDiffuse[] = { 0.0f, 1.0f, 0.9f, 1.0f };			// Lunas Saturno
GLfloat LSSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat LSShininess[] = { 50.0 };



void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,SunDiffuse);
	glLightfv(GL_LIGHT1,GL_SPECULAR,SunSpecular);



}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glLightfv(GL_LIGHT1, GL_POSITION, SunPosition);
	glDisable(GL_LIGHTING);
	glutSolidSphere(2, 50, 12);  //Draw Sun (radio,H,V);
	glEnable(GL_LIGHTING);
	// Mercurio

	glPushMatrix();
		glColor3f(0.545,0.251,0.075);

		//traslacion
		glRotatef(mercurio, 0.0, -1.0, 0.0);
		glPushMatrix();
			glTranslatef(2.5,0.2,0.2);
			glRotatef(mercurio, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MerDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MerSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, MerShininess);
			glutSolidSphere(0.3, 10, 10);  //Draw Sun (radio,H,V);
			glPopMatrix();
	glPopMatrix();

	//Venus
	glPushMatrix();
		glColor3f(0.957, 0.657, 0.376);

		//traslacion
		glRotatef(venus-2, 0.0, -1.0, 0.0);
		glTranslatef(0.5, 0.0, 0.2);
		
		glPushMatrix();
			glTranslatef(3.5, 0.2, 0.2);
			glScalef(1.2, 1.2, 1.2);
			glRotatef(venus, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
			glMaterialfv(GL_FRONT, GL_DIFFUSE, VenusDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, VenusSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, VenusShininess);
			glutSolidSphere(0.3, 10, 10);  //Draw Sun (radio,H,V);
		glPopMatrix();
	glPopMatrix();

	//tierra
	glPushMatrix();
		glColor3f(0.245, 0.457, 0.975);

		//traslacion
		glRotatef(tierra-2, 0.0, -1.0, 0.0);
		glTranslatef(0.5, 0.0, 0.2);
		glPushMatrix();

			glTranslatef(6, 0.2, 0.2);
			glScalef(1.6, 1.6, 1.6);
			glPushMatrix();
				glRotatef(tierra, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
				glMaterialfv(GL_FRONT,GL_DIFFUSE ,EarthDiffuse );
				glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
				glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
				glutSolidSphere(0.3, 10, 10);  //Draw Sun (radio,H,V);
			glPopMatrix();

			//luna
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				//traslacion
				glRotatef(luna, 0.0, -1.0, 0.0);
				glTranslatef(0.5, 0.0, 0.2);
				//rotacion
				glScalef(0.4, 0.4, 0.4);
				glRotatef(luna+2, 0.0, 0.0, 1.0);	//El Sol gira sobre su eje
				glutSolidSphere(0.3, 10, 10);  //Draw Sun (radio,H,V);
			glPopMatrix();
			glPopMatrix();
	glPopMatrix();

	//marte

	glPushMatrix();
		glColor3f(0.957, 0.057, 0.376);

		//traslacion
		glRotatef(marte-6, 0.0, -1.0, 0.0);
		glTranslatef(0.5, 0.0, 0.2);

		glPushMatrix();
			glTranslatef(9.0, 0.2, 0.2);
			glScalef(1.6, 1.6, 1.6);
			glRotatef(marte, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);
			glutSolidSphere(0.3, 10, 10);  //Draw Sun (radio,H,V);
		glPopMatrix();
	glPopMatrix();


	//Jupiter

	glPushMatrix();
		glColor3f(0.9, 0.6, 0.0);
		//traslacion
		glRotatef(jupiter, 0.0, -1.0, 0.0);
		glTranslatef(0.5, 0.0, 0.2);
		glPushMatrix();
			glTranslatef(12.0, 0.2, 0.2);
			glScalef(2.4, 2.4, 2.4);
			glRotatef(jupiter, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
			glMaterialfv(GL_FRONT, GL_DIFFUSE, JuDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, JuSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, JuShininess);
			glutSolidSphere(0.3, 10, 10);  //Draw Sun (radio,H,V);


			//luna1
			glMaterialfv(GL_FRONT, GL_DIFFUSE, LJDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, LJSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, LJShininess);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				//traslacion
				glRotatef(luna1, 0.0, -0.5, 0.0);
				glTranslatef(0.5, 0.0, 0.2);
				//rotacion
				glScalef(0.4, 0.4, 0.4);
				glRotatef(luna1, 0.0, 0.0, 1.0);	//El Sol gira sobre su eje
				glutSolidSphere(0.3, 10, 10);  //Draw Sun (radio,H,V);
			glPopMatrix();
			//luna2
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				//traslacion
				glRotatef(luna2, 0.0, -1.0, 0.0);
				glTranslatef(0.3, 0.6, 0.2);
				//rotacion
				glScalef(0.4, 0.4, 0.4);
				glRotatef(luna2, 0.0, 0.0, 1.0);	//El Sol gira sobre su eje
				glutSolidSphere(0.3, 10, 10);  //Draw Sun (radio,H,V);
			glPopMatrix();

			//luna3
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				//traslacion
				glRotatef(luna3, 0.0, 1.0, 0.0);
				glTranslatef(0.3, -0.6, 0.2);
				//rotacion
				glScalef(0.4, 0.4, 0.4);
				glRotatef(luna3, 0.0, 0.0, 1.0);	//El Sol gira sobre su eje
				glutSolidSphere(0.3, 10, 10);  //Draw Sun (radio,H,V);
			glPopMatrix();
			glPopMatrix();

	glPopMatrix();



	//Saturno

	glPushMatrix();
		glColor3f(0.957, 0.857, 0.876);

		//traslacion
		glRotatef(saturno, 0.0, 1.0, 0.0);
		glTranslatef(0.5, 0.0, 0.2);
		glPushMatrix();
			glTranslatef(15.0, 0.2, 0.2);
			glScalef(1.9, 1.9, 1.9);
			glRotatef(saturno, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
			glMaterialfv(GL_FRONT, GL_DIFFUSE, SaDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, SaSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, SaShininess);
			glutSolidSphere(0.3, 10, 10);  //Draw Sun (radio,H,V);
			glutWireTorus(0.11, 0.7, 10, 10);

			glMaterialfv(GL_FRONT, GL_DIFFUSE, LSDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, LSSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, LSShininess);

			//luna1
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				//traslacion
				glRotatef(luna1, 0.0, -1.0, 0.0);
				glTranslatef(0.8, 0.0, 0.2);
				//rotacion
				glScalef(0.4, 0.4, 0.4);
				glRotatef(luna1 + 2, 0.0, 0.0, 1.0);	//El Sol gira sobre su eje
				glutSolidSphere(0.3, 10, 10);  //Draw Sun (radio,H,V);
			glPopMatrix();
			//luna2
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				//traslacion
				glRotatef(luna2, 0.0, -1.0, 0.0);
				glTranslatef(0.8, 0.6, 0.2);
				//rotacion
				glScalef(0.4, 0.4, 0.4);
				glRotatef(luna2 + 2, 0.0, 0.0, 1.0);	//El Sol gira sobre su eje
				glutSolidSphere(0.3, 10, 10);  //Draw Sun (radio,H,V);
			glPopMatrix();

		glPopMatrix();
	glPopMatrix();


	//Urano


	glPushMatrix();
		glColor3f(0.0, 0.8, 1.0);
		//traslacion
		glRotatef(urano, 0.0, -1.0, 0.0);
		glTranslatef(0.5, 0.0, 0.2);
		glPushMatrix();
			glTranslatef(18.0, 0.2, 0.2);
			glScalef(1.6, 1.6, 1.6);
			glRotatef(urano, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
			glMaterialfv(GL_FRONT, GL_DIFFUSE, UrDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, UrSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, UrShininess);
			glutSolidSphere(0.3, 10, 10);  //Draw Sun (radio,H,V);
		glPopMatrix();
	glPopMatrix();


	//neptuno

	glPushMatrix();
		glColor3f(0.0, 0.6, 1.0);
		//traslacion
		glRotatef(neptuno, 0.0, 1.0, 0.0);
		glTranslatef(0.5, 0.0, 0.2);
		glPushMatrix();
			glTranslatef(21.0, 0.2, 0.2);
			glScalef(1.6, 1.6, 1.6);
			glRotatef(neptuno, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
			glMaterialfv(GL_FRONT, GL_DIFFUSE, NepDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, NepSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, NepShininess);
			glutSolidSphere(0.3, 10, 10);  //Draw Sun (radio,H,V);
		glPopMatrix();
	glPopMatrix();



	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 1) % 360;

		dwLastUpdateTime = dwCurrentTime;

		mercurio = (mercurio - 8) % 360;
		venus = (venus - 7) % 360;
		tierra = (tierra - 6) % 360;
		luna = (luna - 5) % 360;
		marte = (marte - 5) % 360;
		jupiter = (jupiter - 4) % 360;
		saturno = (saturno- 3) % 360;
		urano = (urano - 2) % 360;
		neptuno = (neptuno - 2) % 360;
		luna1 = (luna1 - 5) % 360;
		luna1 = (luna1 - 5) % 360;
		luna1 = (luna1 - 3) % 360;
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

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
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
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...

		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...

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


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tama�o de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut funci�n de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut funci�n en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut funci�n de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}