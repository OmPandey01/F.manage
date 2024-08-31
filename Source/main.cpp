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



void renameImg(imgdetail entry,string name){
    //This funtion takes structure containing file detail
    //and path of destination where we have to 
    string onlyPath= entry.path;
    string toRemove=entry.name;
    size_t pos=onlyPath.find(toRemove);
    if(pos != string::npos){
        onlyPath.erase(pos,toRemove.length());
    }

    string destin=onlyPath+name+entry.extension;

    rename(entry.path,destin);


}


void move(imgdetail entry,const string& destination){
    //This funtion takes structure containing file detail
    //and path of destination where we have to 
    string source= entry.path;

    string destin=destination+"/"+entry.name;

    rename(source,destin);


}


int main(){

    vector<imgdetail> images;

    getdetails("/home/om/Documents/folder_1",images);
    int count =000;
    for(const auto& img:images){
        renameImg(img,to_string(count));

        
        
        count++;


    }


//struct to store data



}