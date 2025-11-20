//First making wordle in C++. I think it will be easier 
//if I do this then convert to C

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

string word;
vector <char> v;
cout << "Enter a 5-letter word\n";
cin >> word;

for (char ch : word)
{
    v.push_back(ch);
}

if (word.size() == 5)
{

    bool win = false;

    for (int i{0}; i<6; i++)
    {
        string guess;
        cout << "Enter a word\n";
        cin >> guess;
        if (guess.size() != 5)
        {
            cout << "Enter a 5-letter word!\n";
            i--;
            continue;
        }
        else
        {
            vector <char> vec;
            for (char p : guess)
            {
                vec.push_back(p);
            }
            vector <char> ans(5, 'X');

            for (int j{0}; j<5; j++)
            {
                
                if (vec[j] == v[j])
                {
                    ans[j] = 'G';
                    continue;
                }

                else if (find(v.begin(), v.end(), vec[j]) != v.end() && vec[j] != v[j])
                {
                
                    ans[j] = 'Y';
                    continue;
                }
                
            }

            for (char c : ans) 
            {
                cout << c;
            }

            cout << '\n';
            
            if (ans == vector<char>{'G', 'G', 'G', 'G', 'G'})
            {
                cout << "You win!";
                win = true;
                break;
            }

            if (i == 5 && win == false)
            {
                cout << "Game over";
                break;
            }

        }
    }
}
else 
{
    cout << "Please enter a 5-letter word!\n";
}


return 0;
}
