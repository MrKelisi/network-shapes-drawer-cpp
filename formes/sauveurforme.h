#pragma once

#include <formes/visiteurforme.h>
#include <formes/forme.h>
#include <geometrie/vecteur.h>
#include <chargerDonnees/ChargerDonnees.h>

class SauveurForme : public VisiteurForme {
public:
    /**
     * @brief Permet de sauvegarder dans un fichier les formes
     * @param nomFichier Nom du fichier
     */
    SauveurForme(std::string nomFichier);
    virtual ~SauveurForme();

    virtual void visiter(const Cercle* cercle) const override;
    virtual void visiter(const Polygone* polygone) const override;
    virtual void visiter(const Segment* segment) const override;
    virtual void visiter(const Triangle* triangle) const override;
    virtual void visiter(const Groupe* groupe) const override;

    /**
     * @brief Charge les formes du fichier de sauvegarde
     */
    int charger(Forme ** &formes) const;

    /**
     * @brief Vide le fichier de sauvegarde
     */
    void vider() const;

private:

    std::string _filename;
    ChargerDonnees* _chargerDonnees;

    /**
     * @brief Envoie des données au fichier de sauvegarde
     * @param data Données à envoyer
     */
    void enregistrer(const std::string& data) const;

    /**
     * @brief Méthode commune à toutes les formes
     * @param forme Forme à visiter
     * @return std::string contenant les données de la forme
     */
    std::string visiterForme(const Forme* forme) const;

    /**
     * @brief Donne les données du vecteur en tant que chaîne de caractères
     * @param vecteur Vecteur à traiter
     * @return std::string contenant les données du vecteur
     */
    std::string visiterVecteur(const Vecteur& vecteur) const;
};