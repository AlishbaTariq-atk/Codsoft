#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void show_board(int x_state[], int o_state[]);
int first_turn();
int sum(int a, int b, int c);
int win_check(int x_state[], int o_state[]);

int main() {
    int x_state[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int o_state[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    int turn = first_turn();
    int count =0;

    while(1)
    {
        show_board(x_state, o_state);
        if(turn == 0)
        {
            cout << "O's Turn: " << endl;
            while(1)
            {
                int value;
                cout << "Enter the position you want to mark (0-8): " << endl;
                cin >> value;
                if(x_state[value] == 1 || o_state[value] == 1)
                {
                    cout << "Invalid option! That position is already marked." << endl;
                }
                else 
                {
                    o_state[value] = 1;
                    count += 1;
                    break;
                }
            }

        }
        else
        {
           cout << "X's Turn: " << endl;
            while(1)
            {
                int value;
                cout << "Enter the position you want to mark (0-8): " << endl;
                cin >> value;
                if(x_state[value] == 1 || o_state[value] == 1)
                {
                    cout << "Invalid option! That position is already marked." << endl;
                }
                else 
                {
                    x_state[value] = 1;
                    count += 1;
                    break;
                }

            } 
        }
    
        int winner = win_check(x_state , o_state);
        if(winner == 1)
        {
            cout << "---X Wins!---" << endl;
            break;
        }
        else if(winner == 0)
        {
            cout << "---O Wins!" << endl;
            break;
        }
        else if(count == 9)
        {
            cout << "--- Match Draw!---" << endl;
            break;
        }

        turn = 1 - turn;
    }

    return 0;
}

void show_board(int x_state[], int o_state[]) //display board
{
    system("cls");
    cout << "TIC-TAC-TOE" << endl;
    cout << "------------" << endl;
    
    char cell_values[9];
    for (int i = 0; i < 9; i++) {
        if (x_state[i]) {
            cell_values[i] = 'X';
        } else if (o_state[i]) {
            cell_values[i] = 'O';
        } else {
            cell_values[i] = '0' + i; // Convert index to character
        }
    }

    cout << " " << cell_values[0] << " | " << cell_values[1] << " | " << cell_values[2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << cell_values[3] << " | " << cell_values[4] << " | " << cell_values[5] << endl;
    cout << "---|---|---" << endl;
    cout << " " << cell_values[6] << " | " << cell_values[7] << " | " << cell_values[8] << endl;

}


int first_turn() //first person to take a turn (1 for 'X' and 0 for 'O')
{
    srand(time(0));
    int turn = rand() % 2;
    return turn;
}


int sum(int a, int b, int c) //sum for combination to win for player 
{
    return a + b + c;
}

int win_check(int x_state[], int o_state[]) //function to identify the winner
{
    int win[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 4, 8}, {2, 4, 6}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}};
    for (int i = 0; i < 8; i++) 
    {
        if (sum(x_state[win[i][0]], x_state[win[i][1]], x_state[win[i][2]]) == 3) {
            return 1;
        } else if (sum(o_state[win[i][0]], o_state[win[i][1]], o_state[win[i][2]]) == 3) {
            return 0;
        }
    }
    return -1;
}
