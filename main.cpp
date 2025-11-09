#include <iostream>
#include <fstream>

using namespace std;

void reverseFile(ifstream file) {
    string text;
    ofstream outfile("CSC450-mod5-reverse.txt");
    char ch;

    while (file.get(ch)) {
        text += ch;
    }

    for (int i = text.length(); i>0; i--) {
        outfile << text[i-1];
    }
}

int main() {
    ofstream file("CSC450_CT5_mod5.txt", ios::app);

    if (file.is_open()) {
        //Append user input to file
        cout << "Type something:" << endl;
        string text;
        cin >> text;
        file << text << endl;
        file.close();

        ifstream ifile("CSC450_CT5_mod5.txt", ios::app);
        reverseFile(std::move(ifile));

    }
    else {
        cout << "Can't open file" << endl;
    }



    return 0;
}