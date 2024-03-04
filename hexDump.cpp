#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string charToHex(unsigned char c);
string stringToHex(const string& input);
string FileToHex(const char* filename);
void printHexWithFormat(const string& hex_text);


int main(int argc, char* argv[]) {
    string data = FileToHex(argv[1]);
    printHexWithFormat(data);
    return 0;
}

string charToHex(unsigned char c) {
    stringstream ss;
    ss << hex << setw(2) << setfill('0') << (int)c;
    return ss.str();
}

string stringToHex(const string& input) {
    stringstream ss;
    for (size_t i = 0; i < input.length(); i++){
        ss << charToHex((unsigned char)input[i]);
    }
    return ss.str();
}

string FileToHex(const char* filename) {
    string text;
    
    ifstream MyReadFile(filename);
    string line;

    while(getline(MyReadFile, line)) {
        line = stringToHex(line); 
        text += line;
    }

    MyReadFile.close();

    return text;
}

void printHexWithFormat(const string& hex_text) {
    for (size_t i = 0; i < hex_text.length(); i += 2) {
        cout << hex_text.substr(i, 2) << " ";
        if ((i + 2) % 32 == 0) {
            cout << endl;
        }
    }
}

