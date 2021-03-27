#include <iostream>
#include <string>
#include <uchar.h>

using namespace std;


int main(int argc, char* argv[])
{
    string s = argv[1];
    string s_str = argv[2];
    cout << "\nAuthor Repyuk Natasha\n";
    int n = s.length();
    int m = s_str.length();
    
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        bool succes = true;
        for (int j = 0; j < m; j++)
        {
            if (s_str[j] != s[i + j])
                succes = false;
        }
        if (succes)
            index = i;
    }
    if (index != -1)
    {
        cout << "The substring is present in the string\n";
        cout << index;
    }
    else { cout << "There is no substring in the string";
    }
    index = 0;
}


