#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

float x, y, z;

bool UserInput(string input) {
    if (input.empty()) return false;
    try {
        int number = stoi(input);
        if (number < 0) return false;
    }
    catch (...) {
        return false;
    }
    return true;
}

void enterNumber(int& varLink, string label) {
    string str_input;
    cout << label << " = ";
    getline(cin, str_input);
    while (!UserInput(str_input)) {
        cout << label << " = ";
        getline(cin, str_input);
    }
    varLink = stoi(str_input);
}

void enterX() 
{
 //branch1_enterx
}

void enterY() 
{
 //branch2_entery
}

void enterZ() 
{
 //branch3_enterz
}

int IntSumm(float x, float y, float z) //branch4_IntSumm
{
    int sum = x + y + z;
    cout << "Int summ: " << sum << endl;
}

float FractPart(float x, float y, float z) //branch5_FractPart
{
    float xyz = x * y * z;
    float geo_mean1 = pow(xyz, 1/3);
    int geo_mean2 = pow(xyz, 1/3);
    float fractpart = geo_mean1 - geo_mean2;
    cout << "FractPart: " << fractpart << endl;
}

struct MenuItem {
    string title;
    function<void()> action;
    };
int main() 
{
    map<int, MenuItem> menu = {
        {1, {"Enter x: ", enterX}},
        {2, {"Enter y: ", enterY}},
        {3, {"Enter z: ", enterZ}},
        {4, {"IntSumm: ", IntSumm}},
        {5, {"FractPart: ", FractPart}},
    };

    int choice = 0;

    while (true) 
    {
        cout << "Меню:" << endl;
        for (const auto& item : menu) 
        {
            cout << "Task " << item.first << ". " << item.second.title << endl;
        }
        cout << "0. выход" << endl;
        enterNumber(choice, "Input number of menu: ");

        if (choice == 0) 
        {
            cout << "@ 2025 Kazachkova Taya" << endl;
            break;
        }
        cout << endl;
        if (menu.find(choice) != menu.end()) 
        {
            menu[choice].action();
        } else 
        {
            cout << "Некорректный ввод." << endl;
        }
        cout << endl;
    }
    return 0;
}
