#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>

// Creating a node
class Node {
public:
    int posx;
    int posy;
    Node* next;
};

void draw();

void gotoxy(int x, int y);

void goUp();

void goDown();

void goRight();

void goLeft();

void goStraight();

void died();

void generateTarget();

void createTail();

void ShowConsoleCursor(bool showFlag);

int TargetPosition[2];
int score = 0;
char pressedKey, lastPressed = 'd';
bool getTarget = false;

Node first_node;
Node* head;
Node* tail;
Node* temp_node;

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    ShowConsoleCursor(false);
    first_node.posx= 15;
    first_node.posy= 10;
    head = new Node();
    head->next = &first_node;
    tail = new Node();
    tail->next = &first_node;
    draw();
    gotoxy(first_node.posx, first_node.posy);
    std::cout << "o";
    getch();
    Sleep(25);
    system("cls");
    draw();
    first_node.posx = first_node.posx + 1;
    gotoxy(first_node.posx, first_node.posy);
    std::cout << "o";
    Sleep(25);
    while (true) {
        generateTarget();
        if (kbhit()) {
            pressedKey = getch();
        } else {
            pressedKey = lastPressed;
        }
        Sleep(1);
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
        if(first_node.posx == TargetPosition[0] && first_node.posy == TargetPosition[1]){
            score++;
            getTarget = false;
            createTail();
            generateTarget();
        }
        if (first_node.posx >= 29 || first_node.posx <= 0 || first_node.posy >= 22 || first_node.posy <= 1) {
            died();
        }
    }
    Sleep(100);
    return 0;
}

void createTail() {
    Node* added_node = new Node();
    while(head->next->next != nullptr){
        head->next = head->next->next;
    }
    switch (lastPressed) {
        case 'w':
            added_node->posx = head->next->posx;
            added_node->posy = head->next->posy + 1;
            break;
        case 's':
            added_node->posx = head->next->posx;
            added_node->posy = head->next->posy - 1;
            break;
        case 'a':
            added_node->posx = head->next->posx + 1;
            added_node->posy = head->next->posy;
            break;
        case 'd':
            added_node->posx = head->next->posx - 1;
            added_node->posy = head->next->posy;
            break;
        default:
            std::cerr << "WAIT!STH WRONG" << std::endl;
            break;
    }
    head->next->next = added_node;
    added_node->next = nullptr;
    head->next = &first_node;
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
    temp_node = new Node;
    system("cls");
    draw();
    head->posx = first_node.posx;
    head->posy = first_node.posy;
    first_node.posy = first_node.posy - 1;
    while(head->next->next != nullptr){
        head->next = head->next->next;
        temp_node->posx = head->next->posx;
        temp_node->posy = head->next->posy;
        head->next->posx = head->posx;
        head->next->posy = head->posy;
        head->posx = temp_node->posx;
        head->posy = temp_node->posy;
    }
    head->next = &first_node;
    do{
        gotoxy(head->next->posx, head->next->posy);
        std::cout << "o";
        head->next = head->next->next;
    }while(head->next != nullptr);
    head->next = &first_node;
    lastPressed = 'w';
}

void goDown() {
    temp_node = new Node;
    system("cls");
    draw();
    head->posx = first_node.posx;
    head->posy = first_node.posy;
    first_node.posy = first_node.posy + 1;
    while(head->next->next != nullptr){
        head->next = head->next->next;
        temp_node->posx = head->next->posx;
        temp_node->posy = head->next->posy;
        head->next->posx = head->posx;
        head->next->posy = head->posy;
        head->posx = temp_node->posx;
        head->posy = temp_node->posy;
    }
    head->next = &first_node;
    do{
        gotoxy(head->next->posx, head->next->posy);
        std::cout << "o";
        head->next = head->next->next;
    }while(head->next != nullptr);
    head->next = &first_node;
    lastPressed = 'a';
}

void goRight() {
    temp_node = new Node;
    system("cls");
    draw();
    head->posx = first_node.posx;
    head->posy = first_node.posy;
    first_node.posx = first_node.posx + 1;
    while(head->next->next != nullptr){
        head->next = head->next->next;
        temp_node->posx = head->next->posx;
        temp_node->posy = head->next->posy;
        head->next->posx = head->posx;
        head->next->posy = head->posy;
        head->posx = temp_node->posx;
        head->posy = temp_node->posy;
    }
    head->next = &first_node;
    do{
        gotoxy(head->next->posx, head->next->posy);
        std::cout << "o";
        head->next = head->next->next;
    }while(head->next != nullptr);
    head->next = &first_node;
    lastPressed = 'd';
}

void goLeft() {
    temp_node = new Node;
    system("cls");
    draw();
    head->posx = first_node.posx;
    head->posy = first_node.posy;
    first_node.posx = first_node.posx - 1;
    while(head->next->next != nullptr){
        head->next = head->next->next;
        temp_node->posx = head->next->posx;
        temp_node->posy = head->next->posy;
        head->next->posx = head->posx;
        head->next->posy = head->posy;
        head->posx = temp_node->posx;
        head->posy = temp_node->posy;
    }
    head->next = &first_node;
    do{
        gotoxy(head->next->posx, head->next->posy);
        std::cout << "o";
        head->next = head->next->next;
    }while(head->next != nullptr);
    head->next = &first_node;
    lastPressed = 'a';
}

void goStraight() {
    std::cout << lastPressed << std::endl;
    Sleep(5);
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
    TargetPosition[1] = rand() % 18;
    if (TargetPosition[1] == 0 || TargetPosition[1] == 1)
        TargetPosition[1] = TargetPosition[1] + 2;
    gotoxy(TargetPosition[0], TargetPosition[1]);
    std::cout << "*";
    getTarget = true;
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}