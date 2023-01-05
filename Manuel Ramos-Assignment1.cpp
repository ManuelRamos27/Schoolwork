#include <iostream>
#include <iomanip> // for std::fixed and std::setprecision

int main()
{
    float Number;
    float AreaSquare1, AreaSquare2, AreaSquare3;

    // Output a message asking the user to enter a number
    std::cout << "Enter a number: ";

    // Input a value from the user into the Number variable
    std::cin >> Number;

    // Compute the area of the square with side Number and store the result in AreaSquare1
    AreaSquare1 = Number * Number;

    // Compute the area of the square with side 2*Number and store the result in AreaSquare2
    AreaSquare2 = 2 * Number * 2 * Number;

    // Compute the area of the square with side 3*Number and store the result in AreaSquare3
    AreaSquare3 = 3 * Number * 3 * Number;

    // Output the message "The areas of the squares for different numbers (where Number is Number) are: "
    std::cout << "The areas of the squares for different numbers (where Number is " << Number << ") are:" << std::endl;

    // Output the data from the table in a formatted manner
    std::cout << "Number:  " << std::fixed << std::setprecision(2) << Number << std::endl;
    std::cout << "Area of square with side length " << Number << ": " << std::fixed << std::setprecision(2) << AreaSquare1 << std::endl;
    std::cout << "Area of square with side length " << 2 * Number << ": " << std::fixed << std::setprecision(2) << AreaSquare2 << std::endl;
    std::cout << "Area of square with side length " << 3 * Number << ": " << std::fixed << std::setprecision(2) << AreaSquare3 << std::endl;

    return 0;
}
