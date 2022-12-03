#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER '\r'
using namespace std;

void homeState0()
{
    cout<<endl;
    cout<<endl;
    cout<<"                                                         ______                      ___ "<<endl;
    cout<<"                                                         |  ___|                    /   |"<<endl;
    cout<<"                                                         | |_ ___  _ __ ______ _   / /| |"<<endl;
    cout<<"                                                         |  _/ _ \\| '__|_  / _` | / /_| |"<<endl;
    cout<<"                                                         | || (_) | |   / / (_| | \\___  |"<<endl;
    cout<<"                                                         \\_| \\___/|_|  /___\\__,_|     |_/"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                                              Gioca <==                                        Esci"<<endl;
    cout<<"                                              Statistiche                                      Opzioni"<<endl;
}

void homeState1()
{
    cout<<endl;
    cout<<endl;
    cout<<"                                                         ______                      ___ "<<endl;
    cout<<"                                                         |  ___|                    /   |"<<endl;
    cout<<"                                                         | |_ ___  _ __ ______ _   / /| |"<<endl;
    cout<<"                                                         |  _/ _ \\| '__|_  / _` | / /_| |"<<endl;
    cout<<"                                                         | || (_) | |   / / (_| | \\___  |"<<endl;
    cout<<"                                                         \\_| \\___/|_|  /___\\__,_|     |_/"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                                              Gioca                                            Esci <=="<<endl;
    cout<<"                                              Statistiche                                      Opzioni"<<endl;
}

void homeState2()
{
    cout<<endl;
    cout<<endl;
    cout<<"                                                         ______                      ___ "<<endl;
    cout<<"                                                         |  ___|                    /   |"<<endl;
    cout<<"                                                         | |_ ___  _ __ ______ _   / /| |"<<endl;
    cout<<"                                                         |  _/ _ \\| '__|_  / _` | / /_| |"<<endl;
    cout<<"                                                         | || (_) | |   / / (_| | \\___  |"<<endl;
    cout<<"                                                         \\_| \\___/|_|  /___\\__,_|     |_/"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                                              Gioca                                            Esci"<<endl;
    cout<<"                                              Statistiche <==                                  Opzioni"<<endl;
}

void homeState3()
{
    cout<<endl;
    cout<<endl;
    cout<<"                                                         ______                      ___ "<<endl;
    cout<<"                                                         |  ___|                    /   |"<<endl;
    cout<<"                                                         | |_ ___  _ __ ______ _   / /| |"<<endl;
    cout<<"                                                         |  _/ _ \\| '__|_  / _` | / /_| |"<<endl;
    cout<<"                                                         | || (_) | |   / / (_| | \\___  |"<<endl;
    cout<<"                                                         \\_| \\___/|_|  /___\\__,_|     |_/"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                                              Gioca                                            Esci"<<endl;
    cout<<"                                              Statistiche                                      Opzioni <=="<<endl;
}
void board()
{

}
void boardState0()
{
    cout<<"|"<<endl;
    cout<<"V"<<endl;
}
void boardState1()
{
    cout<<" |"<<endl;
    cout<<" V"<<endl;
}
void boardState2()
{
    cout<<"  |"<<endl;
    cout<<"  V"<<endl;
}
void boardState3()
{
    cout<<"   |"<<endl;
    cout<<"   V"<<endl;
}
void boardState4()
{
    cout<<"    |"<<endl;
    cout<<"    V"<<endl;
}
void boardState5()
{
    cout<<"     |"<<endl;
    cout<<"     V"<<endl;
}
void boardState6()
{
    cout<<"      |"<<endl;
    cout<<"      V"<<endl;
}
void gameModeSelectorState0()
{
    cout<<endl;
    cout<<"                                                    Seleziona la modalit� di gioco"<<endl;
    cout<<endl;
    cout<<"                                         Singleplayer <==                         Multiplayer"<<endl;
}
void gameModeSelectorState1()
{
    cout<<endl;
    cout<<"                                                    Seleziona la modalit� di gioco"<<endl;
    cout<<endl;
    cout<<"                                         Singleplayer                             Multiplayer <=="<<endl;
}

