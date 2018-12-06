#include "csomopont.h"



Csomopont *Csomopont::nullasGyermek () const
{
    return balNulla;
}

Csomopont *Csomopont::egyesGyermek () const
{
    return jobbEgy;
}

void Csomopont::ujNullasGyermek (Csomopont * gy)
{
    balNulla = gy;
}

void Csomopont::ujEgyesGyermek (Csomopont * gy)
{
    jobbEgy = gy;
}

char Csomopont::getBetu () const
{
    return betu;
}
