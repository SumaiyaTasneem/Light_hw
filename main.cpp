#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

GLboolean angle1 = false,angle2 = false, angle3 = false, angle4 = false;
GLfloat x=2.3, y=1.8, z=2.0;
GLfloat width= 600, height= 600;
void wall(double thickness)    // function to create the walls with given thickness
{
    glPushMatrix();
    glTranslated(0.5,0.5*thickness,0.5);
    glScaled(1.0,thickness,1.0);
    glutSolidCube(1.0);
    glPopMatrix();
}

void circle(float center_x, float center_y, float radius, float r, float g, float b, int S)
{
    float PI = 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(r,g,b);
    float I;
    for (I = 0.0; I <S; I=I++)
    {
        float angle1=(2*I*PI)/S;
        float x = center_x + cos(angle1) * radius;
        float y = center_y + sin(angle1) * radius;
        glVertex2f(x,y);
    }

    glEnd();
}

GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient[] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = {20};

GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat light_ambient[]  = {1.0, 1.0, 1.0, 1.0};
GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1 };
GLfloat light_specular[] = { 1, 1, 1, 1 };
GLfloat light_position[] = { 2.0, 25.0, 3.0, 1.0 };

void setLighting( int scene){
	glDisable( GL_LIGHT0);
	glDisable( GL_LIGHT1);
	glDisable( GL_LIGHT2);
	glDisable( GL_LIGHT3);

	if( scene == 0){
		glEnable( GL_LIGHT0);

		// only ambient light in the scene
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
		//Ambient illumination is light that's been scattered so much by the environment that its direction is
		//impossible to determine - it seems to come from all directions.
		glLightfv(GL_LIGHT0, GL_DIFFUSE, no_light);
		//The diffuse component is the light that comes from one direction, so it's brighter if it comes squarely
		//down on a surface than if it barely glances off the surface. Once it hits a surface, however, it's scattered
		//equally in all directions, so it appears equally bright, no matter where the eye is located.
		glLightfv(GL_LIGHT0, GL_SPECULAR, no_light);
		//specular light comes from a particular direction, and it tends to bounce off the surface in a
		//preferred direction. A well-collimated laser beam bouncing off a high-quality mirror produces almost
		//100 percent specular reflection.
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);

		glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, no_mat);
		glMaterialfv( GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
		//Like lights, materials have different ambient, diffuse, and specular colors, which determine the ambient,
		//diffuse, and specular reflectances of the material
	}
	else if( scene == 1){
		glEnable( GL_LIGHT1);

		//ambient and diffuse light in the scene
		glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT1, GL_SPECULAR, no_light);
		glLightfv(GL_LIGHT1, GL_POSITION, light_position);

		glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv( GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
	}
	else if( scene == 2){
		glEnable( GL_LIGHT2);

		//ambient ,diffuse and specular light in the scene
		glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
		glLightfv(GL_LIGHT2, GL_POSITION, light_position);
     //   glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 5.0);
       // glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 2.0);

		glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
	}
	else if( scene == 3){
		glEnable( GL_LIGHT3);


		//spot light
		glLightfv( GL_LIGHT3, GL_AMBIENT, light_ambient);
		glLightfv( GL_LIGHT3, GL_DIFFUSE, no_light);
		glLightfv( GL_LIGHT3, GL_SPECULAR, light_specular);
		glLightfv( GL_LIGHT3, GL_POSITION, light_position);
		GLfloat spot_direction[] = { 0.0, -2.0, 0.0 };
		glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spot_direction);
		glLightf( GL_LIGHT3, GL_SPOT_CUTOFF, 10.0);

		glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, no_mat);
		glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
	}
}

