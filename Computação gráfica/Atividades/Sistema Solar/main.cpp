#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
static int year = 0, day = 0;

/* angulos de rotacao para os corpos celestes */
float angleMercurio = 0;

float angleVenus = 0;

float angleEarth = 0;

	float angleMoon = 0;

float angleMars = 0;

float angleJupter = 0;

	float angleEuropaMoon = 0;
	
	float angleCalistoMoon = 0;
	
	float angleGanimedesMoon = 0;
	
	float angleIoMoon = 0;
	
float angleSaturno = 0;

float angleUrano = 0;

float angleNetuno = 0;

/* para a camera, lembrem-se dos exercicios anteriores */
#define y_min 60
#define ro_min 360
float eyex = 0;
float eyey = y_min;
float eyez = ro_min;

// desenha sol
void drawSun(){
	
	glColor3f( 1, 1, 0 );
	glutSolidSphere( 25,35, 35);

}

//desenha mercurio
void drawMercurio(){

	glColor3f( 1, 0.4, 0 );
	glutSolidSphere( 2, 20, 20 );

}

//desenha venus
void drawVenus(){
	
	glColor3f( 0.9, 0.7, 0 );
	glutSolidSphere( 3, 16, 16 );

}

//desenha terra
void drawEarth(){

	glColor3f( 0, 0, 1 );
	glutSolidSphere( 5,20, 20 );

}

//desenha lua da terra
void drawMoon(){
	
	glColor3f( 0.5, 0.5, 0.5 );
	glutSolidSphere( 2.3, 20, 20 );

}

//desenha marte
void drawMars(){
	
	glColor3f( 1, 0.2, 0 );
	glutSolidSphere( 4, 20, 20 );

}

//desenha jupter
void drawJupter(){
	
	glColor3f( 1, 0.7, 0 );
	glutSolidSphere( 9, 25, 25 );

}

void drawMoonEuropa(){
	
	glColor3f( 0.5, 0.5, 0.5 );
	glutSolidSphere( 1.2, 16, 16 );

}

void drawMoonCalisto(){

	glColor3f( 0.5, 0.5, 0.5 );
	glutSolidSphere( 1.1, 16, 16 );

}

void drawMoonGanimedes(){

	glColor3f( 0.5, 0.5, 0.5 );
	glutSolidSphere( 1.3, 16, 16 );

}

void drawMoonIo(){

	glColor3f( 0.5, 0.5, 0.5 );
	glutSolidSphere( 1.2, 16, 16 );

}
//desenha saturno
void drawSaturno(){

	glColor3f( 1, 0.5, 0 );
	glutSolidSphere( 6.8, 22, 22 );

}

//desenha urano
void drawUrano(){

	glColor3f( 0, 0.5, 0.6 );
	glutSolidSphere( 4.55, 20, 20 );

}

//desenha netuno
void drawNetuno(){

	glColor3f( 0.1, 0, 0.7 );
	glutSolidSphere( 4.55, 20, 20 );

}

void display(void){
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
	gluLookAt(eyex,eyey,eyez,0,0,0,0.2,1,0);
	
	// Desenha os planetas do sistema solar
	glPushMatrix();
	
	drawSun();
	  	//mercurio
		glPushMatrix();
	  	  	glRotatef( angleMercurio, 0, 1, 0 );
	    	glTranslatef( 35, 0, 0 );
	    	drawMercurio();
	 	glPopMatrix();
	  
	 	//venus
	    glPushMatrix();
		    glRotatef( angleVenus, 0, 1, 0 );
		    glTranslatef( 48, 0, 0 );
		    drawVenus();
	  	glPopMatrix();
	  
	 	//terra
	 	glPushMatrix();
		    glRotatef( angleEarth, 0, 1, 0 );
		    glTranslatef( 70, 0, 0 );
	   		drawEarth();
		    
		    glPushMatrix();
			    glRotatef( angleMoon, 0, 1, 0 );
			    glTranslatef( 8, 0, 0 );
		     	drawMoon(); 
		    glPopMatrix();
	  	glPopMatrix();
	  
	    //marte
	  	glPushMatrix();
		    glRotatef( angleMars, 0, 1, 0 );
		    glTranslatef( 95, 0, 0 );
	   		drawMars();
	  	glPopMatrix();
	  
	    // jupter
	  	glPushMatrix();
	    glRotatef( angleJupter, 0, 1, 0 );
	    glTranslatef( 125, 0, 0 );
	    drawJupter();
	    
		    //Lua Europa
		    glPushMatrix();
				glRotatef( angleEuropaMoon, 0, 1, 0 );
				glTranslatef( 14.25, 0, 0 );
				drawMoonEuropa();
		    glPopMatrix();
		    
		    //Lua Calisto
		    glPushMatrix();
			    glRotatef( angleCalistoMoon, 0, 1, 0 );
				glTranslatef( -19.95, 0, 0 );
				drawMoonCalisto();
		    glPopMatrix();
		    
		     //Lua Ganimedes
		    glPushMatrix();
			    glRotatef( angleGanimedesMoon, 0, 1, 0 );
				glTranslatef( -16.47, 0, 0 );
				drawMoonGanimedes();
		    glPopMatrix();
		    
		     //Lua Io
		    glPushMatrix();
			    glRotatef( angleIoMoon, 0, 1, 0 );
				glTranslatef( -12.65, 0, 0 );
				drawMoonIo();
		    glPopMatrix();
	    
	  	glPopMatrix();
	  
	  	//saturno
	  	glPushMatrix();
			glRotatef( angleSaturno, 0, 1, 0 );
			glTranslatef( 156, 0, 0 );
			drawSaturno();
	  	glPopMatrix();
	  
		//urano
		glPushMatrix();
			glRotatef( angleUrano, 0, 1, 0 );
			glTranslatef( 178, 0, 0 );
			drawUrano();
		glPopMatrix();
		
		//netuno
		glPushMatrix();
			glRotatef( angleNetuno, 0, 1, 0 );
			glTranslatef( 201, 0, 0 );
			drawNetuno();
		glPopMatrix();

	glPopMatrix();
	
	glutSwapBuffers();
	 
}


