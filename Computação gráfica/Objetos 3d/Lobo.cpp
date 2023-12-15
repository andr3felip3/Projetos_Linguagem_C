#ifndef LOBO_CPP
#include "glut.h"
//#include "geometry.h"
#define LOBO_CPP


void draw_lobo(){
	
//-------------------------------------------------	
	//corpo
	glPushMatrix();
		glColor3f(0.9, 0.9, 1);
		glScalef(1.6,1.6,1.8);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
	  glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.9, 0.9, 1);
		glScalef(2.5,1.4,1.5);
		glTranslatef(-7,-0.7,0);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
	  glutWireCube(10);
	glPopMatrix();
	
//-------------------------------------------------	
		
	//cabeca
	glPushMatrix();
		glColor3f(0.9, 0.9, 1);
		glScalef(1.3,1.3,1.2);
		glTranslatef(6,-0.5,0);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
//-------------------------------------------------

	//fussinho
	glPushMatrix();
		glColor3f(0.9, 0.9, 1);
		glScalef(1,0.7,1.1);
		glTranslatef(14,-5.5,-0.3);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
//--------------------------------------------------
	
	//pernas 
	
	      //frente
	    
	   //esquerda
	glPushMatrix();
		glColor3f(0.9, 0.9, 1);
		glScalef(0.5,1.3,0.5);
		glTranslatef(8,-10,-9);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	     //direita
	glPushMatrix();
	    glColor3f(0.9, 0.9, 1);
		glScalef(0.5,1.3,0.5);
		glTranslatef(8,-10,9);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	
	         //atras
	    
	   //esquerda
	glPushMatrix();
		glColor3f(0.9, 0.9, 1);
		glScalef(0.5,1.3,0.5);
		glTranslatef(-42,-10,-9);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	     //direita
	glPushMatrix();
	    glColor3f(0.9, 0.9, 1);
		glScalef(0.5,1.3,0.5);
		glTranslatef(-42,-10,9);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
	   glutWireCube(10);
	glPopMatrix();
	
	
//-------------------------------------	
	//unhas
	
       //pe esquerdo frente	
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(17,-190,-30);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(17,-190,-50);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
	  glutWireCube(10);
	glPopMatrix();
	
	     //pe direito frente	
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(17,-190,30);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
	  glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(17,-190,50);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	
	
	       //pe esquerdo atras	
glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(-66,-190,-30);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(-66,-190,-50);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	     //pe direito atras	
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(-66,-190,30);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(-66,-190,50);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	


//------------------------------------
  //rosto
  
	//nariz
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.4,0.5);
		glTranslatef(62,-8,-0.2);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
  
  
  //boca
 	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.05,0.9);
		glTranslatef(62,-128,-0.2);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
  
//-----------------------------------
   //olhos
       
      //pupila
     glPushMatrix();
		glColor3f(0, 0, 0);
		glScalef(0.3,0.2,0.2);
		glTranslatef(45,10,18);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0, 0, 0);
		glScalef(0.3,0.2,0.2);
		glTranslatef(45,10,-18);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	  //cornea
	    glPushMatrix();
		glColor3f(1, 1, 1);
		glScalef(0.3,0.2,0.2);
		glTranslatef(45,10,12);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(1, 1, 1);
		glScalef(0.3,0.2,0.2);
		glTranslatef(45,10,-12);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	   glPushMatrix();
		glColor3f(1, 1, 1);
		glScalef(0.3,0.2,0.2);
		glTranslatef(45,10,22);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(1, 1, 1);
		glScalef(0.3,0.2,0.2);
		glTranslatef(45,10,-22);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
   
//-----------------------------------  
    //rabo	
  
  	glPushMatrix();
	    glColor3f(0.9, 0.9, 1);
	    glRotatef(135, 0, 0, 1);
		glScalef(0.5,1.35,0.5);
		glTranslatef(40,20,0);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
	   glutWireCube(10);
	glPopMatrix();
	
	
	
//-----------------------------------
   //orelhas
   
            //esquerda
  	glPushMatrix();
		glColor3f(0.9, 0.9, 1);
		glScalef(0.2,0.7,0.4);
		glTranslatef(45,12,-8);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	 
	   //direita
		glPushMatrix();
	glColor3f(0.9, 0.9, 1);
		glScalef(0.2,0.7,0.4);
		glTranslatef(45,12,8);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	   
	   


}
#endif
