/**
 * @date: 2017.06.05
 * @description: 螺旋线。
 */

#include <GL/glut.h>
#include <math.h>

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 900.0);
}

void simulate(void) {
	GLfloat pi2 = 3.1415936 * 2;
	GLfloat one = 1.0;
	GLfloat zero = 0.0;
	GLfloat r = 450;
	GLfloat x = 500.0;
	GLfloat y = 450.0;
	GLfloat c = 0.08;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POINTS);

	for (GLfloat j = 0; j < pi2 * 10; j += 0.01) {
		r = r < zero ? zero : r;
		glVertex2f(x + r * cos(j) + one, y + r * sin(j) + one);
		glVertex2f(x + r * cos(j) + one, y + r * sin(j) - one);
		glVertex2f(x + r * cos(j) - one, y + r * sin(j) + one);
		glVertex2f(x + r * cos(j) - one, y + r * sin(j) - one);
		glVertex2f(x + r * cos(j), y + r * sin(j));
		r -= c;		

	}

	glEnd();
	glFlush();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(1000,900);
	glutCreateWindow("an example OpenGL Program");

	init();
	glutDisplayFunc(simulate);
	glutMainLoop();

	return 0;
}
