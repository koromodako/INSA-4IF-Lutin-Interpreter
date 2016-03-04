#ifndef DATAMAP_H
#define DATAMAP_H

#include <map>
#include <string>

using namespace std;


/**
 * @brief Cette structure décrit une mémoire et les méta-données relatives à cette mémoire.
 */
struct Data {
    bool cst;       ///< la mémoire est constante ou non
    bool set;       ///< la mémoire est écrite ou non
    bool used;      ///< la mémoire est lue ou non
    double value;   ///< la valeur stockée dans la mémoire
    Data(bool _cst = false,
         bool _set = false,
         bool _used = false,
         double _value = -1) :
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
    /// \todo Implementer la methode de test
    ///
    ///
	public:
    /**
         * @brief Stringify
         * @return la structure de donnée sous forme de string à restituer
         */
		string Stringify();
		string Test();
	
	
	
	private:



};

#endif // DATAMAP_H
