#include <GL/glut.h>
#include <cmath>
#include <fstream>

void nacrtajZemlju();
void nacrtajSunce();
void nacrtajMjesec();
void idle();
void promijeni_duzinu_dana(int, int, int, int);
void tastatura(unsigned char, int, int);
void reshape(GLint, GLint);

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  nacrtajSunce();
  nacrtajZemlju();
  nacrtajMjesec();
  glutSwapBuffers();
  glFlush();
}

void init() {
  glClearColor(0.0, 0.0, 0.1, 0.0);
  glEnable(GL_DEPTH_TEST);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(700, 700);
  glutCreateWindow("Sunce, Zemlja, Mjesec");
  init();
  glutReshapeFunc(reshape);
  glutKeyboardFunc(tastatura);
  glutDisplayFunc(display);
  glutMouseFunc(promijeni_duzinu_dana);
  glutIdleFunc(idle);
  glutMainLoop();
  return 0;
}

