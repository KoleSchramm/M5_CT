#include <iostream>
#include <fstream>

using namespace std;

void reverseFile(ifstream file) {
    string text;
    ofstream rFile("CSC450-mod5-reverse.txt");
    char ch;

    while (file.get(ch)) {
        text += ch;
    }
    for (int i = text.length(); i>0; i--) {
        rFile << text[i-1];
    }

    rFile.close();
}

int main() {
    ofstream file("CSC450_CT5_mod5.txt", ios::app);

    if (file.is_open()) {
        //Append user input to file
        cout << "Type something:" << endl;
        string text;
        getline(cin, text);
        file << text << endl;
        file.close();

        //Reverse file
        ifstream iFile("CSC450_CT5_mod5.txt", ios::app);
        reverseFile(std::move(iFile));
        iFile.close();
    }
    else {
        cout << "Can't open file" << endl;
    }

    return 0;
}