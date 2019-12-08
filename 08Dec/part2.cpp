#include <iostream>
#include <fstream>
#include <vector>
#include <array>

const int MAXCOLS = 25;

int main()
{
    std::ifstream inFile;
    inFile.open("input");

    if (!inFile)
        std::cout << "Unable to read file" << std::endl;

    uint counter = 0;
    uint row = 0;
    uint column = 0;

    char input;
    std::array<int, 25*6> inputImage;
    inputImage.fill(-1);
    while (inFile >> input) {
        int idx = row * MAXCOLS + column;
        if (idx % 150 == 0) {
            row = 0;
            column = 0;
        }
        if (column == 25) {
            column = 0;
            row++;
        }
        idx = row * MAXCOLS + column;
        int value = input - '0';
        if (value == 0) {
            if (inputImage[idx] == -1)
                inputImage[idx] = 0;
        }
        else if (value == 1) {
            if (inputImage[idx] == -1)
                inputImage[idx] = 1;
        }

        counter++;
        column++;
    }
    std::cout << "end of thingy\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 25; j++) {
            int idx  = i * MAXCOLS + j;
            if (inputImage[idx] == 0)
                std::cout << ".";
            else
                std::cout << "#";
        }
        std::cout << std::endl;
    }
}
