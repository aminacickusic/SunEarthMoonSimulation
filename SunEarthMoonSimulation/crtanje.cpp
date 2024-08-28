
// CRTANJE SUNCA, MJESECA I ZEMLJE
#include <GL/glut.h>
float sat = 0.0;
float dan = 0.0;
float duzina_sata = 1.0;
float ugaoOkoSunca = 360.0 / 365.0;
float ugaoOkoOse = 360.0 / 24.0;
float ugaoOkoZemlje = 360.0 / 30;
bool upali_teksturu = false;
GLint svjetlo = 0;

void svjetloSunca();
void postaviBojuZemlje();
void postaviBojuMjeseca();
void orthoPogled();
void frustumPogled();
void postaviTeksturu(int);
void tastatura(unsigned char tipka, int x, int y) {
  switch (tipka) {
    case 27:
      exit(0);
      break;
    case 'o':
      orthoPogled();
      break;
    case 'f':
      frustumPogled();
      break;
    case 't':
      upali_teksturu = true;
      break;
    case 'x':
      upali_teksturu = false;
      break;
    case 'l':
      svjetlo = 1;
      break;
    case 's':
      svjetlo = 0;
      break;
  }
  glutPostRedisplay();
}

void promijeni_duzinu_dana(int button, int state, int x, int y) {
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    duzina_sata = duzina_sata * 2;
  }
  if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
    duzina_sata = duzina_sata / 2;
  }
  glutPostRedisplay();
}

void idle() {
  if (dan >= 366.0) dan = 0.0;
  if (sat >= 24.0) sat = 0.0;
  sat += duzina_sata;
  dan += duzina_sata / 24;
  glutPostRedisplay();
}

void nacrtajSunce() {
  if (svjetlo == 1) {
    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    svjetloSunca();

  } else {
    glDisable(GL_LIGHTING);
    glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHT1);
    glColor3f(0.846, 0.848, 0.890);
  }
  glTranslatef(0.0, 0.0, -4.0);
  /*if (upali_teksturu == true) {

  glEnable(GL_TEXTURE_2D);
   glGenTextures(1, &suntex);
   glBindTexture(GL_TEXTURE_2D, suntex);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, gimp_image.width, gimp_image.height,
              0, GL_RGBA, GL_UNSIGNED_BYTE, gimp_image.pixel_data);
  glBindTexture(GL_TEXTURE_2D, suntex);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glutSolidSphere(0.25, 30, 30);
  }   else {
  //gilDisable(GL_TEXTURE_2D);
  glutSolidSphere(0.25, 30, 30);
  glDisable(GL_TEXTURE_2D);
  }*/  //dio koda koji bi se koristio kad bi se teksture ucitavale preko fajla u kojem je definirana c struktura koristenjem gimp alata

  if (upali_teksturu == true) {
    glEnable(GL_TEXTURE_2D);
    postaviTeksturu(1);
  } else {
    glutSolidSphere(0.25, 50, 50);
    glDisable(GL_TEXTURE_2D);
  }
}

void nacrtajZemlju() {
  if (svjetlo == 1) {
    glDisable(GL_LIGHT0);
    postaviBojuZemlje();
    glColor3f(0.157, 0.220, 0.630);

  } else {
    glColor3f(0.0867, 0.108, 0.510);
  }
  glPushMatrix();
  glRotatef(ugaoOkoSunca * dan, 0.0, 1.0, 0.0);
  glTranslatef(0.6, 0.0, 0.0);
  glPushMatrix();
  glRotatef(ugaoOkoOse * sat, 0.0, 1.0, 0.0);
  glRotatef(-90.0, 1.0, 0.0, 0.0);

  /*if (upali_teksturu == true) {
  glColor3f(1,1,1);
  glRotatef(-90.0, 1.0, 0.0, 0.0);

  glEnable(GL_TEXTURE_2D);
     glGenTextures(1, &earthtex);
      glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
     glBindTexture(GL_TEXTURE_2D, earthtex);
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, gimp_image2.width,
  gimp_image2.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, gimp_image2.pixel_data);
     glBindTexture(GL_TEXTURE_2D, earthtex);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glutSolidSphere(0.13, 30, 30);

  }   else {
  glDisable(GL_TEXTURE_2D);
  glutSolidSphere(0.13, 30, 30);
  }*/   //dio koda koji bi se koristio kad bi s teksture ucitavale preko fajla u kojem je c struktura
  if (upali_teksturu == true) {
    glEnable(GL_TEXTURE_2D);
    postaviTeksturu(2);
  } else {
    glDisable(GL_TEXTURE_2D);
    glutSolidSphere(0.13, 30, 30);
  }
  glPopMatrix();
}

void nacrtajMjesec() {
  if (svjetlo == 1) {
    glDisable(GL_LIGHT0);
    postaviBojuMjeseca();
    glColor3f(0.460, 0.455, 0.455);

  } else {
    glColor3f(0.883, 0.885, 0.920);
  }
  glRotatef(ugaoOkoZemlje * dan, 0.0, 1.0, 0.0);
  glTranslatef(0.22, 0.0, 0.0);
  /*if (upali_teksturu == true) {

  glEnable(GL_TEXTURE_2D);
     glGenTextures(1, &moontex);
      glEnable(GL_TEXTURE_GEN_S);
         glEnable(GL_TEXTURE_GEN_T);
     glBindTexture(GL_TEXTURE_2D, moontex);

     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, gimp_image3.width,
  gimp_image3.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, gimp_image3.pixel_data);
     glBindTexture(GL_TEXTURE_2D, moontex);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glutSolidSphere(0.05, 30, 30);

  }   else {
  glDisable(GL_TEXTURE_2D);
  glutSolidSphere(0.05, 30, 30);
  }*/ // isto kao i kod mjeseca i zemlje
  if (upali_teksturu == true) {
    glEnable(GL_TEXTURE_2D);
    postaviTeksturu(3);
  } else {
    glDisable(GL_TEXTURE_2D);
    glutSolidSphere(0.05, 30, 30);
  }
  glPopMatrix();
}
