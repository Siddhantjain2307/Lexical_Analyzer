#include <iostream>

using namespace std;

bool is_Letter(char ch);
bool is_Digit(char ch);
bool is_Delimeter(char ch);
void Lexical(string str);
int main()
{
   string s;
   cout<<"Enter the String"<<endl;
   getline(cin,s);
   // cout<<"string:"<<s<<endl;
   Lexical(s);
    return 0;
}

bool is_Letter(char ch)
{
    if( (ch >='A' && ch <= 'Z') || (ch >='a' && ch <= 'z') )
        return true;
    else
        return false;
}
bool is_Digit(char ch)
{
    if(ch >='0' && ch <= '9')
        return true;
    else
        return false;
}
bool is_Delimeter(char ch)
{
     if(ch ==' ' || ch == '\t' || ch == '\n' )
            return true;
        else
            return false;
}
void Lexical(string str)
{
  int state = 0 ;
  int flag = 1;
  int i=0;
  char c='\0';
  string lexeme="";

    while(str[i]!='\0')
    {
        c=str[i];

        flag=1;
       switch(state)
        {
            case 0:
                if(is_Letter(c))
                {
                    state=1;
                }
                else if(is_Digit(c))
                {
                    state=2;
                }
                else if(c=='+')
                {
                    state=0;
                    lexeme=c;
                    cout<<"TOKEN<"<<" PO ,"<<lexeme<<">"<<endl;
                    lexeme="";
                    flag=0;
                }
                else if(c=='=')
                {
                    state=0;
                    lexeme=c;
                    cout<<"TOKEN< "<<" AO ,"<<lexeme<<" >"<<endl;
                    lexeme="";
                    flag=0;
                }
                 else if(c==';')
                {
                    state=0;
                    lexeme=c;
                    cout<<"TOKEN< "<<" SC ,"<<lexeme<<" >"<<endl;
                    lexeme="";
                    flag=0;
                }
                else if(is_Delimeter(c))
                {
                    flag=0;
                }
                else
                {
                    cout<<"Invalid Tokken"<<endl;
                    break;
                }
            break;

            //Identifier
            case 1:

                if(is_Letter(c))
                {
                    state=1;
                }
                else if(is_Digit(c))
                {
                    state=1;
                }
                else
                {

                    state=0;
                    if(lexeme=="int" || lexeme=="print")
                    {
                        cout<<"TOKEN< "<<" KW , "<<lexeme<<" >"<<endl;
                    }
                    else
                    {
                        cout<<"TOKEN< "<<" ID , "<<lexeme<<" >"<<endl;
                    }
                    lexeme="";
                    flag=0;
                    continue;
                }
            break;

            //Int Literal
            case 2:

                if(is_Digit(c))
                {
                    state=2;
                }
                else
                {
                    state=0;
                    cout<<"TOKEN<"<<" IntLit , "<<lexeme<<" >"<<endl;
                    lexeme="";
                    flag=0;
                    continue;
                }
            break;



        }

        if (flag)
             {
                lexeme=lexeme+c;
             }
        i++;
    }

}
void Lexical(string str);
