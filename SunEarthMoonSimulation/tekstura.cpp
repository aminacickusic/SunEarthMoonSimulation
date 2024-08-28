#include <GL/glut.h>
#include <fstream>
using namespace std;

struct Slika {
  char* pixel;
  int sirina;
  int visina;

  Slika(char* podaci, int s, int v) {
    pixel = podaci;
    sirina = s;
    visina = v;
  }

  ~Slika() { delete[] pixel; }
};
GLuint tekstura;
Slika* objekat;
GLUquadricObj* obj;

template <class V>
struct pom_struktura {
  V* niz1;
  bool obrisi;

  pom_struktura(V* niz = NULL) : niz1(niz), obrisi(false) {}

  ~pom_struktura() {
    if (!obrisi && niz1 != NULL) {
      delete[] niz1;
    }
  }

  V* dealociraj() {
    obrisi = true;
    return niz1;
  }
};

int procitajBajte(ifstream& fajl) {
  char niz[4];
  fajl.read(niz, 4);
  return (int)(((unsigned char)niz[3] << 24) | ((unsigned char)niz[2] << 16) |
               ((unsigned char)niz[1] << 8) | (unsigned char)niz[0]);
}

Slika* loadBMP(const char* fajl) {
  ifstream podatak;
  podatak.open(fajl, ifstream::binary);
  char niz[2];
  podatak.read(niz, 2);
  podatak.ignore(8);

  int pomjeraj = procitajBajte(podatak);
  int velicinaH = procitajBajte(podatak);
  int sirina1 = procitajBajte(podatak);
  int visina1 = procitajBajte(podatak);
  podatak.ignore(2);

  int bajti = ((sirina1 * 3 + 3) / 4) * 4 - (sirina1 * 3 % 4);
  int vel = bajti * visina1;

  pom_struktura<char> pixeli(new char[vel]);
  podatak.seekg(pomjeraj, ios_base::beg);
  podatak.read(pixeli.niz1, vel);

  pom_struktura<char> pixeli2(new char[sirina1 * visina1 * 3]);
  for (int y = 0; y < visina1; ++y) {
    for (int x = 0; x < sirina1; ++x) {
      for (int c = 0; c < 3; ++c) {
        pixeli2.niz1[3 * (sirina1 * y + x) + c] =
            pixeli.niz1[bajti * y + 3 * x + (2 - c)];
      }
    }
  }

  podatak.close();
  return new Slika(pixeli2.dealociraj(), sirina1, visina1);
}

void postaviTeksturu(int p) {
  if (p == 1)
    objekat = loadBMP("./images/sunce.bmp");
  if (p == 2)
    objekat = loadBMP("./images/okzemlja.bmp");
  if (p == 3)
    objekat = loadBMP("./images/okmjesec.bmp");

  glGenTextures(1, &tekstura);
  glBindTexture(GL_TEXTURE_2D, tekstura);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, objekat->sirina, objekat->visina, 0,
               GL_RGB, GL_UNSIGNED_BYTE, objekat->pixel);
  delete objekat;

  glColor3f(1, 1, 1);
  obj = gluNewQuadric();
  gluQuadricNormals(obj, GLU_SMOOTH);
  glBindTexture(GL_TEXTURE_2D, tekstura);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  gluQuadricTexture(obj, 1);
  if (p == 1) gluSphere(obj, 0.25, 60, 60);
  if (p == 2) gluSphere(obj, 0.13, 50, 50);
  if (p == 3) gluSphere(obj, 0.05, 50, 50);
  gluDeleteQuadric(obj);
}

