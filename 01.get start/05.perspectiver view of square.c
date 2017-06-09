/**
* @date: 2017.06.05
*/

#include <GL/glut.h>

GLfloat winWidth = 600, winHeight = 600;

GLfloat x0 = 100, y0 = 50, z0 = 50;
GLfloat xref = 50, yref = 50, zref = 0.0;
GLfloat Vx = 0.0, Vy = 1.0, Vz = 0.0;

GLfloat xwMin = -40, ywMin =-60, xwMax = 40, ywMax = 60;

GLfloat dnear = 25.0, dfar = 125.0;

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(x0, y0, z0, xref, yref, zref, Vx, Vy, Vz);

	glMatrixMode(GL_PROJECTION);
	glFrustum(xwMin, xwMax, ywMin, ywMax, dnear, dfar);
}

void displayFcn(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 1.0, 0.0);
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_LINE);
	glBegin(GL_QUADS);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(100.0, 0.0, 0.0);
	glVertex3f(100.0, 100.0, 0.0);
	glVertex3f(0.0, 100.0, 0.0);
	glEnd();
	
	glFlush();
}

void reshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	winWidth = newHeight;
	winHeight = newHeight;
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("perspectiver View of A Square");

	init();
	glutDisplayFunc(displayFcn);
	glutReshapeFunc(reshapeFcn);

	glutMainLoop();

}

