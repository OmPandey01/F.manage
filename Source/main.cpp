#include<iostream>
#include<string>
#include<filesystem>
#include<vector>

using namespace std;
using namespace std::filesystem;


struct imgdetail{

    string name;
    string extension;
    string path;
};

void getdetails(const string& folderpath,vector<imgdetail>& images){

    for(const auto& entry:directory_iterator(folderpath)){

            imgdetail  img;

            img.name=entry.path().filename().string();
            img.extension=entry.path().extension().string();
            img.path=entry.path().string();

            images.push_back(img);



        
    }




}




void Rename(imgdetail entry,const string& destination){
    //This funtion takes structure containing file detail
    //and path of destination where we have to 
    string source= entry.path;

    string destin=destination+"/"+entry.name;

    rename(source,destin);


}


int main(){

    vector<imgdetail> images;

    getdetails("movedImages",images);
    
    for(const auto& img:images){

        Rename(img,"folder_1");
        


    
    }

//struct to store data



}