#include "iostream"
#include "string"
using namespace std;


void display();
void stdToMlt();
void mltToStd();
void displayTime(int hour, int min, string amOrPm);
void displayMltTime(int hour, int min);

char getSelection();

int getH();
int getM();
string getAmOrPm();

int main()
{
    char choice = ' ';
    cout<<"Time Conversion Program:"<<endl;
    display();
    cout<<"What is your choice? "<<endl;
    choice = getSelection();

    switch (choice)
    {
    case 'A':
    case 'a':
        stdToMlt();
        break;

    case 'B':
    case 'b':
        mltToStd();
        break;

    
    default:
        break;
    }
    system("PAUSE");
    return 0;
}



void display()
{
    cout<<"What kind of conversion you will use?"<<endl;
    cout<<"A. 12-24 hour notation\n";
    cout<<"B. 24-12 hour notation\n";

}

char getSelection()
{
    char choice;
    cin>>choice;
    return choice;
}

void stdToMlt()
{
    int hour;
    int min;
    string amOrPm = " ";
    cout<<"Time (Hour)"; hour = getH();
    cout<<"Time (Min):"; min = getM();
    cout<<"AM or PM"; amOrPm = getAmOrPm();
    
    if(amOrPm == "PM" || amOrPm == "pm")
    {
        hour = hour+12;
    }
    displayMltTime(hour,min);
}


void displayMltTime(int hour, int min)
{
    char zero = ' ';
    char hrzero = ' ';
    if(hour<10)
    {
        hrzero = '0';
    }
    if(min<10)
    {
        zero = '0';
    }

    cout<<endl<<"Time: "<<hrzero<<hour<<":"<<zero<<min<<endl;
}


void mltToStd()
{
    int hour;
    int min;
    string amOrPm = " ";
    cout<<"Time (Hour)"; hour = getH();
    cout<<"Time (Min):"; min = getM();

    if(hour % 12 == 0)
    {
        amOrPm = "AM";
    }
    else if(hour % 12 > 0)
    {
        amOrPm = "PM";
        hour = hour % 12;
    }
        

    displayTime(hour,min,amOrPm);
}

int getH()
{
    int h;
    cin>>h;
    return h;
}

int getM()
{
    int m;
    cin>>m;
    return m;
}

string getAmOrPm()
{
    string ampm;
    cin>>ampm;
    return ampm;
}

void displayTime(int hour, int min, string amOrPm)
{
    char zero = ' ';
    if(min<10)
    {
        zero = '0';
    }
    cout<<endl<<"Time: "<<hour<<":"<<zero<<min<<" "<<amOrPm<<endl;
}