#include<iostream>
#include<string>
#include<filesystem>
#include<vector>
#include<chrono>

using namespace std;
using namespace std::filesystem;


struct fileInfo{

    string name;
    string extension;
    string path;
    double size;
    time_t lmTime;

};













class Operations{

public:

        
    void getdetails(const string& folderpath,vector<fileInfo>& images){

        for(const auto& entry:directory_iterator(folderpath)){

                fileInfo  img;

                img.name=entry.path().filename().string();
                img.extension=entry.path().extension().string();
                img.path=entry.path().string();
                img.size=file_size(img.path);
                images.push_back(img);

        }
    }

            




   void findDuplicate(string d1,string d2,string fname){  

        int choice;
        vector<string> folders;
        
          
        vector<fileInfo> f1;

        vector<fileInfo> f2;


        int count=0;

        fileInfo tempFile;

        create_directory(fname);


        for(const auto& file:directory_iterator(d1)){

            tempFile.name=file.path().filename().string();
            tempFile.extension=file.path().extension().string();

            tempFile.path=file.path().string();            
            f1.push_back(tempFile);
        }

        for(const auto& file :directory_iterator(d2)){

            tempFile.name=file.path().filename().string();

            tempFile.extension=file.path().extension().string();

            tempFile.path=file.path().string();

            f2.push_back(tempFile);

        }
            vector<string> name;

        for(const fileInfo& ft1:f1){
            for(const fileInfo& ft2:f2)
            {
                if(ft1.name ==ft2.name && ft1.extension==ft2.extension){
                    name.push_back(ft1.name);

                    count++;
                    move(ft1,fname);
                    remove(ft2.path);

                }
    


            }

        }


            cout<<"These "<<"  "<<count<<"Files were common and have been moved to"<<fname<<endl;
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

        string fName=onlyPath+name+entry.extension;

        rename(entry.path,fName);


    }

    void patternRenaming(string path,int choice){

        int number=000;
        vector<fileInfo> file;
        getdetails(path,file);

        string name;
        string prefix;
        if (choice==1){
                
                cout<<"Enter First few Words: ";
                 
                 cin>>prefix;
            }
           

        for(auto& f:file){
            if(choice==0){
                if(f.extension==".jpg" || f.extension==".png" || f.extension==".jpeg" || f.extension==".gif"){
                    name="Img_"+to_string(number);
                    
                }
                 if(f.extension==".pdf" || f.extension==".pptx" || f.extension==".docx"  ){
                    name="Doc_"+to_string(number);
                    
                }       
                if(f.extension==".mp4" || f.extension==".mkv" || f.extension==".mov"  ){
                    name="Vid_"+to_string(number);
                    
                }
            }
            else if (choice==1){

                 name=prefix+"_"+to_string(number);
                 
                 
            }

            renameImg(f,name);
            number++;
        }
    }

            






    void move(fileInfo entry,const string& destination){
        //This funtion takes structure containing file detail
        //and path of destination where we have to  move those files

        string targetPath =destination+"/"+entry.name;

        rename(entry.path,targetPath);


    }

    void organise(string& path) {
    vector<fileInfo> files;
    getdetails(path, files);

    // Create folders using create_directories funtion
    
     create_directory(path+"/Images");
    create_directory(path+"/Documents");
    create_directory(path+"/Videos"); 
    create_directory(path+"/others");
    
    for (auto& f : files) {
        try{
            if (f.extension == ".jpg" || f.extension == ".png" ||
                f.extension == ".jpeg" || f.extension == ".gif") {
                move(f, path + "/Images");
            } else if (f.extension == ".pdf" || f.extension == ".pptx" ||
                       f.extension == ".docx") {
                move(f, path + "/Documents");
            } else if (f.extension == ".mp4" || f.extension == ".mkv" ||
                       f.extension == ".mov") {
                move(f, path + "/Videos");
            } 
            
            else{
                if(f.extension!=""){
                    move(f,path+"/others");
                }
            }



            
        } 

     catch (const filesystem_error& e) {
            cerr << "Error moving theese filea: " << e.what() << endl;
        }
    }
    
}

};

void openDir(string& directoryPath) {
    string command = "xdg-open \"" + directoryPath + "\"";
    system(command.c_str());
    
}



int main(){

    system("clear");

    Operations op;

    vector<fileInfo> files;
    

  
    int sChoice;
    cout<<"\033[33m \033[1m *******************************Dynamic File Management Tool***************************************\033[32m"<<endl;
    cout<<"1>Renaming "<<endl<<endl;
    cout<<"2>finding Common Files in two folders "<<endl<<endl;
        cout<<"3>Organise Files"<<endl<<endl;

    cout<<"Enter Your choice :";

    cin>>sChoice;

    system("clear");
    cout<<"\033[33m \033[1m *******************************Dynamic File Management Tool***************************************\033[32m"<<endl;


    int choice1;
    string path1,path2,path;

    

switch (sChoice){
    case 1:
        cout<<endl<<"Enter 0 for Automatic Rename based on file name"<<endl<<endl;
        cout<<" Enter 1 for your choosen name"<<endl<<endl;
        cout<<" Enter choice:";
        cin>>choice1;
        system("clear");

    cout<<"\033[33m \033[1m *******************************Dynamic File Management Tool***************************************\033[32m"<<endl;


        cout<<endl<<"Enter path:";

        cin>>path;
        



        op.patternRenaming(path,choice1);
        openDir(path);
        

        break;

    case 2:
        cout<<"Enter path folders"<<endl;
        cout<<"Path 1 :";
        cin>>path1;
        cout<<endl;
        cout<<"Path 2 :";
        cout<<endl;
        cin>>path2;
        cout<<endl;
        cout<<"Path to store:";

        cin>>path;

        op.findDuplicate(path1,path2,path);
        break;
    case 3:
        cout<<"Enter Path:";
        cin>>path;
        op.organise(path);
        break;

    case 4:


        break;
    default:
        cout<<"Please Run the program again and Enter correct option!!";
        break;
    

    }

}

