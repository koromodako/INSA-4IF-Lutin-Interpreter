#ifndef DATAMAP_H
#define DATAMAP_H

#include <map>
#include <string>

using namespace std;


/**
 * @brief Cette structure décrit une mémoire et les méta-données relatives à cette mémoire.
 */
struct Data {
    bool exist;     ///< la mémoire existe (au sens a été déclarée à l'aide de 'const' ou 'var')
    bool cst;       ///< la mémoire est constante ou non
    bool set;       ///< la mémoire est écrite ou non. Si la mémoire est constante, set est true
                    ///< si elle a été réafféctée après sa création
    bool used;      ///< la mémoire est lue ou non
    double value;   ///< la valeur stockée dans la mémoire
    Data(bool _exist = false,
         bool _cst = false,
         bool _set = false,
         bool _used = false,
         double _value = -1) :
        exist(_exist),
        cst(_cst),
        set(_set),
        used(_used),
        value(_value)
    {}
};

/**
 * @brief Represente la table des symboles
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
     * @brief Commence l'ajout d'une nouvelle variable
     * @param identifier
     *      Identifiant de la variable
     */
    void StartVar(const string & identifier);
    /**
     * @brief Donne la valeur de la donnée (constante ou la variable) en cours d'ajout
     * @param value
     *      Valeur à donner à la donnée
     */
    void SetDataValue(double value);
    /**
     * @brief Termine l'ajout de la nouvelle donnée (constante ou variable)
     * return true si la donnée a pu être ajouté, false sinon (en cas de double déclaration).
     */
    bool EndData();
    /**
     * @brief Stringify
     * @return la structure de donnée sous forme de string à restituer
     */
    string Stringify() const;
    /**
     * @brief Cette méthode vérifie l'intégrité de la structure en réalisant les tests suivant :
     *      + les variables utilisées existent
     *      + les variables déclarées sont utilisées
     *      + les constantes ne sont pas utilisées en partie gauche d'une affectation
     *
     * @return les erreurs trouvées sous forme de chaine de charactère
     */
    string Test() const;

private:
    string _current_identifier;
    Data _current_data;
};

#endif // DATAMAP_H
