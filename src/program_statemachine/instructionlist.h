#ifndef INSTRUCTIONLIST_H
#define INSTRUCTIONLIST_H

#include <list>
#include <string>

#include "../types.h"
/**
 * @brief Classe representant la liste de toutes les instructions du programme
 */
class InstructionList: public list<Instruction>
{
	public:
    /**
         * @brief Stringify
         * @return la structure de donnée sous forme de string à restituer
         */
        string Stringify() const;
	
	private:
};

#endif // INSTRUCTIIONLIST_H
