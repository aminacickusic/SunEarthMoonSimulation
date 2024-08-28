#include <GL/glut.h>

void svjetloSunca() {
  GLfloat diffuseLight[] = {0.64, 0.64, 0.64, 1.0};
  GLfloat specularLight[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat position[] = {0.0, 0.0, -4.0, 1.0};
  GLfloat position2[] = {0.0, 0.0, -4.0 / 3.0, 1.0};

  glLightfv(GL_LIGHT1, GL_POSITION, position);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight);
  glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight);
  glLightfv(GL_LIGHT0, GL_POSITION, position2);

  glMaterialf(GL_FRONT, GL_SHININESS, 50.0);
  glColor3f(0.846, 0.878, 0.890);
}

void postaviBojuZemlje() {
  GLfloat ambient[] = {0.0, 0.1, 0.1, 1.0};
  GLfloat diffuse[] = {0.0, 0.7, 0.7, 1.0};
  GLfloat specular[] = {0.0, 0.8, 0.8, 1.0};
  GLfloat shininess = 150.0f;
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
  glColor4f(0.21, 0.46, 0.53, 1.0);
}

void postaviBojuMjeseca() {
  GLfloat ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};
  GLfloat diffuse[] = {0.7f, 0.7f, 0.7f, 1.0f};
  GLfloat specular[] = {0.9f, 0.9f, 0.9f, 1.0f};
  GLfloat shininess = 150.0f;
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
  glColor4f(0.5, 0.5, 0.5, 1.0);
}

