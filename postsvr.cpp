#include <stdio.h>
#include <string.h>
#include <iostream>  
#include <sstream>
#include <curl/curl.h>
#include <unistd.h>
using namespace std;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
	string data((const char*)ptr, (size_t)size * nmemb);

	*((stringstream*)stream) << data << endl;

	return size * nmemb;
}

int main() {
	
	stringstream ret;

	CURL *curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, "EchoServer");
	struct curl_slist* headers = curl_slist_append(headers, "Content-Type:application/json;charset=UTF-8");
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	curl_easy_setopt(curl, CURLOPT_POST, 1);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ret);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{\"hi\" : \"there\"}");

    while(true){
	    curl_easy_perform(curl);
        cout << ret.str() << endl;
        sleep(5);
    }
	
	return 0;
}