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

    /**
     * @brief eval
     * @param dmap
     * @return
     */
    virtual int eval(DataMap & dmap) = 0;
    /**
     * @brief simplify
     * @param dmap
     */
    virtual void simplify(DataMap & dmap) = 0;
    /**
     * @brief stringify
     * @return
     */
    virtual string stringify() = 0;

protected:
    AbstractExpression();

};

#endif // ABSTRACTEXPRESSION_H
