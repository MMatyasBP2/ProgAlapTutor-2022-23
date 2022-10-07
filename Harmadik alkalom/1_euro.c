/*Az EURO árfolyamát egy negyedéven keresztül hetente nyilvántartjuk (HUF / EUR). Írjon C
programokat az alábbi kérdések megválaszolására.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    /*Hányszor volt a negyedévben 300 Ft alatt az árfolyam értéke? A tömböt inicializálja*/
    
    int db = 0;

        double euro[] = {289.5, 292.6, 290.2, 295.5, 300.4, 302.3, 302.5, 303.3, 303.5, 299.9};
        int size = sizeof(euro) / sizeof(double);
        double limit = 300.0;

        printf("\nHUF/EURO arfolyamok:\n");
        for (unsigned int i = 0; i < size; i++) {
            printf("%d. ertek: %.2lf\n", i + 1, euro[i]);
        //Feltételt kielégítő elemek megszámlálása
            if (euro[i] < limit)
            {
                db++;
            }
        }

        printf("\nAz arfolyam erteke %d-szor volt %.2f alatt.\n", db, limit);

    /*Monoton nőtt-e az árfolyam a negyedév során? Alkalmazzon ellenőrzött adatbeolvasást.
    A válasz kiírását feltételes operátorral valósítsa meg. */

    bool is_monotone = true;
        for (unsigned int i = 1; i < size; i++)
        {
        if (euro[i - 1] > euro[i])
        {
            is_monotone = false;
            break;
        }
    }

    printf("A sor %s.\n", is_monotone ? "monoton növekvö" : "nem monoton");       

    /* Melyik héten volt a legmagasabb, és melyiken a legalacsonyabb az árfolyam és hol?*/

    int min = euro[0], max = euro[0];
    for (unsigned int i = 1; i < size; i++)
    {
        if (euro[i] < min)
        {
            min = euro[i];
        }
        if (euro[i] > max)
        {
            max = euro[i];
        }
        
    }
    
    printf("Minimum ertek: %d\n", min);
    printf("Maximum ertek: %d\n\n", max);

    int min_index = 0, max_index = 0;
    for (unsigned int i = 1; i < size; i++)
    {
        if (euro[i] < euro[min_index])
        {
            min_index = i;
        }
        if (euro[i] > euro[max_index])
        {
            max_index = i;
        }
    }
    
    printf("Minimum ertek helye: %d\n", min_index);
    printf("Maximum ertek helye: %d\n\n", max_index);

    /*Mennyi az adott negyedévre vonatkozó átlagos árfolyam érték? 
    Előjelhelyesen írja ki, hogy az egyes adatok mennyivel térnek el az átlagtól. 
    Ezt a feladatot pointer használatával is oldja meg.*/

    float avg = 0;
    for (unsigned int i = 0; i < size; i++)
    {
        avg += euro[i];
    }

    avg /= size;
    printf("Atlag: %.2lf\n\n", avg);
    
    // Átlagtól való eltérés

    printf("Sorszam\tAtlag\tAtlagtol valo elteres\n");
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%d.\t%.2lf\t%.2lf\n", i + 1, euro[i], euro[i] - avg);
    }
    

    return 0;
}