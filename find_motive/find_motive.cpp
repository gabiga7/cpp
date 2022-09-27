#include <iostream>
using namespace std;

#include "find_motive.h"

// Create the fallback list
void preTraitment(string motive, int f[]) {
    int my_lmotive = motive.length();
    int x = 1, y = 0;
    f[0] = 0; // list fallback
    while (x < my_lmotive) {
        if (motive[x] == motive[y]) {
            f[x] = y + 1;
            x++;
            y++;
        }
        else if (y > 0)
            y = f[y-1];
        else
            f[x] = 0;
            x++;
    }
}

int find_motive(string text, string motive) {
    int my_ltext = text.length();
    int my_lmotive = motive.length();
    if (my_lmotive > my_ltext) return 0;

    int f[my_lmotive];
    preTraitment(motive, f);
    int x = 0,y = 0;

    int count = 0;
    while (x < my_ltext) {
        if (text[x] == motive[y]) {
            x++;
            y++;
            if (y == my_lmotive) {
                count++;
                y = 0;
                while(text[x]!=' ' & text[x]!='\t' & text[x]!='\n') x++;
                x++;
            }
        }
        else {
            // if (y == 0) x++;
            // else y = f[y];
            y = 0;
            x++;
        }
    }
    return count;
}