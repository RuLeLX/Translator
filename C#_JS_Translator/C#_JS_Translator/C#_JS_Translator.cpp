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

//Возвращает порядковый номер идентификатора в базе идентификаторов
int number_id(string identificators) {

    string id = "";
    vector<string> list_id;

    for (int i = 0; i < identificators.length(); i++) {
        if (identificators[i] != ' ') id += identificators[i];
        else {

        }
    }
   

}

void ChangeState(char &symbol,  unsigned char &state, unsigned char &pred_state) {
    //Возможные значения state: S, F, Z, 1...10(схему смотри) + 11 вспомогательное

    string litters = "qwertyuiopasdfghjklzxcvbnm"; //Латинские буквы

    string operations = "+ - * % = ! > < & | ^";

    string separators = "{ } [ ] ( ) , ; . ";

    switch (state) {
        case 'S':
            pred_state = 'S';
            if (litters.find(symbol) != string::npos) state = 1;

            else if (symbol >= '0' && symbol <= '9') state = 3;

            else if (symbol == '.') state = 4;

            else if (symbol == '/') state = 6;

            else if (operations.find(symbol) != string::npos) state = 9;

            else if (separators.find(symbol) != string::npos) state = 'S';
            break;

        case 1:
            pred_state = 1;
            if (litters.find(symbol) != string::npos) state = 1;

            else if (symbol >= '0' && symbol <= '9') state = 2;

            else if (operations.find(symbol) != string::npos || separators.find(symbol) != string::npos) state = 'S';
            break;

        case 2:
            pred_state = 2;
            if (litters.find(symbol) != string::npos || (symbol >= '0' && symbol <= '9')) state = 2;

            else if (operations.find(symbol) != string::npos || separators.find(symbol) != string::npos) state = 'S';
            break;
        
        case 3:
            pred_state = 3;
            if (symbol >= '0' && symbol <= '9') state = 3;

            else if (symbol == '.') state = 5;

            else if (operations.find(symbol) != string::npos || separators.find(symbol) != string::npos) state = 'S';
            break;

        case 4:
            pred_state = 4;

            if (symbol >= '0' && symbol <= '9') state = 5;

            else if (operations.find(symbol) != string::npos || separators.find(symbol) != string::npos) state = 'S';
            break;

        case 5:
            pred_state = 5;

            if (symbol >= '0' && symbol <= '9') state = 5;

            else if (operations.find(symbol) != string::npos || separators.find(symbol) != string::npos) state = 'S';
            break;

        case 6:
            pred_state = 6;

            if (symbol == '/') state = 7;

            if (symbol == '=') state = 9;
            break;

        case 7:
            pred_state = 7;

            if (symbol != ' ') state = 7;
            else state = 'S';
            break;

        case 9:
            pred_state = 9;

            if (operations.find(symbol) != string::npos) state = 11;
            else state = 'F';
            break;

        case 11:
            pred_state = 11;

            if (operations.find(symbol) != string::npos) state = 'S';
            else state = 'F';
            break;
    }
}

int count_id = 0; //Числовая часть внутреннего представления идентификатра
void Semantic_procedure_1(string buffer, string &identificators, string &result) {
    if (identificators.find(buffer) == std::string::npos) {
        identificators += ' ' + buffer;

        //база идентификаторов
        ofstream f("Identificators.txt");
        f << identificators << endl;
        f.close();

        result += " I" + to_string(count_id++);
        ofstream res("Result.txt"); //файл лексем программы С# во внутреннем представлении
        res << result;
    } else {
        //база идентификаторов представлена строкой, преобразуем её в вектор??


        //Находим номер идентификатора в базе идентификаторов


    }
}

int count_system_word = 0;
void Semantic_procedure_2() {

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

        
        
    }

    

}