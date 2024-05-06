#include <iostream>
#include <windows.h>

using namespace std;

const int width = 100, height = 20;

void setPosition(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void upperlowerwalls() {
    cout << "+";
    for(int i = 0; i < width-1; i++) {
        cout << "-";
    }
    cout << "+" << endl;
}

void drawwalls() {
    upperlowerwalls();
    for(int i = 1; i < height; i++) {
        setPosition(0,i);
        cout << "|";
        setPosition(width, i);
        cout << "|" << endl;
    }
    setPosition(0, height);
    upperlowerwalls();
}

void drawball(int x, int y, int prevX, int prevY) {
    if (prevX >= 1 && prevX <= width - 2 && prevY >= 1 && prevY <= height - 2) {
        setPosition(prevX, prevY);
        cout << " ";
    }
    if (x >= 1 && x <= width - 2 && y >= 1 && y <= height - 2) {
        setPosition(x, y);
        cout << "O";
    }
}

void clear(int x, int y) {
    if (x >= 1 && x <= width - 2 && y >= 1 && y <= height - 2) {
        setPosition(x, y);
        cout << " ";
    }
}

int main() {
    int x = 1, y = 1, dx = 1, dy = 1;
    int prevX = x, prevY = y;

    drawwalls();
    while(true) {
        drawball(x, y, prevX, prevY);
        Sleep(50);
        clear(prevX, prevY);
        prevX = x;
        prevY = y;
        x += dx;
        y += dy;
        if(x < 2 || x > width-3) { // Módosítás itt
            dx = -dx;
        }
        if(y < 2 || y > height-3) { // Módosítás itt
            dy = -dy;
        }
    }
    return 0;
}