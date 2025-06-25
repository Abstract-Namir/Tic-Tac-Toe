#include<iostream>
#include<ctime>
using namespace std;
void drawboard(char *spaces);
void playermove(char *spaces ,char player);
void computermove(char *spaces ,char computer);
bool checkwinner(char *spaces,char player ,char computer);
bool checktie(char *spaces);
int main(){
    char spaces[]={' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player='X';
    char computer='O';
    bool running=true;

    drawboard(spaces); //when passing an array it decays it into a pointer and dosent need a (*) 

    while(running){
        playermove(spaces ,player);
        drawboard(spaces);
        if(checkwinner(spaces,player,computer)){
            running=false;
            break;
        }
            else if(checktie(spaces)){
                running = false;
                break;
            }
        

        computermove(spaces,computer);
        drawboard(spaces);
        if(checkwinner(spaces,player,computer)){
            running=false;
            break;
        }
            else if(checktie(spaces)){
                running = false;
                break;
            }
        


    }
    cout<<"THANKS FOR PLAYING"<<endl;
    return 0;
}
void drawboard(char *spaces){
    cout<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<"  "<<endl;
    cout<<"     |     |     "<<endl;
    cout<<endl;
}
void playermove(char *spaces ,char player){ 
 int num;
 do{
    cout<<"To make a move enter a number from (1-9): ";
    cin>>num;
    num--;
    if(spaces[num]==' '){
        spaces[num]=player;
        break;
    }
 }while(!num>0 || !num<8);
}
void computermove(char *spaces ,char computer){
int num;
srand(time(0));
while(true){
    num=rand()%9;
    if(spaces[num]==' '){
        spaces[num]=computer;
        break;
    }
}
}
bool checkwinner(char *spaces,char player ,char computer){
    if(spaces[0]!=' '&& spaces[0]==spaces[1] && spaces[1]==spaces[2]){
        spaces[0]==player? cout<<"YOU WON! "<<endl : cout<<"YOU LOSE! "<<endl;
    }
    else if(spaces[3]!=' '&& spaces[3]==spaces[4] && spaces[4]==spaces[5]){
        spaces[3]==player? cout<<"YOU WON! "<<endl : cout<<"YOU LOSE! "<<endl;
    }
    else if(spaces[6]!=' '&& spaces[6]==spaces[7] && spaces[7]==spaces[8]){
        spaces[6]==player? cout<<"YOU WON! "<<endl : cout<<"YOU LOSE! "<<endl;
    }
    else if(spaces[0]!=' '&& spaces[0]==spaces[4] && spaces[4]==spaces[8]){
        spaces[0]==player? cout<<"YOU WON! "<<endl : cout<<"YOU LOSE! "<<endl;
    }
    else if(spaces[2]!=' '&& spaces[2]==spaces[4] && spaces[4]==spaces[6]){
        spaces[2]==player? cout<<"YOU WON! "<<endl : cout<<"YOU LOSE! "<<endl;
    }
   else if(spaces[0]!=' '&& spaces[0]==spaces[3] && spaces[3]==spaces[6]){
        spaces[0]==player? cout<<"YOU WON! "<<endl : cout<<"YOU LOSE! "<<endl;
    }
    else if(spaces[1]!=' '&& spaces[1]==spaces[4] && spaces[4]==spaces[7]){
        spaces[1]==player? cout<<"YOU WON! "<<endl : cout<<"YOU LOSE! "<<endl;
    }
    else if(spaces[2]!=' '&& spaces[2]==spaces[5] && spaces[5]==spaces[8]){
        spaces[2]==player? cout<<"YOU WON! "<<endl : cout<<"YOU LOSE! "<<endl;
    }
    else{
        return false;
    }
return true;    
}
bool checktie(char *spaces){
    for(int i=0;i<9;i++){
        if(spaces[i]==' '){
            return false;
        }
        cout<<"IT'S A TIE"<<endl;
    }
    return true;

}