int botIA(char matrix [6] [7]) //attacco 3>difesa3>attacco2
{
    int combo=0;
    for (int i=5;i>=0;i--) //attacco orizzontale
    {
        for (int j=0;j<4;j++)
        {
            if (matrix [i] [j]==matrix [i] [j+1] && matrix [i] [j+1]==matrix [i] [j+2] && matrix [i] [j]=='X' && matrix [i] [j+3] !='X' && matrix [0][j+3]==' ')
            {
                return (j+3);
            }
        }
    }

    for(int i=0;i<6;i++) //attacco verticale
    {
        for (int j=5;j>=3;j--)
        {
            if (matrix [j] [i] == matrix [j-1] [i] && matrix [j-1] [i]== matrix [j-2] [i] && matrix [j] [i]=='X' && matrix [j-3] [i] !='X' && matrix [0][i]==' ')
            {
                return i;
            }
        }
    }

    for (int i=5;i>=3;i--) //attacco basso-sinistra/alto-destra
    {
        for (int j=0;j<4;j++)
        {
            if (matrix [i][j]== matrix [i-1] [j+1] && matrix [i-1] [j+1] == matrix [i-2] [j+2] && matrix [i] [j]=='X' && matrix [i-3] [j+3] !='X' && matrix [i-2] [j+3] !=' ' && matrix [0][j+3]==' ')
            {
                return j+3;
            }
        }
    }

    for (int i=5;i>=3;i--) //attacco basso-destra/alto-sinistra
    {
        for (int j=6; j>2;j--)
        {
            if (matrix [i] [j]== matrix [i-1] [j-1] && matrix [i-1] [j-1]== matrix [i-2] [j-2] && matrix [i] [j]=='X' && matrix [i-3] [j-3] !='X' && matrix [i-2] [j-3] !=' ' && matrix [0][j-3]==' ')
            {
                return j-3;
            }
        }
    }

    for (int i=6;i>=0;i--) //Protezione orizzontale
    {
        for (int j=0;j<5;j++)
        {
            if (matrix [i] [j]==matrix [i] [j+1] && matrix [i] [j+1]==matrix [i] [j+2] && matrix [i] [j]=='O' && matrix [i] [j+3] !='X' && matrix [0][j+3]==' ')
            {
                return (j+3);
            }
        }
    }

    for(int i=0;i<7;i++) //Protezione verticale
    {
        for (int j=5;j>=3;j--)
        {
            if (matrix [j] [i] == matrix [j-1] [i] && matrix [j-1] [i]== matrix [j-2] [i] && matrix [j] [i]=='O' && matrix [j-3] [i] !='X' && matrix [0][i]==' ')
            {
                return i;
            }
        }
    }

    for (int i=6;i>=4;i--) //protezione basso-sinistra/alto-destra
    {
        for (int j=0;j<4;j++)
        {
            if (matrix [i][j]== matrix [i-1] [j+1] && matrix [i-1] [j+1] == matrix [i-2] [j+2] && matrix [i] [j]=='O' && matrix [i-3] [j+3] !='X' && matrix [i-2] [j+3] !=' ' && matrix [0][j+3]==' ')
            {
                return j+3;
            }
        }
    }

    for (int i=5;i>=3;i--) //protezione basso-destra/alto-sinistra
    {
        for (int j=6; j>2;j--)
        {
            if (matrix [i] [j]== matrix [i-1] [j-1] && matrix [i-1] [j-1]== matrix [i-2] [j-2] && matrix [i] [j]=='O' && matrix [i-3] [j-3] !='X' && matrix [i-2] [j-3] !=' ' && matrix [0][j-3]==' ')
            {
                return j-3;
            }
        }
    }

    for (int i=5;i>=0;i--) // attacco 2 orrizzontale
    {
        for (int j=0;j<4;j++)
        {
            if (matrix [i] [j]== matrix [i] [j+1] && matrix [i] [j+2]==' ' && matrix [i] [j+3]==' ' && matrix [i] [j]=='X' && matrix [0][j+2]==' ')
            {
                return j+2;
            }
        }
    }

    for (int i=0;i<7;i++)
    {
        for (int j=5;j>=3;j--)
        {
            if (matrix [j] [i] == matrix [j-1] [i] && matrix [j-2] [i]==' ' && matrix [j] [i]=='X')
            {
                return i;
            }
        }
    }
    combo=0;
    int blocco[7]={-1};
    for (int i=1;i<7;i++)
    {
        if (matrix [0] [i]== matrix [0] [i-1] && matrix [0] [i]==' ')
        {
            combo++;
            if (combo==6 && i==6)
            {
                return 69;
            }
        }
        else
        {
            blocco[i]=i;
        }
    }
    srand(time(NULL));
    int random=rand()%7;
    while(random == blocco[0] || random == blocco[1] || random == blocco[2] || random == blocco[3] || random == blocco[4] || random == blocco[5] || random == blocco[6])
    {
        srand(time(NULL));
        random=rand()%7;
    }
    return 69;
}


