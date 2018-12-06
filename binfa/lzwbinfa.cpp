#include "lzwbinfa.h"

void LZWBinFa::operator<< (char b)
{
    // Mit kell betenni éppen, '0'-t?
    if (b == '0')
    {
        /* Van '0'-s gyermeke az aktuális csomópontnak?
       megkérdezzük Tőle, a "fa" mutató éppen reá mutat */
        if (!fa->nullasGyermek ())	// ha nincs, hát akkor csinálunk
        {
            // elkészítjük, azaz páldányosítunk a '0' betű akt. parammal
            Csomopont *uj = new Csomopont ('0');
            // az aktuális csomópontnak, ahol állunk azt üzenjük, hogy
            // jegyezze már be magának, hogy nullás gyereke mostantól van
            // küldjük is Neki a gyerek címét:
            fa->ujNullasGyermek (uj);
            // és visszaállunk a gyökérre (mert ezt diktálja az alg.)
            fa = &gyoker;
            
            nullasok++;
        }
        else			// ha van, arra rálépünk
        {
            // azaz a "fa" pointer már majd a szóban forgó gyermekre mutat:
            fa = fa->nullasGyermek ();
        }
    }
    // Mit kell betenni éppen, vagy '1'-et?
    else
    {
        if (!fa->egyesGyermek ())
        {
            Csomopont *uj = new Csomopont ('1');
            fa->ujEgyesGyermek (uj);
            fa = &gyoker;
            
            egyesek++;
        }
        else
        {
            fa = fa->egyesGyermek ();
        }
    }
}

void LZWBinFa::kiir (void)
{
    // Sokkal elegánsabb lenne (és más, a bevezetésben nem kibontandó reentráns kérdések miatt is, mert
    // ugye ha most két helyről hívják meg az objektum ilyen függvényeit, tahát ha kétszer kezd futni az
    // objektum kiir() fgv.-e pl., az komoly hiba, mert elromlana a mélység... tehát a mostani megoldásunk
    // nem reentráns) ha nem használnánk a C verzióban globális változókat, a C++ változatban példánytagot a
    // mélység kezelésére: http://progpater.blog.hu/2011/03/05/there_is_no_spoon
    melyseg = 0;
    // ha nem mondta meg a hívó az üzenetben, hogy hova írjuk ki a fát, akkor a
    // sztenderd out-ra nyomjuk
    kiir (&gyoker, std::cout);
}

void LZWBinFa::kiir (std::ostream & os)
{
    melyseg = 0;
    kiir (&gyoker, os);
}

void LZWBinFa::kiir (Csomopont * elem, std::ostream & os)
{
    // Nem létező csomóponttal nem foglalkozunk... azaz ez a rekurzió leállítása
    if (elem != NULL)
    {
        ++melyseg;
        kiir (elem->egyesGyermek (), os);
        // ez a postorder bejáráshoz képest
        // 1-el nagyobb mélység, ezért -1
        for (int i = 0; i < melyseg; ++i)
            os << "---";
        os << elem->getBetu () << "(" << melyseg - 1 << ")" << std::endl;
        kiir (elem->nullasGyermek (), os);
        --melyseg;
    }
}

void LZWBinFa::szabadit (Csomopont * elem)
{
    // Nem létező csomóponttal nem foglalkozunk... azaz ez a rekurzió leállítása
    if (elem != NULL)
    {
        szabadit (elem->egyesGyermek ());
        szabadit (elem->nullasGyermek ());
        // ha a csomópont mindkét gyermekét felszabadítottuk
        // azután szabadítjuk magát a csomópontot:
        delete elem;
    }
}





















int LZWBinFa::getNullasok() const
{
	return this->nullasok;
}

int LZWBinFa::getEgyesek() const
{
	return this->egyesek;
}

int
LZWBinFa::getMelyseg (void)
{
    melyseg = maxMelyseg = 0;
    rmelyseg (&gyoker);
    return maxMelyseg - 1;
}

double
LZWBinFa::getAtlag (void)
{
    melyseg = atlagosszeg = atlagdb = 0;
    ratlag (&gyoker);
    atlag = ((double) atlagosszeg) / atlagdb;
    return atlag;
}

double
LZWBinFa::getSzoras (void)
{
    atlag = getAtlag ();
    szorasosszeg = 0.0;
    melyseg = atlagdb = 0;

    rszoras (&gyoker);

    if (atlagdb - 1 > 0)
        szoras = std::sqrt (szorasosszeg / (atlagdb - 1));
    else
        szoras = std::sqrt (szorasosszeg);

    return szoras;
}

void
LZWBinFa::rmelyseg (Csomopont * elem)
{
    if (elem != NULL)
    {
        ++melyseg;
        if (melyseg > maxMelyseg)
            maxMelyseg = melyseg;
        rmelyseg (elem->egyesGyermek ());
        // ez a postorder bejáráshoz képest
        // 1-el nagyobb mélység, ezért -1
        rmelyseg (elem->nullasGyermek ());
        --melyseg;
    }
}

void
LZWBinFa::ratlag (Csomopont * elem)
{
    if (elem != NULL)
    {
        ++melyseg;
        ratlag (elem->egyesGyermek ());
        ratlag (elem->nullasGyermek ());
        --melyseg;
        if (elem->egyesGyermek () == NULL && elem->nullasGyermek () == NULL)
        {
            ++atlagdb;
            atlagosszeg += melyseg;
        }
    }
}

void
LZWBinFa::rszoras (Csomopont * elem)
{
    if (elem != NULL)
    {
        ++melyseg;
        rszoras (elem->egyesGyermek ());
        rszoras (elem->nullasGyermek ());
        --melyseg;
        if (elem->egyesGyermek () == NULL && elem->nullasGyermek () == NULL)
        {
            ++atlagdb;
            szorasosszeg += ((melyseg - atlag) * (melyseg - atlag));
        }
    }
}
