#include <iostream>
#include <windows.h>
#include <ctime>


using namespace std;
char** fieldCreate() {
    int const n = 3;
    char** field = new char* [n];
    for (int i = 0; i < n; i++) {
        field[i] = new char[n];
        field[i][0] = '_';
        field[i][1] = '_';
        field[i][2] = '_';

    }
    return field;
}
void defoultMassive(char** field) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            field[i][j] = '_';
        }
    }
}
void output(char** field) {                  
    cout << "     1   2   3" << endl;
    cout << "    ___________" << endl;
    cout << "   |   |   |   |" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " " << " | ";
        for (int j = 0; j < 3; j++) {
            cout << field[i][j] << " | ";

        }
        cout << endl;
        cout << "   |___|___|___|" << endl;
        if (i < 2) {
            cout << "   |   |   |   |" << endl;
        }



    }
    cout << endl;

}
void input(char** field) {
    int answer;
    while (true) {

        cout << "  You play X " << endl << "  Enter the row and column number : ";


        cin >> answer;
        if (answer > 10 && answer < 34) {
            int i = answer / 10;
            int j = answer % 10;
            if (0 < j && j < 4) {
                if (field[i - 1][j - 1] != 'X' && field[i - 1][j - 1] != 'O') {
                    field[i - 1][j - 1] = 'X';
                    break;
                }
            }
        }
        cout << "You entered the wrong cell" << endl;
    }
}
void randomPlayer(string& Name1, string& Name2) {
    srand(time(NULL));
    int number = rand() % 2;
    cout << "Enter the name of the first player: ";
    cin >> Name1;
    cout << "Enter the name of the second player: ";
    cin >> Name2;
    if (number) {
        string tmp = Name1;
        Name1 = Name2;
        Name2 = tmp;
    }
}
void input(char** field, bool& gamer, string& Name1, string& Name2) {
    int move;
    while (true) {
        if (gamer) {
            cout << Name1;
        }
        else {
            cout << Name2;
        }
        cout << ", enter the row and column number: ";


        cin >> move;
        if (move > 10 && move < 34) {
            int i = move / 10;
            int j = move % 10;
            if (0 < j && j < 4) {
                if (field[i - 1][j - 1] != 'X' && field[i - 1][j - 1] != 'O') {
                    if (gamer) {
                        field[i - 1][j - 1] = 'X';
                    }
                    else {
                        field[i - 1][j - 1] = 'O';
                    }
                    gamer = !gamer;
                    break;
                }
            }
        }
        cout << "You entered the wrong cell" << endl;
    }
}
bool inputBot(char** field)    
{
        if (field[1][1] != 'X' && field[1][1] != 'O')  
        {
            field[1][1] = 'O';
            return true;
        }



        for (int i = 0; i < 3; i++)
        {
            if ((field[i][0] == 'O') && (field[i][1] == 'O')) //checks the  row for his win
            {
                if (field[i][2] != 'X' && field[i][2] != 'O')
                {
                    field[i][2] = 'O';
                    return true;
                }
            }
            if ((field[0][i] == 'O') && (field[2][i] == 'O')) //checks the column for his win
            {
                if (field[1][i] != 'X' && field[1][i] != 'O')
                {
                    field[1][i] = 'O';
                    return true;
                }
            }
            if ((field[i][1] == 'O') && (field[i][2] == 'O')) //checks the column for his win
            {
                if (field[i][0] != 'X' && field[i][0] != 'O')
                {
                    field[i][0] = 'O';
                    return true;
                }
            }
            if ((field[i][0] == 'O') && (field[i][2] == 'O')) //checks the row for his win
            {
                if (field[i][1] != 'X' && field[i][1] != 'O')
                {
                    field[i][1] = 'O';
                    return true;
                }
            }
            if ((field[0][i] == 'O') && (field[1][i] == 'O'))//checks the column for his win
            {
                if (field[2][i] != 'X' && field[2][i] != 'O')
                {
                    field[2][i] = 'O';
                    return true;
                }
            }
            if ((field[1][i] == 'O') && (field[2][i] == 'O')) //checks the row for his win
            {
                if (field[0][i] != 'X' && field[0][i] != 'O')
                {
                    field[0][i] = 'O';
                    return true;
                }
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if ((field[i][0] == 'X') && (field[i][1] == 'X')) //checks the row for a player's victory
            {
                if (field[i][2] != 'X' && field[i][2] != 'O')
                {
                    field[i][2] = 'O';
                    return true;
                }
            }
            if ((field[i][1] == 'X') && (field[i][2] == 'X'))//checks the row for a player's victory
            {
                if (field[i][0] != 'X' && field[i][0] != 'O')
                {
                    field[i][0] = 'O';
                    return true;
                }
            }
            if ((field[i][0] == 'X') && (field[i][2] == 'X')) //checks the row for a player's victory
            {
                if (field[i][1] != 'X' && field[i][1] != 'O')
                {
                    field[i][1] = 'O';
                    return true;
                }
            }
            if ((field[0][i] == 'X') && (field[1][i] == 'X')) //checks the column for a player's victory
            {
                if (field[2][i] != 'X' && field[2][i] != 'O')
                {
                    field[2][i] = 'O';
                    return true;
                }
            }
            if ((field[1][i] == 'X') && (field[2][i] == 'X')) //checks the column for a player's victory
            {
                if (field[0][i] != 'X' && field[0][i] != 'O')
                {
                    field[0][i] = 'O';
                    return true;
                }
            }
            if ((field[0][i] == 'X') && (field[2][i] == 'X')) //checks the column for a player's victory
            {
                if (field[1][i] != 'X' && field[1][i] != 'O')
                {
                    field[1][i] = 'O';
                    return true;
                }
            }
        }


       
        if ((field[0][0] == 'O') && (field[1][1] == 'O')) //checks the diagonal for his win
        {
            if (field[2][2] != 'X' && field[2][2] != 'O')
            {
                field[2][2] = 'O';
                return true;
            }
        }
        if ((field[2][0] == 'O') && (field[1][1] == 'O')) //checks the diagonal for his win
        {
            if (field[0][2] != 'X' && field[0][2] != 'O')
            {
                field[0][2] = 'O';
                return true;
            }
        }
        if ((field[0][2] == 'O') && (field[2][0] == 'O'))//checks the diagonal for his win
        {
            if (field[1][1] != 'X' && field[1][1] != 'O')
            {
                field[1][1] = 'O';
                return true;
            }
        }
        if ((field[0][2] == 'O') && (field[1][1] == 'O')) //checks the diagonal for his win
        {
            if (field[2][0] != 'X' && field[2][0] != 'O')
            {
                field[2][0] = 'O';
                return true;
            }
        }
        if ((field[1][1] == 'O') && (field[2][2] == 'O'))//checks the diagonal for his win
        {
            if (field[0][0] != 'X' && field[0][0] != 'O')
            {
                field[0][0] = 'O';
                return true;
            }
        }
        if ((field[0][0] == 'O') && (field[2][2] == 'O'))//checks the diagonal for his win
        {
            if (field[1][1] != 'X' && field[1][1] != 'O')
            {
                field[1][1] = 'O';
                return true;
            }
        }
        if ((field[0][0] == 'X') && (field[1][1] == 'X')) //checks the diagonal for a player's victory
        {
            if (field[2][2] != 'X' && field[2][2] != 'O')
            {
                field[2][2] = 'O';
                return true;
            }
        }
        if ((field[0][0] == 'X') && (field[2][2] == 'X')) //checks the diagonal for a player's victory
        {
            if (field[1][1] != 'X' && field[1][1] != 'O')
            {
                field[1][1] = 'O';
                return true;
            }
        }
        if ((field[1][1] == 'X') && (field[2][2] == 'X')) //checks the diagonal for a player's victory
        {
            if (field[0][0] != 'X' && field[0][0] != 'O')
            {
                field[0][0] = 'O';
                return true;
            }
        }
        if ((field[0][2] == 'X') && (field[1][1] == 'X')) //checks the diagonal for a player's victory
        {
            if (field[2][0] != 'X' && field[2][0] != 'O')
            {
                field[2][0] = 'O';
                return true;
            }
        }
        if ((field[0][2] == 'X') && (field[2][0] == 'X')) //checks the diagonal for a player's victory
        {
            if (field[1][1] != 'X' && field[1][1] != 'O')
            {
                field[1][1] = 'O';
                return true;
            }
        }
        if ((field[2][0] == 'X') && (field[1][1] == 'X')) //checks the diagonal for a player's victory
        {
            if (field[0][2] != 'X' && field[0][2] != 'O')
            {
                field[0][2] = 'O';
                return true;
            }
        }
        int n = 0, m = 0;  
        srand(time(NULL));
        bool val = true;
        while (val) {
            n = rand() % 3;
            m = rand() % 3;
            if (field[n][m] != 'X' && field[n][m] != 'O') {
                field[n][m] = 'O';
                val = false;
            }
        }
    }
bool chekWin(char** field, string& Name1, string& Name2) {    //check for victory when playing for two
    bool chekWin = false, player = false;
    int row = 0;
    int col = 0;
    int diag1 = 0;
    int diag2 = 0;
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            if (field[i][j] == 'X')
                row++;

            if (field[j][i] == 'X')
                col++;

            if (field[j][j] == 'X')
                diag1++;

            if (field[2 - j][j] == 'X')
                diag2++;

        }
        if (row == 3 || col == 3 || diag1 == 3 || diag2 == 3) {
           
            player = true;
            chekWin = true;
           
        }
        row = 0;
        col = 0;
        diag1 = 0;
        diag2 = 0;
    }
    
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            if (field[i][j] == 'O')
                row++;

            if (field[j][i] == 'O')
                col++;

            if (field[j][j] == 'O')
                diag1++;

            if (field[2 - j][j] == 'O')
                diag2++;

        }
        if (row == 3 || col == 3 || diag1 == 3 || diag2 == 3) {

            chekWin = true;
            
        }
        row = 0;
        col = 0;
        diag1 = 0;
        diag2 = 0;
    }

    if (chekWin) {
        if (player) {
            cout << Name1 << " won! " << endl;
        }
        else {
            cout << Name2 << " won!" << endl;
        }
        return true;
    }
    else {
        bool draw = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (field[i][j] != 'X' && field[i][j] != 'O') {
                    draw = false;
                }
            }
        }

        if (draw) {
            cout << "draw" << endl;
            return true;
        }
    }
    
    return false;
}
bool chekWinbot(char** field) {
    bool chekWinbot = false, participant = false;
    int row = 0;
    int col = 0;
    int diag1 = 0;
    int diag2 = 0;
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            if (field[i][j] == 'X')
                row++;

            if (field[j][i] == 'X')
                col++;

            if (field[j][j] == 'X')
                diag1++;

            if (field[2 - j][j] == 'X')
                diag2++;

        }
        if (row == 3 || col == 3 || diag1 == 3 || diag2 == 3) {

            participant = true;
            chekWinbot = true;

        }
        row = 0;
        col = 0;
        diag1 = 0;
        diag2 = 0;
    }

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            if (field[i][j] == 'O')
                row++;

            if (field[j][i] == 'O')
                col++;

            if (field[j][j] == 'O')
                diag1++;

            if (field[2 - j][j] == 'O')
                diag2++;

        }
        if (row == 3 || col == 3 || diag1 == 3 || diag2 == 3) {

            chekWinbot = true;

        }
        row = 0;
        col = 0;
        diag1 = 0;
        diag2 = 0;
    }


    if (chekWinbot) {
        if (participant) {
            cout << "You won!" << endl;
        }
        else {
            cout << "You lost!" << endl;
        }
        return true;
    }
   
    else {
        bool draw = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (field[i][j] != 'X' && field[i][j] != 'O') {
                    draw = false;
                }
            }
        }

        if (draw) {
            cout << "draw" << endl;
            return true;
        }
    }

    return false;
}
bool continueGame() {
    bool chekWin = false, gamer = false;
    bool flag = true;
    while (true) {
        int choice;
       
        cout << "Do you want to continue the game? " << endl << "Enter 1 if yes " << endl;
        cout << "Enter 2 if you want to end the game ";
        cin >> choice;
        system("Cls");
        switch (choice)
        {
        case 1:
            break;
        case 2:
            flag = false;
            break;

        default:
            cout << "There is no such answer!";

        }
        return flag;
    }

}
void deleteMassive(char** field) {
    for (int i = 0; i < 3; i++) {
        delete[] field[i];
    }
    delete[] field;
}
int main() {

    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD crd = { 45, 20 };
    SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
    SetConsoleWindowInfo(out_handle, true, &src);
    SetConsoleScreenBufferSize(out_handle, crd);


    char** field = fieldCreate();
    
    while (true) {
        int value = 0;
        cout << "Welcome to the game\n" << endl;
        cout << "Enter 1 for single play \n";
        cout << "Enter 2 to play for two \n";
        cin >> value;

            if (value == 1) {
               
                while (true) {
                    defoultMassive(field);
                    while (true) {
                        system("Cls");
                        output(field);
                        if (chekWinbot(field)) {
                            break;
                        }
                        input(field);
                        system("Cls");
                        output(field);
                        if (chekWinbot(field)) {
                            break;
                        }
                        inputBot(field);
                    }
                    break;
                }
                
            }
            if (value == 2) {
                bool gamer = true;
                string Name1, Name2;
                randomPlayer(Name1, Name2);
                while (true) {
                    defoultMassive(field);
                    while (true) {
                        system("Cls");
                        output(field);
                        if (chekWin(field, Name1, Name2))
                            break;
                        input(field, gamer, Name1, Name2);

                    }

                    break;
                }

               
            }
                        
          

            if (!continueGame()) {
                break;
                system("Cls");
            }

           

        }

  

        deleteMassive(field);
        return 0;
    }

