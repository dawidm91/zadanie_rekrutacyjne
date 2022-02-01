#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
#include <locale.h>
#include <thread>

using namespace std;

namespace fs = filesystem;

int sumawierszy = 0;
int sumael = 0;
string address;

void analyze_directory()
{
    getline(cin, address);
    for (auto& p : fs::recursive_directory_iterator(address))
    {
        sumael++;
        int count = 0;
        string liczbawierszy;
        ifstream plik(p.path().string());
        ifstream in(p.path());
        while (getline(plik, liczbawierszy))
            count++;
        sumawierszy = sumawierszy + count;
        //std::cout << endl << "Liczba linii w pliku: " << p.path().stem().string() << ": " << count << endl;
    }
    cout << "Liczba wszystkich linii: " << sumawierszy << endl;
    cout << "Liczba wszystkich elementów: " << sumael << endl;
}

int main()
{
    setlocale(LC_CTYPE, "Polish");
    cout << "Wskaż katalog do analizy:" << endl;
    thread thr1(analyze_directory);
    thr1.join();
    //analyze_directory();
    return 0;
}