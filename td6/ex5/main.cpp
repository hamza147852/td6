
class Personne {
    private String nom;
    private int age;
    private String sexe;

    public Personne(String nom, int age, String sexe) {
        this.nom = nom;
        this.age = age;
        this.sexe = sexe;
    }

    public String getNom() {
        return nom;
    }

    public int getAge() {
        return age;
    }

    public String getSexe() {
        return sexe;
    }


    public void setNom(String nom) {
        this.nom = nom;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setSexe(String sexe) {
        this.sexe = sexe;
    }


    public String getPersonne() {
        return "Nom: " + nom + ", Age: " + age + ", Sexe: " + sexe;
    }
}


class Enseignant extends Personne {
    private String charge;

    public Enseignant(String nom, int age, String sexe, String charge) {
        super(nom, age, sexe);
        this.charge = charge;
    }

    public String getCharge() {
        return charge;
    }

    public void setCharge(String charge) {
        this.charge = charge;
    }

    //
    public String getPersonne() {
        return super.getPersonne() + ", Charge: " + charge;
    }
}

class Etudiant extends Personne {
    private String filiere;

    public Etudiant(String nom, int age, String sexe, String filiere) {
        super(nom, age, sexe);
        this.filiere = filiere;
    }

    public String getFiliere() {
        return filiere;
    }

    public void setFiliere(String filiere) {
        this.filiere = filiere;
    }

    public String getPersonne() {
        return super.getPersonne() + ", Filière: " + filiere;
    }
}

class Contractuel extends Enseignant {
    private String filiere;

    public Contractuel(String nom, int age, String sexe, String charge, String filiere) {
        super(nom, age, sexe, charge);
        this.filiere = filiere;
    }

    public String getFiliere() {
        return filiere;
    }

    public void setFiliere(String filiere) {
        this.filiere = filiere;
    }

    public String getPersonne() {
        return super.getPersonne() + ", Filière: " + filiere;
    }
}

public class GestionRessourcesHumaines {
    public static void main(String[] args) {
        Enseignant enseignant = new Enseignant("Alice", 40, "Féminin", "Cours de Mathématiques");
        Etudiant etudiant = new Etudiant("Bob", 20, "Masculin", "Informatique");
        Contractuel contractuel = new Contractuel("Charlie", 25, "Masculin", "Tutorat", "Physique");

        System.out.println(enseignant.getPersonne());
        System.out.println(etudiant.getPersonne());
        System.out.println(contractuel.getPersonne());
    }
}
