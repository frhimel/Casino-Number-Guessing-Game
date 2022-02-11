#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;
void rules();


void smiley()
{
    cout<<"Congratulations!!"<<endl;
    cout<<endl;

    int w=8;

    for(int g=0;g<2;g++)
    {
        cout<<"   @";    // Displaying
    }
    cout<<endl; // endl is for new line
    cout<<endl;
    for(int a=1;a<=2;a++)
    {

        for(int b=0;b<a;b++)
        {
            cout<<" ";    // displaying space here
        }
        cout<<"*";


        for(int c=1;c<w;c++)
        {
            cout<<" ";
        }
        cout<<" *"<<endl;
        w=w-2;
    }

    for(int e=1;e<=1;e++)
    {

        for(int f=4;f>=e;f--)
        {
            cout<<" ";
        }
        cout<<" **";
    }

}



int main()
{
    string playerName;
    int balance; // stores player's balance
    int bettingAmount;
    int guess;
    int dice; // stores the random number
    int life=7;
    char choice;
    srand(time(0)); // "Seed" the random generator
    cout << "\n\t\t========WELCOME TO CASINO WORLD=======\n\n";
    cout << "\n\nWhat's your Name : ";
    getline(cin, playerName);
    cout << "\n\nEnter the starting balance to play game : $";
    cin >> balance;
    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current balance is $ " << balance << "\n";
// Get player's betting balance
        do
        {
            cout << "Hey, " << playerName<<", enter amount to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > balance)
                cout << "Betting balance can't be more than current balance!\n"
                     <<"\nRe-enter balance\n ";
        }while(bettingAmount > balance);
// Get player's numbers

        do
        {
            cout<< "\nHard Level: Casino Number Guessing";
            cout << "\nGuess any betting number between 1 & 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "\nNumber should be between 1 to 10\n"
                     <<"Re-enter number:\n ";
        }while(guess <= 0 || guess > 10);
        dice = rand()%10 + 1;
        if(dice == guess)
        {
            smiley();
            cout << "\n\nYou are in luck!! You have won Rs." << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
            cout<< "\n\nYou won 3 more lifes!!";
            life=life+3;
            printf("\n\nYou have now total %d lifes", life);
        }
        else

        {
            cout << "\n\nOops, better luck next time !! You lost $ "<< bettingAmount <<"\n";
            balance = balance - bettingAmount;
            cout << "\nThe winning number was : " << dice <<"\n";
            //cnt=cnt++;

            if(life>=1){
                life=life-1;
                printf("\n\nYou have %d lifes left", life);

            }
           /* if(life == 0)
            {
                cout << "\n\nBetter luck next time!";
                break;
            }
            */

        }

        while(life<=3){
            cout<<"\n\n Easier Level: Casino Number Guessing";
            do
            {
                cout << "\n\n Guess any betting number between 1 & 5 :";
                cin >> guess;
                if(guess <= 0 || guess > 5)
                    cout << "\nNumber should be between 1 to 5\n"
                         <<"Re-enter number:\n ";
            }while(guess <= 0 || guess > 5);
            dice = rand()%5 + 1;
            if(dice == guess)
            {
                smiley();
                cout << "\n\nYou are in luck!! You have won Rs." << bettingAmount * 5;
                balance = balance + bettingAmount * 5;
                cout<< "\n\nYou won 2 more lifes!!";
                life=life+2;
                printf("\n\nYou have now total %d lifes", life);
            }
            else

            {
                cout << "\n\nOops, better luck next time !! You lost $ "<< bettingAmount <<"\n";
                balance = balance - bettingAmount;
                cout << "\nThe winning number was : " << dice <<"\n";

                if(life>=1){
                    life=life-1;
                    printf("\n\nYou have %d lifes left", life);
                    ///////////

                    if(life == 0)
                    {
                        cout << "\n\nBetter luck next time!";
                        break;
                    }


                    cout << "\n\n"<<playerName<<", \n\nYou have balance of $ " << balance << "\n";
                    if(balance == 0)
                    {
                        cout << "You have no money to play ";
                        break;
                    }

                }
            }
        }



        if(life == 0)
        {
            //cout << "\n\nBetter luck next time!";
            break;
        }


        cout << "\n\n"<<playerName<<", \n\nYou have balance of $ " << balance << "\n";
        if(balance == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";
    return 0;
}

void rules()
{
    system("cls");
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number\n";
    cout << "\t2. Hard Level: Winner gets 10 times of the money bet & 3 bonus life\n";
    cout << "\t3. You can only exit the game from Hard Level\n";
    cout << "\t4. Easier Level: Winner gets 5 times of the money bet & 2 bonus life\n";
    cout << "\t5. Wrong bet, and you lose the amount you bet\n\n";
}