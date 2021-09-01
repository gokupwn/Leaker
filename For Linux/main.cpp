#include <iostream>
#include <fstream>
#include <string>
#include "CSVRow.h"
#include <stdlib.h>

using namespace std;

void banner()
{
    system("Color 01");

    cout << "         ██▓    ▓█████ ▄▄▄       ██ ▄█▀▓█████  ██▀███"
         << "\n";
    cout << "        ▓██▒    ▓█   ▀▒████▄     ██▄█▒ ▓█   ▀ ▓██ ▒ ██▒"
         << "\n";
    cout << "        ▒██░    ▒███  ▒██  ▀█▄  ▓███▄░ ▒███   ▓██ ░▄█ ▒"
         << "\n";
    cout << "        ▒██░    ▒▓█  ▄░██▄▄▄▄██ ▓██ █▄ ▒▓█  ▄ ▒██▀▀█▄"
         << "\n";
    cout << "        ░██████▒░▒████▒▓█   ▓██▒▒██▒ █▄░▒████▒░██▓ ▒██▒"
         << "\n";
    cout << "        ░ ▒░▓  ░░░ ▒░ ░▒▒   ▓▒█░▒ ▒▒ ▓▒░░ ▒░ ░░ ▒▓ ░▒▓░"
         << "\n";
    cout << "        ░ ░ ▒  ░ ░ ░  ░ ▒   ▒▒ ░░ ░▒ ▒░ ░ ░  ░  ░▒ ░ ▒░"
         << "\n";
    cout << "          ░ ░      ░    ░   ▒   ░ ░░ ░    ░     ░░   ░"
         << "\n";
    cout << "            ░  ░   ░  ░     ░  ░░  ░      ░  ░   ░"
         << "\n";

    cout << "\t[*] coded by @hassanalachek [*]\n";
    cout << "\t[*] +---------------------+ [*]\n";
    cout << "\t[*] Transform Data To JSON [*]\n";
    cout << "\t[*] +----------------------+ [*]\n";
}
int main()
{
    // Get Output Json File
    banner();
    string fileOut;
    string fileINCSV;

    cout << "[?]Enter CSV Input File( in.csv )\n";
    cin >> fileINCSV;
    cout << "[?]Enter  JSON File Output\n";
    cin >> fileOut;

    CSVRow test(fileINCSV, fileOut);
    test.getID();
    test.CsvTOJson();

    return 0;
}
