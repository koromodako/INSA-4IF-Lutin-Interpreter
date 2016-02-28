#ifndef ABSTRACTEXPRESSION_H
#define ABSTRACTEXPRESSION_H

#include "src/types.h"

using namespace std;

/**
 * @brief Cette classe définit une expression arithmétique générique
 */
class AbstractExpression
{
public:
    virtual ~AbstractExpression(){}

    /// \todo Trouver si on peut pas éviter ça,
    ///         pas en mettant un enum de type non plus bien sûr
    ///         mais en essayant de trouver une meilleure solution dans le simplify de BinaryExpression
    virtual bool isNumber() = 0;
    virtual bool isBinaryExpression() = 0;
    virtual bool isVariable() = 0;

    /**
     * @brief eval
     * @param dmap
     * @return
     */
    virtual int eval(DataMap & dmap, bool & ok) = 0;
    /**
     * @brief simplify
     * @param dmap
     */
    virtual AbstractExpression * simplify(DataMap & dmap, bool & ok) = 0;
    /**
     * @brief stringify
     * @return
     */
    virtual string stringify() = 0;

protected:
    AbstractExpression();

};

#endif // ABSTRACTEXPRESSION_H
