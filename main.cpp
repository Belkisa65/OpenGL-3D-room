#include <stdlib.h> // standard definitions
#include <math.h> // math definitions
#include <stdio.h> // standard I/O

#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// escape key (for exit)
#define ESC 27


// Camera position
float x = 0.0, y = -5.0; // initially 5 units south of origin
float deltaMove = 0.0; // initially camera doesn't move

// Camera direction
float lx = 0.0, ly = 1.0; // camera points initially along y-axis
float angle = 0.0; // angle of rotation for the camera direction
float deltaAngle = 0.0; // additional angle change when dragging

// Mouse drag control
int isDragging = 0; // true when dragging
int xDragStart = 0; // records the x-coordinate when dragging starts


void changeSize(int w, int h)
{
	float ratio =  ((float) w) / ((float) h); // window aspect ratio
	glMatrixMode(GL_PROJECTION); // projection matrix is active
	glLoadIdentity(); // reset the projection
	gluPerspective(45.0, ratio, 0.1, 100.0); // perspective transformation
	glMatrixMode(GL_MODELVIEW); // return to modelview mode
	glViewport(0, 0, w, h); // set viewport (drawing area) to entire window
}


void update(void)
{
	if (deltaMove) { // update camera position
		x += deltaMove * lx * 0.1;
		y += deltaMove * ly * 0.1;
	}
	glutPostRedisplay(); // redisplay everything
}


GLuint texture1;
GLuint texture2;
GLuint texture3;
//Funkcija za iscrtavanje texture
GLuint LoadTexture(const char* filename, int width, int height){
       GLuint texture;
       unsigned char* data;
       FILE* file;
       file=fopen(filename, "rb");
       if(file==NULL)return 0;
       data=(unsigned char*)malloc(width * height * 3);
       fread(data,width * height * 3,1,file);
       fclose(file);
       glGenTextures(1,&texture);
       glBindTexture(GL_TEXTURE_2D,texture);
       glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
       glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
       free(data);
       return texture;
}
void komoda()
{
     glColor3f(0.7, 0.7, 0.7);

    glPushMatrix();
         glTranslatef(1.2, -8.1, 2.4);
         glScalef(2.5, 5, 3);
         glutSolidCube(0.9);
    glPopMatrix();
}
void teksturaKomode()
{
   glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture1);
    glEnable(GL_TEXTURE_2D);

    //glColor3f(0.5, 0.2, 0.0);
    glBegin(GL_POLYGON);

    glTexCoord2d(1.0, 0.0); glVertex3f(3, -3, 1.1);
    glTexCoord2d(1.0, 1.0); glVertex3f(3, -13.4, 1.1);
    glTexCoord2d(0.0, 1.0); glVertex3f(13.5, -13.4, 1.1);
    glTexCoord2d(0.0, 0.0); glVertex3f(13.5, -3, 1.1);
    glEnd();


    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
void teksturaLadice()
{
glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture2);
    glEnable(GL_TEXTURE_2D);
glRotatef(-90,0,1,0);
glTranslatef(-0.5,-8,-3.43);
    //glColor3f(0.5, 0.2, 0.0);
    glBegin(GL_POLYGON);


    glTexCoord2d(1.0, 0.0); glVertex3f(1.55, 2, 1.1);
    glTexCoord2d(1.0, 1.0); glVertex3f(1.55, -2.2, 1.1);
    glTexCoord2d(0.0, 1.0); glVertex3f(4.2, -2.2, 1.1);
    glTexCoord2d(0.0, 0.0); glVertex3f(4.2, 2, 1.1);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void teksturaSlike()
{
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture3);
    glEnable(GL_TEXTURE_2D);
