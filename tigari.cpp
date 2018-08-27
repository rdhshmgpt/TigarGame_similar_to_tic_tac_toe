#include <stdio.h>
#include <stdlib.h> 
#include <GL/glut.h>
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
GLsizei MOUSEx=0, MOUSEy=0;
GLfloat SIDE=0.50;
GLfloat BLUE[3] = {0,0,1},RED[3]={1,0,0};
int color=0;
int player=0;
double w=1,h=1;
int flag[24]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int place[24]={2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
int flagw=0;
void specialKeys();
int flgm=0;
double rotate_y=0; 
double rotate_x=0;

//For showing Play Game on window sreen

void writeTexton(void) 
{  
   
  string text="PLAY GAME";
 
  glColor3f(0.0,0.0,1.0);
  
  double x;double y;
  glRasterPos3f(4.25,0.25,0);
  
  for(auto d:text) 
  {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, d);
  }

}

//condition for game win 

void writeText(void) 
{  
   
  string text="BLUE WIN";
 
  glColor3f(1,0,0);
  
  double x;double y;
  glRasterPos3f(5,1,0);
  
  for(auto d:text) 
  {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, d);
  }

}

void writeText1(void) 
{  
  

  string text="RED WIN";
  glColor3f(1,0,0);
  
  glRasterPos2f(5,1);
  for(auto d:text) 
  {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, d);
  }

}


//condition for drawing mouse square on the coordinate

void drawSquare1(int player)
{
    if(flgm==0)
    {
        flgm=1;
        return;
    }
    
    player=1-player;

    if(flagw!=-1)
    {
     if(color)
        glColor3fv(BLUE);
     else
       glColor3fv(RED);
    glBegin(GL_POLYGON);
        glVertex3f(MOUSEx/w, MOUSEy/h,0);
        glVertex3f(MOUSEx/w+SIDE, MOUSEy/h,0);
        glVertex3f(MOUSEx/w+SIDE, MOUSEy/h+SIDE,0.0f);
        glVertex3f(MOUSEx/w, MOUSEy/h+SIDE,0.0f);
    glEnd();
    
     printf("\n   %d player moved\n",player);
    }
    if(flagw==1)
 {
   writeText();
   flagw=-1;
    }
    else
    if(flagw==2)
    {
        writeText1();
        flagw=-1;
    }
    glFlush();
}   


void reshape(int cw, int ch)
{   
 glClearColor(0.0, 0.0, 0.0, 1.0);         // black background 
 glMatrixMode(GL_PROJECTION);              // setup viewing projection 
 glLoadIdentity();      
 w=cw/10.0f;
 h=ch/10.0f;                     // start with identity matrix 
 glOrtho(0.0, 10.0,10, 0, -1.0, 1.0);   // setup a 10x10x2 viewing world
   // glLoadIdentity();
     glutPostRedisplay();
}


//condition for matching three co-ordinate for win condition

