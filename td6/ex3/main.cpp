#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Vehicule {
protected:
    static int numeroSerie;
    static int numeroVehicule;
    int serie;
    int numero;
    int annee;
    float prix;

public:
    Vehicule(int annee, float prix) : annee(annee), prix(prix) {
        if (numeroVehicule == 10000) {
            numeroVehicule = 1;
            numeroSerie++;
        }
        serie = numeroSerie;
        numero = numeroVehicule++;
    }

    virtual void accelerer() const = 0;

    virtual void afficher() const {
        cout << "Matricule: " << serie << " TUN " << numero
             << ", Année: " << annee
             << ", Prix: " << prix << " TND" << endl;
    }

    virtual ~Vehicule() {}
};

int Vehicule::numeroSerie = 1;
int Vehicule::numeroVehicule = 1;

class Voiture : public Vehicule {
private:
    int nombrePlaces;

public:
    Voiture(int annee, float prix, int nombrePlaces)
        : Vehicule(annee, prix), nombrePlaces(nombrePlaces) {}

    void accelerer() const override {
        cout << "Je peux atteindre 200km/h." << endl;
    }

    void afficher() const override {
        Vehicule::afficher();
        cout << "Nombre de places: " << nombrePlaces << endl;
    }
};

class Camion : public Vehicule {
private:
    float chargeMaximale;

public:
    Camion(int annee, float prix, float chargeMaximale)
        : Vehicule(annee, prix), chargeMaximale(chargeMaximale) {}

    void accelerer() const override {
        cout << "Je peux atteindre 120km/h." << endl;
    }

    void afficher() const override {
        Vehicule::afficher();
        cout << "Charge maximale: " << chargeMaximale << " tonnes" << endl;
    }
};

int main() {
    Voiture voiture1(2023, 50000, 5);
    Camion camion1(2022, 120000, 10);

    cout << "Caractéristiques de la voiture :" << endl;
    voiture1.afficher();
    voiture1.accelerer();

    cout << "\nCaractéristiques du camion :" << endl;
    camion1.afficher();
    camion1.accelerer();

    Voiture voiture2(2024, 60000, 4);
    cout << "\nCaractéristiques d'une nouvelle voiture :" << endl;
    voiture2.afficher();

    return 0;
}

