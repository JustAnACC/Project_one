#include <iostream>
#include <string.h>
#include "calendar.h"
using namespace std;

int main()
{
    char input[256];
    char check[32];
    cin.getline(input,256);
    calendar cal;
    while(strcmp(input,"exit") != 0)
    {
        strcpy(check,input);
        check[4] = 0;
        if(strcmp(check,"open") == 0)
        {
            cal.set_path(&input[5]);
            cal.load();
        }
        strcpy(check,input);
        check[5] = 0;
        if(strcmp(check,"close") == 0)
        {
            cal.close();
        }
        strcpy(check,input);
        check[4] = 0;
        if(strcmp(check,"save") == 0)
        {
            cal.save();
        }
        strcpy(check,input);
        check[6] = 0;
        if(strcmp(check,"saveas") == 0)
        {
            cal.set_path(&input[7]);
            cal.save();
        }
        cin.getline(input,256);
    }
    return 0;
}
