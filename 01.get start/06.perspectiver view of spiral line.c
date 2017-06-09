/**
* @date: 2017.06.05
*/
#include <GL/glut.h>

GLfloat winWidth = 1000, winHeight = 1000;

GLfloat x0 = 3, y0 = 0, z0 = 110;
GLfloat xref = 0, yref = 0, zref = 0.0;
GLfloat Vx = 0.0, Vy = 1.0, Vz = 0.0;

GLfloat xwMin = -50, ywMin = -50, xwMax = 85, ywMax = 50;

GLfloat dnear = 1, dfar = 1000;

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(x0, y0, z0, xref, yref, zref, Vx, Vy, Vz);

	glMatrixMode(GL_PROJECTION);
	glFrustum(xwMin, xwMax, ywMin, ywMax, dnear, dfar);
}

void displayFcn(void) {
	GLfloat pi2 = 3.1415936 * 2;
	GLfloat one = 1.0;
	GLfloat zero = 0.0;
	GLfloat r = 500;
	GLfloat x = 0;
	GLfloat y = 0;
	GLfloat c = 0.08;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3, 0.5, 0.0);

	glBegin(GL_POINTS);

	for (GLfloat j = 0; j < pi2 * 10; j += 0.01) {
		r = r < zero ? zero : r;
		glVertex3f(x + r * cos(j) + one, y + r * sin(j) + one, 90);
		glVertex3f(x + r * cos(j) + one, y + r * sin(j) - one, 90);
		glVertex3f(x + r * cos(j) - one, y + r * sin(j) + one, 90);
		glVertex3f(x + r * cos(j) - one, y + r * sin(j) - one, 90);
		glVertex3f(x + r * cos(j), y + r * sin(j), 90);
		r -= c;
	}

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
	glutCreateWindow("perspectiver View of A spiral");

	init();
	glutDisplayFunc(displayFcn);
	//	glutReshapeFunc(reshapeFcn);

	glutMainLoop();

}

