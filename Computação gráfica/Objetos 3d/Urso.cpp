#ifndef URSO_CPP
#include "glut.h"
//#include "geometry.h"
#define URSO_CPP


void draw_urso(){
	
//-------------------------------------------------	
	//corpo
	glPushMatrix();
		glColor3f(0.9, 0.9, 1);
		glScalef(1.7,1.8,1.8);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
	  glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.9, 0.9, 1);
		glScalef(2,2,2.3);
		glTranslatef(-7,0,0);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
	  glutWireCube(10);
	glPopMatrix();
	
//-------------------------------------------------	
		
	//cabeca
	glPushMatrix();
		glColor3f(0.9, 0.9, 1);
		glScalef(1.3,1.3,1.2);
		glTranslatef(10,-1,0);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
//-------------------------------------------------

	//fussinho
	glPushMatrix();
		glColor3f(0.9, 0.9, 1);
		glScalef(0.2,0.7,1.1);
		glTranslatef(103,-6,0);
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
		glScalef(0.6,1.3,0.6);
		glTranslatef(5,-10,-9);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	     //direita
	glPushMatrix();
	    glColor3f(0.9, 0.9, 1);
		glScalef(0.6,1.3,0.6);
		glTranslatef(5,-10,9);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	
	         //atras
	    
	   //esquerda
	glPushMatrix();
		glColor3f(0.9, 0.9, 1);
		glScalef(1,1.3,0.6);
		glTranslatef(-15,-10,-10);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	     //direita
	glPushMatrix();
	    glColor3f(0.9, 0.9, 1);
		glScalef(1,1.3,0.6);
		glTranslatef(-15,-10,10);
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
		glTranslatef(17,-190,-50);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(17,-190,-70);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
	  glutWireCube(10);
	glPopMatrix();
	
	     //pe direito frente	
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(17,-190,50);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
	  glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(17,-190,70);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	
	
	       //pe esquerdo atras	
glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(-37,-190,-50);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(-37,-190,-70);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	     //pe direito atras	
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(-37,-190,50);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(-37,-190,70);
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
		glTranslatef(68,-8,0);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
  
  
  //boca
 	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.05,0.9);
		glTranslatef(68,-128,0);
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
		glTranslatef(61,10,18);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0, 0, 0);
		glScalef(0.3,0.2,0.2);
		glTranslatef(61,10,-18);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	  //cornea
	    glPushMatrix();
		glColor3f(1, 1, 1);
		glScalef(0.3,0.2,0.2);
		glTranslatef(61,10,12);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(1, 1, 1);
		glScalef(0.3,0.2,0.2);
		glTranslatef(61,10,-12);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	   glPushMatrix();
		glColor3f(1, 1, 1);
		glScalef(0.3,0.2,0.2);
		glTranslatef(61,10,22);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(1, 1, 1);
		glScalef(0.3,0.2,0.2);
		glTranslatef(61,10,-22);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
   
//-----------------------------------  
    //rabo	
  
  glPushMatrix();
  		glColor3f(0.9, 0.9, 1);
		glScalef(0.3,0.3,0.3);
		glTranslatef(-83,-15,0.8);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
			   
	glPopMatrix();
	
	
//-----------------------------------
   //orelhas
   
            //esquerda
  	glPushMatrix();
		glColor3f(0.9, 0.9, 1);
		glScalef(0.1,0.3,0.3);
		glTranslatef(185,18,-18);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	 
	   //direita
		glPushMatrix();
	glColor3f(0.9, 0.9, 1);
		glScalef(0.1,0.3,0.3);
		glTranslatef(185,18,18);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	   
	   


}
#endif
