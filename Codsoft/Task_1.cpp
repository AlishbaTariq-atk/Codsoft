#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    int num = rand() % 11;
    int guess;
    cout << "\n---Number Guessing Game---\n\nEnter a guess between 0 and 10: " << endl;
    cin >> guess;
    if(guess == num)
    {
        cout << "WElldone ! its a correct guess. The original number was "<< num << endl;
    }
    else if(guess > num )
    {
        cout << "Guess is Higher than the original number.\nThe orginal number was "<< num << "\nBetter luck next time!" << endl;
    }
    else
    {
        cout << "Guess is lower than the original number.\nThe orginal number was "<< num << "\nBetter luck next time!" << endl;
    }


    return 0;
}