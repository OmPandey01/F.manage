#include<iostream>
#include<string>
#include<filesystem>
#include<vector>

using namespace std;
using namespace std::filesystem;


struct imgdetail{

    std::string name;
    std::string extension;
    std::string path;
};

void getdetails(const std::string& folderpath,vector<imgdetail>& images){

    for(const auto& entry:directory_iterator(folderpath)){

            imgdetail  img;

            img.name=entry.path().filename().string();
            img.extension=entry.path().extension().string();
            img.path=entry.path().string();

            images.push_back(img);



        
    }




}

int main(){

    vector<imgdetail> images;

    getdetails("folder_1",images);
    
    for(const auto& img:images){

        cout<<img.name<<endl;
    }

//struct to store data



}