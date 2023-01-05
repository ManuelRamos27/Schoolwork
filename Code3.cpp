//
// Created by Manuel Ramos on 1/4/23.
//
#include <iostream>
#include <fstream>
#include <string>

const int MAX_CONCEPTS = 100;

void ReadConcepts(std::string ArrayConcepts[], int& NumberConcepts) {
    std::ifstream list("LIST.txt");
    std::string concept;
    while (std::getline(list, concept)) {
        ArrayConcepts[NumberConcepts++] = concept;
    }
}

void PrintAllConcepts(const std::string ArrayConcepts[], int NumberConcepts) {
    std::cout << "The concepts are: " << std::endl;
    for (int i = 0; i < NumberConcepts; i++) {
        std::cout << ArrayConcepts[i] << std::endl;
    }
}

std::string EnterWord() {
    std::string word;
    while (true) {
        std::cout << "Enter a string with at least 2 characters: ";
        std::cin >> word;
        if (word.length() >= 2) {
            return word;
        }
        std::cout << "Invalid input. Please try again." << std::endl;
    }
}

void PrintConceptsWord(const std::string ArrayConcepts[], int NumberConcepts, const std::string& Word) {
    std::cout << "The concepts containing " << Word << " are: " << std::endl;
    for (int i = 0; i < NumberConcepts; i++) {
        if (ArrayConcepts[i].find(Word) != std::string::npos) {
            std::cout << ArrayConcepts[i] << std::endl;
        }
    }
}

void PrintConceptsWithoutWord(const std::string ArrayConcepts[], int NumberConcepts, const std::string& Word) {
    std::cout << "The concepts that do not contain " << Word << " are: " << std::endl;
    for (int i = 0; i < NumberConcepts; i++) {
        if (ArrayConcepts[i].find(Word) == std::string::npos) {
            std::cout << ArrayConcepts[i] << std::endl;
        }
    }
}

void SortConcepts(std::string ArrayConcepts[], int NumberConcepts) {
    for (int i = 0; i < NumberConcepts - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < NumberConcepts; j++) {
            if (ArrayConcepts[j] < ArrayConcepts[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(ArrayConcepts[i], ArrayConcepts[minIndex]);
    }
}

int main() {
    std::string ArrayConcepts[MAX_CONCEPTS];
    int NumberConcepts = 0;
    ReadConcepts(ArrayConcepts, NumberConcepts);
    PrintAllConcepts(ArrayConcepts, NumberConcepts);
    std::string Word = EnterWord();
    PrintConceptsWord(ArrayConcepts, NumberConcepts, Word);
    PrintConceptsWithoutWord(ArrayConcepts, NumberConcepts, Word);
    SortConcepts(ArrayConcepts, NumberConcepts);
    PrintAllConcepts(ArrayConcepts, NumberConcepts);
    return 0;
}
