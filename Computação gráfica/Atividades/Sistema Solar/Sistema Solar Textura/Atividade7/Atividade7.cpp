/* Sistema planet�rio - Exerc�cio 3
* Programa: Terra, Lua Marte e Sol
* Objetivo : Anima��o - elementos hier�rquicos
* janelas e fun��es de callback
* Refer�ncia do C�digo: https://www.inf.ufrgs.br/~amaciel/teaching/SIS0381-10-1/exercise8.html

Atividade:
3 � Hierarquia de um planet�rio
https://www.inf.ufrgs.br/~amaciel/teaching/SIS0381-10-1/exercise8.html
- Coloquem uma fonte de luz no centro do Sol.
- Coloquem textura nos planetas e, neste caso, apliquem as rota��es dos planetas sobre seus eixos

Docente: Carolina Yukari Veludo Watanabe
Discentes: Matheus Melo Nascimento e Paulo Vieira Lunas
Compilador: DEV C++ vers�o: 5.11
Sistema Operacional: Windows 10 64 bits
*/

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

GLUquadric* sphere;

#include "tgaload.h"

// Qtd m�xima de texturas a serem usadas no programa
#define MAX_NO_TEXTURES 4

#define CUBE_TEXTURE 0

static int shoulder = 0, elbow = 1, elbow2 = -1;

// vetor com os n�meros das texturas
GLuint texture_id[MAX_NO_TEXTURES];

GLfloat cor_luz0[]        = { 2.0, 2.0, 2.0, 1.0};  // componentes de luz para reflex�o difusa e especular
GLfloat cor_luz0_amb[]    = { 0.3, 0.3, 0.3, 1.0}; 
GLfloat mat_a_brilho[]    = { 50.0 };

void initTexture (void)
{
		glBindTexture ( GL_TEXTURE_2D, texture_id[0] );
	image_t temp_image0;
	tgaLoad  ( "2k_sun.tga", &temp_image0, TGA_FREE | TGA_LOW_QUALITY );
	
		glBindTexture ( GL_TEXTURE_2D, texture_id[1] );
	image_t temp_image1;
	tgaLoad  ( "2k_earth_daymap.tga", &temp_image1, TGA_FREE | TGA_LOW_QUALITY );
	
		glBindTexture ( GL_TEXTURE_2D, texture_id[2] );
	image_t temp_image2;
	tgaLoad  ( "2k_moon.tga", &temp_image2, TGA_FREE | TGA_LOW_QUALITY );
	
		glBindTexture ( GL_TEXTURE_2D, texture_id[3] );
	image_t temp_image3;
	tgaLoad  ( "2k_mars.tga", &temp_image3, TGA_FREE | TGA_LOW_QUALITY );
	
}

void make_tex(void){
    unsigned char data[256][256][3];
    for (int y = 0; y < 255; y++) {
		for (int x = 0; x < 255; x++) {
	    unsigned char *p = data[y][x];
	    p[0] = p[1] = p[2] = (x ^ y) & 8 ? 255 : 0;
		}
	}
   
    glGenTextures (4, texture_id);
	glBindTexture ( GL_TEXTURE_2D, texture_id[0] );
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, (const GLvoid *) data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
}

// Vari�veis para controles de navega��o
GLfloat angle, fAspect;
GLfloat rotX, rotY, rotX_ini, rotY_ini;
GLfloat obsX, obsY, obsZ, obsX_ini, obsY_ini, obsZ_ini;
int x_ini,y_ini,bot;

/* angulos de rotacao para os corpos celestes */
float angleEarth = 0;
float angleMoon = 0;
float angleMars = 0;
float angleSun = 0;

/* para a camera, lembrem-se dos exercicios anteriores */
#define y_min 60
#define ro_min 120
float eyex = 0;
float eyey = y_min;
float eyez = ro_min;

// Largura e altura da janela
GLfloat windowWidth;
GLfloat windowHeight;

void drawSun(){ // desenha o Sol
	
	glRotatef(angleSun, 0, 1, 0);
	
	glColor3f(1.0,1.0,0.0);
    gluQuadricDrawStyle(sphere, GLU_FILL);
    glBindTexture(GL_TEXTURE_2D, texture_id[0]);
    gluQuadricTexture(sphere, GL_TRUE);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    gluSphere(sphere, 12, 32, 16);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_a_brilho);
	
	//glColor3f( 1, 1, 0 );
	//glutSolidSphere( 12, 16, 16 );
}

