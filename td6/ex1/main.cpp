#include <iostream>
#include <cmath>
using namespace std;

class Vecteur {
protected:
    float x, y;

public:

    Vecteur(float x = 0, float y = 0) : x(x), y(y) {}


    void affiche() const {
        cout << "(" << x << " , " << y << ")" << endl;
    }


    void deplacer(float dx, float dy) {
        x += dx;
        y += dy;
    }
};

class Vecteur3D : public Vecteur {
private:
    float z;

public:


    Vecteur3D(float x = 0, float y = 0, float z = 0) : Vecteur(x, y), z(z) {}


    void affiche() const {
        cout << "(" << x << " , " << y << " , " << z << ")" << endl;
    }


    void deplacer(float dx, float dy, float dz) {
        Vecteur::deplacer(dx, dy);
        z += dz;
    }
};

int main() {

    Vecteur v1;
    cout << "Vecteur nul : ";
    v1.affiche();


    v1.deplacer(2, 3);
    cout << "Après déplacement : ";
    v1.affiche();


    Vecteur3D* v3 = new Vecteur3D(1, 2, 3);
    cout << "Vecteur3D créé dynamiquement : ";
    v3->affiche();


    v3->deplacer(1, 1, 1);
    cout << "Après déplacement : ";
    v3->affiche();


    delete v3;

    return 0;
}
