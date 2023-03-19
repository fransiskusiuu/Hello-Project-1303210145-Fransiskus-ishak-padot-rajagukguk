#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

#include <iostream>
using namespace std;

#define info(P) P->info
#define next(P) P->next
#define edge(P) P->edge
#define firstM(P) ((P).firstM)
#define lastM(P) ((P).lastM)
#define firstA(P) ((P).firstA)
#define lastA(P) ((P).lastA)
#define firstR(P) ((P).firstR)
#define lastR(P) ((P).lastR)
#define nil NULL

struct movie {
    string namaFilm;
};

struct actor {
    string namaAktor;
};

typedef struct movie infotypeMovie;
typedef struct actor infotypeActor;

typedef struct elmMovie *adrMovie;
typedef struct elmActor *adrActor;
typedef struct elmRelasi *adrRelasi;

struct elmMovie{
    string info;
    adrRelasi edge;
    adrMovie next;
};

struct elmActor{
    string info;
    adrActor next;
};

struct elmRelasi {
    adrActor info;
    adrRelasi next;
};

struct listMovie {
    adrMovie firstM;
    adrMovie lastM;
};

struct listActor {
    adrActor firstA;
    adrActor lastA;
};
/*
struct listRelasi {
    adrRelasi firstR;
    adrRelasi lastR;
};
*/
adrMovie newMovie(string judulMovie);
adrActor newActor(string namaAktor);
adrActor cariAktor(listActor L, string namaAktor);
adrMovie cariMovie(listMovie L, string judulMovie);
string dataMovie(listActor L, string namaAktor);
void tambahMovie(listMovie &L, string judulMovie);
void tambahAktor(listActor &L, string namaAktor);
void tambahRelasi(listActor &L, listMovie &M, string namaAktor, string judulMovie);
void deleteMovieByActor(listActor &L,  string namaAktor, adrActor &q);
void hapusRelasi(listMovie &M, listActor &L);
void hapusBintangFilm(listMovie &M, string judulMovie);
int hitungJumlahMovie(listMovie M, string namaAktor);
void bintangFilmTerbanyak(listMovie M);
void showMoviesAndActors(listMovie M);

#endif // MOVIE_H_INCLUDED
