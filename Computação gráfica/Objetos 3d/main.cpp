/* Template
* Projeto base para aplicacao do OpenGL ja configurado com GLUT_DOUBLE e glutSwapBuffers
* Exemplificando operacoes de transformacao e controle do comportamento pelo teclado
* Referencia do Codigo: OpenGL Programming Guide - RedBook
*/
#include <windows.h>
#include "glut.h"
#include <stdio.h>
#include <stdlib.h>
#include "Porco.h"
#include "Urso.h"
#include "Leao.h"
#include "Lobo.h"
#define WIDTH 1920
#define HEIGHT 1080


/* Definições da câmera */
#define y_min 0
#define ro_min 240

float angleMX = -150;
float angleMY = 0;
 
float angle = 0;

float eyex = 0, eyey = y_min, eyez = ro_min;



void display1(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    /* Limpa o Buffer de Pixels */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    /* Define a posição do observador */
	gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
    glRotatef(angle, 0,1,0);
    /* Desenha os planetas com hierarquia*/
    glTranslatef(angleMX, angleMY, 0);
    glPushMatrix();
    glRotatef(225, 0,1,0);
     	draw_porco();
    	//draw_urso();
    	//draw_leao();
    	//draw_lobo();
	glPopMatrix();
    	
    /* 
	Inicia o processo de desenho atraves dos
    dados bufferizados
    */
    glutSwapBuffers();
}
void display2(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    /* Limpa o Buffer de Pixels */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    /* Define a posição do observador */
	gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
    glRotatef(angle, 0,1,0);
    /* Desenha os planetas com hierarquia*/
    glTranslatef(angleMX, angleMY, 0);
    glPushMatrix();
     	//draw_porco();
     	glRotatef(225, 0,1,0);
    	draw_urso();
    	//draw_leao();
    	//draw_lobo();
	glPopMatrix();
    	
    /* 
	Inicia o processo de desenho atraves dos
    dados bufferizados
    */
    glutSwapBuffers();
}
void display3(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    /* Limpa o Buffer de Pixels */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    /* Define a posição do observador */
	gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
    glRotatef(angle, 0,1,0);
    /* Desenha os planetas com hierarquia*/
    glTranslatef(angleMX, angleMY, 0);
    glPushMatrix();
     	//draw_porco();
    	//draw_urso();
    	glRotatef(225, 0,1,0);
    	draw_leao();
    	//draw_lobo();
	glPopMatrix();
    	
    /* 
	Inicia o processo de desenho atraves dos
    dados bufferizados
    */
    glutSwapBuffers();
}

void display4(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    /* Limpa o Buffer de Pixels */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    /* Define a posição do observador */
	gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
    glRotatef(angle, 0,1,0);
    /* Desenha os planetas com hierarquia*/
    glTranslatef(angleMX, angleMY, 0);
    glPushMatrix();
     	//draw_porco();
    	//draw_urso();
    	//draw_leao();
    	glRotatef(225, 0,1,0);
    	draw_lobo();
	glPopMatrix();
    	
    /* 
	Inicia o processo de desenho atraves dos
    dados bufferizados
    */
    glutSwapBuffers();
}


void TimerFunc(int value) {	
	if((angleMX>=-150 && angleMX < 0) && (angleMY>=0 && angleMY<70)){
            angleMX = angleMX +1;
            angleMY = angleMY +0.46; 
			glutDisplayFunc(display1);      
        }
        if((angleMX>=0 && angleMX <150) && (angleMY<=70 && angleMY>0)){
			angleMX = angleMX +1;
            angleMY = angleMY -0.5; 
			glutDisplayFunc(display2);
        }
        if((angleMX<=150 && angleMX >0) && (angleMY<=0 && angleMY>-70)){
            angleMX = angleMX -1;
            angleMY = angleMY -0.5;
			glutDisplayFunc(display3);

        }
        if((angleMX<=0 && angleMX >-150) && (angleMY>=-70 && angleMY<0)){
            angleMX = angleMX -1;
            angleMY = angleMY +0.5;
            glutDisplayFunc(display4);

        }

	glutPostRedisplay();
	glutTimerFunc( 33, TimerFunc, 1);
}

void reshape(int width, int height) {
	glViewport(0,0,width,height); // Reset The Current Viewport
	
	glMatrixMode(GL_PROJECTION); // Select The Projection Matrix
	glLoadIdentity(); // Reset The Projection Matrix
	
	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(float)WIDTH/(float)HEIGHT,0.1f,1000.0f);
	// Always keeps the same aspect as a 640 wide and 480 high window
	
	glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
	glLoadIdentity(); // Reset The Modelview Matrix
}

void key(unsigned char key, int x, int y) {
	switch(key) {
		case 27:
			exit(0);
			break;
	}
}

void init() {
	glClearColor(1,1,1,1);
	glClearDepth(1.0); // Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS); // The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST); // Enables Depth Testing
	glShadeModel(GL_SMOOTH); // Enables Smooth Color Shading
}

/*
Funcao principal do programa.
*/
int main(int argc, char** argv)
{
	//Inicia a Telinha
	glutInit(&argc,argv);
	
    /*
    Estabelece o modo de exibicao a ser utilizado pela janela a ser
    neste caso utiliza-se de um buffer duplo, ou seja, a apresentacao
    execucao
    Define o modo de cores como RGBA
    */
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    
    /*
    Determina o tamanho em pixels da
    janela a ser criada
    */
    glutInitWindowSize (WIDTH, HEIGHT);
    
    /*
    Estabelece a posicao inicial para criacao da
    janela
    */
    glutInitWindowPosition (0, 0);
    
    /*
    Cria uma janela com base nos parametros especificados
    nas funcoes glutInitWindowSize e glutInitWindowPosition
    com o nome de titulo especificado em seu argumento
    */
    glutCreateWindow ("Projeto Morfing");
    
    /*
    Especifica os parametros inicias para as variaveis
    de estado do OpenGL
    */
    init ();
    
    // Associa a funcao display como uma funcao de callback
    glutDisplayFunc(display1);
	glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    glutTimerFunc(33, TimerFunc, 1);
    /*
    Inicia a execucao do programa OpenGL.
    O programa ira executar num loop infinito devendo
    o desenvolvedor especificar as condicoes de saida do mesmo
    atraves de interrupcoes no proprio programa ou atraves
    de comandos de mouse ou teclado como funcoes de callback
    */
    glutMainLoop();
    return 0;
}
