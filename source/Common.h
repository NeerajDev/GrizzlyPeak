#ifndef COMMON_H
#define COMMON_H

#include <math.h>

inline double round(double r)
    {
    return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
    }

#endif // COMMON_H
