#include <iostream>
#include "movie.h"

using namespace std;

int main()
{
    listActor A; listMovie M;
    firstA(A) = nil; lastA(A) = nil;
    firstM(M) = nil; lastM(M) = nil;

    tambahAktor(A, "Frans");
    tambahAktor(A, "Michael");

    tambahMovie(M, "Avatar");
    tambahMovie(M, "Avenger");
    tambahMovie(M, "Dragonball");

    tambahRelasi(A, M, "Frans", "Avatar");
    tambahRelasi(A, M, "Frans", "Dragonball");
    tambahRelasi(A, M, "Michael", "Dragonball");
    tambahRelasi(A, M, "Michael", "Avenger");

    adrMovie p = firstM(M);

    while (next(p) != firstM(M)) {
        cout << info(p) << ", ";
        p = next(p);
    }
    cout << info(p);

    cout << "\n\n";

    adrActor q = firstA(A);

    while (q != nil) {
        cout << info(q) << ", ";
        q = next(q);
    }

    cout << "\n\n";
    /*
    p = cariMovie(M, "Avatar");
    adrRelasi r = edge(p);
    cout << "Avatar = [";
    while (next(r) != nil) {
        cout << info(info(r)) <<   ", ";
        r = next(r);
    }
    cout << info(info(r)) << "]";
    */
    showMoviesAndActors(M);
    return 0;
}
