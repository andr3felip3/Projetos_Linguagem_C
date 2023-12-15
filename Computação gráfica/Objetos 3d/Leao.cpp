#ifndef LEAO_CPP
#include "glut.h"
//#include "geometry.h"
#define LEAO_CPP


void draw_leao(){
	
//-------------------------------------------------	
	//corpo
	
	//juba
	glPushMatrix();
		glColor3f(0.6, 0.3,0);
		glScalef(1,1.8,2);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
	  glutWireCube(10);
	glPopMatrix();
	
	//tronco1
	glPushMatrix();
		glColor3f(0.8, 0.7,0.4);
		glScalef(2.6,1.2,1.8);
		glTranslatef(-7,-5,0);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
	  glutWireCube(10);
	glPopMatrix();
	
//-------------------------------------------------	
		
	//cabeca
	glPushMatrix();
		glColor3f(0.8, 0.7,0.4);
		glScalef(1.3,1.3,1.2);
		glTranslatef(3,-1,0);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
//-------------------------------------------------

	//fussinho
	glPushMatrix();
		glColor3f(0.8, 0.7,0.4);
		glScalef(0.2,0.7,1.1);
		glTranslatef(58,-5.8,0);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
//--------------------------------------------------
	
	//pernas 
	
	      //frente
	    
	   //esquerda
	glPushMatrix();
		glColor3f(0.8, 0.7,0.4);
		glScalef(0.6,1.3,0.6);
		glTranslatef(-15,-10,-8);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	 
	glPopMatrix();
	  
	
	
	
	     //direita
	glPushMatrix();
	    glColor3f(0.8, 0.7,0.4);
		glScalef(0.6,1.3,0.6);
		glTranslatef(-15,-10,9);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	
	         //atras
	    
	   //esquerda
	glPushMatrix();
		glColor3f(0.8, 0.7,0.4);
		glScalef(0.6,1.3,0.6);
		glTranslatef(-45,-10,-8);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	     //direita
	glPushMatrix();
	    glColor3f(0.8, 0.7,0.4);
		glScalef(0.6,1.3,0.6);
		glTranslatef(-45,-10,8);
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
		glTranslatef(-23,-190,-50);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(-23,-190,-70);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
	  glutWireCube(10);
	glPopMatrix();
	
	     //pe direito frente	
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(-23,-190,50);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
	  glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(-23,-190,70);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	
	
	       //pe esquerdo atras	
glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(-84,-190,-50);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(-84,-190,-70);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	     //pe direito atras	
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(-84,-190,50);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.1,0.1);
		glTranslatef(-84,-190,70);
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
		glTranslatef(38,-8,0);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
  
  
  //boca
 	glPushMatrix();
		glColor3f(0.1, 0, 0);
		glScalef(0.3,0.05,0.9);
		glTranslatef(38,-128,0);
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
		glTranslatef(30,10,18);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0, 0, 0);
		glScalef(0.3,0.2,0.2);
		glTranslatef(30,10,-18);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	  //cornea
	    glPushMatrix();
		glColor3f(1, 1, 1);
		glScalef(0.3,0.2,0.2);
		glTranslatef(30,10,12);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(1, 1, 1);
		glScalef(0.3,0.2,0.2);
		glTranslatef(30,10,-12);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	   glPushMatrix();
		glColor3f(1, 1, 1);
		glScalef(0.3,0.2,0.2);
		glTranslatef(30,10,22);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(1, 1, 1);
		glScalef(0.3,0.2,0.2);
		glTranslatef(30,10,-22);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	
   
//-----------------------------------  
    //rabo	
  
  glPushMatrix();
  		glColor3f(0.8, 0.7,0.4);
		glScalef(0.4,0.1,0.165);
		glTranslatef(-82,-75,0.8);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
		
		glPushMatrix();
		glColor3f(0.8, 0.7,0.4);
		glScalef(0.3,5,0.5);
		glTranslatef(-15,-4.5,4.5);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	   glPopMatrix();
	   
	   	glPushMatrix();
		glColor3f(0.8, 0.7,0.4);
		glScalef(0.9,0.7,0.9);
		glTranslatef(-10,-60,4.5);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	   
	glPopMatrix();
	
//-----------------------------------
   //orelhas
   
            //esquerda
  	glPushMatrix();
		glColor3f(0.8, 0.7,0.4);
		glScalef(0.1,0.3,0.3);
		glTranslatef(66,18,-16);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	 
	   //direita
		glPushMatrix();
	    glColor3f(0.8, 0.7,0.4);
		glScalef(0.1,0.3,0.3);
		glTranslatef(66,18,16);
		glutSolidCube(10);
		glColor3f(0, 0, 0);
		glutWireCube(10);
	glPopMatrix();
	   
	   


}
#endif
