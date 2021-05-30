#include<iostream>
using namespace std;

bool is_Letter(char ch);
bool is_Digit(char ch);
bool is_Delimeter(char ch);
void Lexical(string str);

int main()
{
    string input;
    cout<<"Enter the String"<<"\n";
    getline(cin,input);
    //cout<<input<<endl;
    Lexical(input);
    return 0;
}

bool is_Letter(char ch)
{
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
    {
        return true;
    }
    else false;
}
bool is_Digit(char ch)
{
    if(ch>='0' && ch<='9')
    {
        return true;
    }
    else false;
}
bool is_Delimeter(char ch)
{
    if(ch==' ' || ch=='\t' || ch=='\n')
    {
        return true;
    }
    else false;
}

void Lexical(string str)
{
    int state=0;
    int i=0;
    string lexeme="";
    int flag=1;
    char c='\0';

    while(str[i]!='\0')
    {
        c=str[i];
        flag=1;
        switch (state)
        {
        case 0:
            if(is_Letter(c))
            {
                state=1;
            }
            else if (is_Digit(c))
            {
                state=2;
            }
            else if (c=='=')
            {
                state=0;
                lexeme=c;
                cout<<"Tokken < "<<" AS, "<<lexeme<<">"<<"\n";
                lexeme="";
             }
            else if (c=='+')
            {
                state=0;
                lexeme=c;
                cout<<"Tokken < "<<" AO, "<<lexeme<<">"<<"\n";
                lexeme="";
            }
            else if (c==';')
            {
                state=0;
                cout<<"Tokken < "<<" SC, "<<lexeme<<">"<<"\n";
                lexeme="";
            }
            else if (c=='<')
            {
                state=3;
            }
            else if (c=='{')
            {
                state=0;
                cout<<"Tokken < "<<" OP, "<<lexeme<<">"<<"\n";
                lexeme="";
            }
            else if (c=='}')
            {
                state=0;
                cout<<"Tokken < "<<" SP, "<<lexeme<<">"<<"\n";
                lexeme="";
            }
            else if (is_Delimeter(c))
            {
                flag=0;
            }
            else 
            {
                cout<<"Invalid Tokken"<<"\n";
                break;
            }
        break;

        case 1:
            if(is_Letter(c) || is_Digit(c))
            {
                state=0;
                if(lexeme=="int" || lexeme=="main" || lexeme=="cout")
                {
                    cout<<"Tokken < "<<" KW, "<<lexeme<<">"<<"\n";
                }
                else
                {
                    cout<<"Tokken < "<<" ID, "<<lexeme<<">"<<"\n";
                }
                lexeme="";

                continue;
            }
        break;

        case 2:
              if(is_Digit(c))
              {
                state=0;
                cout<<"Tokken < "<<" IL, "<<lexeme<<">"<<"\n";
                lexeme="";
                continue;
              }
        break;      

        case 3:
            if(c=='=')
            {
               state=0;
               cout<<"Tokken < "<<" LE, "<<lexeme<<">"<<"\n";
               lexeme=""; 
            }
            else
            {
                state=0;
                cout<<"Tokken < "<<" LT, "<<lexeme<<">"<<"\n";
                lexeme="";
                continue;
            }
        break;
        }
        
        if(flag)
        {
            lexeme = lexeme + c;
        }

        i++;
 
    }

}