void drawEarth(){ // desenha a Terra
	
	glRotatef(angleEarth, 0, 1, 0);
	
	gluQuadricDrawStyle(sphere, GLU_FILL);
    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    gluQuadricTexture(sphere, GL_TRUE);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    gluSphere(sphere, 5, 32, 16);
	glColor3f( 0, 0, 1 );
}

void drawMoon(){ // desenha a Lua
	
	glRotatef(angleMoon, 0, 1, 0);
	
	gluQuadricDrawStyle(sphere, GLU_FILL);
    glBindTexture(GL_TEXTURE_2D, texture_id[2]);
    gluQuadricTexture(sphere, GL_TRUE);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    gluSphere(sphere, 1, 32, 16);
	//glColor3f( 0.5, 0.5, 0.5 );
}
void drawMars(){ // desenha Marte
	
	glRotatef(angleMars, 0, 1, 0);
	
	gluQuadricDrawStyle(sphere, GLU_FILL);
    glBindTexture(GL_TEXTURE_2D, texture_id[3]);
    gluQuadricTexture(sphere, GL_TRUE);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    gluSphere(sphere, 5, 32, 16);
	glTranslatef(1.6,-0.3,1.8);
	glScalef(0.4,0.6,0.4);
	
	glPopMatrix();
}

void display(void){
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	//glLoadIdentity();
	
	//gluLookAt(eyex,eyey,eyez,0,0,0,0,1,0);
	
	// Draw planetary system
	glPushMatrix();
	glRotatef(angleSun, 0, 1, 0);
	  drawSun();
	  GLfloat posicao_luz0[]    = { 0.0, 0.0, 0.0, 1.0};  // posi��o da luz
	  glLightfv(GL_LIGHT0, GL_POSITION, posicao_luz0);
	  glPushMatrix();
	    glRotatef(angleEarth, 0, 1, 0);
	    glTranslatef( 30, 0, 0 );
	    drawEarth();
	    glPushMatrix();
	      glRotatef(angleMoon, 0, 1, 0);
	      glTranslatef( 7, 0, 0 );
	      drawMoon();
	    glPopMatrix();
	  glPopMatrix();
	  glPushMatrix();
	    glRotatef(angleMars, 0, 1, 0);
	    glTranslatef( 50, 0, 0 );
	    drawMars();
	  glPopMatrix();
	glPopMatrix();
	
	glutSwapBuffers();
}

void TimerFunction( int value ){
	
	angleSun += 0.5;
	if(angleSun >= 360) angleSun = 0;
	
	angleEarth += 3;
	if(angleEarth >= 360) angleEarth = 0;
	
	angleMoon += 6;
	if(angleMoon >= 360) angleMoon = 0;
	
	angleMars += 2;
	if(angleMars >= 360) angleMars = 0;
	
	glutPostRedisplay();
	glutTimerFunc( 60, TimerFunction, 1);
}

// Fun��o usada para especificar a posi��o do observador virtual
void PosicionaObservador(void){
	
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	// Posiciona e orienta o observador
	glTranslatef(-obsX,-obsY,-obsZ);
	glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);
}

// Fun��o usada para especificar o volume de visualiza��o
void EspecificaParametrosVisualizacao(void){
	
	// Especifica sistema de coordenadas de proje��o
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de proje��o
	glLoadIdentity();

	// Especifica a proje��o perspectiva(angulo,aspecto,zMin,zMax)
	gluPerspective(angle,fAspect,0.1,1200);

	PosicionaObservador();
}

// Fun��o callback chamada quando o tamanho da janela � alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h){
	
	// Para previnir uma divis�o por zero
	if ( h == 0 ) h = 1;

	// Especifica as dimens�es da viewport
	glViewport(0, 0, w, h);
 
	// Calcula a corre��o de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Fun��o callback para eventos de bot�es do mouse
void GerenciaMouse(int button, int state, int x, int y){
	
	if(state==GLUT_DOWN)
	{
		// Salva os par�metros atuais
		x_ini = x;
		y_ini = y;
		obsX_ini = obsX;
		obsY_ini = obsY;
		obsZ_ini = obsZ;
		rotX_ini = rotX;
		rotY_ini = rotY;
		bot = button;
	}
	else bot = -1;
}

// Fun��o callback para eventos de movimento do mouse
#define SENS_ROT	5.0
#define SENS_OBS	15.0
#define SENS_TRANSL	30.0

