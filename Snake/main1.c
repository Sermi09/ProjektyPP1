#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
 
#define GORA    72
#define DOL  80
#define LEWO  75
#define PRAWO 77

void krawedzie();
void pojawianie_weza();
void ruch();
void gora();
void dol();
void lewo();
void prawo();
void stworz_cialo();
void koniec();
void zjedz_jablko();
void jedzenie();
void krawedzie();

 void goToXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
 
void setXY(int x, int y) {
    COORD c;
    fflush(stdout);
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

struct wspolrzedne {
    int X;
    int Y;
    int kierunek;
};

typedef struct wspolrzedne wspolrzedne;
 
wspolrzedne glowa, jablko, cialo;
 
int cialo_waz[500];
int przegrana_licz = 0;
int ilosc_zjedzonych_jablek = 0;
int zycia = 3;


void krawedzie() {
    setXY(2, 2);
    printf("Pozostale zycia: ");
    setXY(19, 2);
    printf("%d", zycia);
    int i;
    for (i = 5; i < 81; i++) {
        setXY(i, 5);
        printf("-");
        setXY(i, 30);
        printf("-");
    }
    for (i = 5; i < 31; i++) {
        setXY(5, i);
        printf("| |");
        setXY(80, i);
        printf("| |");
    }
}

void pojawianie_weza() {
    int x = 81 / 2;
    int y = 31 / 2;
    glowa.X = x;
    glowa.Y = y;
    glowa.kierunek = PRAWO;
    setXY(x, y);
    printf(">");
}

 
 
void ruch() {
    koniec();
    krawedzie();
    jedzenie();
    stworz_cialo();
    char wejscie;
    while (!kbhit()) {
        int chwilowy_kier;
        chwilowy_kier = glowa.kierunek;
        if (chwilowy_kier == LEWO) {
            koniec();
            krawedzie();
            system("cls");
            glowa.X--;
            krawedzie();
            jedzenie();
            setXY(glowa.X, glowa.Y);
            printf("<");
            zjedz_jablko();
            stworz_cialo();
        }
        else if (chwilowy_kier == PRAWO) {
            koniec();
            krawedzie();
            system("cls");
            glowa.X++;
            krawedzie();
            jedzenie();
            setXY(glowa.X, glowa.Y);
            printf(">");
            zjedz_jablko();
            stworz_cialo();
        } else if (chwilowy_kier == GORA) {
            koniec();
            krawedzie();
            system("cls");
            glowa.Y--;
            krawedzie();
            jedzenie();
            setXY(glowa.X, glowa.Y);
            printf("^");
            zjedz_jablko();
            stworz_cialo();
        } else {
            koniec();
            krawedzie();
            system("cls");
            glowa.Y++;
            krawedzie();
            jedzenie();
            setXY(glowa.X, glowa.Y);
            printf("v");
            zjedz_jablko();
            stworz_cialo();
        }
    }
    if (kbhit()) {
        koniec();
        while (przegrana_licz == 0) {
            wejscie = getch();    //Change INPUT to desired direction.         
            if (wejscie == GORA) {
                gora();
            }
            if (wejscie == DOL) {
                dol();
            }
            if (wejscie == LEWO) {
                lewo();
            }
            if (wejscie == PRAWO) {
                prawo();
            } else if (przegrana_licz == 1) {
                system("cls");
            } else if (wejscie == 27) {
                przegrana_licz = 1;
                system("cls");
                exit(0);
            }
        }
    }
}
 

 
void gora() {
    zjedz_jablko();
    if (glowa.kierunek != DOL) {
        glowa.kierunek = GORA;
        glowa.Y--;
        system("cls");
        krawedzie();
        setXY(glowa.X, glowa.Y);
        printf("^");
        koniec();
        ruch();
        jedzenie();
        stworz_cialo();
    } else {
        koniec();
        ruch();
        jedzenie();
    }
}
 
void dol() {
    zjedz_jablko();
    if (glowa.kierunek != GORA) {
        glowa.kierunek = DOL;
        glowa.Y++;
        system("cls");
        krawedzie();
        setXY(glowa.X, glowa.Y);
        printf("v");
        koniec();
        ruch();
        jedzenie();
        stworz_cialo();
    } else {
        koniec();
        ruch();
        jedzenie();
    }
}
 
void lewo() {
    zjedz_jablko();
    if (glowa.kierunek != PRAWO) {
        glowa.kierunek = LEWO;
        glowa.X--;
        system("cls");
        krawedzie();
        setXY(glowa.X, glowa.Y);
        printf("<");
        koniec();
        ruch();
        jedzenie();
        stworz_cialo();
    } else {
        koniec();
        ruch();
        jedzenie();
    }
}
 
void prawo() {
    zjedz_jablko();
    if (glowa.kierunek != LEWO) {
        glowa.kierunek = PRAWO;
        glowa.X++;
        system("cls");
        krawedzie();
        setXY(glowa.X, glowa.Y);
        printf(">");
        koniec();
        ruch();
        jedzenie();
        stworz_cialo();
    } else {
        koniec();
        ruch();
        jedzenie();
    }
}

void jedzenie() {
    if (jablko.X == 0 && jablko.Y == 0) {
        int rx = ((rand() % 74 + 5));
        int ry = ((rand() % 24 + 5));
        jablko.X = rx;
        jablko.Y = ry;
        setXY(jablko.X, jablko.Y);
        printf("A");
    } else {
        setXY(jablko.X, jablko.Y);
        printf("A");
    }
}
 
void zjedz_jablko() {
    if (glowa.X == jablko.X && glowa.Y == jablko.Y) {
        ilosc_zjedzonych_jablek++;
        jablko.X = 0;
        jablko.Y = 0;
        cialo_waz[ilosc_zjedzonych_jablek] = 0;
    }
}
 
void stworz_cialo() {
    if (glowa.kierunek == PRAWO) {
        int i;
		for ( i = 1; i <= ilosc_zjedzonych_jablek; i++) {
            cialo.X = (glowa.X - i);
            cialo.Y = (glowa.Y);
            setXY(cialo.X, cialo.Y);
            printf("%d", cialo_waz[i]);
        }
    } else if (glowa.kierunek == LEWO) {
        int i;
		for ( i = 1; i <= ilosc_zjedzonych_jablek; i++) {
            cialo.X = (glowa.X + i);
            cialo.Y = (glowa.Y);
            setXY(cialo.X, cialo.Y);
            printf("%d", cialo_waz[i]);
        }
    } else if(glowa.kierunek == GORA) {
        int i;
		for ( i = 1; i <= ilosc_zjedzonych_jablek; i++) {
            cialo.X = (glowa.X);
            cialo.Y = (glowa.Y + i);
            setXY(cialo.X, cialo.Y);
            printf("%d", cialo_waz[i]);
        }
    }
    else if (glowa.kierunek == DOL) {
        int i;
		for ( i = 1; i <= ilosc_zjedzonych_jablek; i++) {
            cialo.X = (glowa.X);
            cialo.Y = (glowa.Y - i);
            setXY(cialo.X, cialo.Y);
            printf("%d", cialo_waz[i]);
        }
    }
}
 
void koniec() {
    if (glowa.X <= 5 || glowa.X >= 81 || glowa.Y <= 5 || glowa.Y >= 30) {
        zycia--;
        system("cls");
        ilosc_zjedzonych_jablek = 0;
        main();
    } else {
        przegrana_licz = 0;
    }
    if (zycia == 0) {
        przegrana_licz = 1;
        system("cls");
        exit(0);
    }
}

int main() {
    setXY(2, 2);
    printf("Pozostale zycia:");
    jablko.X = 0;
    jablko.Y = 0;
    krawedzie();
    pojawianie_weza();
    ruch();
}

