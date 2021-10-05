#include <iostream>
#include <ctime>

using namespace std;

const int sizeArray = 3;

void printField(string array[sizeArray][sizeArray]);

void printUI();

void fillingSFiled(string array[sizeArray][sizeArray]);

void moveUser(string figure, string array[3][3]);

void moveAI(string figure, string array[sizeArray][sizeArray]);

int main() {

    int countParties = 0;
    string figure = "";
    string arrayTicTacToe[sizeArray][sizeArray];

    fillingSFiled(arrayTicTacToe);

    cout << "     ...::TIC-TAC-TOE:::..." << endl << "(c) 2021, by Hanexical, w_myslicki" << endl << endl
         << "Choose who to play for ('x' or 'o')" << endl << "Enter:";
    cin >> figure;

    if (figure == "x") {
        while (countParties != 9) {
            moveUser(figure, arrayTicTacToe);
            countParties++;
            moveAI("o", arrayTicTacToe);
            countParties++;
        }
    } else if (figure == "o") {
        while (countParties != 9) {
            moveAI("x", arrayTicTacToe);
            countParties++;
            moveUser(figure, arrayTicTacToe);
            countParties++;
        }
    } else {
        cout << "The game is played 'x' and 'o' !";
        return -1;
    }
}

void moveAI(string figure, string array[sizeArray][sizeArray]) {
    srand(time(NULL));
    bool exit = false;
    int position = 1 + rand() % 10;
    if (position >= 1 && position <= 9) {
        while (!exit) {
            switch (position) {
                case 1:
                    if (array[position - 1][position - 1] != "x" &&
                        array[position - 1][position - 1] != "o") {
                        array[position - 1][position - 1] = figure;
                    }
                    exit = true;
                    break;
                case 2:
                    if (array[position - 2][position - 1] != "x" &&
                        array[position - 2][position - 1] != "o") {
                        array[position - 2][position - 1] = figure;
                    }
                    exit = true;
                    break;
                case 3:
                    if (array[position - 3][position - 1] != "x" &&
                        array[position - 3][position - 1] != "o") {
                        array[position - 3][position - 1] = figure;
                    }
                    exit = true;
                    break;
                case 4:
                    if (array[position - 3][position - 4] != "x" &&
                        array[position - 3][position - 4] != "o") {
                        array[position - 3][position - 4] = figure;
                    }
                    exit = true;
                    break;
                case 5:
                    if (array[position - 4][position - 4] != "x" &&
                        array[position - 4][position - 4] != "o") {
                        array[position - 4][position - 4] = figure;
                    }
                    exit = true;
                    break;
                case 6:
                    if (array[position - 5][position - 4] != "x" &&
                        array[position - 5][position - 4] != "o") {
                        array[position - 5][position - 4] = figure;
                    }
                    exit = true;
                    break;
                case 7:
                    if (array[position - 5][position - 7] != "x" &&
                        array[position - 5][position - 7] != "o") {
                        array[position - 5][position - 7] = figure;
                    }
                    exit = true;
                    break;
                case 8:
                    if (array[position - 6][position - 7] != "x" &&
                        array[position - 6][position - 7] != "o") {
                        array[position - 6][position - 7] = figure;
                    }
                    exit = true;
                    break;
                case 9:
                    if (array[position - 7][position - 7] != "x" &&
                        array[position - 7][position - 7] != "o") {
                        array[position - 7][position - 7] = figure;
                    }
                    exit = true;
                    break;
            }
        }
        cout << "Move AI" << endl;
        printField(array);
    }
}

void moveUser(string figure, string array[sizeArray][sizeArray]) {
    int position;
    bool exit = false;
    printUI();
    cout << "Select a field:";
    cin >> position;
    cout << endl;
    if (position >= 1 && position <= 9) {
        while (!exit) {
            switch (position) {
                case 1:
                    if (array[position - 1][position - 1] != "x" &&
                        array[position - 1][position - 1] != "o") {
                        array[position - 1][position - 1] = figure;
                    }
                    exit = true;
                    break;
                case 2:
                    if (array[position - 2][position - 1] != "x" &&
                        array[position - 2][position - 1] != "o") {
                        array[position - 2][position - 1] = figure;
                    }
                    exit = true;
                    break;
                case 3:
                    if (array[position - 3][position - 1] != "x" &&
                        array[position - 3][position - 1] != "o") {
                        array[position - 3][position - 1] = figure;
                    }
                    exit = true;
                    break;
                case 4:
                    if (array[position - 3][position - 4] != "x" &&
                        array[position - 3][position - 4] != "o") {
                        array[position - 3][position - 4] = figure;
                    }
                    exit = true;
                    break;
                case 5:
                    if (array[position - 4][position - 4] != "x" &&
                        array[position - 4][position - 4] != "o") {
                        array[position - 4][position - 4] = figure;
                    }
                    exit = true;
                    break;
                case 6:
                    if (array[position - 5][position - 4] != "x" &&
                        array[position - 5][position - 4] != "o") {
                        array[position - 5][position - 4] = figure;
                    }
                    exit = true;
                    break;
                case 7:
                    if (array[position - 5][position - 7] != "x" &&
                        array[position - 5][position - 7] != "o") {
                        array[position - 5][position - 7] = figure;
                    }
                    exit = true;
                    break;
                case 8:
                    if (array[position - 6][position - 7] != "x" &&
                        array[position - 6][position - 7] != "o") {
                        array[position - 6][position - 7] = figure;
                    }
                    exit = true;
                    break;
                case 9:
                    if (array[position - 7][position - 7] != "x" &&
                        array[position - 7][position - 7] != "o") {
                        array[position - 7][position - 7] = figure;
                    }
                    exit = true;
                    break;
            }
        }
        cout << "Move User" << endl;
        printField(array);
    } else {
        cout << "The position is within [1...9]!" << endl;
    }
}

void fillingSFiled(string array[sizeArray][sizeArray]) {
    for (int i = 0; i < sizeArray; ++i) {
        for (int j = 0; j < sizeArray; ++j) {
            array[i][j] = "|";
        }
    }
}

void printField(string array[sizeArray][sizeArray]) {
    for (int i = 0; i < sizeArray; ++i) {
        for (int j = 0; j < sizeArray; ++j) {
            cout << " " << array[i][j] << " ";
        }
        cout << endl << endl;
    }
}

void printUI() {
    cout << endl << "Field" << endl;
    cout << 1 << 2 << 3 << endl
         << 4 << 5 << 6 << endl
         << 7 << 8 << 9 << endl;
}