int controlloVittoria(char matrix [6] [7], bool &vittoria, int coordinate [8])
{
    int combo=0;
    bool combo_fatta=false;
    for (int j=5;j>=0;j--)
    {
        combo=0;
        for (int i=0;i<7;i++)
            {
                if (matrix [j] [i]==matrix [j] [i+1] && (matrix [j] [i] =='O' || matrix [j] [i] =='X')&& combo_fatta==false)
                {
                    combo++;
                    if (combo==3)
                    {
                        for (int k=0;k<8;k++)
                        {
                            if (k<4)
                            {
                                coordinate [k]=(i-k)+1;
                            }
                            else{
                                coordinate [k]=j;
                            }
                        }
                        vittoria=true;
                        combo_fatta=true;
                        if (matrix [j] [i]=='O')return 1;
                        else if (matrix [j] [i]=='X')return 2;
                    }
                    else{
                        vittoria=false;
                    }
                }
                else combo=0;
            }
    }
    if (!vittoria)
    {
        for (int i=0;i<7;i++)
    {
        combo=0;
        for (int j=5;j>=0;j--)
            {
                if (matrix [j] [i]==matrix [j-1] [i] && (matrix [j] [i] =='O' || matrix [j] [i] =='X') && combo_fatta==false)
                {
                    combo++;
                    if (combo==3)
                    {
                        for (int k=0;k<8;k++)
                        {
                            if (k<4)
                            {
                                coordinate [k]=i;
                            }
                            else{
                                coordinate [k]=(j-(k-4))+2;
                            }
                        }
                        vittoria=true;
                        combo_fatta=true;
                        if (matrix [j] [i]=='O')return 1;
                        else if (matrix [j] [i]=='X')return 2;

                    }
                    else{
                        vittoria=false;
                    }
                }
                else combo=0;

    }

}
    }

    if (!vittoria)
    {
        for (int i=0;i<4;i++) //diagonale basso/destra
    {
        for (int j=5;j>2;j--)
        {
            if (matrix [j] [i]== matrix [j-1] [i+1] && matrix [j-2] [i+2]== matrix [j-1] [i+1]&& matrix [j-2] [i+2]== matrix [j-3] [i+3] && (matrix [j] [i] =='O' || matrix [j] [i] =='X') && combo_fatta==false)
            {
                for (int k=0;k<8;k++)
                        {
                            if (k<4)
                            {
                                coordinate [k]=i+k;
                            }
                            else{
                                coordinate [k]=j-(k-4);
                            }
                        }
                vittoria=true;
                combo_fatta=true;
                if (matrix [j] [i]=='O')return 1;
                        else if (matrix [j] [i]=='X')return 2;
            }
        }
    }
    }


    if (!vittoria)
    {
        for (int i=6;i>2;i--) //diagonale basso/destra
    {
        for (int j=5;j>2;j--)
        {
            if (matrix [j] [i]== matrix [j-1] [i-1] && matrix [j-2] [i-2]== matrix [j-1] [i-1]&& matrix [j-2] [i-2]== matrix [j-3] [i-3] && (matrix [j] [i] =='O' || matrix [j] [i] =='X') && combo_fatta==false)
            {
                for (int k=0;k<8;k++)
                        {
                            if (k<4)
                            {
                                coordinate [k]=i-k;
                            }
                            else{
                                coordinate [k]=j-(k-4);
                            }
                        }
                vittoria=true;
                combo_fatta=true;
                if (matrix [j] [i]=='O')return 1;
                        else if (matrix [j] [i]=='X')return 2;
            }
        }
    }
    }
return 0;
}

