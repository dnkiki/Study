#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool gameover;

const int width = 20;
const int height = 15;

int x, y, dungX, dungY, score;

enum eDirecton
{
    STOP = 0,
    LEFT,
    RIGHT,
}; // Controls

eDirecton dir;

void Setup()
{
    gameover = false;
    dir = STOP;
    x = width / 2;
    y = height - 1;

    srand(static_cast<unsigned>(time(0))); // 시간을 난수화

    dungX = rand() % width; // width로 나눈 나머지로 x 위치를 설정
    dungY = 0;

    score = 0;
}

void Draw()
{
    system("cls");

    for (int i = 0; i < width + 2; i++) // 상단 벽
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#"; // 좌측 벽

            if (i == y && j == x)
                cout << "*"; // 위에서 선언한 플레이어 위치 x,y
            else if (i == dungY && j == dungX)
                cout << "D"; // 똥 생성 위치
            else
                cout << " ";
        }
        cout << "#"; //우측벽면
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score:" << score << endl;
}

void Input()
{
    char input;
    cin >> input;

    switch (input)
    {
    case 'a':
        dir = LEFT;
        break;
    case 'd':
        dir = RIGHT;
        break;
    case 'x':
        gameover = true;
        cout << "Game Over! Your Score: " << score << endl;
        break;
    default:
        dir = STOP;
        break;
    }
}

void algorithm()
{
    // 똥이 한 칸씩 아래로 이동
    dungY++;

    // 똥이 바닥에 닿으면 새로운 똥 위치 설정
    if (dungY >= height)
    {
        dungY = 0;
        dungX = rand() % width;

        score += 10; // 똥 피하면(바닥에 닿으면) 10점 증가
    }

    // 플레이어가 키를 입력하면 좌나 우로 이동
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    default:
        break;
    }

    // 플레이어가  똥에 맞거나 벽에 닿으면 게임 종료
    if (x < 0 || x >= width || y < 0 || y >= height || (x == dungX && y == dungY))
    {
        gameover = true;
        cout << "Game Over! Your Score: " << score << endl;
    }
}

int main()
{
    Setup();

    while (!gameover)
    {
        Draw();
        Input();
        algorithm();
    }

    return 0;
}