void check_score()
{
    if(flagw==-1)
    return;

    if(place[0]==1 &&place[12]==1 && place[1]==1 || place[4]==1 &&place[16]==1 && place[5]==1  || place[8]==1 &&place[20]==1 && place[9]==1 ||
       place[11]==1 &&place[22]==1 && place[10]==1 ||place[7]==1 &&place[18]==1 && place[6]==1 || place[3]==1 &&place[14]==1 && place[2]==1 ||
       place[0]==1 &&place[15]==1 && place[3]==1 || place[4]==1 &&place[19]==1 && place[7]==1  || place[8]==1 &&place[23]==1 && place[11]==1 ||
       place[9]==1 &&place[21]==1 && place[10]==1 || place[5]==1 &&place[17]==1 && place[6]==1 || place[1]==1 &&place[13]==1 && place[2]==1 ||
       place[0]==1 &&place[4]==1 && place[8]==1 || place[12]==1 &&place[16]==1 && place[20]==1 || place[1]==1 &&place[5]==1 && place[9]==1 ||
       place[13]==1 &&place[17]==1 && place[21]==1 || place[2]==1 &&place[6]==1 && place[10]==1 || place[14]==1 &&place[18]==1 && place[22]==1 || 
       place[3]==1 &&place[7]==1 && place[11]==1 || place[15]==1 &&place[19]==1 && place[23]==1)
    {
        
        flagw=1;
       
    }
    else if(place[0]==0 &&place[12]==0 && place[1]==0 || place[4]==0 &&place[16]==0 && place[5]==0  || place[8]==0 &&place[20]==0 && place[9]==0 ||
       place[11]==0 &&place[22]==0 && place[10]==0 ||place[7]==0 &&place[18]==0 && place[6]==0 || place[3]==0 &&place[14]==0 && place[2]==0 ||
       place[0]==0 &&place[15]==0 && place[3]==0 || place[4]==0 &&place[19]==0 && place[7]==0  || place[8]==0 &&place[23]==0 && place[11]==0 ||
       place[9]==0 &&place[21]==0 && place[10]==0 || place[5]==0 &&place[17]==0 && place[6]==0 || place[1]==0 &&place[13]==0 && place[2]==0 ||
       place[0]==0 &&place[4]==0 && place[8]==0 || place[12]==0 &&place[16]==0 && place[20]==0 || place[1]==0 &&place[5]==0 && place[9]==0 ||
       place[13]==0 &&place[17]==0 && place[21]==0 || place[2]==0 &&place[6]==0 && place[10]==0 || place[14]==0 &&place[18]==0 && place[22]==0 || 
       place[3]==0 &&place[7]==0 && place[11]==0 || place[15]==0 &&place[19]==0 && place[23]==0)
    {
        
        flagw=2;
        return;
        
    }
}


void spindisplay(void)
{       
    glutPostRedisplay();
}

//mouse position set in X and Y coordinate

void setX(int x)
{
    MOUSEx=x;
}

void setY(int y)
{
    MOUSEy=y;
}


//this mouse function is use for click on particluar fixed coordination points


