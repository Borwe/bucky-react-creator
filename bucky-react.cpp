#include <iostream>
#include <experimental/filesystem>
#include <string>
#include <cstdlib>

using namespace std;

class CreateProject{
    private:
        string ex_no;
        string files_dest;
        string files_origin;

    public:
        CreateProject(string &ex){
            ex_no=ex;
            files_origin="~/bucky-react-boilerplate/React-Boilerplate";
            files_dest="~/htdocs/buck-react/"+ex_no;
        }

        void transfer_files(){

           experimental::filesystem::path p=files_dest.c_str();
           if(experimental::filesystem::exists(p)){
                cout<<"File directory already exists,"
                    <<"remove it please. and try again"<<endl;
           }else{
            cout<<"Starting to move files...."<<endl;

            string cmd="cp -R ";//copy command
            cmd=cmd+files_origin+"*";//files to copy
            cmd=cmd+" "+files_dest;
            system(cmd.c_str());

            cout<<"Done moving files."<<endl;
           }
        }
};

int main(){
    cout<<"Enter the project name to create a  Bucky React project"<<endl;
    string no;
    getline(cin,no);
    if(no.length()<1){
        cout<<"Please enter something more reasonable."<<endl;
    }else{
        CreateProject proj(no);
        proj.transfer_files();
    }
    return 0;
}
