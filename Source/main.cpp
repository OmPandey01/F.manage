#include<iostream>
#include<string>
#include<filesystem>
#include<vector>

using namespace std;
using namespace std::filesystem;


struct fileInfo{

    string name;
    string extension;
    string path;
};


class Operations{

public:

        
    void getdetails(const string& folderpath,vector<fileInfo>& images){

        for(const auto& entry:directory_iterator(folderpath)){

                fileInfo  img;

                img.name=entry.path().filename().string();
                img.extension=entry.path().extension().string();
                img.path=entry.path().string();

                images.push_back(img);

        }
    }

            




   void findDuplicate(string d1,string d2){  
          
        vector<fileInfo> f1;

        vector<fileInfo> f2;


        int count=0;
        fileInfo f;

        create_directory("Common_files");


        for(const auto& file:directory_iterator(d1)){
            f.name=file.path().filename().string();
            f.extension=file.path().extension().string();

            f.path=file.path().string();            
            f1.push_back(f);
        }

        for(const auto& file :directory_iterator(d2)){

            f.name=file.path().filename().string();

            f.extension=file.path().extension().string();

            f.path=file.path().string();

            f2.push_back(f);

        }
            vector<string> name;

        for(const fileInfo& ft1:f1){
            for(const fileInfo& ft2:f2)
            {
                if(ft1.name ==ft2.name && ft1.extension==ft2.extension){
                    name.push_back(ft1.name);

                    count++;
                    move(ft1,"Common_files");
                    remove(ft2.path);

                }
    


            }

        }


            cout<<"These "<<count<<"Files were common and have been moved to"<<endl;
                count=1;
            for(string& n:name){
                

                cout<<count<<". "<<n<<endl;
                
                 count++;


            }  






        
    }


    void renameImg(fileInfo entry,string name){
        //This funtion takes structure containing file detail
        //and new name of file we want to give 
        string onlyPath= entry.path;
        string toRemove=entry.name;
        size_t pos=onlyPath.find(toRemove);
        if(pos != string::npos){
            onlyPath.erase(pos,toRemove.length());
        }

        string destin=onlyPath+name+entry.extension;

        rename(entry.path,destin);


    }


    void move(fileInfo entry,const string& destination){
        //This funtion takes structure containing file detail
        //and path of destination where we have to  move those files

        string targetPath=destination+"/"+entry.name;

        rename(entry.path,targetPath);


    }

};

// void lb(void){

//     cout<<"\033[32m ===================================================================================================================\033[0m"<<endl;

// }

// void sb(void){

//     cout<<endl<<endl;

// }



int main(){

    

    Operations op;

    op.findDuplicate("folder_1","folder_2");





}