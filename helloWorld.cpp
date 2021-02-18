#include<iostream>
#include <string>
#include <curl/curl.h>
#include "URL.hpp"
using namespace std;

int main(int argc, char* argv[])
{

//URL* u1 = new URL("https://www.google.com");
//cout<<u1->getContents()<<endl;


//URL* u2 = new URL();
    URL* u1;
    URL* u2;
    URL* u3;    
    cout<<"enter google Yahoo or hearthstone\n";
    string userInput;
    cin >>  userInput;


    //if statement practice
    if (userInput == "google")
        u1->getContents("https://www.google.com");
        return 0;

    if (userInput == "Yahoo")
        u2->getContents("https://www.yahoo.com");
        return 0;   

    if (userInput == "heartstone")
        u3->getContents("https://api.hearthstonejson.com/v1/25770/enUS/cards.json");
        return 0;    


}

