#ifndef ABSTRACTSTATE_H
#define ABSTRACTSTATE_H

#include <string>

using namespace std;

/**
 * @brief Cette classe abstraite représente un état quelconque d'une machine à états
 */
class AbstractState
{
public:
    virtual ~AbstractState(){}
    /**
     * @brief Affiche le nom de l'état
     */
    void print() const;

protected:
    AbstractState(const string & name);

private:
    string _name; // nom de l'état
};

#endif // ABSTRACTSTATE_H
