// reverse string using stack
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

void reverse(char str[], int len)
{
    stack<char> strack;
    for (int i = 0; i < len; i++)
        strack.push(str[i]);
    for (int i = 0; i < len; i++)
    {
        str[i] = strack.top();
        strack.pop();
    }
}

int main()
{
    char str[50];
    cout << "Enter String: ";
    cin >> str;
    reverse(str, strlen(str));
    cout << str;
    return 0;
}
