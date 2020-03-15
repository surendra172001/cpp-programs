#include<bits/stdc++.h>
using namespace std;

#define N 10
char cross[N][N];

void printCross() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << cross[i][j];
        }
        cout << endl;
    }
}
bool isValidVertically(string word, int row, int col) {
    if (N - row > 0) {
        for (int i = 0; i < word.length(); i++) {
            if (cross[i + row][col] != '-' && cross[i + row][col] != word[i]) {
                return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
}


bool isValidHoritally(string word, int row, int col) {
    if (N - col > 0) {
        for (int i = 0; i < word.length(); i++) {
            if (cross[row][col + i] != '-' && cross[row][col + i] != word[i]) {
                return false;
            }
        }
        return true;
    }
    else {
        return false;
    }   
}

void setVertical(string word, bool marker[], int row, int col) {
    for (int i = 0; i < word.length(); i++) {
        if (cross[row + i][col] == '-') {
            marker[i] = true;
            cross[row + i][col] = word[i];
        }
        else {
            marker[i] = false;
        }
    }
}

void resetVertical(string word, bool marker[], int row, int col) {
    for (int i = 0; i < word.length(); i++) {
        if (marker[i]) {
            cross[row + i][col] = '-';
        }
    }
}


void setHorizontal(string word, bool marker[], int row, int col) {
    for (int  i = 0; i < word.length(); i++) {
        if (cross[row][col + i] == '-') {
            marker[i] = true;
            cross[row][col + i] = word[i];
        }
        else {
            marker[i] = false;
        }
    }
}

void resetHorizontal(string word, bool marker[], int row, int col) {
    for (int i = 0; i < word.length(); i++) {
        if (marker[i]) {
            cross[row][col + i] = '-';
        }
    }   
}

bool solveCrossWord(vector<string> words, int index) {
    if (index < words.size()) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (cross[r][c] == '-' || cross[r][c] == words[index][0]) {
                    bool *marker = new bool [words[index].length()];
                    if (isValidVertically(words[index], r, c)) {
                        setVertical(words[index], marker, r, c);
                        if (solveCrossWord(words, index + 1)) {
                            return true;
                        }
                        else {
                            resetVertical(words[index], marker, r, c);
                        }
                    }
                    else if (isValidHoritally(words[index], r, c)) {
                        setHorizontal(words[index], marker, r, c);
                        if (solveCrossWord(words, index + 1)) {
                            return true;
                        }
                        else {
                            resetHorizontal(words[index], marker, r, c);
                        }
                    }
                    delete [] marker;
                }
            }
        }
        return false;
    }
    else {
        return true;
    }
}

int main() { 
    vector<string> inputWords;
    string input, word;
    int i = 0, j = 0;
    for(; i < N; i++) {
        j = 0;
        for (; j < N; j++) {
            cin >> cross[i][j];
        }
    }

    cin >> input;
    stringstream s(input);
    while (getline(s, word, ';')) {
        inputWords.push_back(word);
    }

    solveCrossWord(inputWords, 0);
    printCross();

    return 0;
}

