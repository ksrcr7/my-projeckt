#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

string Checkwinner(vector<string> &);
void DisplayMap(vector<string> &);
bool isNumber(const string &);


int main() {
    vector<string> map;
    bool check = true;
    bool Entermove= true;
    int counter=0;

    for(int i=1; i<=9;i++)
        map.push_back(to_string(i));



    string temp;


    while (true){
        DisplayMap(map);

        cout << "Which player are you? (X / O): ";
        cin >> temp;

        if (temp != "X" && temp != "O") {
            cout << "Invalid player. Please enter X or O." << endl;
            continue;
        }

        int move;
        cout << "Enter your move (1-9): ";
        cin >> move;

        if (!cin || move < 1 || move > 9) {
            cout << "Invalid move. Please enter a number between 1 and 9." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (map[move - 1] == "X" || map[move - 1] == "O") {
            cout << "This position is already taken. Try again!" << endl;
            continue;
        }

        map[move - 1] = temp;
        counter++;

        string result = Checkwinner(map);
        if (result == "X") {
            DisplayMap(map);
            cout << "Congratulations! Player X wins!" << endl;
            break;
        }
        else if (result == "O") {
            DisplayMap(map);
            cout << "Congratulations! Player O wins!" << endl;
            break;
        }
        else if (result == "D") {
            DisplayMap(map);
            cout << "It's a draw!" << endl;
            break;
        }

        
    }

}
bool isNumber(const string &s){
    return s == "1" || s == "2" || s == "3" || s == "4" || s == "5"
           || s == "6" || s == "7" || s == "8" || s == "9";
}
string Checkwinner(vector<string> &vec) {
    for (int i = 0; i < 9; i += 3) {
        if (vec[i] == vec[i + 1] && vec[i + 1] == vec[i + 2] && vec[i] != "1" && vec[i] != "2" && vec[i] != "3" &&
            vec[i] != "4" && vec[i] != "5"
            && vec[i] != "6" && vec[i] != "7" && vec[i] != "8" && vec[i] != "9")
            return vec[i];
    }

    for (int i = 0; i < 3; i++) {
        if (vec[i] == vec[i + 3] && vec[i + 3] == vec[i + 6] && vec[i] != "1" && vec[i] != "2" && vec[i] != "3" &&
            vec[i] != "4" && vec[i] != "5"
            && vec[i] != "6" && vec[i] != "7" && vec[i] != "8" && vec[i] != "9")
            return vec[i];
    }

    if (vec[0] == vec[4] && vec[4] == vec[8] && !isNumber(vec[0]))
        return vec[0];

    if (vec[2] == vec[4] && vec[4] == vec[6] && !isNumber(vec[2]))
        return vec[2];

    for (int i = 0; i < 9; ++i) {
        if (isNumber(vec[i]))
            return "N";

    }
    return "D";
}
void DisplayMap(vector<string> &vec) {
    for (int i = 0; i < 3; ++i) {
        cout << " " << vec[i * 3] << " | " << vec[i * 3 + 1] << " | " << vec[i * 3 + 2] << endl;
        if (i < 2) cout << "---+---+---" << endl;
    }
}


