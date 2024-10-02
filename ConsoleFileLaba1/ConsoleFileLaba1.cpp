#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <locale>
#include <iomanip> // все ради quoted
//#include "func_1.cpp"

using namespace std;

void create_file(string input_, string primer_) {

    ofstream fout(input_);

    fout << primer_ << endl;

    fout.close();

    cout << "Создан файл " << input_ << " c примером: " << primer_ << endl;


}

void OpenFunc() {

    //system("g++ -c ConsoleFileLaba1.cpp");
    //system("g++ func_1.cpp -o func_1 -mconsole");
    //system("g++ ConsoleFileLaba1.o func_1.o -o s.exe");
    //system("s.exe");
}

void f(string primer_) {
    stringstream ss(primer_);
    char op;
    double num1, num2, result;
    ss >> num1;
    while (ss >> op >> num2) {
        switch (op) {
        case '+': num1 += num2; break;
        case '-': num1 -= num2; break;
        case '*': num1 *= num2; break;
        case '/': num1 /= num2; break;
        default: cout << "Неизвестная операция: " << op << endl;
        }
    }
    cout << "Ответ: " << num1 << endl;
}


void create_file_code(string name_, string primer_, string type_) {


        ofstream fout(name_);

        fout << "#include <iostream>" << endl;
        fout << "#include <sstream>" << endl;
        fout << "#include <string>" << endl;
        fout << "using namespace std;" << endl;
        fout << "int f() {" << endl;
        fout << "    stringstream ss(" << std::quoted(primer_) << "); " << endl;
        fout << "    char op;" << endl;
        fout << "    " << type_ << " num1, num2, result;" << endl;
        fout << "    ss >> num1;" << endl;
        fout << "    while (ss >> op >> num2) {" << endl;
        fout << "        switch (op) {" << endl;
        fout << "            case '+': num1 += num2; break;" << endl;
        fout << "            case '-': num1 -= num2; break;" << endl;
        fout << "            case '*': num1 *= num2; break;" << endl;
        fout << "            case '/': num1 /= num2; break;" << endl;
        fout << "            default: cout << \"Неизвестная операция: \" << op << endl;" << endl;
        fout << "        }" << endl;
        fout << "    }" << endl;
        fout << "    cout << \"Ответ: \" << num1 << endl;" << endl;
        fout << "}" << endl;

        fout.close();

}

void create_file_code_my(string input_) {
    ofstream fout(input_);

    string input1_;
    cout << "Введите строку (напишите '@end' для завершения): " << endl;
    while (true) {
        getline(cin, input1_);
        if (input1_ == "@end") {
            break;
        }
        fout << input1_ << endl;
    }

    fout.close();
}



void StateOpen(string input) {
    ifstream file(input);
    string firstLine;

    if (file.good()) {
        getline(file, firstLine);
        cout << "Пример: " << firstLine << endl;
        file.close();
        f(firstLine);
        OpenFunc();
        //double result = f(firstLine);
        //cout << "Ответ: " << result << endl;
    }
    else {
        cout << "Файл не существует." << endl;
    }
}



int main() {
        std::locale::global(std::locale("rus"));
        std::cout.imbue(std::locale());

        string input, primer, type;

        int state = 0;
        cout << "================" << endl;
        cout << "Создать файл-пример \t\t\t(1);" << endl;
        cout << "Прочитать файл-пример\t\t\t(2);" << endl;
        cout << "Решить пример\t\t\t\t(3);" << endl;
        cout << "Создать файл-код для решения примера\t(4);" << endl;
        cout << "Создать собственный файл-код\t\t(5);" << endl;
        cout << "================" << endl;
        cout << "return 0\t\t\t\t(-1);" << endl;
        cout << "================" << endl;
        cout << "Введите число: ";
        getline(cin, input); // Используем getline для считывания всей строки
        state = std::stoi(input);


        while (state > 0) {
            switch (state) {
            case 1:
                cout << "Введите название файла (Например, File.txt): " << endl;
                getline(cin, input);
                cout << "Введите пример (Например, 12 + 34 * 2): " << endl;
                getline(cin, primer);
                create_file(input, primer);

                state = 0;
                break;
            case 2:
                cout << "Введите название файла (Например, File.txt):" << endl;
                getline(cin, input);
                StateOpen(input);

                state = 0;
                break;
            case 3:
                cout << "Введите пример (Например, 12 + 34 * 2):" << endl;
                getline(cin, input);
                f(input);

                state = 0;
                break;
            case 4:
                cout << "Введите название файла (Например, File.txt): " << endl;
                getline(cin, input);
                cout << "Введите тип переменной (Например, double): " << endl;
                getline(cin, type);
                cout << "Введите пример (Например, 12 + 34 * 2): " << endl;
                getline(cin, primer);
                create_file_code(input, primer, type);

                state = 0;
                break;
            case 5:
                cout << "Введите название файла (Например, File.txt): " << endl;
                getline(cin, input);
                create_file_code_my(input);

                state = 0;
                break;
            }
        }
        return 0;

}

