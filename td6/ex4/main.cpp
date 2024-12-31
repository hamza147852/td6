#include <iostream>
#include <vector>
using namespace std;

class Piece {
protected:
    string couleur;
    int x, y;

public:
    Piece(string couleur, int x, int y) : couleur(couleur), x(x), y(y) {}

    virtual void deplacer() = 0;

    virtual void afficher() const {
        cout << "Type: " << typeid(*this).name() << ", Couleur: " << couleur
             << ", Position: (" << x << ", " << y << ")" << endl;
    }

    virtual ~Piece() {}
};

class Pion : public Piece {
public:
    Pion(string couleur, int x, int y) : Piece(couleur, x, y) {}

    void deplacer() override {
        if (y + 1 > 8) {
            cout << "Déplacement hors limites pour le Pion à la position (" << x << ", " << y << ")" << endl;
        } else {
            y += 1;
        }
    }

    void afficher() const override {
        cout << "Pion, ";
        Piece::afficher();
    }
};

class Roi : public Piece {
public:
    Roi(string couleur, int x, int y) : Piece(couleur, x, y) {}

    void deplacer() override {
        int dx, dy;
        cout << "Entrez le déplacement pour le Roi (dx dy): ";
        cin >> dx >> dy;
        if (x + dx < 1 || x + dx > 8 || y + dy < 1 || y + dy > 8) {
            cout << "Déplacement hors limites pour le Roi à la position (" << x << ", " << y << ")" << endl;
        } else {
            x += dx;
            y += dy;
        }
    }

    void afficher() const override {
        cout << "Roi, ";
        Piece::afficher();
    }
};

int main() {
    vector<Piece*> pieces;

    pieces.push_back(new Pion("Blanc", 2, 2));
    pieces.push_back(new Pion("Noir", 5, 7));
    pieces.push_back(new Pion("Blanc", 3, 6));
    pieces.push_back(new Roi("Noir", 4, 4));

    for (Piece* piece : pieces) {
        piece->afficher();
    }

    cout << "\nDéplacement des pièces :\n";
    for (Piece* piece : pieces) {
        piece->deplacer();
        piece->afficher();
    }

    for (Piece* piece : pieces) {
        delete piece;
    }

    return 0;
}
