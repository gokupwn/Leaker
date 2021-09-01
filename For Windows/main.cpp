#include <iostream>
#include <fstream>
#include <string>
#include "CSVRow.h"
#include <stdlib.h>
//#include <windows.h>

using namespace std;

void banner()
{
    system("Color 09");

    cout << " (                      )       ("
         << "\n";
    cout << ")\\ )        (       ( /(       )\\ )"
         << "\n";
    cout << "(()/(  (     )\\      )\\()) (   (()/("
         << "\n";
    cout << "/(_)) )\\ ((((_)(  |((_)\\  )\\   /(_))"
         << "\n";
    cout << "(_))  ((_) )\\ _ )\\ |_ ((_)((_) (_))"
         << "\n";
    cout << "| |   | __|(_)_\\(_)| |/ / | __|| _ \\"
         << "\n";
    cout << "| |__ | _|  / _ \\    ' <  | _| |   /"
         << "\n";
    cout << "|____||___|/_/ \\_\\  _|\\_\\ |___||_|_\\"
         << "\n";

    cout << "\n";
    cout << "\n";
    cout << "\t[*] +---------------------+ [*]\n";
    cout << "\t[*] coded by @hassanalachek [*]\n";
    cout << "\t[*] +---------------------+ [*]\n";
    cout << "\t[*] Transform CSV To JSON  [*]\n";
    cout << "\t[*] +----------------------+[*]\n";
}
int main()
{
    // Get Output Json File
    banner();
    string fileOut;
    string fileINCSV;

    cout << "[?]Enter CSV Input File( in.csv )\n";
    cin >> fileINCSV;
    cout << "[?]Enter JSON File Output(out.json)\n";
    cin >> fileOut;

    CSVRow test(fileINCSV, fileOut);
    test.getID();
    test.CsvTOJson();

    return 0;
}
