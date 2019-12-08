#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream inFile;
    inFile.open("input");

    if (!inFile)
        std::cout << "Unable to read file" << std::endl;

    uint mostZeros = 200;
    uint counter = 0;
    uint layerNumber = 0;
    char input;
    std::vector<std::vector<int>> inputNumbers;
    std::vector<int> currNumbers(3);
    currNumbers  = {0,0,0};
    bool firstIt = true;
    while (inFile >> input) {
        if (counter % 150 == 0 && !firstIt) {
            if (layerNumber != 0) {
                if (currNumbers.at(0) < inputNumbers.at(mostZeros).at(0)) {
                    mostZeros = layerNumber;
                }
            }
            else {
                mostZeros = layerNumber;
            }
            inputNumbers.push_back(currNumbers);
            currNumbers = {0,0,0};
            counter = 0;
            layerNumber++;
        }
        int value = input - '0';
        firstIt = false;
        if (value == 0) {
            currNumbers.at(0)++;
        }
        else if (value == 1) {
            currNumbers.at(1)++;
        }
        else if (value == 2) {
            currNumbers.at(2)++;
        }
        else {
            std::cout << "invalid input: " << input << std::endl;
            exit(1);
        }

        counter++;
    }
    std::cout << "end of thingy\n";
    if (currNumbers.at(0) < inputNumbers.at(mostZeros).at(0)) {
        mostZeros = layerNumber;
    }
    inputNumbers.push_back(currNumbers);
    currNumbers[0] = 0;
    currNumbers[1] = 0;
    currNumbers[2] = 0;
    counter = 0;
    layerNumber++;
    inFile.close();

    std::cout << "ones: " << inputNumbers.at(mostZeros).at(1) << " twos: " << inputNumbers.at(mostZeros).at(2) << std::endl;
    std::cout << "answer: " << inputNumbers.at(mostZeros).at(1)*inputNumbers.at(mostZeros).at(2) << std::endl;
}
