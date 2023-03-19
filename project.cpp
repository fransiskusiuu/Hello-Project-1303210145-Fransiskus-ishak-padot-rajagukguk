#include "movie.h"

adrMovie newMovie(string judulMovie) {
    adrMovie newMovie = new elmMovie;
    info(newMovie) = judulMovie;
    edge(newMovie) = nil;
    next(newMovie) = nil;
    return newMovie;
}
adrActor newActor(string namaAktor) {
    adrActor newActor = new elmActor;
    info(newActor) = namaAktor;
    next(newActor) = nil;
    return newActor;
}
void tambahMovie(listMovie &L, string judulMovie){
    adrMovie p = newMovie(judulMovie);
    if(firstM(L) == nil ){
        firstM(L) = p;
        lastM(L) = p;
        next(lastM(L)) = firstM(L);
    } else {
        next(lastM(L)) = p;
        lastM(L) = p;
        next(p) = firstM(L);
    }
};
void tambahAktor(listActor &L, string namaAktor){
    adrActor p = newActor(namaAktor);
    if(firstA(L) == nil ){
        firstA(L) = p;
        lastA(L) = p;
    } else {
        next((lastA(L))) = p;
        lastA(L) = p;
    }
}
adrMovie cariMovie(listMovie L, string namaMovie) {
    adrMovie p = firstM(L);
    while (next(p) != firstM(L) && info(p) != namaMovie) {
        p = next(p);
    }
    if (info(p) == namaMovie) {
        return p;
    } else {
        return nil;
    }
}
adrActor cariAktor(listActor L, string namaAktor){
    adrActor p = firstA(L);
    while (p != nil && info(p) != namaAktor) {
        p = next(p);
    }
    return p;
};
void tambahRelasi(listActor &L, listMovie &M, string namaAktor, string judulMovie){
    adrMovie p = cariMovie(M, judulMovie);
    adrActor q = cariAktor(L, namaAktor);
    if (p != nil && q != nil) {
       adrRelasi r = new elmRelasi;
       info(r) = q;
       next(r) = nil;
       if (edge(p) == nil) {
            edge(p) = r;
       } else {
            next(r) = edge(p);
            edge(p) = r;
       }
    }
};
string dataMovie(listMovie M, string namaAktor){
    string movies = "";
    adrMovie p = firstM(M);
    while (next(p) != firstM(M)) {
        adrRelasi q = edge(p);
        while (q != NULL) {
            if (info(info(q)) == namaAktor) {
                movies += info(info(q)) + " ";
            }
            q = next(q);
        }
        p = next(p);
    }
    return movies;
};
void showMoviesAndActors(listMovie M) {
    adrMovie p = firstM(M);
    while (next(p) != firstM(M)) {
        adrRelasi r = edge(p);
        cout << info(p) << " = [";
        while (next(r) != nil) {
        cout << info(info(r)) <<   ", ";
        r = next(r);
        }
        cout << info(info(r)) << "]\n";
        p = next(p);
    }
    adrRelasi r = edge(p);
    cout << info(p) << " = [";
    while (next(r) != nil) {
        cout << info(info(r)) <<   ", ";
        r = next(r);
    }
    cout << info(info(r)) << "]\n";
}
void hapusRelasi(listMovie &M, listActor &L);
void deleteMovieByActor(listActor &L,  string namaAktor, adrActor &q);
void hapusBintangFilm(listMovie &M, string judulMovie);
int hitungJumlahMovie(listMovie M, string namaAktor);
void bintangFilmTerbanyak(listMovie M);
