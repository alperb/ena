#include <GL\glut.h>
#include <math.h>

typedef struct SphereStruct {
  float x,y,z;
} SphereStruct;


GLfloat xRotated, yRotated, zRotated;
GLdouble radius = 1;

SphereStruct tSphere[16];
int SphereCount=0, iFrameCount;

void display(void);
void reshape(int x, int y);
void idle(void)
{
    xRotated += 0.01;
    //yRotated += 0.01;
    zRotated += 0.01;
		
		for (int n=0 ; n < SphereCount ; n++) {
			tSphere[n].z += 5;
			if (tSphere[n].z > 20) {
				//move last sphere to fill this sphere slot
				if (SphereCount>0) memcpy( tSphere+n ,  tSphere+SphereCount-1 , sizeof(SphereStruct) );
				SphereCount--; //one sphere deleted
				n-- ; continue; //continue (repeating processing the new sphere at this slot)
			}
		}
		
		if (--iFrameCount <= 0) {
			iFrameCount = 60*2; //every 2 seconds
			tSphere[SphereCount].x = (-1+(rand()%3))*22;
			tSphere[SphereCount].y = -22;
			tSphere[SphereCount].z = -1040;
			SphereCount += 1;
		}		
		
    display();
		SleepEx(15,0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Solid Sphere");
    xRotated = yRotated = zRotated = 30.0;
    xRotated = 43;
    yRotated = 50;

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}

void display(void)
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glBegin(GL_LINES);
    for (int n = -33; n <= 33; n += 22) {
        glVertex3f(n, -22.0f, 0.0f);
        glVertex3f(n, -22.0f, -1000.0f);
    }
    glEnd();
		
		for (int n = 0 ; n < SphereCount ; n++ ) {		
			glLoadIdentity();
			glTranslatef( tSphere[n].x , tSphere[n].y , tSphere[n].z );
			glColor3f(0.9, 0.3, 0.2);
			glRotatef(xRotated, 1.0, 0.0, 0.0);
			glRotatef(yRotated, 0.0, 1.0, 0.0);
			glRotatef(zRotated, 0.0, 0.0, 1.0);
			glScalef(1.0, 1.0, 1.0);

			glutWireSphere(3.0 , 20, 20);			
			
		}

    glFlush();
}

void reshape(int x, int y) {
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(39.0, (GLdouble)x / (GLdouble)y, 0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, x, y);
}