glRotatef(-90,0,1,0);
glTranslatef(3.823,-3.3,-1.16);
    //glColor3f(0.5, 0.2, 0.0);
    glBegin(GL_POLYGON);

    glTexCoord2d(1.0, 0.0); glVertex3f(1.45, 1.4, 1.1);
    glTexCoord2d(1.0, 1.0); glVertex3f(1.45, -1.9, 1.1);
    glTexCoord2d(0.0, 1.0); glVertex3f(4.18, -1.9, 1.1);
    glTexCoord2d(0.0, 0.0); glVertex3f(4.18, 1.4, 1.1);
    glEnd();


    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void teksturaSlike2()
{
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture3);
    glEnable(GL_TEXTURE_2D);
glRotatef(-90,0,1,0);
glTranslatef(3.842,-12.43,-1.25);
    //glColor3f(0.5, 0.2, 0.0);
    glBegin(GL_POLYGON);

    glTexCoord2d(1.0, 0.0); glVertex3f(1.45, 1.4, 1.1);
    glTexCoord2d(1.0, 1.0); glVertex3f(1.45, -1.9, 1.1);
    glTexCoord2d(0.0, 1.0); glVertex3f(4.15, -1.9, 1.1);
    glTexCoord2d(0.0, 0.0); glVertex3f(4.15, 1.4, 1.1);
    glEnd();


    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
