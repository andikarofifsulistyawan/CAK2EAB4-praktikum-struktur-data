// NIM: 109082500013
// NAMA: Andika Rofif Sulistyawan

#include <iostream>

int main() {
    float input1 = 0.0;
    float input2 = 0.0;

    std::cout << "Bilangan pertama: ";
    std::cin >> input1;

    std::cout << "Bilangan kedua: ";
    std::cin >> input2;

    std::cout << input1 << " + " << input2 << " = " << input1 + input2 << std::endl;
    std::cout << input1 << " - " << input2 << " = " << input1 - input2 << std::endl;
    std::cout << input1 << " * " << input2 << " = " << input1 * input2 << std::endl;
    if (input2 == 0.0) {
        std::cout << input1 << " / " << input2 << " = tidak terdefinisi" << std::endl;
    } else {
        std::cout << input1 << " / " << input2 << " = " << input1 / input2 << std::endl;
    }

    return 0;
}