#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>

void draw();

void gotoxy(int x, int y);

void goUp();

void goDown();

void goRight();

void goLeft();

void goStraight();

void died();

void generateTarget();

int SnakePos[2] = {15, 10};
int TargetPosition[2];
int score = 0;
char pressedKey, lastPressed = 'd';
bool getTarget = false;

int main() {
    draw();
    gotoxy(SnakePos[0], SnakePos[1]);
    std::cout << "o";
    getch();
    Sleep(100);
    system("cls");
    draw();
    SnakePos[0] = SnakePos[0] + 1;
    gotoxy(SnakePos[0], SnakePos[1]);
    std::cout << "o";
    Sleep(100);
    while (true) {
        generateTarget();
        if (kbhit()) {
            pressedKey = getch();
        } else {
            pressedKey = lastPressed;
        }
        Sleep(10);
        switch (pressedKey) {
            case 'w':
                if(lastPressed == 's'){
                    break;
                }
                goUp();
                lastPressed = 'w';
                break;
            case 'd':
                if(lastPressed == 'a'){
                    break;
                }
                goRight();
                lastPressed = 'd';
                break;
            case 'a':
                if(lastPressed == 'd'){
                    break;
                }
                goLeft();
                lastPressed = 'a';
                break;
            case 's':
                if(lastPressed == 'w'){
                    break;
                }
                goDown();
                lastPressed = 's';
                break;
            default:
                goStraight();
                break;
        }
        if(SnakePos[0] == TargetPosition[0] && SnakePos[1] == TargetPosition[1]){
            score++;
            getTarget = false;
            generateTarget();
        }
        if (SnakePos[0] >= 29 || SnakePos[0] <= 0 || SnakePos[1] >= 22 || SnakePos[1] <= 1) {
            died();
        }
    }
    Sleep(100);
    return 0;
}

void draw() {
    std::cout << "Score: " << score << std::endl;
    for (int i = 0; i < 30; i++) {
        std::cout << "=";
    }
    for (int k = 0; k < 20; k++) {
        std::cout << "\n|";
        for (int j = 0; j < 28; j++) {
            std::cout << " ";
        }
        std::cout << "|";
    }
    std::cout << "\n";
    for (int i = 0; i < 30; i++) {
        std::cout << "=";
    }
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void goUp() {
    system("cls");
    draw();
    SnakePos[1] = SnakePos[1] - 1;
    gotoxy(SnakePos[0], SnakePos[1]);
    std::cout << "o";

}

void goDown() {
    system("cls");
    draw();
    SnakePos[1] = SnakePos[1] + 1;
    gotoxy(SnakePos[0], SnakePos[1]);
    std::cout << "o";
    lastPressed = 'a';
}

void goRight() {
    system("cls");
    draw();
    SnakePos[0] = SnakePos[0] + 1;
    gotoxy(SnakePos[0], SnakePos[1]);
    std::cout << "o";
    lastPressed = 'd';
}

void goLeft() {
    system("cls");
    draw();
    SnakePos[0] = SnakePos[0] - 1;
    gotoxy(SnakePos[0], SnakePos[1]);
    std::cout << "o";
    lastPressed = 'a';
}

void goStraight() {
    std::cout << lastPressed << std::endl;
    Sleep(10);
    switch (lastPressed) {
        case 'w':
            goUp();
            break;
        case 'd':
            goRight();
            break;
        case 'a':
            goLeft();
            break;
        case 's':
            goDown();
            break;
        default:
            std::cerr << "ERROR! Unexpected behaviour. Exit(1)" << std::endl;
            exit(2);
    }
}

void died() {
    gotoxy(25, 25);
    std::cout << "Game is over. Your score is: " << score << std::endl;
    getch();
    exit(1);
}

void generateTarget() {
    if (getTarget) {
        gotoxy(TargetPosition[0], TargetPosition[1]);
        std::cout << "*";
        return;
    }
    srand((unsigned) time(nullptr));
    TargetPosition[0] = rand() % 27;
    if (TargetPosition[0] == 0)
        TargetPosition[0] = TargetPosition[0] + 2;
    srand((unsigned) time(nullptr));
    TargetPosition[1] = rand() % 17;
    if (TargetPosition[1] == 0)
        TargetPosition[1] = TargetPosition[1] + 2;
    gotoxy(TargetPosition[0], TargetPosition[1]);
    std::cout << "*";
    getTarget = true;
}
