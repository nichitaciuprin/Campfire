#ifndef SUBGEN1_H
#define SUBGEN1_H

#include "Subgen.h"

extern Subgen _Subgen1Subgen;
extern bool _Subgen1Created;

inline void _Subgen1Init()
{
    if (!_Subgen1Created) return;
    _Subgen1Created = false;
    _Subgen1Subgen = SubgenCreate(0);
}

inline int Subgen1Next()
{
    _Subgen1Init();
    return SubgenNext(&_Subgen1Subgen);
}
inline float Subgen1FractionUnsigned()
{
    _Subgen1Init();
    return SubgenFractionUnsigned(&_Subgen1Subgen);
}
inline float Subgen1FractionSigned()
{
    _Subgen1Init();
    return SubgenFractionSigned(&_Subgen1Subgen);
}
inline float Subgen1Range(float min, float max)
{
    _Subgen1Init();
    return SubgenRange(&_Subgen1Subgen, min , max);
}

#endif
