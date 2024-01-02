#include <iostream>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

string getArrayOfChar() {
    string arr;
    for(char c = 'a'; c <= 'z'; c++) {
        arr.push_back(c);
    }
    for(char c = '0'; c <= '9'; c++) {
        arr.push_back(c);
    }
    return arr;
}

string possibleChar = getArrayOfChar();

int crackPass(string targetPass, string tryPass) {
    if(tryPass == targetPass) {
        return 1;
    }
    if(tryPass.length() >= targetPass.length()) {
        return 0;
    }

    for(int i = 0; i < possibleChar.length(); i++) {
        tryPass.push_back(possibleChar[i]);
        if(crackPass(targetPass, tryPass)) {
            return 1;
        }
        else {
            tryPass.pop_back();
        }
    }
}

int main() {

    string targetPass, tryPass;
    cout << "Enter a password: " << endl;
    cin >> targetPass;

    clock_t time;
    time = clock();
    tryPass = "";
    crackPass(targetPass, tryPass);
    time = clock() - time;

    cout << "Password takes " << ((float)time)/CLOCKS_PER_SEC << " to crack!" << endl;

    return 0;
}
