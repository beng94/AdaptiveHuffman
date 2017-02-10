#include "data.hpp"


Data::Data() :
    order{512}
{}

Data::Data(int order, char code) :
    order{order}, code{code}, weight{0}
{}
