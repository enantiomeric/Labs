// Aditya Aparadh     22610082    S3
// Program to compare and concatenate two strings using operator overloading and friend functions

#include <iostream>

using namespace std;

class String
{
private:
    char *str;
    int len;

public:
    String(char *s)
    { // Parameterized Constructor
        len = 0;
        while (*s != '\0')
        {
            len++;
            s++;
        }
        str = new char[len + 1];
        s -= len;
        int i = 0;
        while (*s != '\0')
        {
            str[i++] = *s;
            s++;
        }
        str[i] = '\0';
    }

    String()
    { // Default Constructor
        len = 0;
        str = NULL;
    }

    String(const String &s)
    { // Copy Constructor
        len = s.len;
        str = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            str[i] = s.str[i];
        }
        str[len] = '\0';
    }

    void display()
    {
        for (int i = 0; i < len; i++)
        {
            cout << str[i];
        }
        cout << endl;
    }

    friend String operator+(String, String);
    friend bool operator<=(String, String);
};

String operator+(String s1, String s2)
{
    String s3;
    s3.len = s1.len + s2.len;
    s3.str = new char[s3.len + 1];
    for (int i = 0; i < s1.len; i++)
    {
        s3.str[i] = s1.str[i];
    }
    for (int i = 0; i < s2.len; i++)
    {
        s3.str[i + s1.len] = s2.str[i];
    }
    s3.str[s3.len] = '\0';

    return s3;
}

bool operator<=(String s1, String s2)
{
    if (s1.len <= s2.len)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char one[10], two[10];
    cout << "Enter s1: ";
    cin >> one;
    cout << "Enter s2: ";
    cin >> two;

    String s1(one);
    String s2(two);
    String s3;

    if (s1 <= s2)
    {
        cout << "s1 is smaller than or equal to s2" << endl;
    }
    else
    {
        cout << "s1 is greater than s2" << endl;
    }

    s3 = s1 + s2;
    cout << "Concatenated string: ";
    s3.display();
}