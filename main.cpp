#include <iostream>

using namespace std;

const int rSIZE = 3;

void printField(string array[rSIZE][rSIZE]);

void printUI();

void fillingSFiled(string array[rSIZE][rSIZE]);

void moveUser(string figure, string array[rSIZE][rSIZE]);

void moveAI(string figure, string array[rSIZE][rSIZE]);

int getRand();

bool hasEmptySlot(string array[rSIZE][rSIZE]);

int main() {

    string figure = "";
    string arrayTicTacToe[rSIZE][rSIZE];
    bool availableStep = false;

    fillingSFiled(arrayTicTacToe);

    cout << "     ...::TIC-TAC-TOE:::..." << endl << "(c) 2021, by Hanexical, w_myslicki" << endl << endl
         << "Choose who to play for ('x' or 'o')" << endl << "Enter:";
    cin >> figure;

    if (figure == "x") {
        availableStep = hasEmptySlot(arrayTicTacToe);
        while (availableStep) {
            moveUser(figure, arrayTicTacToe);
            availableStep = hasEmptySlot(arrayTicTacToe);
            if (availableStep) {
                moveAI("o", arrayTicTacToe);
                availableStep = hasEmptySlot(arrayTicTacToe);
            }
        }
    } else if (figure == "o") {
        availableStep = hasEmptySlot(arrayTicTacToe);
        while (availableStep) {
            moveAI("x", arrayTicTacToe);
            availableStep = hasEmptySlot(arrayTicTacToe);
            if (availableStep) {
                moveUser(figure, arrayTicTacToe);
                availableStep = hasEmptySlot(arrayTicTacToe);
            }
        }
    } else {
        cout << "The game is played 'x' and 'o'!";
        return -1;
    }
}

void moveAI(string figure, string array[rSIZE][rSIZE]) {
    int positionX = getRand();
    int positionY = getRand();

    if (array[positionX][positionY] == "|") {
        cout << "Move AI" << endl;
        array[positionX][positionY] = figure;
        printField(array);
    } else {
        moveAI(figure, array);
    }
}

void moveUser(string figure, string array[rSIZE][rSIZE]) {
    bool stepUser = false;
    while (!stepUser) {
        int position;
        cout << "Select a field:";
        cin >> position;
        cout << endl;
        if (position >= 1 && position <= 9) {
            switch (position) {
                case 1:
                    if (array[position - 1][position - 1] != "x" &&
                        array[position - 1][position - 1] != "o") {
                        array[position - 1][position - 1] = figure;
                        stepUser = true;
                    } else {
                        cout << "Wrong move!";
                        stepUser = false;
                    }
                    break;
                case 2:
                    if (array[position - 2][position - 1] != "x" &&
                        array[position - 2][position - 1] != "o") {
                        array[position - 2][position - 1] = figure;
                        stepUser = true;
                    } else {
                        cout << "Wrong move!";
                        stepUser = false;
                    }
                    break;
                case 3:
                    if (array[position - 3][position - 1] != "x" &&
                        array[position - 3][position - 1] != "o") {
                        array[position - 3][position - 1] = figure;
                        stepUser = true;
                    } else {
                        cout << "Wrong move!";
                        stepUser = false;
                    }
                    break;
                case 4:
                    if (array[position - 3][position - 4] != "x" &&
                        array[position - 3][position - 4] != "o") {
                        array[position - 3][position - 4] = figure;
                        stepUser = true;
                    } else {
                        cout << "Wrong move!";
                        stepUser = false;
                    }
                    break;
                case 5:
                    if (array[position - 4][position - 4] != "x" &&
                        array[position - 4][position - 4] != "o") {
                        array[position - 4][position - 4] = figure;
                        stepUser = true;
                    } else {
                        cout << "Wrong move!";
                        stepUser = false;
                    }
                    break;
                case 6:
                    if (array[position - 5][position - 4] != "x" &&
                        array[position - 5][position - 4] != "o") {
                        array[position - 5][position - 4] = figure;
                        stepUser = true;
                    } else {
                        cout << "Wrong move!";
                        stepUser = false;
                    }
                    break;
                case 7:
                    if (array[position - 5][position - 7] != "x" &&
                        array[position - 5][position - 7] != "o") {
                        array[position - 5][position - 7] = figure;
                        stepUser = true;
                    } else {
                        cout << "Wrong move!";
                        stepUser = false;
                    }
                    break;
                case 8:
                    if (array[position - 6][position - 7] != "x" &&
                        array[position - 6][position - 7] != "o") {
                        array[position - 6][position - 7] = figure;
                        stepUser = true;
                    } else {
                        cout << "Wrong move!";
                        stepUser = false;
                    }
                    break;
                case 9:
                    if (array[position - 7][position - 7] != "x" &&
                        array[position - 7][position - 7] != "o") {
                        array[position - 7][position - 7] = figure;
                        stepUser = true;
                    } else {
                        cout << "Wrong move!";
                        stepUser = false;
                    }
                    break;
            }
        } else {
            cout << "The position is within [1...9]!" << endl;
        }
    }
    cout << "Move User" << endl;
    printField(array);
}

void fillingSFiled(string array[rSIZE][rSIZE]) {
    for (int i = 0; i < rSIZE; ++i) {
        for (int j = 0; j < rSIZE; ++j) {
            array[i][j] = "|";
        }
    }
}

void printField(string array[rSIZE][rSIZE]) {
    for (int i = 0; i < rSIZE; ++i) {
        for (int j = 0; j < rSIZE; ++j) {
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

int getRand() {
    return rand() % 3;
}

bool hasEmptySlot(string array[rSIZE][rSIZE]) {
    for (int i = 0; i < rSIZE; i++) {
        for (int j = 0; j < rSIZE; j++) {
            if (array[i][j] == "|") {
                return true;
            }
        }
    }
    return false;
}
