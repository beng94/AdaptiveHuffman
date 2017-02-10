#include "data.hpp"


Data::Data() :
    order{512}, code{0x0}, weight{0}
{}

Data::Data(int order, char code) :
    order{order}, code{code}, weight{0}
{}
