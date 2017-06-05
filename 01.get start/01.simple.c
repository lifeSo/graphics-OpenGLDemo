/**
 * @date: 2017.06.05
 */

#include <GL/glut.h>

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.4, 0.2);

	glBegin(GL_LINES);
	glVertex2i(10, 10);
	glVertex2i(190, 10);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(10, 10);
	glVertex2i(10, 140);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(190, 10);
	glVertex2i(190, 140);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(10, 140);
	glVertex2i(190, 140);
	glEnd();

	glFlush();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(1200, 300);
	glutCreateWindow("an example OpenGL Program");

	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();

	return 0;
}