void mouse(int btn, int state, int x, int y)
{

    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)   
    {
      player = (player +1)%2;
      
 //for larger square coordinate covert into pixels

       if((x>=185&&x<=200)&&(y>=185&&y<=200))
       {  
           
            if(flag[0] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
                 place[0]=color;
        	          check_score();
        	            drawSquare1(player);
                        flag[0]=0;
                        
            }
         }    
           

     if((x>=775&&x<=800)&&(y>=185&&y<=200))
       {        
         
                if(flag[1] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
                  place[1]=color;
                  check_score();
        	            drawSquare1(player);
        	            
                        flag[1]=0;
            }
                        }    
            
          

     if((x>=775&&x<=800)&&(y>=775&&y<=800))
       {        
           
              if(flag[2] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
                  place[2]=color;
        	            check_score();
        	            drawSquare1(player);
        	           //check_win();
                        flag[2]=0;
            }
                        }    
           

     if((x>=185&&x<=200)&&(y>=775&&y<=800))
       {        
          
              if(flag[3] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
                  place[3]=color;
        	            check_score();
        	            drawSquare1(player);
                        flag[3]=0;
            }
                        }    
            

 //for second lager square  coordinate covert into pixels

   if((x>=285&&x<=300)&&(y>=285&&y<=300))
       {        
         
                if(flag[4] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
                  place[4]=color;
        	           check_score();
        	            drawSquare1(player);
                        flag[4]=0;
            }
                        }    
            

      if((x>=685&&x<=700)&&(y>=285&&y<=300))
       {        
          
                 if(flag[5] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
                  place[5]=color;
        	            check_score();
        	            drawSquare1(player);
                        flag[5]=0;
            }
                        }    
           

      if((x>=685&&x<=700)&&(y>=685&&y<=700))
       {       
         
           if(flag[6] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
                  place[6]=color;
        	            check_score();
        	            drawSquare1(player);
                        flag[6]=0;
             }
                        }    
            	

        if((x>=285&&x<=300)&&(y>=685&&y<=700))
       {        
         
                 if(flag[7] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
        	            place[7]=color;
        	            check_score();
        	            drawSquare1(player);
                        flag[7]=0;
            }
                        }    
          

 //for small square coordinate covert into pixels
     
      if((x>=385&&x<=400)&&(y>=385&&y<=400))
       {        
        
                 if(flag[8] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
        	            place[8]=color;
        	            check_score();
        	            drawSquare1(player);
                        flag[8]=0;
            }
                        }    
           
    
       
          if((x>=585&&x<=600)&&(y>=385&&y<=400))
       {        
          
                if(flag[9] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
        	            place[9]=color;
        	            check_score();
        	            drawSquare1(player);
                        flag[9]=0;
            }
                        }    
            

       if((x>=585&&x<=600)&&(y>=585&&y<=600))
       {        
        
                if(flag[10] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
        	            place[10]=color;
        	            check_score();
        	            drawSquare1(player);
                        flag[10]=0;
            }
                        }    
           

       if((x>=385&&x<=400)&&(y>=585&&y<=600))
       {        
         
                 if(flag[11] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
                  place[11]=color;
        	           check_score();
        	            drawSquare1(player);
                        flag[11]=0;
            }
                        }    
           
 

if((x>=485&&x<=500)&&(y>=185&&y<=200))
       {        
        
                 if(flag[12] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
                  place[12]=color;
        	           check_score();
        	            drawSquare1(player);
                        flag[12]=0;
            }
                        }    
           

      if((x>=785&&x<=800)&&(y>=485&&y<=500))
       {        
         
               if(flag[13] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
                  place[13]=color;
        	           check_score();
        	            drawSquare1(player);
                        flag[13]=0;
            }
                        }    
           

    if((x>=485&&x<=500)&&(y>=785&&y<=800))
       {        
       
                 if(flag[14] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
                  place[14]=color;
        	            check_score();
        	            drawSquare1(player);
                        flag[14]=0;
            }
                        }    
           

    if((x>=185&&x<=200)&&(y>=485&&y<=500))
       {        
          
                 if(flag[15] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
                  place[15]=color;
        	            check_score();
        	            drawSquare1(player);
                        flag[15]=0;
            }
                        }    
            

    // for second larger square midpoint coordinate covert into pixels
    

    if((x>=485&&x<=500)&&(y>=285&&y<=300))
       {        
        
                 if(flag[16] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
                  place[16]=color;
        	            check_score();
        	            drawSquare1(player);
                        flag[16]=0;
            }
                        }    
            

    if((x>=685&&x<=700)&&(y>=485&&y<=500))
       {        
          
                if(flag[17] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
                  place[17]=color;
        	            check_score();
        	            drawSquare1(player);
                        flag[17]=0;
            }
                        }    
          
    
     if((x>=485&&x<=500)&&(y>=685&&y<=700))
       {        
       
                 if(flag[18] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
        	            place[18]=color;
        	            check_score();
        	            drawSquare1(player);
                        flag[18]=0;
            }
                        }    
            

    if((x>=285&&x<=300)&&(y>=485&&y<=500))
       {        
      
                 if(flag[19] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
        	            place[19]=color;
        	            check_score();
        	            drawSquare1(player);
                        flag[19]=0;
            }
                        }   
                         
           
  // for small square midpoint coordinate covert into pixels


    if((x>=485&&x<=500)&&(y>=385&&y<=400))
       {        
      
                 if(flag[20] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
        	            place[20]=color;
        	            check_score();
        	            drawSquare1(player);
                        flag[20]=0;
            }
                        }    
            
      
      if((x>=585&&x<=600)&&(y>=485&&y<=500))
       {        
        
                 if(flag[21] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
                  place[21]=color;
        	            check_score();
        	            drawSquare1(player);
                        flag[21]=0;
            }
                        }    
            
      
      if((x>=485&&x<=500)&&(y>=585&&y<=600))
       {        
          
                if(flag[22] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
                  place[22]=color;
        	           check_score();
        	            drawSquare1(player);
                        flag[22]=0;
            }
                        }    
            

        if((x>=385&&x<=400)&&(y>=485&&y<=500))
       {        
          
                if(flag[23] == 1)
            {
                 setX(x);
                  setY(y);
                  color= (color+1)%2;
                  place[23]=color;
        	            check_score();
        	            drawSquare1(player);
                        flag[23]=0;
            }
                        }    
           
       }
    
    if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)   
    {
        exit(1);   
    }
} 



