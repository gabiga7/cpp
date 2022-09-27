#include <iostream>
#include "find_motive.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


int main(int argc, char *argv[])
{
    ifstream monFlux(argv[1]);

    if(monFlux)
    {
        stringstream buff;
        buff << monFlux.rdbuf();
        cout << "The file " << argv[1] << " contains " << find_motive(buff.str(), argv[2]) << " words containing the motive " << argv[2] << '\n';
        monFlux.close();
    }
    else
    {
        cout << "The file " << argv[1] << " could not be opened." << endl;
        return 1;
    }
    return 0;
}