#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "---Mini Calculator---" << endl;

    float num1, num2; //two variables for the user to enter values
    int option; //variable for the operation to be choosed by user
    
    while(option!= 5) //loop till the user dont want to use the calculator further
    {
        cout << "--operations: " << endl
             << "1. Sum (+)" << endl
             << "2. Subrtract (-)" << endl
             << "3. Multiplication (*)" << endl
             << "4. Division (/)" << endl
             << "5. Exit " << endl
             << "  \nOption:" ;
        cin >> option;


        switch(option) //applying the operation user choosed on the numbers
        {
            case 1:
            {
                
                cout << "\nEnter  first number: " << endl; //asking for values in each case separately for better user interface.
                cin >> num1;
                cout << "Enter second number: " << endl;
                cin >> num2;

                cout << "Num_1= " << num1 << "\nNum_2= " << num2 << endl;
                cout << "Sum= " << setprecision(3) << num1 + num2 << endl;
                break; 
            }
            case 2:
            {
                
                cout << "\nEnter  first number: " << endl;
                cin >> num1;
                cout << "Enter second number: " << endl;
                cin >> num2;

                cout << "Num_1= " << num1 << "\nNum_2= " << num2 << endl;
                cout << "Subtraction= " << setprecision(3) << num1 - num2 << endl;
                break; 
            }
            case 3:
            {
                cout << "\nEnter  first number: " << endl;
                cin >> num1;
                cout << "Enter second number: " << endl;
                cin >> num2;

                cout << "Num_1= " << num1 << "\nNum_2= " << num2 << endl;
                cout << "Multiplication= " << setprecision(3) << num1 * num2 << endl;
                break; 
            }
            case 4:
            {
                cout << "\nEnter  first number: " << endl;
                cin >> num1;
                cout << "Enter second number: " << endl;
                cin >> num2;

                cout << "Num_1= " << num1 << "\nNum_2= " << num2 << endl;
                cout << "Division= " << setprecision(3) << num1 / num2 << endl;
                break; 
            }
            case 5:
            {
                cout << "Thankyou for using our services!" << endl;
                break;
            }
                
            default:
                cout << "\nInvalid option!Kinldy enter a valid option\n" << endl;
                break;

        }   
    }


    return 0;
}
