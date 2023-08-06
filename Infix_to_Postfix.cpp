#include<bits/stdc++.h>
using namespace std;

bool isOperand(char x){
    if(x=='+'or x=='-' or x=='*' or x=='/' or x=='^')
        return false;
    else
        return true;
}

int precedence(char x){
    if(x=='+' or x=='-')
        return 1;
    else if(x=='*' or x=='/')
        return 2;
    else if(x=='^')
        return 3;
    return 0;
}

char *convert(char *infix)
{
    char *postfix = new char[strlen(infix)+1];
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(precedence(infix[i])>precedence(Top()))
                push(infix[i++]);
            else{
                while(precedence(infix[i])<=precedence(Top())){
                    postfix[j++] = Top();
                    pop();
                }
            }
        }
        while(!isEmpty()){
            postfix[j++] = Top();
            pop();
        }
        postfix[j] = '\0';
        return postfix;
    }
}



int main(){
    return 0;
}
