#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
    Служебные слова W
    Идентификаторы I
    Операции O
    Разделители R
    Константы числовые N
    Константы символьные С
*/

//Возвращает порядковый номер идентификатора в базе идентификаторов + подходит для баз прочих лексем

void ChangeState(char &symbol,  unsigned char &state, unsigned char &pred_state) {
    //Возможные значения state: S, F, Z, 1...10(схему смотри) + 11 вспомогательное

    string litters = "qwertyuiopasdfghjklzxcvbnm"; //Латинские буквы

    string operations = "+ - * % = ! > < & | ^";

    string separators = "{ } [ ] ( ) , ; . ";

    switch (state) {
        case 'S':
            pred_state = 'S';
            
            break;

        case 1:
            pred_state = 1;
            
            break;

        case 2:
            pred_state = 2;
           
            break;
        
        case 3:
            pred_state = 3;
           
            break;

        case 4:
            pred_state = 4;

            break;

        case 5:
            pred_state = 5;

  
            break;

        case 6:
            pred_state = 6;

            break;

        case 7:
            pred_state = 7;

            break;

        case 9:
            pred_state = 9;

            break;

        case 11:
            pred_state = 11;

            break;
    }
}

int count_id = 0; //Числовая часть внутреннего представления идентификатра
void Semantic_procedure_1(string &buffer, string &identificators, string &result) {
    
}

void Semantic_procedure_2(string &buffer, string SystemWordBase, string &identificators, string &result) {
    
}

void Semantic_procedure_3(string& buffer, string Operations, string& result) {

}

void Semantic_procedure_4(string &buffer, string Separators, string& result) {
  
}

void Semantic_procedure_5() {

}

void Semantic_procedure_6() {

}


int main()
{
    setlocale(LC_ALL, "ru");

    //Формируем базу служебных слов С# 
    ifstream f("SystemWord.txt");
    string line;
    string SystemWordBase = "";

    if (f.is_open())
    {

        while (getline(f, line))
        {
            SystemWordBase += line + ' ';
        }


        f.close();
    }


    //Формируем базу операций(арифметические, логические, побитовые, унарные, реляционные)
    ifstream g("Operations.txt");
    string Operations = "";

    if (g.is_open()) {

        while (getline(g, line)) {
            Operations += line + ' ';
        }


        g.close();
    }


    //Формируем базу разделителей
    ifstream h("Separators.txt");
    string Separators = "";

    if (h.is_open()) {

        while (getline(h, line)) {
            Separators += line + ' ';
        }

        h.close();

    }


    //Формируем базу идентификитаров
    string identificators = "";

    //Формируем базу констант
    string constants = "";

    //Внутренне представление лексем
    string result = "";



    //Начало анализа
    ifstream program("Programms\\main.cs");
    string program_tokens = "";

    if (program.is_open()) {

        while (getline(program, line)) {
            program_tokens += line + ' ';
        }
    }

    //в program_tokens сохранен текст программы main.cs
    string buffer = ""; //сохраняется лексема для последующей обработки
    unsigned char pred_state;
    unsigned char state = 'S'; //Состояние лексического анализатора, которое зависит от входящих символов и определяет вид процедуры обработки; Начальное состояние – S 

    for (int i = 0; i < program_tokens.length(); i++) {
        
        ChangeState(program_tokens[i], state, pred_state);
        buffer += program_tokens[i];

        if (state == 'S') {
            switch (pred_state) {
                case 1:
                    Semantic_procedure_2(buffer, SystemWordBase, identificators, result);
                    break;

                case 2:
                    Semantic_procedure_1(buffer, identificators, result);
                    break;

                case 3:
                    Semantic_procedure_3(buffer, constants, result);
                    break;
                
                case 4:
                    Semantic_procedure_9(buffer, Separators, result);
                    break;

                case 5:
                    Semantic_procedure_3(buffer, constants, result);
                    break;
                
                case 11:
                    Semantic_procedure_6(buffer, Operations, result);
                    break;

                case 'S':
                    Semantic_procedure_9(buffer, Separators, result);
                    break;
            }   
        }   
    }

}