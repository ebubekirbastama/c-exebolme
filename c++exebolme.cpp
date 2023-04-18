#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string inputFileName;
    cout << "Please enter the name of the input exe file: ";
    cin >> inputFileName;

    // Exe dosyasının tamamını oku
    ifstream input(inputFileName.c_str(), ios::binary | ios::ate);
    if (!input)
    {
        cout << "Error: cannot open input file." << endl;
        return 1;
    }

    streamsize size = input.tellg();
    input.seekg(0, ios::beg);
    char* buffer = new char[size];
    if (input.read(buffer, size))
    {
        string firstPartFileName, secondPartFileName;
        cout << "Please enter the name of the first part exe file: ";
        cin >> firstPartFileName;

        // İlk bölümü oluştur
        ofstream output1(firstPartFileName.c_str(), ios::binary);
        output1.write(buffer, size / 2);
        output1.close();

        cout << "Please enter the name of the second part exe file: ";
        cin >> secondPartFileName;

        // İkinci bölümü oluştur
        ofstream output2(secondPartFileName.c_str(), ios::binary);
        output2.write(buffer + size / 2, size - size / 2);
        output2.close();
    }
    delete[] buffer;

    return 0;
}
