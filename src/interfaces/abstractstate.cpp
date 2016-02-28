#include "abstractstate.h"

#include <iostream>

void AbstractState::print() const
{
    cout << _name << endl << flush;
}

AbstractState::AbstractState(const string &name) :
    _name(name)
{

}
