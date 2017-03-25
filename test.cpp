#include "TXLib.h"
#include "questionmodule.h"

int main()
{
    txCreateWindow(600, 400);

    //Открыли файл
    //10 вопросов
    //записали куда-нибудь
    //файл закрыт
    for (int i = 0; i < 10; i++) {
        questionModule::runQuestionModule(/*читаем откуда-нибудь*/);
    }


    questionModule::runQuestionModule(1,"1825 кратно 5?");  //12 67 80
    questionModule::runQuestionModule(2,"1960 кратно 3?");  //12 65 79
    questionModule::runQuestionModule(2,"160 кратно 3?");   //11 65 78
    questionModule::runQuestionModule(2,"1717 кратно 35?"); //13 67 82
    return 0;
}
