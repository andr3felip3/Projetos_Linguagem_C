#ifndef PORCO_CPP
#include "glut.h"
//#include "geometry.h"
#define PORCO_CPP




void draw_porco(){
	
//-------------------------------------------------	
	//corpo
	glPushMatrix();
		glColor3f(0.9, 0.7, 0.7);
		glScalef(2.5,1.8,2);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
	  glutWireCube(10);
	glPopMatrix();
	
//-------------------------------------------------	
		
	//cabeça
	glPushMatrix();
		glColor3f(0.9, 0.7, 0.7);
		glScalef(1.5,1.8,1.6);
		glTranslatef(11.5,3,0);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
//-------------------------------------------------

	//nariz
	glPushMatrix();
		glColor3f(0.9, 0.7, 0.7);
		glScalef(0.6675,0.7,0.8);
		glTranslatef(38,3,0);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
//--------------------------------------------------
	
	//pernas 
	
	      //frente
	    
	   //esquerda
	glPushMatrix();
		glColor3f(0.9, 0.7, 0.7);
		glScalef(0.8,1.3,0.6);
		glTranslatef(10,-10,-10);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	     //direita
	glPushMatrix();
	    glColor3f(0.9, 0.7, 0.7);
		glScalef(0.8,1.3,0.6);
		glTranslatef(10,-10,10);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	
	         //atras
	    
	   //esquerda
	glPushMatrix();
		glColor3f(0.9, 0.7, 0.7);
		glScalef(0.8,1.3,0.6);
		glTranslatef(-10,-10,-10);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	     //direita
	glPushMatrix();
	    glColor3f(0.9, 0.7, 0.7);
		glScalef(0.8,1.3,0.6);
		glTranslatef(-10,-10,10);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
	   glutWireCube(10);
	glPopMatrix();
	
	
//-------------------------------------	
	//unhas
	
       //pe esquerdo frente	
	glPushMatrix();
		glColor3f(0.6, 0.3, 0);
		glScalef(0.9,0.1,0.1);
		glTranslatef(9,-190,-50);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.6, 0.3, 0);
		glScalef(0.9,0.1,0.1);
		glTranslatef(9,-190,-70);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
	  glutWireCube(10);
	glPopMatrix();
	
	     //pe direito frente	
	glPushMatrix();
		glColor3f(0.6, 0.3, 0);
		glScalef(0.9,0.1,0.1);
		glTranslatef(9,-190,50);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
	  glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.6, 0.3, 0);
		glScalef(0.9,0.1,0.1);
		glTranslatef(9,-190,70);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	
	
	       //pe esquerdo atras	
glPushMatrix();
		glColor3f(0.6, 0.3, 0);
		glScalef(0.9,0.1,0.1);
		glTranslatef(-9,-190,-50);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.6, 0.3, 0);
		glScalef(0.9,0.1,0.1);
		glTranslatef(-9,-190,-70);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	     //pe direito atras	
	glPushMatrix();
		glColor3f(0.6, 0.3, 0);
		glScalef(0.9,0.1,0.1);
		glTranslatef(-9,-190,50);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.6, 0.3, 0);
		glScalef(0.9,0.1,0.1);
		glTranslatef(-9,-190,70);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	


//------------------------------------
  //narinas
  
  glPushMatrix();
		glColor3f(0.3, 0, 0);
		glScalef(0.3,0.2,0.2);
		glTranslatef(91,4,14);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.3, 0, 0);
		glScalef(0.3,0.2,0.2);
		glTranslatef(91,4,-14);
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
		glTranslatef(78,50,20);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0, 0, 0);
		glScalef(0.3,0.2,0.2);
		glTranslatef(78,50,-20);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	  //cornea
	    glPushMatrix();
		glColor3f(1, 1, 1);
		glScalef(0.3,0.2,0.2);
		glTranslatef(78,50,14);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(1, 1, 1);
		glScalef(0.3,0.2,0.2);
		glTranslatef(78,50,-14);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	   glPushMatrix();
		glColor3f(1, 1, 1);
		glScalef(0.3,0.2,0.2);
		glTranslatef(78,50,25);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(1, 1, 1);
		glScalef(0.3,0.2,0.2);
		glTranslatef(78,50,-25);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
   
//-----------------------------------  
    //rabo	
  
  glPushMatrix();
  		glColor3f(0.9, 0.7, 0.7);
  		glScalef(0.4,0.1,0.165);
		glTranslatef(-36,-75,0.8);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
		
		glPushMatrix();
		glColor3f(0.9, 0.7, 0.7);
		glScalef(0.3,5,0.5);
		glTranslatef(-15,4.5,4.5);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	   glPopMatrix();
	   
	   	glPushMatrix();
		glColor3f(0.9, 0.7, 0.7);
		glScalef(0.9,0.7,0.9);
		glTranslatef(-10,60,4.5);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	   
	glPopMatrix();
	
	
//-----------------------------------
   //orelhas
   
            //esquerda
  	glPushMatrix();
		glColor3f(0.9, 0.7, 0.7);
		glScalef(0.6,0.6,0.2);
		glTranslatef(30,20,-45);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	 
	   //direita
		glPushMatrix();
		glColor3f(0.9, 0.7, 0.7);
		glScalef(0.6,0.6,0.2);
		glTranslatef(30,20,45);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	   
	   


}
#endif
