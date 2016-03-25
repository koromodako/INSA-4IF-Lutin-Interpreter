#ifndef DATAMAP_H
#define DATAMAP_H

#include <map>
#include <string>

using namespace std;

/**
 * @brief Cette structure décrit une mémoire et les méta-données relatives à cette mémoire
 */
struct Data {
    bool exist;     ///< la mémoire existe (a été déclarée à l'aide de 'const' ou 'var')
    bool cst;       ///< la mémoire est constante
    bool set;       ///< la mémoire est écrite. Si la mémoire est constante, set est true
    bool multdecl;  ///< la mémoire a été déclarée plus d'une fois
    bool used;      ///< la mémoire est lue
    bool isKnown;   ///< la valeur de la mémoire est connue après la propagation de constantes
    double value;   ///< la valeur stockée dans la mémoire
    Data(bool _exist = false, bool _cst = false, bool _set = false,
         bool _multdecl = false, bool _used = false, double _value = -1) :
        exist(_exist), cst(_cst), set(_set), multdecl(_multdecl),
        used(_used), isKnown(false), value(_value)
    {}
};

/**
 * @brief Représente la table des symboles
 */
class DataMap: public map<string, Data>
{
public:
    DataMap();
    /**
     * @brief Commence l'ajout d'une nouvelle constante
     * @param identifier
     *      Identifiant de la constante
     */
    void StartConst(const string & identifier);

    /**
     * @brief Ajoute une variable avec le nom donné si elle
     *        n'est pas déjà dans la map.
     * @param identifier
     *      Identifiant de la variable
     */
    void AddIfNotExist(const string &identifier);

    /**
     * @brief Ajoute une nouvelle variable
     * @param identifier
     *      Identifiant de la variable
     * @return vrai si c'est la première déclaration de la variable
     */
    bool AppendVar(const string & identifier);
    /**
     * @brief Affecte la valeur à la mémoire (constante) en cours d'ajout
     * @param value
     *      Valeur à donner à la donnée
     */
    bool SetDataValue(double value);
    bool SetDataValue(string value);
    /**
     * @brief Termine l'ajout de la nouvelle mémoire
     * @return true si la donnée a pu être ajoutée, false sinon (en cas de double déclaration).
     */
    bool EndData();
    /**
     * @brief Retourne une chaîne de caractères correspondant aux déclarations des variables et constantes
     * @return la structure de donnée sous forme de string à restituer
     */
    string Stringify() const;
    /**
     * @brief Cette méthode vérifie l'intégrité de la structure en réalisant les tests suivants :
     *      + les variables utilisées existent
     *      + les variables déclarées sont utilisées
     *      + les variables déclarées sont initialisées et utilisées
     *
     * @return les erreurs trouvées sous forme de chaîne de caractères
     */
    string Test(bool &ok) const;
    /**
     * @brief Retourne la dernière erreur
     * @return la dernière erreur rencontrée
     */
    inline const string &GetLastError() const { return _lastError; }

private:
    string _currentIdentifier;
    Data _currentData;
    string _lastError;
};

#endif // DATAMAP_H