void foo(char matrix [6] [7])
{
    for (int i=0;i<6;i++)
    {
        for (int j=0;j<7;j++)
        {
            cout<<matrix [i] [j];
        }
        cout<<endl;
    }
}

void spazioVuoto(char matrix[6] [7])
{
    for (int i=0;i<6;i++)
    {
        for (int j=0;j<7;j++)
        {
            matrix [i] [j]=' ';
        }
    }
}

void macchinaDaScrivere(string line)
{
    int time=10;
    for (int i=0;i<line.length();i++)
    {
        cout<<line[i];
        Sleep(time);
    }
}
int main()
{
    string line;
    bool amici=false;
    int vittoria1=0;
    char matrix [6] [7]={' '};
    int coordinate [8]={0};
    spazioVuoto(matrix);
    int c1=0; int c2=0; int z=0; int scelta;
    bool vittoria=false;
    int vincitore=0;
    bool refresh;
    bool sel;
    char c;
    int home;
    system("mode con lines=50");
    system("mode con cols=150");
    while (true)
    {
        refresh=false;
        homeState0();
        sel=true;
        scelta=0;
        while (sel)
        {
            switch((c=_getch()))
            {
            case KEY_RIGHT:
                if (scelta==0 || scelta==2)
                {
                    scelta++;
                    refresh=true;
                }
                break;
            case KEY_LEFT:
                if (scelta==1 || scelta==3)
                {
                    scelta--;
                    refresh=true;
                }
                break;
            case KEY_UP:
                if (scelta==2 || scelta==3)
                {
                    scelta=scelta-2;
                    refresh=true;
                }
                break;
            case  KEY_DOWN:
                if (scelta==0 || scelta==1)
                {
                    scelta=scelta+2;
                    refresh=true;
                }
                break;
            case KEY_ENTER:
                sel=false;
                refresh=true;
                break;
            default: break;
            }
            if (refresh)
            {
                system("cls");
                if (scelta==0)
                {
                    homeState0();
                    home=0;
                }
                if (scelta==1)
                {
                    homeState1();
                    home=1;
                }
                if (scelta==2)
                {
                    homeState2();
                    home=2;
                }
                if (scelta==3)
                {
                    homeState3();
                    home=3;
                }
            }
        }
        vittoria=false;
        spazioVuoto(matrix);
        if (home==0)
        {
            system("cls");
            refresh=false;
            sel=true;
            scelta=0;
            gameModeSelectorState0();
            while(sel)
            {
                switch ((c=_getch()))
                {
                case KEY_LEFT:
                    if (scelta==1)scelta--;
                    refresh=true;
                break;
                case KEY_RIGHT:
                    if (scelta==0)scelta++;
                    refresh=true;
                break;
                case KEY_ENTER:
                    sel=false;
                    refresh=true;
                break;
                default: break;
                }
                if (refresh)
                {
                    system("cls");
                    if (scelta==0)
                    {
                        gameModeSelectorState0();
                        amici=false;
                    }
                    if (scelta==1)
                    {
                        gameModeSelectorState1();
                        amici=true;
                    }
                }
            }
        if (amici)
        {
             while (!vittoria)
            {
                system("cls");
                refresh=false;
                sel=true;
                scelta=0;
                z=0;
                vincitore=controlloVittoria(matrix, vittoria, coordinate);
                if (!vittoria)
                {
                    cout<<"Deve giocare il giocatore 1"<<endl;
                    boardState0();
                    foo(matrix);
                    while(sel)
                    {
                        switch((c=_getch()))
                        {
                        case KEY_RIGHT:
                            if (scelta<6 && scelta>-1)
                            {
                                scelta++;
                                refresh=true;
                            }
                        break;
                        case KEY_LEFT:
                           if (scelta>0 && scelta<7)
                           {
                               scelta--;
                               refresh=true;
                           }
                        break;
                        case KEY_ENTER:
                            if (matrix [0] [c1] == ' ')
                                {
                                    sel=false;
                                }
                                else
                                {
                                    cout<<endl;
                                    cout<<"La colonna � piena, scegli una colonna che non lo sia"<<endl;
                                    Sleep(1000);
                                }
                                refresh=true;
                        break;
                        default: break;
                        }
                        if (refresh)
                        {
                            if (scelta==0)
                            {
                                c1=0;
                                system("cls");
                                cout<<"Deve giocare il giocatore 1"<<endl;
                                boardState0();
                                foo(matrix);
                            }
                            if (scelta==1)
                            {
                                c1=1;
                                system("cls");
                                cout<<"Deve giocare il giocatore 1"<<endl;
                                boardState1();
                                foo(matrix);
                            }
                            if (scelta==2)
                            {
                                c1=2;
                                system("cls");
                                cout<<"Deve giocare il giocatore 1"<<endl;
                                boardState2();
                                foo(matrix);
                            }
                            if (scelta==3)
                            {
                                c1=3;
                                system("cls");
                                cout<<"Deve giocare il giocatore 1"<<endl;
                                boardState3();
                                foo(matrix);
                            }
                            if (scelta==4)
                            {
                                c1=4;
                                system("cls");
                                cout<<"Deve giocare il giocatore 1"<<endl;
                                boardState4();
                                foo(matrix);
                            }
                            if (scelta==5)
                            {
                                c1=5;
                                system("cls");
                                cout<<"Deve giocare il giocatore 1"<<endl;
                                boardState5();
                                foo(matrix);
                            }
                            if (scelta==6)
                            {
                                c1=6;
                                system("cls");
                                cout<<"Deve giocare il giocatore 1"<<endl;
                                boardState6();
                                foo(matrix);
                            }
                        }
                    }
                    system("cls");
                    for (int i=5; i>=0;i--)
                    {
                        if (matrix [i] [c1]==' ' && z==0){
                            matrix [i] [c1]='O';
                            z++;
                        }
                    }
                    foo(matrix);
                    vincitore=controlloVittoria(matrix, vittoria, coordinate);
                    if (!vittoria)
                    {
                        system("cls");
                        z=0;
                        refresh=false;
                        sel=true;
                        scelta=0;
                        cout<<"Deve giocare il giocatore 2"<<endl;
                        boardState0();
                        foo(matrix);
                        while(sel)
                        {
                            switch((c=_getch()))
                            {
                            case KEY_RIGHT:
                                if (scelta<6 && scelta>-1)
                                {
                                    scelta++;
                                    refresh=true;
                                }
                            break;
                            case KEY_LEFT:
                               if (scelta>0 && scelta<7)
                               {
                                   scelta--;
                                   refresh=true;
                               }
                            break;
                            case KEY_ENTER:
                                if (matrix [0] [c2] == ' ')
                                {
                                    sel=false;
                                }
                                else
                                {
                                    cout<<endl;
                                    cout<<"La colonna � piena, scegli una colonna che non lo sia"<<endl;
                                    Sleep(1000);
                                }
                                refresh=true;
                            break;
                            default: break;
                            }
                            if (refresh)
                            {
                                if (scelta==0)
                                {
                                    c2=0;
                                    system("cls");
                                    cout<<"Deve giocare il giocatore 2"<<endl;
                                    boardState0();
                                    foo(matrix);
                                }
                                if (scelta==1)
                                {
                                    c2=1;
                                    system("cls");
                                    cout<<"Deve giocare il giocatore 2"<<endl;
                                    boardState1();
                                    foo(matrix);
                                }
                                if (scelta==2)
                                {
                                    c2=2;
                                    system("cls");
                                    cout<<"Deve giocare il giocatore 2"<<endl;
                                    boardState2();
                                    foo(matrix);
                                }
                                if (scelta==3)
                                {
                                    c2=3;
                                    system("cls");
                                    cout<<"Deve giocare il giocatore 2"<<endl;
                                    boardState3();
                                    foo(matrix);
                                }
                                if (scelta==4)
                                {
                                    c2=4;
                                    system("cls");
                                    cout<<"Deve giocare il giocatore 2"<<endl;
                                    boardState4();
                                    foo(matrix);
                                }
                                if (scelta==5)
                                {
                                    c2=5;
                                    system("cls");
                                    cout<<"Deve giocare il giocatore 2"<<endl;
                                    boardState5();
                                    foo(matrix);
                                }
                                if (scelta==6)
                            {
                                c2=6;
                                system("cls");
                                cout<<"Deve giocare il giocatore 2"<<endl;
                                boardState6();
                                foo(matrix);
                            }
                            }
                        }
                        system("cls");
                        for (int i=5; i>=0;i--)
                        {
                            if (matrix [i] [c2]==' ' && z==0)
                            {
                                matrix [i] [c2]='X';
                                z++;
                            }
                        }
                        foo(matrix);
                    }
                }
                if (vittoria)
                {
                    for (int i=0; i<3; i++)
                    {
                        system("cls");
                        matrix [coordinate [4]] [coordinate [0]]=' ';
                        matrix [coordinate [5]] [coordinate [1]]=' ';
                        matrix [coordinate [6]] [coordinate [2]]=' ';
                        matrix [coordinate [7]] [coordinate [3]]=' ';
                        foo(matrix);
                        Sleep(500);
                        system("cls");
                        if (vincitore == 1)
                        {
                            matrix [coordinate [4]] [coordinate [0]]='O';
                            matrix [coordinate [5]] [coordinate [1]]='O';
                            matrix [coordinate [6]] [coordinate [2]]='O';
                            matrix [coordinate [7]] [coordinate [3]]='O';
                        }
                        if (vincitore == 2)
                        {
                            matrix [coordinate [4]] [coordinate [0]]='X';
                            matrix [coordinate [5]] [coordinate [1]]='X';
                            matrix [coordinate [6]] [coordinate [2]]='X';
                            matrix [coordinate [7]] [coordinate [3]]='X';
                        }
                        foo(matrix);
                        Sleep(500);
                    }
                    if (vincitore == 1)
                    {
                        ifstream myfile ("Stats.txt");
                            {
                                while ( getline (myfile,line))
                                {
                                }
                              myfile.close();
                            }
                            vittoria1= stoi(line);
                            vittoria1++;
                            ofstream file;
                            file.open ("Stats.txt");
                            file<<vittoria1;
                            file.close();
                    }
                    else{
                        ifstream myfile1 ("Stats1.txt");
                            {
                                while ( getline (myfile1,line))
                                {
                                }
                              myfile1.close();
                            }
                            vittoria1= stoi(line);
                            vittoria1++;
                            ofstream file;
                            file.open ("Stats1.txt");
                            file<<vittoria1;
                            file.close();
                    }
                    Sleep(1000);
                    system("cls");
                    cout<<endl;
                    cout<<endl;
                    cout<<"Il giocatore "<<vincitore<<" ha vinto!!"<<endl;
                    Sleep(3000);
                    system("cls");
                    cout<<"Ritorno alla lobby"<<endl;
                    Sleep(1000);
                    system("cls");
                }
                if (matrix [0] [0] !=' ' && matrix [0] [1] !=' ' && matrix [0] [2] !=' ' && matrix [0] [3] !=' ' && matrix [0] [4] !=' ' && matrix [0] [5] !=' ' && matrix [0] [6] !=' ')
                {
                    vittoria=true;
                    system("cls");
                    cout<<endl;
                    cout<<"Avete pareggiato"<<endl;
                    Sleep(3000);
                    system("cls");
                    cout<<"Ritorno alla lobby"<<endl;
                    Sleep(1000);
                    system("cls");
                }
            }
        }
        if (!amici)
        {
             while (!vittoria)
            {
                system("cls");
                refresh=false;
                sel=true;
                scelta=0;
                z=0;
                vincitore=controlloVittoria(matrix, vittoria, coordinate);
                if (!vittoria)
                {
                    cout<<"Deve giocare il giocatore 1"<<endl;
                    boardState0();
                    foo(matrix);
                    while(sel)
                    {
                        switch((c=_getch()))
                        {
                        case KEY_RIGHT:
                            if (scelta<6 && scelta>-1)
                            {
                                scelta++;
                                refresh=true;
                            }
                        break;
                        case KEY_LEFT:
                           if (scelta>0 && scelta<7)
                           {
                               scelta--;
                               refresh=true;
                           }
                        break;
                        case KEY_ENTER:
                            sel=false;
                            refresh=true;
                        break;
                        default: break;
                        }
                        if (refresh)
                        {
                            if (scelta==0)
                            {
                                c1=0;
                                system("cls");
                                cout<<"Deve giocare il giocatore 1"<<endl;
                                boardState0();
                                foo(matrix);
                            }
                            if (scelta==1)
                            {
                                c1=1;
                                system("cls");
                                cout<<"Deve giocare il giocatore 1"<<endl;
                                boardState1();
                                foo(matrix);
                            }
                            if (scelta==2)
                            {
                                c1=2;
                                system("cls");
                                cout<<"Deve giocare il giocatore 1"<<endl;
                                boardState2();
                                foo(matrix);
                            }
                            if (scelta==3)
                            {
                                c1=3;
                                system("cls");
                                cout<<"Deve giocare il giocatore 1"<<endl;
                                boardState3();
                                foo(matrix);
                            }
                            if (scelta==4)
                            {
                                c1=4;
                                system("cls");
                                cout<<"Deve giocare il giocatore 1"<<endl;
                                boardState4();
                                foo(matrix);
                            }
                            if (scelta==5)
                            {
                                c1=5;
                                system("cls");
                                cout<<"Deve giocare il giocatore 1"<<endl;
                                boardState5();
                                foo(matrix);
                            }
                            if (scelta==6)
                            {
                                c1=6;
                                system("cls");
                                cout<<"Deve giocare il giocatore 1"<<endl;
                                boardState6();
                                foo(matrix);
                            }
                        }
                    }
                    system("cls");
                    for (int i=5; i>=0;i--)
                    {
                        if (matrix [i] [c1]==' ' && z==0){
                            matrix [i] [c1]='O';
                            z++;
                        }
                    }
                    foo(matrix);
                    vincitore=controlloVittoria(matrix, vittoria, coordinate);
                    if (!vittoria)
                    {
                        system("cls");
                        z=0;
                        srand(time(NULL));
                        c2=botIA(matrix);
                        if (c2==69)
                        {
                            c2=rand()%7;
                        }

                        for (int i=5; i>=0;i--)
                        {
                            if (matrix [i] [c2]==' ' && z==0)
                            {
                                matrix [i] [c2]='X';
                                z++;
                            }
                        }
                        foo(matrix);
                    }
                }
                if (vittoria)
                {
                    for (int i=0; i<3; i++)
                    {
                        system("cls");
                        matrix [coordinate [4]] [coordinate [0]]=' ';
                        matrix [coordinate [5]] [coordinate [1]]=' ';
                        matrix [coordinate [6]] [coordinate [2]]=' ';
                        matrix [coordinate [7]] [coordinate [3]]=' ';
                        foo(matrix);
                        Sleep(500);
                        system("cls");
                        if (vincitore == 1)
                        {
                            matrix [coordinate [4]] [coordinate [0]]='O';
                            matrix [coordinate [5]] [coordinate [1]]='O';
                            matrix [coordinate [6]] [coordinate [2]]='O';
                            matrix [coordinate [7]] [coordinate [3]]='O';
                        }
                        if (vincitore == 2)
                        {
                            matrix [coordinate [4]] [coordinate [0]]='X';
                            matrix [coordinate [5]] [coordinate [1]]='X';
                            matrix [coordinate [6]] [coordinate [2]]='X';
                            matrix [coordinate [7]] [coordinate [3]]='X';
                        }
                        foo(matrix);
                        Sleep(500);
                    }
                    if (vincitore == 1)
                    {
                        ifstream playerStats ("playerPoint.txt");
                            {
                                while ( getline (playerStats,line))
                                {
                                }
                              playerStats.close();
                            }
                            vittoria1= stoi(line);
                            vittoria1++;
                            ofstream file;
                            file.open ("Stats.txt");
                            file<<vittoria1;
                            file.close();
                    }
                    else{
                        ifstream botStats ("botPoint.txt");
                            {
                                while ( getline (botStats,line))
                                {
                                }
                              botStats.close();
                            }
                            vittoria1= stoi(line);
                            vittoria1++;
                            ofstream file;
                            file.open ("Stats1.txt");
                            file<<vittoria1;
                            file.close();
                    }
                    Sleep(1000);
                    system("cls");
                    cout<<endl;
                    cout<<endl;
                    if (vincitore==1)
                    {
                        cout<<"Hai vinto!!"<<endl;
                    }
                    else macchinaDaScrivere("Hai perso...");
                    Sleep(3000);
                    system("cls");
                    cout<<"Ritorno alla lobby"<<endl;
                    Sleep(1000);
                    system("cls");
                }
                if (matrix [0] [0] !=' ' && matrix [0] [1] !=' ' && matrix [0] [2] !=' ' && matrix [0] [3] !=' ' && matrix [0] [4] !=' ' && matrix [0] [5] !=' ' && matrix [0] [6] !=' ')
                {
                    vittoria=true;
                    system("cls");
                    cout<<endl;
                    cout<<"Avete pareggiato"<<endl;
                    Sleep(3000);
                    system("cls");
                    cout<<"Ritorno alla lobby"<<endl;
                    Sleep(1000);
                    system("cls");
                }
            }
        }
        }
        if (home==1)
        {
            system("cls");
            cout<<"Ritorna presto!"<<endl;
            Sleep(1000);
            return 0;
        }
        if (home==2)
        {
            system("cls");
            ifstream myfile ("Stats.txt");
                {
                    while ( getline (myfile,line))
                        {
                        }
                    myfile.close();
                }
            string line1;
            line1=line;
            ifstream myfile1 ("Stats1.txt");
                {
                    while ( getline (myfile1,line))
                        {
                        }
                    myfile1.close();
                }
            cout<<" _____ _        _   _     _   _      _          "<<endl;
            cout<<"/  ___| |      | | (_)   | | (_)    | |         "<<endl;
            cout<<"\\ `--.| |_ __ _| |_ _ ___| |_ _  ___| |__   ___ "<<endl;
            cout<<" `--. \\ __/ _` | __| / __| __| |/ __| '_ \\ / _ \\"<<endl;
            cout<<"/\\__/ / || (_| | |_| \\__ \\ |_| | (__| | | |  __/"<<endl;
            cout<<"\\____/ \\__\\__,_|\\__|_|___/\\__|_|\\___|_| |_|\\___|"<<endl;
            cout<<endl;
            cout<<endl;
            macchinaDaScrivere("Statistiche multiplayer");
            cout<<endl;
            cout<<endl;
            macchinaDaScrivere("-Il giocatore 1 ha vinto ");
            cout<<line1;
            macchinaDaScrivere(" volte");
            cout<<endl;
            macchinaDaScrivere("-Il giocatore 2 ha vinto ");
            cout<<line;
            macchinaDaScrivere(" volte");
            cout<<endl;
            cout<<endl;
            float perc=stoi(line1);
            float perc1=stoi(line);
            if (perc>perc1)
            {
                macchinaDaScrivere("Il giocatore 1 ha vinto la maggioranza delle partite con il ");
                cout<<(perc/(perc+perc1))*100;
                macchinaDaScrivere("% di vittorie");
                cout<<endl;
            }
            else
            {
                macchinaDaScrivere("Il giocatore 2 ha vinto la maggioranza delle partite con il ");
                cout<<(perc1/(perc+perc1))*100;
                macchinaDaScrivere("% di vittorie");
                cout<<endl;
            }
            cout<<endl;
            cout<<endl;
            macchinaDaScrivere("Singleplayer");
            cout<<endl;
            cout<<endl;
            macchinaDaScrivere("-Hai sconfitto il robot ");
            ifstream playerStats ("playerStats.txt");
                {
                    while ( getline (playerStats,line))
                        {
                        }
                    playerStats.close();
                }
            cout<<line;
            macchinaDaScrivere(" volte");
            cout<<endl;
            macchinaDaScrivere("-Il robot, invece, ti ha battuto ");
            ifstream botStats ("botStats.txt");
                {
                    while ( getline (botStats,line))
                        {
                        }
                    botStats.close();
                }
            cout<<line;
            macchinaDaScrivere(" volte");
            cin.get();
            system("cls");
            cout<<"Ritorno alla lobby"<<endl;
            Sleep(1000);
            system("cls");
        }
    }
}
