#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Robot {
protected:
    string nom;
    float x, y;
    float portee;
    bool estMort;

public:

    Robot(string nom, float x, float y, float portee)
        : nom(nom), x(x), y(y), portee(portee), estMort(false) {}


    virtual void affiche() const {
        cout << "Nom: " << nom
             << ", Position: (" << x << ", " << y << ")"
             << ", Portée: " << portee
             << ", Statut: " << (estMort ? "Mort" : "En vie")
             << endl;
    }


    void deplacer(float dx, float dy) {
        x += dx;
        y += dy;
    }


    bool estMortStatus() const {
        return estMort;
    }


    pair<float, float> getPosition() const {
        return {x, y};
    }


    string getNom() const {
        return nom;
    }


    void setMort() {
        estMort = true;
    }
};

class RobotChasseur : public Robot {
public:

    RobotChasseur(string nom, float x, float y, float portee)
        : Robot(nom, x, y, portee) {}


    bool estDansPortee(const Robot& autre) const {
        float dx = x - autre.getPosition().first;
        float dy = y - autre.getPosition().second;
        return sqrt(dx * dx + dy * dy) <= portee;
    }


    void tuer(Robot& autre) {
        if (!autre.estMortStatus() && estDansPortee(autre)) {
            autre.setMort();
            cout << autre.getNom() << " a été abattu par " << nom << "!" << endl;
        }
    }
};

int main() {

    RobotChasseur optimus("Optimus", 2, 3, 25);
    optimus.affiche();


    optimus.deplacer(33, 19);
    cout << "Après déplacement :" << endl;
    optimus.affiche();


    vector<Robot> robots = {
        Robot("Megatron", 30, 20, 10),
        Robot("Bumblebee", 40, 25, 10),
        Robot("Starscream", 10, 5, 10),
        Robot("Jazz", 35, 22, 10),
        Robot("Ironhide", 15, 18, 10)
    };


    cout << "\nListe des robots :" << endl;
    for (const auto& robot : robots) {
        robot.affiche();
    }


    cout << "\nChasse en cours :" << endl;
    for (auto& robot : robots) {
        if (optimus.estDansPortee(robot)) {
            optimus.tuer(robot);
        }
    }


    cout << "\nÉtat final des robots :" << endl;
    for (const auto& robot : robots) {
        robot.affiche();
    }

    return 0;
}