//Display the three different square and lines 


void display(void) 
{ 

if(flagw==1)
 {
   writeText();
    return;
    }
    

 glClear( GL_COLOR_BUFFER_BIT); 
 writeTexton();
 glRotatef( rotate_x, 1.0, 0.0, 0.0 );
 glRotatef( rotate_y, 0.0, 1.0, 0.0 );
 
 glColor3f(0.0, 1.0, 0.0); 
 glBegin(GL_POLYGON); 
  glVertex3f(2.0, 2.0, 0.0); 
  glVertex3f(8.0, 2.0, 0.0); 
  glVertex3f(8.0, 8.0, 0.0); 
  glVertex3f(2.0, 8.0, 0.0); 

glColor3f(0.40, 0.70, 0.50); 
 glBegin(GL_POLYGON); 
  glVertex3f(2.0, 2.0, -1.50); 
  glVertex3f(8.0, 2.0, -1.50); 
  glVertex3f(8.0, 8.0, -1.50); 
  glVertex3f(2.0, 8.0, -1.50);  
 glEnd(); 

glColor3f(0.50 ,0.50, 0.50); 
 glBegin(GL_POLYGON); 
  glVertex3f(2.0, 2.0, 0.0); 
  glVertex3f(2.0, 2.0, -1.50); 
  glVertex3f(8.0, 2.0, -1.50); 
  glVertex3f(8.0, 2.0, 0.0);  
 glEnd(); 


glColor3f(0.60 ,0.60, 0.60);
 glBegin(GL_POLYGON); 
  glVertex3f(8.0, 2.0, 0.0); 
  glVertex3f(8.0, 2.0, -1.50); 
  glVertex3f(8.0, 8.0, -1.50); 
  glVertex3f(8.0, 8.0, 0.0);  
 glEnd(); 


glColor3f(0.70 ,0.70, 0.70); 
 glBegin(GL_POLYGON); 
  glVertex3f(8.0, 8.0, 0.0); 
  glVertex3f(8.0, 8.0, -1.50); 
  glVertex3f(2.0, 8.0, -1.50); 
  glVertex3f(2.0, 8.0, 0.0);  
 glEnd(); 


glColor3f(0.80 ,0.80, 0.80); 
 glBegin(GL_POLYGON); 
  glVertex3f(2.0, 8.0, 0.0); 
  glVertex3f(2.0, 8.0, -1.50); 
  glVertex3f(2.0, 2.0, -1.50); 
  glVertex3f(2.0, 2.0, 0.0);  
 glEnd(); 





  /* 
  glBegin(GL_POLYGON);
  glColor3f(  1.0, 0.0, 1.0 );
  glVertex3f( 8.0, 2.0, 8.0 );
  glVertex3f( 8.0, 2.0, 2.0 );
  glVertex3f( 8.0, 8.0, 2.0 );
  glVertex3f( 8.0, 8.0, 8.0 );
  glEnd(); 
  
  */
  
 glEnd(); 
 glColor3f(1.0, 1.0, 0.0); 
 glBegin(GL_POLYGON); 
  glVertex3f(3.0, 3.0, 0.0); 
  glVertex3f(7.0, 3.0, 0.0); 
  glVertex3f(7.0, 7.0, 0.0); 
  glVertex3f(3.0, 7.0, 0.0); 
 glEnd(); 
 glColor3f(0.0, 1.0, 1.0); 
 glBegin(GL_POLYGON); 
  glVertex3f(4.0, 4.0, 0.0); 
  glVertex3f(6.0, 4.0, 0.0); 
  glVertex3f(6.0, 6.0, 0.0); 
  glVertex3f(4.0, 6.0, 0.0);
   
 glEnd(); 
 glLineWidth(2.5); 
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex3f(2.0, 2.0, 0.0);
  glVertex3f(4.0, 4.0, 0.0);
 glEnd();
 
 glLineWidth(2.5); 
 glColor3f(1.0, 0.0, 0.0);
 glBegin(GL_LINES);
 glVertex3f(6.0, 6.0, 0.0);
 glVertex3f(8.0, 8.0, 0.0);
 glEnd();
 
 glLineWidth(2.5); 
 glColor3f(1.0, 0.0, 0.0);
 glBegin(GL_LINES);
 glVertex3f(6.0, 4.0, 0.0);
 glVertex3f(8.0, 2.0, 0.0);
 glEnd();
 
 glLineWidth(2.5); 
 glColor3f(1.0, 0.0, 0.0);
 glBegin(GL_LINES);
 glVertex3f(4.0, 6.0, 0.0);
 glVertex3f(2.0, 8.0, 0.0);
 glEnd();
 
 glLineWidth(2.5); 
 glColor3f(1.0, 0.0, 0.0);
 glBegin(GL_LINES);
 glVertex3f(5.0, 4.0, 0.0);
 glVertex3f(5.0, 2.0, 0.0);
 glEnd();
 
 glLineWidth(2.5); 
 glColor3f(1.0, 0.0, 0.0);
 glBegin(GL_LINES);
 glVertex3f(2.0, 5.0, 0.0);
 glVertex3f(4.0, 5.0, 0.0);
 glEnd();
 
 glLineWidth(2.5); 
 glColor3f(1.0, 0.0, 0.0);
 glBegin(GL_LINES);
 glVertex3f(5.0, 8.0, 0.0);
 glVertex3f(5.0, 6.0, 0.0);
 glEnd();
 
 glLineWidth(2.5); 
 glColor3f(1.0, 0.0, 0.0);
 glBegin(GL_LINES);
 glVertex3f(6.0, 5.0, -1.0);
 glVertex3f(8.0, 5.0, 0.0);
 glEnd();
 glFlush();
}

//rotation keyword 

void specialKeys( int key, int x, int y ) {
 
  //  Right arrow - increase rotation by 0.1 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 0.1;
 
  //  Left arrow - decrease rotation by 0.1 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 0.1;
 
  else if (key == GLUT_KEY_UP)
    rotate_x += 0.1;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 0.1;
 
  //  Request display update
  glutPostRedisplay();
 
}

//main function

int main(int argc, char **argv) 
{ 
 printf("hello here tigari game\n"); 
 glutInit(&argc, argv);  
 drawSquare1(player) ;
 glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

 glutInitWindowPosition(0,0); 
 glutInitWindowSize(1000,1000); 
 glutCreateWindow ("Play tigari game");



 glClearColor(0.75, 0.50, 0.60, 0.0);         // black background 
 glMatrixMode(GL_PROJECTION);              // setup viewing projection 
 glLoadIdentity();                           // start with identity matrix 
 glOrtho(0.0, 10.0, 10, 0, -1.0, 1.0);   // setup a 10x10x2 viewing world
 
 
 glutDisplayFunc(display);
 glutSpecialFunc(specialKeys);
 glutReshapeFunc(reshape);
 glutMouseFunc(mouse);
 glutMainLoop();

 return 0; 
}
