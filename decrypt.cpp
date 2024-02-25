#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string debugChar;
    string decryptThis;
    int stringlen;
    int decryptNum = -1;
    int i;
    int decryptLet;
    int decryptRemain;
    cout << "Please type in a string to decrypt\n";
    getline(cin,decryptThis);
    stringlen = decryptThis.length();
    while(decryptNum < 0)
    {
        cout << "Please enter the number used in the encryption\n";
        cin >> decryptNum;
        if(decryptNum <= 0 || decryptNum >= 26)
        {
            cout << "Please enter a valid number\n";
            decryptNum = -1;
        }
        else
        {
            for(i = 0; i < stringlen; i++)
            {
                if((decryptThis[i]) < 91 && (decryptThis[i]) > 64)
                {
                    
                    decryptLet = decryptThis[i];
                    decryptRemain = decryptThis[i] - 65;
                    if(decryptRemain <= decryptNum)
                    {
                        decryptThis[i] = 90 - (decryptNum - decryptRemain);
                    }
                    else
                    {
                        decryptThis[i] = decryptThis[i] - decryptNum;
                    }
                }
                else if((decryptThis[i]) < 123 && (decryptThis[i]) > 96)
                {
                    decryptLet = decryptThis[i];
                    decryptRemain = decryptThis[i] - 97;
                    if(decryptRemain < decryptNum)
                    {
                        decryptThis[i] = 122 - (decryptNum - decryptRemain);
                    }
                    else
                    {
                        decryptThis[i] = decryptThis[i] - decryptNum;
                    }
                }
                else
                {
                    continue;
                }
            }
            break;
        }
    }
    cout << "\nDecrypted String: " + decryptThis + "\n";
    return 0;
}