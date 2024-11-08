#include <curl/curl.h>
#include <fstream>
#include <sstream>
#include <filesystem>  
#include<bits/stdc++.h>

using namespace std;

void fetch_HTML(const string&, const string&);
size_t write_fun(void*, size_t, size_t, void*);

int main() {

    //URL for the server hosting the HTML pages
    string base_url = "http://localhost:8000/";

    // Location of HTML files
    string html_dir = "html_dataset/";

    // Directory to save the fetched HTML pages
    string save_dir = "fetched_files/";

    // Create the fetched_files directory if it doesn't exist
    if(!filesystem::exists(save_dir)) {
        filesystem::create_directory(save_dir);
    }

    // Get the list of HTML files
    vector<string> htmlFiles;
    for(const auto& entry : filesystem::directory_iterator(html_dir)) {
        if(entry.path().extension() == ".html") {
            htmlFiles.push_back(entry.path().filename().string());
        }
    }

    // Check if there are HTML files to fetch
    if(htmlFiles.empty()) {
        cerr << "No HTML files found in " << html_dir << endl;
        return 1;
    }

    //Saving files
    for(const auto& htmlFile : htmlFiles) {
        
        string url = base_url + html_dir + htmlFile;
        string filePath = save_dir + htmlFile;
        cout << "Fetching: " << url << endl;
        fetch_HTML(url, filePath);
        cout << "Saved to: " << filePath << endl;
    }

    cout << "All pages fetched and saved in " << save_dir << "." << endl;

    return 0;
}

// Function to fetch HTML from a URL and save it
void fetch_HTML(const string& url, const string& filePath) {
    CURL* curl;
    CURLcode req;
    string readBuffer;

    curl = curl_easy_init();  // Initialize curl session
    if(curl) {
        // Set the URL
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Function to capture the data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_fun);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Perform the request
        req = curl_easy_perform(curl);

        // Check if the request worked fine
        if(req != CURLE_OK)
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(req) << endl;
        
        // Cleanup curl
        curl_easy_cleanup(curl);

        // Save HTML content to file in fetched_files
        ofstream outFile(filePath);
        if(outFile.is_open()) {
            outFile << readBuffer;
            outFile.close();
        } else {
            cerr << "Failed to open file: " << filePath << endl;
        }
    }
}

// Callback function to store HTML content in a string
size_t write_fun(void* content, size_t size, size_t n, void* userp) {
    ((string*)userp)->append((char*)content, size * n);
    return size * n;
}