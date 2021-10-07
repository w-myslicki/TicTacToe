#include <iostream>
#include <ctime>

using namespace std;

const int rSIZE = 3;
int scoreCross = 0;
int scoreZero = 0;

int getRand();

void printField(string array[rSIZE][rSIZE]);

void printMenu();

void printNumPad();

void fillingSFiled(string array[rSIZE][rSIZE]);

void moveUser(string figure, string array[rSIZE][rSIZE]);

void moveAI(string figure, string array[rSIZE][rSIZE]);

bool hasEmptySlot(string array[rSIZE][rSIZE]);

bool getWinner(string figure, string array[rSIZE][rSIZE]);

bool isWinner(string figure, string array[rSIZE][rSIZE]);

int main() {
    srand(time(NULL));

    string arrayTicTacToe[rSIZE][rSIZE];
    string figure = "";

    bool availableStep = false;
    bool hasWinner = true;
    int menuPoint = 0;
    int exitMenu = 1;

    fillingSFiled(arrayTicTacToe);

    while (exitMenu != 2) {
        printMenu();
        fillingSFiled(arrayTicTacToe);
        cin >> menuPoint;
        cout << endl;
        switch (menuPoint) {
            case 1:
                cout << "Choose who to play for ('x' OR 'o')" << endl;
                cout << "Enter:";
                cin >> figure;
                cout << endl;
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
                        } else if (!availableStep && !hasWinner) {
                            cout << "Draw!" << endl << endl;
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
                        } else if (!availableStep) {
                            cout << "Draw!" << endl << endl;
                        }
                    }
                } else {
                    cout << "The game is played 'x' and 'o'!" << endl << endl;
                }
                break;
            case 2:
                exitMenu = 2;
                break;
        }
    }
}

int getRand() {
    return rand() % 3;
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
    int position;
    while (!stepUser) {
        printNumPad();
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
                        cout << "Wrong move!" << endl;
                        stepUser = false;
                    }
                    break;
                case 2:
                    if (array[position - 2][position - 1] != "x" &&
                        array[position - 2][position - 1] != "o") {
                        array[position - 2][position - 1] = figure;
                        stepUser = true;
                    } else {
                        cout << "Wrong move!" << endl;
                        stepUser = false;
                    }
                    break;
                case 3:
                    if (array[position - 3][position - 1] != "x" &&
                        array[position - 3][position - 1] != "o") {
                        array[position - 3][position - 1] = figure;
                        stepUser = true;
                    } else {
                        cout << "Wrong move!" << endl;
                        stepUser = false;
                    }
                    break;
                case 4:
                    if (array[position - 3][position - 4] != "x" &&
                        array[position - 3][position - 4] != "o") {
                        array[position - 3][position - 4] = figure;
                        stepUser = true;
                    } else {
                        cout << "Wrong move!" << endl;
                        stepUser = false;
                    }
                    break;
                case 5:
                    if (array[position - 4][position - 4] != "x" &&
                        array[position - 4][position - 4] != "o") {
                        array[position - 4][position - 4] = figure;
                        stepUser = true;
                    } else {
                        cout << "Wrong move!" << endl;
                        stepUser = false;
                    }
                    break;
                case 6:
                    if (array[position - 5][position - 4] != "x" &&
                        array[position - 5][position - 4] != "o") {
                        array[position - 5][position - 4] = figure;
                        stepUser = true;
                    } else {
                        cout << "Wrong move!" << endl;
                        stepUser = false;
                    }
                    break;
                case 7:
                    if (array[position - 5][position - 7] != "x" &&
                        array[position - 5][position - 7] != "o") {
                        array[position - 5][position - 7] = figure;
                        stepUser = true;
                    } else {
                        cout << "Wrong move!" << endl;
                        stepUser = false;
                    }
                    break;
                case 8:
                    if (array[position - 6][position - 7] != "x" &&
                        array[position - 6][position - 7] != "o") {
                        array[position - 6][position - 7] = figure;
                        stepUser = true;
                    } else {
                        cout << "Wrong move!" << endl;
                        stepUser = false;
                    }
                    break;
                case 9:
                    if (array[position - 7][position - 7] != "x" &&
                        array[position - 7][position - 7] != "o") {
                        array[position - 7][position - 7] = figure;
                        stepUser = true;
                    } else {
                        cout << "Wrong move!" << endl;
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

void printNumPad() {
    cout << "    !Number Pad!    " << endl;
    cout << "|1|\t" << "|2|\t" << "|3|\t" << endl;
    cout << "|4|\t" << "|5|\t" << "|6|\t" << endl;
    cout << "|7|\t" << "|8|\t" << "|9|\t" << endl;
    cout << "Select the field number:";
}

void printMenu() {
    cout << "..::TIC-TAC-TOE::.." << endl;
    cout << ":::::::GAME::::::::" << endl;
    cout << "Cross:" << scoreCross << " " << "Zero:" << scoreZero << endl;
    cout << "1. New game" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter:";
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
        cout << figure << " - winner!" << endl << endl;
        if (figure == "x") {
            scoreCross++;
        } else if (figure == "o") {
            scoreZero++;
        }
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
        for (int j = 0; j < rSIZE; j++) {
            if (i == j && array[i][j] == figure) {
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
            if (array[2][0] == figure) {
                return true;
            }
        }
    }

//    for (int j = rSIZE; j > 0; j--) {
//        for (int i = rSIZE; i > 0; i--) {
//            if (i == j && array[i][j] == figure) {
//                figureCounter++;
//                if (figureCounter == 3) {
//                    return true;
//                }
//            }
//        }
//    }
    return false;
}
