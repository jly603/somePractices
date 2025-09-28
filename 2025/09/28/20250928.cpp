#include<iostream>
#define wxn using
#define suki namespace
#define zxw std
wxn suki zxw;
const int MAX = 10001;
char desktop[MAX][MAX]; //前为y，后为x
int LEFT = 10000, RIGHT = 0;
int UP = 10000, DOWN = 0;
int angle[][2] = {
    {0, 0}, {0, -3}, {4, 0}, {4, -3}, {2, -5}, {6, -5}, {6, -2}
};
int length[][2] = {
    {1, 0}, {1, -3}, {3, -5}
};
int height[][2] = {
    {0, -1}, {0, -2}, {4, -1}, {4, -2}, {6, -3}, {6, -4}
};
int width[][2] = {
    {5, -1}, {5, -4}, {1, -4}
};
int blank[][2] = {
    {0, 0}, {2, -2}
};
void init() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            desktop[i][j] = '.';
        }
    }
}
void setBlock(int y, int x) { //我很好奇这里怎样能写的不臭
    //记录
    if (y > DOWN) DOWN = y;
    if (x > RIGHT) RIGHT = x;
    if (y < UP) UP = y;
    if (x < LEFT) LEFT = x;
    //留白
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= 3; j++) {
            for (int k = 0; k <= 4; k++) {
                desktop[y + blank[i][1] - j][x + blank[i][0] + k] = ' ';
            }
        }
    }
    //放块
    for (int i = 0; i < 7; i++) {
        desktop[y + angle[i][1]][x + angle[i][0]] = '+';
    }
    for (int i = 0; i < 3; i++) {
        desktop[y + width[i][1]][x + width[i][0]] = '/';
    }
    for (int i = 0; i < 6; i++) {
        desktop[y + height[i][1]][x + height[i][0]] = '|';
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= 2; j++) {
            desktop[y + length[i][1]][x + length[i][0] + j] = '-';
        }
    }
}
int main() {
    init();
    int l, w, max = 0;
    int xDef = 500, yDef = 8000; //随便取的值
    int blocks[51][51];
    cin >> w >> l;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < l; j++) {
            cin >> blocks[i][j];
            if (!i && blocks[i][j] > max) {
                max = blocks[i][j];
            }
        }
    }
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < blocks[i][j]; k++)
                setBlock(yDef + 2 * i - 3 * k, xDef + 4 * j - 2 * i);
        }
    }
    RIGHT += 6; UP -= 5;
    for (int i = UP; i <= DOWN; i++) {
    	for (int j = LEFT; j <=RIGHT; j++)
	    printf("%c", desktop[i][j]);
	    printf("\n");
	}
    return 0;
}
