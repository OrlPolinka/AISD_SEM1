#include <iostream>
#include <string>   
using namespace std;

struct Stack
{
    char data;
    Stack* next;
};

void push(char x, Stack*& myStk)
{
    Stack* e = new Stack;    
    e->data = x;             
    e->next = myStk;        
    myStk = e;				
}

int isEmpty(Stack*& myStk) {
    if (myStk == NULL)
    {
        return 1;
    }
    else {
        return 0;
    }
}

char pop(Stack*& myStk)   
{
    if (myStk == NULL)
    {
        return -1;
    }
    else
    {
        Stack* e = myStk;        
        int x = myStk->data;  
        if (myStk)
            myStk = myStk->next;  

        delete e;
        return x;

    }
}

char top(Stack*& myStk)
{
    if (myStk == NULL)
    {
        cout << "Стек пуст!" << endl;
        return 1;
    }
    else {
        return myStk->data;
    }
}

bool prov(const string& s, int& count) {
    Stack* stack;
    stack = NULL;
    for (char c : s) {
        switch (c) {
        case '(':
            push(')', stack);
            count++;
            break;
        case '[':
            push(']', stack);
            count++;
            break;
        case '{':
            push('}', stack);
            count++;
            break;
        case ')':
        case ']':
        case '}':
            if (isEmpty(stack) || top(stack) != c) {
                if (c == ')' || c == '}' || c == ']')
                    count++;
                return false;
            }
            pop(stack);
            break;
        default:
            break;
        }
    }
    return isEmpty(stack);
}

void test(const string& s, int& count) {
    bool stackClear = prov(s, count);
    if (stackClear && count > 0)
        cout << "Скобки расставлены верно" << endl << endl;
    if (count == 0)
        cout << "Скобки отсутствуют" << endl << endl;
    else
        if (!stackClear && count > 0)
            cout << "Скобки расставлены неверно" << endl << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    while (true) {
        int count = 0;
        cout << "Введите строку с клавиатуры (для выхода введите 'exit'): ";
        string str;
        getline(cin, str);
        if (str == "exit")
            break;
        test(str, count);
    }
    return 0;
}