void televizor()
{
     glColor3f(0, 0, 0);

    glPushMatrix();
         glTranslatef(1.2, -8.2, 3.8);
         glScalef(1.5, 2, 0.2);
         glutSolidCube(0.7);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(1.2, -8.2, 3.8);
         glScalef(0.5, 2, 3.7);
         glutSolidCube(0.3);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(1.2, -8.2, 5.4);
         glScalef(0.5, 6, 3.7);
         glutSolidCube(0.6);
    glPopMatrix();
}
void dusek()
{
     glColor3f(0.7, 0.0, 0.7);

    glPushMatrix();
         glTranslatef(8.53, -6.5, 1.95);
         glScalef(9.2, 3, 1);
         glutSolidCube(0.9);
    glPopMatrix();

    glColor3f(0.7, 0.3, 0.7);

    //naslanjac
    glPushMatrix();
         glTranslatef(8.53, -5.1, 2.8);
         glScalef(9.25, 1, 2.9);
         glutSolidCube(0.9);
    glPopMatrix();
}
void sto()
{
    glColor3f(0.7, 0.1, 0.2);
    glPushMatrix();
         glTranslatef(9.8, -10.8, 2.0);
         glScalef(5.5, 2, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();

    //noge od stola
    glPushMatrix();
         glTranslatef(12.25, -11.6, 1.5);
         glScalef(0.1, 0.2, 1.0);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(7.35, -11.6, 1.5);
         glScalef(0.1, 0.2, 1.0);
         glutSolidCube(0.9);
    glPopMatrix();


    glPushMatrix();
         glTranslatef(12.25, -10.0, 1.5);
         glScalef(0.1, 0.2, 1.0);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(7.35, -10.0, 1.5);
         glScalef(0.1, 0.2, 1.0);
         glutSolidCube(0.9);
    glPopMatrix();
}
void fotelja()
{
    glColor3f(0.5f, 0.35f, 0.05f);
    glPushMatrix();
         glTranslatef(6.5, -14.1, 1.4);
         glScalef(3.5, 3, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();

    //dusek za fotelju
    glColor3f(0.7, 0.0, 0.7);

    glPushMatrix();
         glTranslatef(6.53, -13.9, 1.95);
         glScalef(3.2, 1.99, 1);
         glutSolidCube(0.9);
    glPopMatrix();

    //naslanjac za fotelju
    glColor3f(0.7, 0.3, 0.7);
    glPushMatrix();
         glTranslatef(6.53, -15.1, 2.8);
         glScalef(3.2, 0.7, 2.9);
         glutSolidCube(0.9);
    glPopMatrix();

    glColor3f(0.5f, 0.35f, 0.05f);
    glPushMatrix();
         glTranslatef(8.033, -15.46, 2.15);
         glScalef(0.1, 0.2, 2.5);
         glutSolidCube(0.9);
    glPopMatrix();

    glColor3f(0.5f, 0.35f, 0.05f);
    glPushMatrix();
         glTranslatef(4.99, -15.46, 2.15);
         glScalef(0.1, 0.2, 2.5);
         glutSolidCube(0.9);
    glPopMatrix();

    glColor3f(0.5f, 0.35f, 0.05f);
    glPushMatrix();
         glTranslatef(8.033, -12.9, 2.15);
         glScalef(0.1, 0.2, 2.5);
         glutSolidCube(0.9);
    glPopMatrix();

    glColor3f(0.5f, 0.35f, 0.05f);
    glPushMatrix();
         glTranslatef(4.99, -12.9, 2.15);
         glScalef(0.1, 0.2, 2.5);
         glutSolidCube(0.9);
    glPopMatrix();

    //naslon za ruku na fotelji 1
    glColor3f(0.5f, 0.35f, 0.05f);
    glPushMatrix();
         glTranslatef(8.1, -14.18, 3.2);
         glScalef(0.2, 2.8, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();

    //naslon za ruku na fotelji 2
    glColor3f(0.5f, 0.35f, 0.05f);
    glPushMatrix();
         glTranslatef(4.99, -14.18, 3.2);
         glScalef(0.2, 2.8, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();
}
void kauc()
{
     glColor3f(0.5f, 0.35f, 0.05f);

    glPushMatrix();
         glTranslatef(8.5, -6.1, 1.4);
         glScalef(9.5, 4, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();

    glColor3f(0.5f, 0.35f, 0.05f);
    glPushMatrix();
         glTranslatef(12.685, -7.88, 2.15);
         glScalef(0.2, 0.3, 2.5);
         glutSolidCube(0.9);
    glPopMatrix();


    //naslon za ruke na kaucu 1
    glColor3f(0.5f, 0.35f, 0.05f);
    glPushMatrix();
         glTranslatef(12.685, -6.11, 3.2);
         glScalef(0.2, 4, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();

    //naslon za ruke na kaucu 2
    glColor3f(0.5f, 0.35f, 0.05f);
    glPushMatrix();
         glTranslatef(4.33, -6.11, 3.2);
         glScalef(0.2, 4, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();


    glColor3f(0.5f, 0.35f, 0.05f);
    glPushMatrix();
         glTranslatef(4.33, -7.88, 2.15);
         glScalef(0.2, 0.3, 2.5);
         glutSolidCube(0.9);
    glPopMatrix();

    glColor3f(0.5f, 0.35f, 0.05f);
    glPushMatrix();
         glTranslatef(12.685, -4.45, 2.15);
         glScalef(0.2, 0.3, 2.5);
         glutSolidCube(0.9);
    glPopMatrix();

    glColor3f(0.5f, 0.35f, 0.05f);
    glPushMatrix();
         glTranslatef(4.33, -4.45, 2.15);
         glScalef(0.2, 0.3, 2.5);
         glutSolidCube(0.9);
    glPopMatrix();
}
void knjiga(float r, float g,float b)
{
    //KNJIGA
   glPushMatrix();
         glTranslatef(11.45, -4, 2);
         glScalef(0.1, 1.3, 1.8);

         glColor3f(r , g , b );
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(11.7, -4, 2);
         glScalef(0.4, 1.3, 1.8);

         glColor3f(1 , 1 , 1 );
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(11.93, -4, 2);
         glScalef(0.1, 1.3, 1.8);

         glColor3f(r , g , b );
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(11.7, -4.6, 2);
         glScalef(0.6,0.1, 1.8);

         glColor3f(r , g , b );
         glutSolidCube(0.9);
    glPopMatrix();
}
void polica()
{
    //POLICA
   glPushMatrix();
        glTranslatef(0,1,4);
        glRotatef(90,1,0,0);
        glTranslatef(4,-2.96,1.1);
        glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex3d(5,0,0);
        glVertex3d(5,7.99,0);
        glVertex3d(10,7.99,0);
        glVertex3d(10,0,0);
        glEnd();
   glPopMatrix();

   glPushMatrix();
         glTranslatef(11.45, -1, 1.2);
         glScalef(5.2, 2, 0.6);

         glColor3f(0.752941 , 0.752941 , 0.752941 );
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(11.45, -1, 3.7);
         glScalef(5.2, 2, 0.5);

         glColor3f(0.752941 , 0.752941 , 0.752941 );
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(11.45, -1, 6.3);
         glScalef(5.2, 2, 0.5);

         glColor3f(0.752941 , 0.752941 , 0.752941 );
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(11.45, -1, 8.85);
         glScalef(5.2, 2, 0.5);

         glColor3f(0.752941 , 0.752941 , 0.752941 );
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(13.89, -1, 5);
         glScalef(0.4, 2, 9);
         glColor3f(0.7, 0.7, 0.8);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(9, -1, 5);
         glScalef(0.4, 2, 9);
         glColor3f(0.7, 0.7, 0.8);
         glutSolidCube(0.9);
    glPopMatrix();
}
void prozor()
{
     glColor3f(0.8, 0.8, 0.8);

    glPushMatrix();
         glTranslatef(6, 0, 6.5);
         glScalef(0.5, 0.4, 5.7);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(4.5, 0, 6.5);
         glScalef(0.5, 0.3, 5.7);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(3, 0, 6.5);
         glScalef(0.5, 0.4, 5.7);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(4.53, 0, 4);
         glScalef(3.8, 0.4, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(4.53, 0, 9);
         glScalef(3.8, 0.4, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(4.53, 0, 5.9);
         glScalef(3.8, 0.4, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(4.53, 0, 7.5);
         glScalef(3.8, 0.4, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
}
void crtajKucu()
{
    //ZID
   glBegin(GL_QUADS);
        glColor3f(1, 0.95, 1);
        glVertex3d(0,0,0);
        glVertex3d(0,10,0);
        glVertex3d(16,10,0);
        glVertex3d(16,0,0);
   glEnd();


   //zid
   glPushMatrix();
        glRotatef(-90,0,1,0);
        glBegin(GL_QUADS);
        glColor3f(1, 1, 1);
        glVertex3d(0,0,0);
        glVertex3d(0,10,0);
        glVertex3d(16,10,0);
        glVertex3d(16,0,0);
        glEnd();
   glPopMatrix();

   //Okviri slika
   glPushMatrix();
        glRotatef(-90,0,1,0);
        glRotatef(-179.5,1,0,0);
        glScalef(0.18,0.35,0);
        glTranslatef(29,5,0);
        glBegin(GL_QUADS);
        glColor3f(0.1, 0.1, 0.1);
        glVertex3d(0,0,0);
        glVertex3d(0,10,0);
        glVertex3d(16,10,0);
        glVertex3d(16,0,0);
        glEnd();

        glTranslatef(0.4,26,0);
        glBegin(GL_QUADS);
        glColor3f(0.1, 0.1, 0.1);
        glVertex3d(0,0,0);
        glVertex3d(0,10,0);
        glVertex3d(16,10,0);
        glVertex3d(16,0,0);
        glEnd();
   glPopMatrix();

   //Staklo od prozora 1
   glPushMatrix();
        glTranslatef(0,0,4);
        glRotatef(89,1,0,0);
        glTranslatef(0,0,0);
        glBegin(GL_QUADS);
        glColor3f( 0.1, 0.58, 0.98);
        glVertex3d(3,0,0);
        glVertex3d(3,5,0);
        glVertex3d(6,5,0);
        glVertex3d(6,0,0);
        glEnd();
   glPopMatrix();

   //Staklo od prozora 2
   glPushMatrix();
        glTranslatef(0,0,4);
        glRotatef(90,1,0,0);
        glTranslatef(0,0,0.1);
        glBegin(GL_QUADS);
        glColor3f( 0.1, 0.58, 0.98);
        glVertex3d(3,0,0);
        glVertex3d(3,5,0);
        glVertex3d(6,5,0);
        glVertex3d(6,0,0);
        glEnd();
   glPopMatrix();

   //Slike
   glPushMatrix();
        glRotatef(-90,0,1,0);
        glRotatef(-179.4,1,0,0);
        glScalef(0.16,0.32,0);
        glTranslatef(33.5,6,0);
        glBegin(GL_QUADS);
        glColor3f( 0.1, 0.58, 0.98);
        glVertex3d(0,0,0);
        glVertex3d(0,10,0);
        glVertex3d(16,10,0);
        glVertex3d(16,0,0);
        glEnd();

        glTranslatef(0.4,28.5,0);
        glBegin(GL_QUADS);
        glColor3f( 0.1, 0.58, 0.98);
        glVertex3d(0,0,0);
        glVertex3d(0,10,0);
        glVertex3d(16,10,0);
        glVertex3d(16,0,0);
        glEnd();
   glPopMatrix();

   //POD
  glPushMatrix();
        glRotatef(179.84,1,0,0);
        glTranslatef(-0.1,0, -1);
        glBegin(GL_QUADS);
        glColor3f(0.94, 0.81, 0.99);
        glVertex3d(0,0,0);
        glVertex3d(0,16,0);
        glVertex3d(16,16,0);
        glVertex3d(16,0,0);
        glEnd();
   glPopMatrix();


   //TEPIH
   glPushMatrix();
        //transformacije
        glRotatef(179.84,1,0,0);
        glTranslatef(-0.1,0, -1.05);
        glScalef(0.65,0.65,1);
        glTranslatef(4.5,4.5,0);
        glBegin(GL_QUADS);
        glColor3f( 0.87, 0.58, 0.98);
        glVertex3d(0,0,0);
        glVertex3d(0,16,0);
        glVertex3d(16,16,0);
        glVertex3d(16,0,0);
        glEnd();
   glPopMatrix();

}

void lampaLevo()
{
    glColor3f(0.898,0.6,0.233);

    glPushMatrix();
         glTranslatef(2.3, -14.5, 1.1);
         glScalef(2.5, 2, 0.2);
         glutSolidCube(0.7);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(2.3, -14.5, 3.2);
         glScalef(0.2, 0.2, 6.2);
         glutSolidCube(0.7);
    glPopMatrix();

    glColor3f(0.8,0.3,0.2);
     glPushMatrix();
        glTranslatef(2.3, -14.5, 4.6);
        glutSolidCone(1,2,15,21);
     glPopMatrix();


}
void lights()
{
    glEnable(GL_LIGHTING);
     glEnable(GL_NORMALIZE);
     glEnable(GL_COLOR_MATERIAL);
glDisable(GL_LIGHT0);
     glEnable(GL_LIGHTING);
     GLfloat lmodel_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
     GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
     GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
     GLfloat light_positionSunce[] = { -15.0, -15.0, 15.0, 0.0 };
     GLfloat light_position1[] = { -7, -8.7, 3.2, 0.0 };//-7, -8.7, 4.2
     GLfloat light_position2[] = { -7, 0.1, 3.2, 0.0 };//-7, 0.1, 4.2
     GLfloat light_position3[] = { 0.5, 8, 3.2, 0.0 };//0.5, 8, 4.2

glLightfv(GL_LIGHT0,GL_AMBIENT,lmodel_ambient);
     glLightfv(GL_LIGHT0,GL_DIFFUSE,light1_diffuse);
     glLightfv(GL_LIGHT0,GL_SPECULAR,light1_specular);
     glLightfv(GL_LIGHT0, GL_POSITION, light_positionSunce);

     glLightfv(GL_LIGHT1,GL_AMBIENT,lmodel_ambient);
     glLightfv(GL_LIGHT1,GL_DIFFUSE,light1_diffuse);
     glLightfv(GL_LIGHT1,GL_SPECULAR,light1_specular);
     glLightfv(GL_LIGHT1, GL_POSITION, light_position1);

     glLightfv(GL_LIGHT2,GL_AMBIENT,lmodel_ambient);
     glLightfv(GL_LIGHT2,GL_DIFFUSE,light1_diffuse);
     glLightfv(GL_LIGHT2,GL_SPECULAR,light1_specular);
     glLightfv(GL_LIGHT2, GL_POSITION, light_position2);

     glLightfv(GL_LIGHT3,GL_AMBIENT,lmodel_ambient);
     glLightfv(GL_LIGHT3,GL_DIFFUSE,light1_diffuse);
     glLightfv(GL_LIGHT3,GL_SPECULAR,light1_specular);
     glLightfv(GL_LIGHT3, GL_POSITION, light_position3);

GLfloat mat_amb_diff[] = { 0.7, 0.7, 0.7, 1.0 };
     GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
     GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
     GLfloat low_shininess[] = { 10.0 };

glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);

     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, low_shininess);

     glMatrixMode(GL_MODELVIEW);

}
void lightoff(unsigned char key, int x, int y) {

    key = tolower(key);
    if (key == 'a') {
        glDisable(GL_LIGHT0);
    }
    if (key == 's') {
        glEnable(GL_LIGHT0);
    }
    if (key == 'o') {
        glDisable(GL_LIGHT1);
    }
    if (key == 'p') {
        glEnable(GL_LIGHT1);
    }

    if (key == 'n') {
        glDisable(GL_LIGHT2);
    }
    if (key == 'm') {
        glEnable(GL_LIGHT2);
    }

    glutPostRedisplay();
}
void renderScene(void)
{
	int i, j;

	// Clear color and depth buffers
	glClearColor(0.0, 0.0, 0.0, 1.0); // sky color is light blue
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// Set the camera centered at (x,y,1) and looking along directional
	// vector (lx, ly, 0), with the z-axis pointing up
	gluLookAt(
            23,      -21,      9,
			0, 0, 1.0,
			0.0,    0.0,    1.0);

	// Draw ground - 200x200 square colored green
	glColor3f(0.0, 0.7, 0.0);
	glBegin(GL_QUADS);
		glVertex3f(-80.0, -80.0, 0.0);
		glVertex3f(-80.0,  80.0, 0.0);
		glVertex3f( 80.0,  80.0, 0.0);
		glVertex3f( 80.0, -80.0, 0.0);
	glEnd();


	glPushMatrix();
   glTranslatef(0, 0, 1);
   glRotatef(90, 1, 0,0);
   glColor3f(1.0, 0.7, 0.0);


   crtajKucu();


   teksturaKomode();
   teksturaLadice();
   teksturaSlike();
   teksturaSlike2();
   sto();
   komoda();
   televizor();
   lampaLevo();
   fotelja();

   prozor();
   kauc();
   dusek();

   polica();

        glTranslatef(-2.2,3,0);
        knjiga(0.8,0,0.2);

        glTranslatef(0.6,0,0.3);
        knjiga(0,0.4,0.2);

        glTranslatef(0.6,0,0);
        knjiga(0.2,0.4,0.9);

        glTranslatef(0.6,0,0);
        knjiga(0.2,0.9,0.2);

        glTranslatef(0.6,0,0);
        knjiga(1.2,1,0);


        glRotatef(-25,0,1,0);
        glTranslatef(0.6,0,-5.5);
        knjiga(1.2,0.2,0.4);


        glTranslatef(7,0,-6.6);
        glRotatef(-65,0,1,0);
        knjiga(0.2,0.3,0.5);

        glTranslatef(10,-0.1,11.7);
        glRotatef(90,0,1,0);
        knjiga(0.8,0.3,0.5);

        glTranslatef(0.6,0,0);
        knjiga(0.8,0.3,0.2);

        glTranslatef(0.6,0,0);
        knjiga(0.5,0.0,0.5);

        glTranslatef(0,0,2.8);
        knjiga(0.5,0.3,0.5);

        glTranslatef(-0.6,0,0);
        knjiga(0.1,0.3,0.5);

        glTranslatef(-0.6,0,0);
        knjiga(0.5,0.3,0.1);


        glTranslatef(-0.6,0,0);
        knjiga(0.898,0.3,0.233);

        glTranslatef(-0.6,0,0);
        knjiga(0.898,0.6,0.233);

        glTranslatef(-0.6,0,0);
        knjiga(0.23,0.6,0.0);

        glTranslatef(-0.6,0,0);
        knjiga(0.4,0.7,0.9);


   glTranslatef(7.8,-3.1,-5.3);
   fotelja();

   glTranslatef(-2.7,-15.2,0.2);
   glScalef(0.8,0.8,0.8);
   glRotatef(90,0,0,1);
   fotelja();

   glTranslatef(4.5,-7.3,8.3);
        glRotatef(90,0,1,0);
        glScalef(0.5,0.5,0.5);
        knjiga(0.8,0.8,0.5);

    //cajnik
    glColor3f(0.6,0.7,0.9);
    glRotatef(90,0,1,0);
    glRotatef(270,1,0,0);
    glTranslatef(-1.2,-10.9,-1.8);
    glutSolidTeapot(0.9);


	glutSwapBuffers(); // Make it all visible
}

//----------------------------------------------------------------------
// User-input callbacks
//
// processNormalKeys: ESC, q, and Q cause program to exit
// pressSpecialKey: Up arrow = forward motion, down arrow = backwards
// releaseSpecialKey: Set incremental motion to zero
//----------------------------------------------------------------------
void processNormalKeys(unsigned char key, int xx, int yy)
{
	if (key == ESC || key == 'q' || key == 'Q') exit(0);
}

void pressSpecialKey(int key, int xx, int yy)
{
	switch (key) {
		case GLUT_KEY_UP : deltaMove = 1.0; break;
		case GLUT_KEY_DOWN : deltaMove = -1.0; break;
	}
}

void releaseSpecialKey(int key, int x, int y)
{
	switch (key) {
		case GLUT_KEY_UP : deltaMove = 0.0; break;
		case GLUT_KEY_DOWN : deltaMove = 0.0; break;
	}
}

void mouseMove(int x, int y)
{
	if (isDragging) { // only when dragging
		// update the change in angle
		deltaAngle = (x - xDragStart) * 0.005;

		// camera's direction is set to angle + deltaAngle
		lx = -sin(angle + deltaAngle);
		ly = cos(angle + deltaAngle);
	}
}

void mouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) { // left mouse button pressed
			isDragging = 1; // start dragging
			xDragStart = x; // save x where button first pressed
		}
		else  { /* (state = GLUT_UP) */
			angle += deltaAngle; // update camera turning angle
			isDragging = 0; // no longer dragging
		}
	}
}

//----------------------------------------------------------------------
// Main program  - standard GLUT initializations and callbacks
//----------------------------------------------------------------------
int main(int argc, char **argv)
{
	printf("\n\
-----------------------------------------------------------------------\n\
  OpenGL Sample Program:\n\
  - Drag mouse left-right to rotate camera\n\
  - Hold up-arrow/down-arrow to move camera forward/backward\n\
  - q or ESC to quit\n\
-----------------------------------------------------------------------\n");

	// general initializations
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1000, 600);
	glutCreateWindow("OpenGL/GLUT Sampe Program");
lights();
	// register callbacks
	glutReshapeFunc(changeSize); // window reshape callback
	glutDisplayFunc(renderScene); // (re)display callback
	glutIdleFunc(update); // incremental update
	glutIgnoreKeyRepeat(1); // ignore key repeat when holding key down
	glutMouseFunc(mouseButton); // process mouse button push/release
	glutMotionFunc(mouseMove); // process mouse dragging motion
	glutKeyboardFunc(processNormalKeys); // process standard key clicks
	glutSpecialFunc(pressSpecialKey); // process special key pressed
						// Warning: Nonstandard function! Delete if desired.
	glutSpecialUpFunc(releaseSpecialKey); // process special key release

	glutKeyboardFunc(lightoff);

	texture1=LoadTexture("05.bmp", 316, 316);
	texture2=LoadTexture("02.bmp",316,316);
	texture3=LoadTexture("01.bmp",316,316);
	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 0; // this is just to keep the compiler happy
}
