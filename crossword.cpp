#include <iostream>
#include <vector>
using namespace std;

bool canplaceH(vector<vector<char>> &c, int x, int y, string w)
{
    // if (x >= c.size() || (y + w.size() - 1) >= c[0].size())
    //     return false;
    for (int j = 0; j < w.size(); j++)
    {
        if (c[x][y + j] != '-' || c[x][y + j] != w[j])
            return false;
    }
    return true;
}

bool canplaceV(vector<vector<char>> &c, int x, int y, string w)
{
    // if (y >= c[0].size() || (x + w.size() - 1) >= c.size())
    //     return false;
    for (int i = 0; i < w.size(); i++)
    {
        if (c[x + i][y] != '-' || c[x + i][y] != w[i])
            return false;
    }
    return true;
}
vector<bool> placeH(vector<vector<char>> &c, int x, int y, string w)
{
    vector<bool> v(w.size(), false);
    for (int j = 0; j < w.size(); j++)
    {
        if (c[x][y + j] == '-')
        {
            c[x][y + j] = w[j];
            v[j] = true;
        }
    }
    return v;
}
vector<bool> placeV(vector<vector<char>> &c, int x, int y, string w)
{
    vector<bool> v(w.size(), false);
    for (int i = 0; i < w.size(); i++)
    {
        if (c[x + i][y] == '-')
        {
            c[x + i][y] = w[i];
            v[i] = true;
        }
    }
    return v;
}
void unplaceH(vector<vector<char>> &c, int x, int y, vector<bool> v)
{
    for (int j = 0; j < v.size(); j++)
        if (v[j])
            c[x][y + j] = '-';
}
void unplaceV(vector<vector<char>> &c, int x, int y, vector<bool> v)
{
    for (int j = 0; j < v.size(); j++)
        if (v[j])
            c[x + j][y] = '-';
}
// vector<string> aa;
void cross(vector<vector<char>> &c, vector<string> &w, int indx)
{
    if (indx == (w.size()))
    {
        for (auto i : c)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = 0; i < c.size(); i++)
    {
        for (int j = 0; j < c[i].size(); j++)
        {
            if (c[i][j] == '-' || c[i][j] == w[indx][0])
            {
                if (canplaceH(c, i, j, w[indx]))
                {
                    vector<bool> v = placeH(c, i, j, w[indx]);
                    cross(c, w, indx + 1);
                    unplaceH(c, i, j, v);
                }

                if (canplaceV(c, i, j, w[indx]))
                {
                    vector<bool> v = placeV(c, i, j, w[indx]);
                    cross(c, w, indx + 1);
                    unplaceV(c, i, j, v);
                }
            }
        }
    }
}

void crosswordPuzzle(vector<vector<char>> crossword, string words)
{
    vector<string> w;
    string a = "";
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] != ';')
            a += words[i];
        else
        {
            w.push_back(a);
            a = "";
        }
    }
    w.push_back(a);
    // for (auto i : w)
    //     cout << i << " ";
    cross(crossword, w, 0);
    // return aa;
}
int main()
{
    // wordbreak("ilikeicecreamandmango", "");
    vector<vector<char>> c = {{'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                              {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                              {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                              {'+', '-', '-', '-', '-', '-', '+', '+', '+', '+'},
                              {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
                              {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
                              {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
                              {'+', '+', '-', '-', '-', '-', '-', '-', '+', '+'},
                              {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
                              {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'}};
    string w = "LONDON;DELHI;ICELAND;ANKARA";
    crosswordPuzzle(c, w);
    return 0;
}
