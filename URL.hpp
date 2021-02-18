
#include <string>
#include <curl/curl.h>
using namespace std;
string b;
string contents = "";

size_t handle_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    
    int numbytes = size*nmemb;

    char lastchar = *((char *) ptr + numbytes - 1);
    *((char *) ptr + numbytes - 1) = '\0';


    contents.append((char *)ptr);
    contents.append(1,lastchar);
    *((char *) ptr + numbytes - 1) = lastchar; 
    return size*nmemb;
}

class URL
{
  public:


    string getContents(string getUrl)
    {

    CURL* curl = curl_easy_init();
    if(curl) 
    {
       
        curl_easy_setopt(curl,CURLOPT_URL, getUrl.c_str());
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,handle_data); //what function should I "callback" when I get data
        // Do it!
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (res == 0) //if the error code is 0, everything went well
        {
            cout << contents << endl;

            string temp = "";
            for(int i = 0; i < 5; i++)
            {
                temp += contents[i];
            }
            cout << temp << endl;
        }
        else
        {
            cerr << "Error: " << res << endl;
        }
    }
    return 0;
}
};