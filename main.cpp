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
bool getWinner(string figure, string array[rSIZE][rSIZE]);
bool isWinner(string figure, string array[rSIZE][rSIZE]);

int main() {

    int countParties = 0;
    string figure = "";
    string arrayTicTacToe[rSIZE][rSIZE];
    bool availableStep = false;
    bool hasWinner = true;

    fillingSFiled(arrayTicTacToe);

    cout << "     ...::TIC-TAC-TOE:::..." << endl << "(c) 2021, by Hanexical, w_myslicki" << endl << endl
         << "Choose who to play for ('x' or 'o')" << endl << "Enter:";
    cin >> figure;

    if (figure == "x") {
        hasWinner = getWinner(figure, arrayTicTacToe);
        availableStep = hasEmptySlot(arrayTicTacToe);
        while (!hasWinner && availableStep) {
            moveUser(figure, arrayTicTacToe);
            hasWinner = getWinner(figure, arrayTicTacToe);
            availableStep = hasEmptySlot(arrayTicTacToe);
            if (!hasWinner && availableStep) {
                moveAI("o", arrayTicTacToe);
                hasWinner = getWinner("o", arrayTicTacToe);
                availableStep = hasEmptySlot(arrayTicTacToe);
            } else if(!availableStep){
                cout << "Draw!";
                return 1;
            }
        }
    } else if (figure == "o") {
        hasWinner = getWinner(figure, arrayTicTacToe);
        availableStep = hasEmptySlot(arrayTicTacToe);
        while (availableStep && !hasWinner) {
            moveAI("x", arrayTicTacToe);
            hasWinner = getWinner("x", arrayTicTacToe);
            availableStep = hasEmptySlot(arrayTicTacToe);
            if (availableStep && !hasWinner) {
                moveUser(figure, arrayTicTacToe);
                hasWinner = getWinner(figure, arrayTicTacToe);
                availableStep = hasEmptySlot(arrayTicTacToe);
            }else if(!availableStep){
                cout << "Draw!";
                return 1;
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

bool getWinner(string figure, string array[rSIZE][rSIZE]) {
    if (isWinner(figure, array)) {
        cout << figure << " - winner!";
        return true;
    }
    return false;
}

bool isWinner(string figure, string array[rSIZE][rSIZE]) {
    int figureCounter = 0;
    //horizon check
    for (int i = 0; i < rSIZE; i++) {
        for (int j = 0; j < rSIZE; j++) {
            if (array[i][j] == figure) {
                figureCounter++;
                if (figureCounter == 3) {
                    return true;
                }
            }
        }
        figureCounter = 0;
    }
    figureCounter = 0;

    //vertical check
    for (int j = 0; j < rSIZE; j++) {
        for (int i = 0; i < rSIZE; i++) {
            if (array[i][j] == figure) {
                figureCounter++;
                if (figureCounter == 3) {
                    return true;
                }
            }
        }
        figureCounter = 0;
    }
    figureCounter = 0;

    //diagonal 00-22
    for (int i = 0; i < rSIZE; i++) {
        for (int j = rSIZE; j == i; j++) {
            if (array[i][j] == figure) {
                figureCounter++;
                if (figureCounter == 3) {
                    return true;
                }
            }
        }
    }
    figureCounter = 0;

//    diagonal 02-02
    if (array[0][2] == figure) {
        if (array[1][1] == figure) {
            if(array[2][0] == figure){
                return true;
            }
        }
    }

    return false;
}
