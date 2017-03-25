#ifndef QUESTIONMODULE_H
#define QUESTIONMODULE_H

#include "TXLib.h"

namespace questionModule
{

    int One = 1;
    int Two = 2;
    int NoAnswer = 3;
    unsigned int number[];
    char* question[];

    void praseCfg() // unsigned int number, const char* q, const char* a = "Да", const char* a2 = "Нет"
    {
        string line;

        ifstream myfile ("quest.txt");
        if (myfile.is_open())
        {
                int i = 0;
                int c = 0;
                while (myfile.good())
                {
                    getline (myfile,line);

                    if (line.substr(0, strlen("QUESTION_TEXT = ")) == "QUESTION_TEXT = ") {
                        question[i].text = atoi(line.substr(strlen("QUESTION_TEXT = "), 100).c_str());
                        i++;
                        //cout << "nitro = " << nitro << endl;
                    }
                    if (line.substr(0, strlen("QUESTION_TEXT = ")) == "QUESTION_TEXT = ") {
                        question[i].text = atoi(line.substr(strlen("QUESTION_TEXT = "), 100).c_str());
                        c++;
                        //cout << "nitro = " << nitro << endl;
                    }
                    cout << line << endl;
                }
            myfile.close();
        }
    }

    namespace
    {
        HDC imageBackGround;
    }

    bool buttonState1() {
        return (txMouseX() >=  100 and txMouseX() <= 250 and txMouseY() >= 250 and txMouseY() <= 350 and txMouseButtons() == 1);
    }

    bool buttonState2() {
        return (txMouseX() >= 350  and txMouseX() <= 500  and txMouseY() >= 250  and txMouseY() <= 350  and txMouseButtons() == 1);
    }

    int rightAnswer;

    int isRightAnswer() {
        if (rightAnswer == 1 and buttonState1()) {
            return One;
        }
        if (rightAnswer == 2 and buttonState2()) {
            return Two;
        }
        return NoAnswer;
    }

    void draw(const char* a)
    {
        txSetFillColor(TX_GRAY);
        txRectangle(100, 100, 500, 200);
        txDrawText (100, 100, 500, 200, a);
    }

    void draw(const char* a, const char* a2)
    {
        txRectangle(100, 250, 250, 350);
        txDrawText (100, 250, 250, 350, a);
        txRectangle(350, 250, 500, 350);
        txDrawText (350, 250, 500, 350, a2);
    }

    void _END()
    {
        txDeleteDC(imageBackGround);
        txSleep(100);
    }

    void runQuestionModule(unsigned int number, const char* q, const char* a = "Да", const char* a2 = "Нет")
    {
        if (number != 1 and number != 2)
        {
            _END();
            exit(1);
        }

        /*/ Init /*/
        txSetFillColor(TX_WHITE);
        txClear();
        imageBackGround = txLoadImage ("imageBackGround.bmp");
        txBitBlt (txDC(), 0, 0, 800, 600, imageBackGround, 0, 0);
        rightAnswer = number;
        /*/ ==== /*/

        /*/ Question /*/

        draw(q);
        draw(a, a2);
        while (isRightAnswer() == One or Two)
        {
            if (GetAsyncKeyState('N'))
            {
                break;
            }
        }
        if (!isRightAnswer() == number)
        {
            while (true)
            {
                txSetFillColor(RGB(random(255), random(255), random(255)));
                txClear();
            }
        }
        _END();
        /*/ ==== /*/
    }
};

#endif // QUESTIONMODULE_H
