#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void ex2() {
    string input;
    cout << "Enter a string: ";
    // getline(std::cin, input);

    input = "a 235.5 fja3 joi 87 1.0p\n";
    cout << input;

    int numStart, numLen;

    int i = 0;
    while (i < input.length()) {
        if (isdigit(input[i])) {
            // we found a 1st digit!
            numStart = i;

            // figuring out the length
            int j = 0;
            while (i + j < input.length() && (isdigit(input[i + j]) || input[i + j] == '.')) {
                j++;
            }
            numLen = j;

            string numStr = input.substr(numStart, numLen);

            std::istringstream iss(numStr);
            double number;
            if (iss >> number) {
                std::cout << "Found number: " << number << std::endl;
            }

            // we jump over the number we just collected
            i += numLen;
        } else {
            // or we just go up by 1 if there was no number
            i++;
        }
    }
}

int main() {
    string input = "aa ba";
    int len;

    int end = input.length() - 1;
    int start = input.length() - 1;

    int i = input.length() - 1;
    while (i >= 0) {

        if (input.at(i) == ' ' || i == 0) {
            start = i + 1;  // start is now at 'd'
            len = end - start + 1;

            cout << "word: (" << start << ", " << end << ") with length = " << len << endl;

            end = i - 1;  // end is now at ' '
        }

        i--;
    }

    return 0;
}
