#ifndef ABSTRACTPS_H
#define ABSTRACTPS_H

#include "src/interfaces/abstractstate.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class AbstractPS : public AbstractState
{
public:
    ~AbstractPS(){}

    /// \todo ajouter toutes les transitions par defaut ici

protected:
    AbstractPS();
};

#endif // ABSTRACTPS_H
