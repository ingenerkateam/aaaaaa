#include "TXLib.h"
#include "questionmodule.h"

int main()
{
    txCreateWindow(600, 400);

    //������� ����
    //10 ��������
    //�������� ����-������
    //���� ������
    for (int i = 0; i < 10; i++) {
        questionModule::runQuestionModule(/*������ ������-������*/);
    }


    questionModule::runQuestionModule(1,"1825 ������ 5?");  //12 67 80
    questionModule::runQuestionModule(2,"1960 ������ 3?");  //12 65 79
    questionModule::runQuestionModule(2,"160 ������ 3?");   //11 65 78
    questionModule::runQuestionModule(2,"1717 ������ 35?"); //13 67 82
    return 0;
}