void draw_room()
 {

   // glPushMatrix();
     // Saheed Minar

 //first part

            glPushMatrix();
            glTranslated(0.66,.4,0.37);
            glScaled(.01,6.3,.01);
            glColor3f(1.0,1.0,1.0);
            wall(0.02);
            glPopMatrix();

            glPushMatrix();
            glTranslated(0.70,.4,0.37);
            glScaled(.01,6.3,.01);
            glColor3f(1.0,1.0,1.0);
            wall(0.02);
            glPopMatrix();

            glPushMatrix();
            glTranslated(0.717,.5,0.37);
            glRotated(90.0,0.0,0.0,1.0);
            glScaled(.02,3.0,.01);
            glColor3f(1.0,1.0,1.0);
            wall(0.02);
            glPopMatrix();


   //Second part

            glPushMatrix();
            glTranslated(0.75,.4,0.37);
            glScaled(.01,6.53,.01);
            glColor3f(1.0,1.0,1.0);
            wall(0.02);
            glPopMatrix();

            glPushMatrix();
            glTranslated(0.751,.51,0.37);
            glRotated(10.0,0.0,0.0,1.0);
            glScaled(.01,6.53,.01);
            glColor3f(1.0,1.0,1.0);
            wall(0.02);
            glPopMatrix();

            glPushMatrix();
            glTranslated(0.79,.4,0.37);
            glScaled(.01,6.53,.01);
            glColor3f(1.0,1.0,1.0);
            wall(0.02);
            glPopMatrix();

            glPushMatrix();
            glTranslated(0.795,.51,0.37);
            glRotated(10.0,0.0,0.0,1.0);
            glScaled(.01,6.53,.01);
            glColor3f(1.0,1.0,1.0);
            wall(0.02);
            glPopMatrix();

            glPushMatrix();
            glTranslated(0.83,.4,0.37);
            glScaled(.01,6.53,.01);
            glColor3f(1.0,1.0,1.0);
            wall(0.02);
            glPopMatrix();

            glPushMatrix();
            glTranslated(0.835,.51,0.37);
            glRotated(10.0,0.0,0.0,1.0);
            glScaled(.01,6.53,.01);
            glColor3f(1.0,1.0,1.0);
            wall(0.02);
            glPopMatrix();


            glPushMatrix();
            glTranslated(0.82,.63,0.37);
            glRotated(90.0,0.0,0.0,1.0);
            glScaled(.01,4.0,.01);
            glColor3f(1.0,1.0,1.0);
            wall(0.02);
            glPopMatrix();


        //Third part

            glPushMatrix();
            glTranslated(0.88,.4,0.37);
            glScaled(.01,6.3,.01);
            glColor3f(1.0,1.0,1.0);
            wall(0.02);
            glPopMatrix();

            glPushMatrix();
            glTranslated(0.92,.4,0.37);
            glScaled(.01,6.3,.01);
            glColor3f(1.0,1.0,1.0);
            wall(0.02);
            glPopMatrix();

            glPushMatrix();
            glTranslated(0.937,.5,0.37);
            glRotated(90.0,0.0,0.0,1.0);
            glScaled(.02,3.0,.01);
            glColor3f(1.0,1.0,1.0);
            wall(0.02);
            glPopMatrix();


        glPushMatrix();
        glTranslatef(0.308,0.12,0.377);
        circle(.5, .4, .05,1,0,0,15);
        glPopMatrix();

    //Sofa bottom
    glPushMatrix();
    glTranslated(0.2,0.1,.51);
    glScaled(.2,1.0,.3);
    glColor3f(1,.10,.50);
    wall(0.05);
    glPopMatrix();

    //sofa top
    glPushMatrix();

    glTranslated(0.21,0.1,.51);
    glScaled(.13,.2,.30);
    glRotated(90.0,0.0,0.0,1.0);
    glColor3f(0.0,0.0,0.6);
    wall(0.3);
    glPopMatrix();

    //table 4th leg
    glPushMatrix();
    glTranslated(0.77,0.0,0.31);
    glScaled(.02,6.0,.02);
    glColor3f(.0,.0,0.0);
    wall(0.05);
    glPopMatrix();
    //table 3rd leg
    glPushMatrix();
    glTranslated(0.51,0.0,0.31);
    glScaled(.02,6.0,.02);
    glColor3f(.0,.0,0.0);
    wall(0.05);
    glPopMatrix();
    //table 2nd leg
    glPushMatrix();
    glTranslated(0.77,0.0,0.11);
    glScaled(.02,6.0,.02);
    glColor3f(.0,.0,0.0);
    wall(0.05);
    glPopMatrix();
    //table 1st leg
    glPushMatrix();
    glTranslated(0.51,0.0,0.11);
    glScaled(.02,6.0,.02);
    glColor3f(.0,.0,0.0);
    wall(0.05);
    glPopMatrix();
    //table top
    glPushMatrix();
    glTranslated(0.5,0.3,0.1);
    glScaled(0.3,0.5,.25);
    glColor3f(0.8,.4,0.0);
    wall(0.05);
    glPopMatrix();



    //base wall
    glColor3f(0.6,.0,.0);
    wall(0.1);
    //right wall
    glPushMatrix();
    glRotated(-90.0,1.0,0.0,0.0);
    glColor3f(.20,.30,1.0);
    wall(0.05);
    glPopMatrix();
    //left wall
    glRotated(90.0,0.0,0.0,1.0);
    glColor3f(.70,.30,.5);
    wall(0.05);
    glPopMatrix();

    }


