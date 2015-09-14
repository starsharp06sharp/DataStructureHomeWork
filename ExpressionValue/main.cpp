#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

stack<int> num;
stack<char>  oper;

char comp (char now, char before);
bool calcTillBracket (char bracket);
void calc ();

int main()
{
    string exp;
    cin >> exp;
    if (exp[0] != '#' || exp[exp.size() - 1] != '#') {cout << "Synax Error!";exit(-1);}

    for (const auto& ch : exp) {
        if (isdigit(ch)) {
            num.push(ch - '0');
        } else if (!oper.empty()) {
            switch (comp(ch, oper.top())) {
            case '>':
                oper.push(ch);
                break;
            case '=':
                if (calcTillBracket(ch)) {cout << "Synax Error!";exit(-1);}
                break;
            case '<':
                calc();
                oper.push(ch);
                break;
            }
        } else {
            oper.push(ch);
        }
    }
    cout << num.top();
    return 0;
}

char comp (char now, char before)
{
    switch (now) {
    case '#':
    case ')':
        return '=';
    case '+':
    case '-':
        if (before == '#'
            || before == '(') return '>';
        else return '<';
    case '*':
    case '/':
        if (before == '*'
            || before == '/') return '<';
        else return '>';
    case '(':
        return '>';
    }
}

bool calcTillBracket (char bracket)
{
    while (oper.top() != '#' && oper.top() != '(')
            calc();
    return (bracket != oper.top());
}

void calc ()
{
    int b = num.top();
    num.pop();
    int a = num.top();
    num.pop();
    switch (oper.top()) {
    case '+':
        num.push(a + b);
        break;
    case '-':
        num.push(a - b);
        break;
    case '*':
        num.push(a * b);
        break;
    case '/':
        num.push(a / b);
        break;
    }
    oper.pop();
}