void
TimerFunction( int value ){
	//rotação mercurio
	angleMercurio += 3;
	if( angleMercurio >= 360 ) angleMercurio = 0;
	
	//rotação venus
	angleVenus += 2.8;
	if( angleVenus >= 360 ) angleVenus = 0;
	
	//rotação terra
	angleEarth += 2;
	if( angleEarth >= 360 ) angleEarth = 0;
	
		//rotação lua
		angleMoon += 6;
		if( angleMoon >= 360 ) angleMoon = 0;
	
	//rotação marte
	angleMars += 2.1;
	if( angleMars >= 360 ) angleMars = 0;
	
	//rotação jupter
	angleJupter += 1.5;
	if( angleJupter >= 360 ) angleJupter = 0;
		
		//rotação europa
		angleEuropaMoon += 4.5;
		if( angleEuropaMoon >= 360 ) angleEuropaMoon = 0;
		
		//rotação calisto
		angleCalistoMoon += 3;
		if( angleCalistoMoon >= 360 ) angleCalistoMoon = 0;
		
		
		//rotação Ganimedes
		angleGanimedesMoon += 3.8;
		if( angleGanimedesMoon >= 360 ) angleGanimedesMoon = 0;
		
		
		//rotação Io
		angleIoMoon += 5;
		if( angleIoMoon >= 360 ) angleIoMoon = 0;
		
		
	//rotação saturno
	angleSaturno += 1.2;
	if( angleSaturno >= 360 ) angleSaturno = 0;
	
	//rotação urano
	angleUrano += 1.01;
	if( angleUrano >= 360 ) angleUrano = 0;
	
	//rotação netuno
	angleNetuno += 0.5;
	if( angleNetuno >= 360 ) angleNetuno = 0;
	
	
	glutPostRedisplay();
	glutTimerFunc( 33, TimerFunction, 1);
}

// Teclado comandos
void keyboard (unsigned char key, int x, int y){
	switch (key) {
		case 'd':
			day = (day + 10) % 360;
			glutPostRedisplay();break;
		case 'D':
			day = (day - 10) % 360;
			glutPostRedisplay();
		break;
		case 'y':
			year = (year + 5) % 360;
			glutPostRedisplay();
		break;
		case 'Y':
			year = (year - 5) % 360;
			glutPostRedisplay();
		break;
		
		default:
		break;
	}
}

void reshape(int width,int height){
	
	glViewport(0,0,width,height); // Reset The Current Viewport
	
	glMatrixMode(GL_PROJECTION); // Select The Projection Matrix
	glLoadIdentity(); // Reset The Projection Matrix
	
	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.f,(float)850/(float)480,0.1f,1000.0f);
	// Always keeps the same aspect as a 640 wide and 480 high window
	
	glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
	glLoadIdentity(); // Reset The Modelview Matrix
}

void init()
{
	glClearColor(0,0,0.0,0);
	glClearDepth(1.0); // Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS); // The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST); // Enables Depth Testing
	glShadeModel(GL_SMOOTH); // Enables Smooth Color Shading
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE); // We want rgb display functionality
	glutInitWindowSize(1300,700); // Set the window dimensions
	glutInitWindowPosition(0,0); // Set the window starting point
	glutCreateWindow("Sistema Solar"); // Set the caption and launch the window
	
	init();
	
	glutTimerFunc( 33, TimerFunction, 1);
	// Last things before rendering starts
	glutDisplayFunc(display); // This will be called every frame
	glutReshapeFunc(reshape); // Reshape the window when something changes
	//glutKeyboardFunc(key); // Callback for input
	
	glutMainLoop(); // Starts the main program
	
	return 0;
}
