#include "CSVRow.h"
#include <string>
#include <fstream>
#include <vector>
using namespace std;

CSVRow::CSVRow(string csvfile, string fileOut)
{
    // initialization of FilePath string variable
    FilePath = csvfile;
    FileOut = fileOut;

    ifstream CSVFile(csvfile);
    // initialization of the idsLine
    string idsLine;
    getline(CSVFile, idsLine);
    CSVFile.close();

    // initialization of the out vector
    spliter(idsLine, ',', out);

    // initialization of the IDNumber
    IDNumber = out.size();

    // initialization of CSVIDs table of strings
    CSVIDs = new string[IDNumber];
}

void CSVRow::PrintIDs()
{
    for (int i = 0; i < IDNumber; i++)
    {
        cout << CSVIDs[i] << endl;
    }
}

void CSVRow::spliter(string const &str, const char delim, vector<string> &out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

void CSVRow::rejoint(vector<string> out, string CSVIDs[])
{
    int capacity = out.size();
    for (int i = 0; i < capacity; i++)
    {
        CSVIDs[i] = out[i];
    }
}

// Set the CSVIDs which will be in this format
// CSVIDs = ["user_id","name,photo_url","username","twitter","instagram","num_followers","num_following","time_created","invited_by_user_profile"]
void CSVRow::getID()
{
    rejoint(out, CSVIDs);
}

void CSVRow::CsvTOJson()
{
    ifstream CSVFile(FilePath);
    string Line;
    string *LineData;
    ofstream outFile;
    //vector <string> LineVector;

    // read line from the CSV file
    getline(CSVFile, Line);
    outFile.open(FileOut, std::ios_base::app);
    outFile << "[\n";
    outFile.close();

    while (!CSVFile.eof())
    {
        vector<string> LineVector;
        // split data
        getline(CSVFile, Line);
        spliter(Line, ',', LineVector);
        // get table of data
        LineData = new string[LineVector.size()];
        rejoint(LineVector, LineData);

        outFile.open(FileOut, std::ios_base::app);
        outFile << "\t{\n";
        for (int i = 0; i < LineVector.size(); i++)
        {
            if (i == LineVector.size() - 1)
                if (CSVFile.eof())
                    outFile << "\t\t\"" << CSVIDs[i] << "\":\"" << LineVector[i] << "\"\n\t}\n";
                else
                    outFile << "\t\t\"" << CSVIDs[i] << "\":\"" << LineVector[i] << "\"\n\t},\n";
            else
                outFile << "\t\t\"" << CSVIDs[i] << "\":\"" << LineVector[i] << "\",\n";

            //cout<<LineData[i]<<"\n";
        }
        // outFile << "\t},\n";
        outFile.close();

        delete[] LineData;
    }
    outFile.open(FileOut, std::ios_base::app);
    outFile << "]\n";
    outFile.close();

    CSVFile.close();
}

CSVRow::~CSVRow()
{
    //dtor
}
