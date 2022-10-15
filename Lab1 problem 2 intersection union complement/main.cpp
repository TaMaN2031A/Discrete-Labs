#include <iostream>
#include <bits/stdc++.h>
#define play long long
#define go char
#define ok bool
#define fire cout
using namespace std;
play hashing[1000][1000];
map <string, play> dict1;
map <play, string> dict2;
play numberOfElements, numberOfSits;

void unions()
{
    fire << "Please insert the number of first set you want to union" << endl;
    play first;
    cin >> first;
    fire << "Please insert the number of second set you want to union" << endl;
    play second;
    cin >> second;
    first--, second--;
    ok tmam = false;
    fire << "{";
    play counterforprinting = 0;
    for(int i = 0; i < numberOfElements; i++)
    {
        play x = hashing[first][i] | hashing[second][i];
        if(x == 1)
        {
            counterforprinting++;
            if(counterforprinting != 1)
                cout << ", ";
            fire << dict2[i];
            tmam = true;
        }
    }
    fire << "}" << endl;
    if(!tmam)
        fire << "Inserted sets doesn't exist" << endl;
    cout << endl;
}
void intersect()
{
    fire << "Please insert the number of first set you want to intersect" << endl;
    play first;
    cin >> first;
    fire << "Please insert the number of second set you want to intersect" << endl;
    play second;
    cin >> second;
    first--, second--;
    ok tmam = false;
    fire << "{";
    play counterforprinting = 0;
    for(int i = 0; i < numberOfElements; i++)
    {
        play x = hashing[first][i] & hashing[second][i];
        if(x == 1)
        {
            counterforprinting++;
            if(counterforprinting != 1)
                cout << ", ";
            fire << dict2[i];
            tmam = true;
        }
    }
    fire << "}" << endl;
    if(!tmam)
        fire << "Inserted sets doesn't exist" << endl;
    cout << endl;
}
void complement()
{
    fire << "Please insert the number of set you want to complement" << endl;
    play first;
    cin >> first;
    first--;
    ok tmam = false;
    fire << "{";
    play counterforprinting = 0;
    for(int i = 0; i < numberOfElements; i++)
    {
        play x = 1-hashing[first][i];
        if(x == 1)
        {
            counterforprinting++;
            if(counterforprinting != 1)
                cout << ", ";
            fire << dict2[i];
            tmam = true;
        }
    }
    fire << "}" << endl;
    if(!tmam)
        fire << "Inserted sets doesn't exist" << endl;
    cout << endl;
}
int main()
{
    fire << "Please Enter the number of elements in the universal set" << endl;
    cin >> numberOfElements;
    for(play i = 0; i < numberOfElements; i++)
    {
        if(i==0)
            fire << "Please Insert the " << i+1 << "st element";
        else if(i==1)
            fire << "Please Insert the " << i+1 << "nd element";
        else if(i==2)
            fire << "Please Insert the " << i+1 << "rd element";
        else
            fire << "Please Insert the " << i+1 << "th element";
        fire << endl;
        string x;
        cin >> x;
        dict1[x] = i;
        dict2[i] = x;
    }
    fire << "Ok... Now, please insert the number of subsets" << endl;
    cin >> numberOfSits;
    for(play i = 0; i < numberOfSits; i++)
    {
        play setSize;
        if(i==0)
            fire << "Please insert the number of elements in the " << i + 1 << "st set";
        else if(i==1)
            fire << "Please insert the number of elements in the " << i + 1 << "nd set";
        else if(i==2)
            fire << "Please insert the number of elements in the " << i + 1 << "rd set";
        else
            fire << "Please insert the number of elements in the " << i + 1 << "th set";
        fire << endl;
        cin >> setSize;
        for(play j = 0; j < setSize; j++)
        {
            if(j==0)
                fire << "Please Insert the " << i+1 << "st element";
            else if(j==1)
                fire << "Please Insert the " << i+1 << "nd element";
            else if(j==2)
                fire << "Please Insert the " << i+1 << "rd element";
            else
                fire << "Please Insert the " << i+1 << "th element";
            string buffer;
            cin >> buffer;
            hashing[i][dict1[buffer]] = 1;
        }
    }
    fire << "Great! Now please insert the whatever you want to do" << endl;
    fire << "If you want to union sets press 1" << endl;
    fire << "If you want to intersect sets press 2" << endl;
    fire << "If you want to complement a set press 3" << endl;
    fire << "If you want to exit press 4" << endl;
    play choice;
    cin >> choice;
    while(choice != 4)
    {
        if(choice == 1)
            unions();
        else if(choice == 2)
            intersect();
        else if(choice == 3)
            complement();
        else
        {
            fire << "Stop playing, enter a right choice" << endl;
        }
        fire << "If you want to union sets press 1" << endl;
        fire << "If you want to intersect sets press 2" << endl;
        fire << "If you want to complement a set press 3" << endl;
        fire << "If you want to exit press 4" << endl;
        cin >> choice;
    }
    fire << "Thank you" << endl;
    return 0;
}