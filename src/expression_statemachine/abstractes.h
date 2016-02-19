#ifndef ABSTRACTES_H
#define ABSTRACTES_H

#include "src/interfaces/abstractstate.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les expressions arithmétiques.
 */
class AbstractES : public AbstractState
{
public:
    ~AbstractES(){}

    /// \todo ajouter toutes les transitions par defaut ici

protected:
    AbstractES();

};

#endif // ABSTRACTES_H
