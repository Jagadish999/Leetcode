#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

string intToRoman(int num);


int main() {

    int num = 3749;

    string m_int_to_roman = intToRoman(num);

    cout << m_int_to_roman << endl;

    return 0;
}

string intToRoman(int num) {
    string str_roman_signs[] = {"M", "CM", "D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

    string m_roman_str = "";

    int m_size = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < m_size; i++) {
        while (num >= values[i]) {
            num -= values[i];
            m_roman_str += str_roman_signs[i];
        }
    }

    return m_roman_str;
};
