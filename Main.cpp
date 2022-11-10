#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <vector>
#include <stack>
#include <map>
#include <utility>
#include <algorithm>
#include <regex>
using namespace std;

string operators[] = {"!", "%", "*", "+", "-", "/", "<", "<=", "=", "==", ">", ">="};
int opLength = 12;
string separators[] = {"\n", " ", ":", ";", "[", "]", "{", "}"};
int sepLength = 8;
string types[] = {"BOOLEAN", "CHAR", "FLOAT", "INTEGER"};
int typeLength = 4;
string words[] = {"DO", "IF", "LET", "READ", "WHILE", "WRITE"};
int wordLength = 5;
string reserved[] = {"BOOLEAN", "CHAR", "DO", "FLOAT", "IF", "INTEGER", "LET", "READ", "WHILE", "WRITE"};
int reservedLength = 10;
vector<string> identifiers;
map<string, int> tokenTable;
int tokenTableLength = 0;
map<string, int> symbolTable;
int symbolTableLength = 0;
map<string, pair<int, int>> PIF;
int PIFLength = 0;

bool loadTokenTable()
{
    int i = 1;
    tokenTable["const"] = 0;
    tokenTable["ident"] = 1;
    tokenTableLength = 2;
    for (i = 0; i < typeLength; i++)
    {
        tokenTable[types[i]] = tokenTableLength;
        tokenTableLength++;
    }
    for (i = 0; i < wordLength; i++)
    {
        tokenTable[words[i]] = tokenTableLength;
        tokenTableLength++;
    }
    for (i = 0; i < opLength; i++)
    {
        tokenTable[operators[i]] = tokenTableLength;
        tokenTableLength++;
    }
    for (i = 0; i < sepLength; i++)
    {
        tokenTable[separators[i]] = tokenTableLength;
        tokenTableLength++;
    }
    return 1;
}

bool findInSortedStringArray(string token, string *arr, int len)
{
    int i = len / 2;
    int width = len / 2;
    while (width > 0)
    {
        if (token.compare(arr[i]) < 0)
        {
            width = width / 2;
            i = i - width;
        }
        else if (token.compare(arr[i]) > 0)
        {
            width = width / 2;
            i = i + width;
        }
        else
        {
            return true;
        }
    }
    return false;
}

bool isReserved(string token)
{
    return findInSortedStringArray(token, reserved, reservedLength);
}

bool isOperator(string token)
{
    return findInSortedStringArray(token, operators, opLength);
}

bool isSeparator(string token)
{
    return findInSortedStringArray(token, separators, sepLength);
}

bool isIdentifier(string token)
{
    return regex_match(token, regex("[A-Za-z]+[A-Za-z0-9]*$"));
}

bool isConstant(string token)
{
    return regex_match(token, regex("(0|([1-9]+[0-9]*))(\.[0-9]+){0,1}$"));
}

void genFIP(string token, int symbolVal)
{
    if (symbolVal == -1)
    {
        pair<int, int> values(tokenTable[token], -1);
        PIF[token] = values;
    }
    else
    {
        if (isIdentifier(token))
        {
            pair<int, int> values(tokenTable["ident"], symbolVal);
            PIF[token] = values;
        }
        else
        {
            pair<int, int> values(tokenTable["const"], symbolVal);
            PIF[token] = values;
        }
    }
}

int addToST(string token)
{
    symbolTable[token] = symbolTableLength;
    symbolTableLength++;
    return symbolTableLength - 1;
}

void loadPIF()
{

    ifstream in = ifstream("program.txt");
    string token;

    while (in >> token)
    {

        if (isReserved(token) || isOperator(token) || isSeparator(token))
        {
            genFIP(token, -1);
        }
        else
        {
            if (isIdentifier(token) || isConstant(token))
            {
                int symbVal = addToST(token);
                genFIP(token, symbVal);
            }
            else
            {
                cout << "Lexical error";
            }
        }
    }
}

void displayPIF()
{
    for (auto i : PIF)
    {
        cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
    }
}

void displayST()
{
    for (auto i : symbolTable)
    {
        cout << i.first << " " << i.second << "\n";
    }
}

void displayTables()
{
    displayPIF();
    displayST();
}

int main()
{
    ofstream out = ofstream("table.txt");
    if (loadTokenTable())
        cout << "loaded token Table" << endl;
    loadPIF();
    displayST();
    displayPIF();
    return 0;
}
