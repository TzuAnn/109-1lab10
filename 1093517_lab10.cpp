#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime> // contains prototype for function time
#include <string>
#include <cmath>
using namespace std ;
enum status {TH, TL, RT} ;
void generatePassWd(string &, int &) ;
void guess(status &, string, int);
int main (){
    srand(time(0));
    int counter = 1 ;
    int counter2 = 0 ;
    status aGuess ;
    string abc ;
    int x ;
    string j ;
    string cde ; 
    generatePassWd(abc ,x);
    cout << abc << endl ;
    cout << x <<endl;
    cout << "1st guess = " ;
    while ( cin >> cde )
    {
        guess(aGuess,cde,x) ;
        if ( aGuess == TL )
        {
            cout << "Too Low" << endl ;
            counter++ ;
        }
        if ( aGuess == TH )
        {
            cout << "too high" << endl ;
            counter++ ;
        }
        if ( aGuess == RT )
        {
            if ( abc > cde )
            {
                cout <<"Too Low"<<endl ;
                counter++ ;
            }
            if ( abc == cde )
            {
                if ( counter == 1 )
                {
                    break ;
                }
                else 
                {
                    counter++ ;
                    break ;
                }
            }
            if ( abc < cde )
            {
                cout << "Too High " << endl ;
                counter++ ;
            }
        }
        if ( counter == 2 )
        {
            cout << counter << "-nd" ;
        }
        else if ( counter == 3 )
        {
            cout << counter << "-rd" ;
        }
        else 
        {
            cout << counter << "-th";
        }
        cout << "guess = " ;
    }
    if ( counter > 1 )
        {   
            counter = counter - 1 ;
        }
        cout << "Bravo, you guess it right !" << endl ;
        if ( counter <= ceil(log2(pow(26,x))))
        {
            cout << "You know the secret" << endl ;
        }
        if ( counter > ceil(log2(pow(26,x))))
        {
            cout << "You should be able to do better." << endl ; 
        }
    counter2 ++ ;
    while ( counter2 != 0 )
    {
        counter = 1 ;
        cout << " play again ? " ;
        cin >> j ;
        if ( j == "y" || j == "yes" )
        {
            srand(time(0));
            generatePassWd(abc ,x);
            cout << abc << endl ;
            cout << x <<endl;
            cout << "1st guess = " ;
                while ( cin >> cde )
                {
                    guess(aGuess,cde,x) ;
                    if ( aGuess == TL )
                    {
                        cout << "Too Low" << endl ;
                        counter++ ;
                    }
                    if ( aGuess == TH )
                    {
                        cout << "too high" << endl ;
                        counter++ ;
                    }
                    if ( aGuess == RT )
                    {
                        if ( abc > cde )
                        {
                            cout <<"Too Low"<<endl ;
                            counter++ ;
                        }
                        if ( abc == cde )
                        {
                            if ( counter == 1 )
                            {   
                                break ;
                            }
                            else 
                            {
                                counter++ ;
                                break ;
                            }
                        }
                        if ( abc < cde )
                        {
                            cout << "Too High " << endl ;
                            counter++ ;
                        }
                    }
                if ( counter == 2 )
                {
                    cout << counter << "-nd" ;
                }
                else if ( counter == 3 )
                {
                    cout << counter << "-rd" ;
                }
                else 
                {
                    cout << counter << "-th";
                }
                cout << "guess = " ;
            }
            cout << "Bravo, you guess it right !" << endl ;
            if ( counter > 1 )
            {   
                counter = counter - 1 ;
            }
            if ( counter <= ceil(log2(pow(26,x))))
            {
                cout << "You know the secret" << endl ;
            }
            if ( counter > ceil(log2(pow(26,x))))
            {
                cout << "You should be able to do better." << endl ; 
            }
            
        }
            else 
            {
                break ;
            }
    }
}
void generatePassWd(string &passWd, int &passLen)
{
    srand(time(0));
    passLen = rand()%4+1;
    if(passLen==1)
    passWd=" ";
    else if(passLen==2)
    passWd="  ";
    else if(passLen==3)
    passWd="   ";
    else
    passWd="    ";
    for (int i=0; i<passLen; i++)
    passWd[i] = 'a' + rand()% 26;
}
void guess(status &aGuess, string str, int a){
    if ( str.length() > a )
    {
        aGuess = TH ;
    }
    if ( str.length() < a )
    {
        aGuess = TL ;
    }
    if ( str.length() == a )
    {
        aGuess = RT ;
    }
}
