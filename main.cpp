#include <iostream>
#include <windows.h>
#include <conio.h>


void draw();
void gotoxy(int x, int y);
void goUp();
void goDown();
void goRight();
void goLeft();
void goStraight();


int pos[2] = {15, 10};
char pressedKey, lastPressed = 'd';

int main() {
    draw();
    gotoxy(pos[0], pos[1]);
    std::cout << "o";
    getch();
    Sleep(100);
    system("cls");
    draw();
    pos[0] = pos[0] +1;
    gotoxy(pos[0], pos[1]);
    std::cout << "o";
    Sleep(100);
    while(true){
        if (kbhit()){
            pressedKey = getch();
        }else{
            pressedKey = lastPressed;
        }
        Sleep(10);
        switch (pressedKey) {
            case 'w':
                goUp();
                lastPressed = 'w';
                break;
            case 'd':
                goRight();
                lastPressed = 'd';
                break;
            case 'a':
                goLeft();
                lastPressed = 'a';
                break;
            case 's':
                goDown();
                lastPressed = 's';
                break;
            default:
                goStraight();
                break;
        }
    }

    Sleep(100);
    return 0;
}

void draw(){
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

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void goUp() {
    system("cls");
    draw();
    pos[1] = pos[1] - 1;
    gotoxy(pos[0], pos[1]);
    std::cout << "o";

}

void goDown() {
    system("cls");
    draw();
    pos[1] = pos[1] + 1;
    gotoxy(pos[0], pos[1]);
    std::cout << "o";
    lastPressed = 'a';
}

void goRight() {
    system("cls");
    draw();
    pos[0] = pos[0] + 1;
    gotoxy(pos[0], pos[1]);
    std::cout << "o";
    lastPressed = 'd';
}

void goLeft() {
    system("cls");
    draw();
    pos[0] = pos[0] - 1;
    gotoxy(pos[0], pos[1]);
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
    }
}
