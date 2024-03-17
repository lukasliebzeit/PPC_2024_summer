#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main()
{
    /*
    string a{ "Testovaci text" };
    cout << a.substr(3) << endl;
    cout << a.substr(0, 3) << endl;

    if (a.find("!") == string::npos)
    {
        cout << "V retezci vykricnik neni!" << endl;
    }
    cout << a.substr(0, a.find(" ")) << endl;
    cout << a.substr(a.find(" ")+1) << endl;

    cout << endl << endl << "[" << std::left << setw(10) << setfill('_') << 1 << "]" << endl;
    cout << "[" << std::right << setw(10) << setfill(' ') << hex << 23 << "]" << endl;
    cout << "[" << std::internal << setw(10) << setfill('X') << 2 << "]" << endl;
    */
    string input;
    getline(cin, input);
    while (input.find(";") != string::npos)
    {
        string bef = input.substr(0, input.find(";"));
        input = input.substr(input.find(";")+1);
        cout << "|" << bef << "|" << input << "|" << endl;
    }


    return 0;
}
