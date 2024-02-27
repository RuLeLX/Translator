#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
    Служебные слова W
    Идентификаторы I
    Операции O
    Разделители R
    Константы числовые N
    Константы символьные С
*/

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
    for (int i = 0; i < program_tokens.length(); i++) {
        


       

    }

    

}