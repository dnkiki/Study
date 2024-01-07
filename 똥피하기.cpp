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

    srand(static_cast<unsigned>(time(0))); // �ð��� ����ȭ

    dungX = rand() % width; // width�� ���� �������� x ��ġ�� ����
    dungY = 0;

    score = 0;
}

void Draw()
{
    system("cls");

    for (int i = 0; i < width + 2; i++) // ��� ��
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#"; // ���� ��

            if (i == y && j == x)
                cout << "*"; // ������ ������ �÷��̾� ��ġ x,y
            else if (i == dungY && j == dungX)
                cout << "D"; // �� ���� ��ġ
            else
                cout << " ";
        }
        cout << "#"; //��������
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
    // ���� �� ĭ�� �Ʒ��� �̵�
    dungY++;

    // ���� �ٴڿ� ������ ���ο� �� ��ġ ����
    if (dungY >= height)
    {
        dungY = 0;
        dungX = rand() % width;

        score += 10; // �� ���ϸ�(�ٴڿ� ������) 10�� ����
    }

    // �÷��̾ Ű�� �Է��ϸ� �³� ��� �̵�
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

    // �÷��̾  �˿� �°ų� ���� ������ ���� ����
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