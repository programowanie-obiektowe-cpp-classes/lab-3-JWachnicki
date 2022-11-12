#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    //Warunki na początku
    unsigned int ilosc_lodek = 0; //Taki int ale dodatni i może mieć większą wartośc niż zwykły
    unsigned int ilosc_towaru = 0;
    if (towar == 0) 
    {
        return 0;
    }
    else
    {
        while (ilosc_towaru < towar)
        {
            //1. Stworzenie statku
            Stocznia stocznia{};
            Statek* s1 = stocznia();
            //2. Wywołanie metody transportuj
            ilosc_towaru = ilosc_towaru + s1->transportuj();
            //3. Sumowanie łódek
            if (s1 == dynamic_cast<Zaglowiec*>(s1))
            {
                ilosc_lodek++;
            }
            //4. Usunięcie łódki
            delete s1;
        }
        //5. Powrót do 1. jeżeli nie został spełniony warunek ilości towaru
    }
    return ilosc_lodek;
}