void display()
{
   glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0,1.0,-1.0,1.0,.6,100.0);//left, right, bottom, up, near, far
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    //glViewport(0,0,5,-75);
    //gluLookAt(x,y,2.0,0.0,0.25,0.0,0.0,1.0,0.0);

 glViewport(0, 0, width/2, height/2);
   glLoadIdentity();
    //gluLookAt(0.0, 0.0, -3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    gluLookAt(x,y,2.0,0.0,0.25,0.0,0.0,1.0,0.0);
    //glutWireTeapot(1);
    setLighting(0);
    draw_room();

    glViewport(width/2, 0, width/2, height/2);
    glLoadIdentity();
    //gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    gluLookAt(x,y,2.0,0.0,0.25,0.0,0.0,1.0,0.0);
   // glutWireTeapot(1);
   setLighting(1);
    draw_room();

    glViewport(0, height/2, width/2, height/2);
    glLoadIdentity();
    //gluLookAt(0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
    gluLookAt(x,y,2.0,0.0,0.25,0.0,0.0,1.0,0.0);
    //glutWireTeapot(1);
    setLighting(2);
    draw_room();

    glViewport(width/2, height/2, width/2, height/2);
    glLoadIdentity();
    //gluLookAt(0.0, -3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
    gluLookAt(x,y,2.0,0.0,0.25,0.0,0.0,1.0,0.0);
    //glutWireTeapot(1);
    setLighting(3);
    draw_room();

    glFlush();
}


void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 'a':
    case 'A':
        angle1 = !angle1;
        angle2 = false;
        angle3 = false;
        angle4 = false;
        break;
    case 'b':
    case 'B':
        angle2= !angle2;
        angle1 = false;
        angle3 = false;
        angle4 = false;
        break;
    case 'c':
    case 'C':
        angle3= !angle3;
        angle1 = false;
        angle2 = false;
        angle4 = false;
        break;
    case 'd':
    case 'D':
        angle4= !angle4;
        angle1 = false;
        angle2 = false;
        angle3 = false;
        break;
    case 27:    // Escape key
        exit(1);
    }
}

void animate()
{
    if (angle1 == true)
    {
        x += 0.002;
    }
    if (angle2 == true)
    {
        x -= 0.002;
    }
    if (angle3 == true)
    {
        y -= 0.002;
    }
    if (angle4 == true)
    {
        y += 0.002;
    }
    glutPostRedisplay();

}
static void reshape(int w, int h) {
    width = w;
    height = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow(argv[0]);
    //glutCreateWindow("The Room");
//    initRendering();

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(animate);

    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    //glViewport(0,0,640,480);
    glutMainLoop();


}