void GerenciaMovim(int x, int y){
	
	// Bot�o esquerdo ?
	if(bot==GLUT_LEFT_BUTTON){
		// Calcula diferen�as
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica �ngulos
		rotY = rotY_ini - deltax/SENS_ROT;
		rotX = rotX_ini - deltay/SENS_ROT;
	}
	// Bot�o direito ?
	else if(bot==GLUT_RIGHT_BUTTON){
		// Calcula diferen�a
		int deltaz = y_ini - y;
		// E modifica dist�ncia do observador
		obsZ = obsZ_ini + deltaz/SENS_OBS;
	}
	// Bot�o do meio ?
	else if(bot==GLUT_MIDDLE_BUTTON){
		// Calcula diferen�as
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica posi��es
		obsX = obsX_ini + deltax/SENS_TRANSL;
		obsY = obsY_ini - deltay/SENS_TRANSL;
	}
	PosicionaObservador();
	glutPostRedisplay();
}

void inicializa(void){
	
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
  	
	glLightfv(GL_LIGHT0, GL_DIFFUSE, cor_luz0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, cor_luz0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, cor_luz0_amb);
	
	make_tex();
    initTexture ();
    sphere = gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    
    /* Seleciona a cor de fundo para limpeza da tela */
    glClearColor (0.0, 0.0, 0.0, 0.0); // Define a cor de fundo da janela de visualiza��o como branca
    
    // Inicializa a vari�vel que especifica o �ngulo da proje��o
	// perspectiva
	angle=60;
 
	// Inicializa as vari�veis usadas para alterar a posi��o do 
	// observador virtual
	rotX = 90;
	rotY = 0;
	obsX = obsY = 0;
	obsZ = 100;
}

void draw(void){
	
   // glClearColor(0.5, 0.5, 1.0, 1);
   // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // glMatrixMode(GL_MODELVIEW);
   // glLoadIdentity();
    
    glRotatef ((GLfloat) shoulder, 0.0, 1.0, 0.0);

    glColor3f(0.0,.0,0.0);
    gluQuadricDrawStyle(sphere, GLU_FILL);
    glBindTexture(GL_TEXTURE_2D, texture_id[0]);
    gluQuadricTexture(sphere, GL_TRUE);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    gluSphere(sphere, 1.0, 32, 16);

    glutSwapBuffers();
}

void init(void){
	
    glEnable(GL_DEPTH_TEST);
  
    make_tex();
    initTexture ();
    sphere = gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
}

/*
Cria a janela
*/
int main(int argc, char** argv){
	
	//Inicia a Telinha
	glutInit(&argc,argv);
	
    /* Estabelece o modo de exibi��o a ser utilizado pela janela a ser criada
    neste caso utiliza-se de um buffer simples, ou seja, a apresenta��o ser� imediata �
    execu��o
    Define o modo de cores como RGBA */
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    
    /*Determina o tamanho em pixels da
    janela a ser criada*/
    glutInitWindowSize (800, 800);
  
    /* Cria uma janela com base nos par�metros especificados
    nas fun��es glutInitWindowSize e glutInitWindowPosition
    com o nome de t�tulo especificado em seu argumento */
    glutCreateWindow ("Pratica 3 - Exercicio 3 - Sistema Planetario");
    
    TimerFunction(2);
    
    /*Estabelece a posi��o inicial para cria��o da
    janela
    glutInitWindowPosition (100, 100);*/

    // Associa a fun��o display como uma fun��o de callback
    glutDisplayFunc(display );
	
	// Registra a fun��o callback de redimensionamento da janela de visualiza��o
	glutReshapeFunc(AlteraTamanhoJanela); // Reshape the window when something changes 

	// Registra a fun��o callback para eventos de bot�es do mouse	
	glutMouseFunc(GerenciaMouse);
	 
	// Registra a fun��o callback para eventos de movimento do mouse	
	glutMotionFunc(GerenciaMovim);

	// glutKeyboardFunc(keyboard);
	
	// Chama a fun��o respons�vel por fazer as inicializa��es 
	inicializa();
	
    /* Inicia a execu��o do programa OpenGL.
    O programa ir� executar num loop infinito devendo
    o desenvolvedor especificar as condi��es de sa�da do mesmo
    atrav�s de interrup��es no pr�prio programa ou atrav�s
    de comandos de mouse ou teclado como fun��es de callback*/
    glutMainLoop(); //Starts the main program
    
    return 0;
}

