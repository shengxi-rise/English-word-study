#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int welcome();
int learn();
int review();

int welcome(){                                                     
    cout <<" _ __ ___   ___ _ __  _ __ ___   ___  _ __ _   _ " << endl;
    cout <<"| '_ ` _ \\ / _ \\ '_ \\| '_ ` _ \\ / _ \\| '__| | | |" << endl;
    cout <<"| | | | | |  __/ | | | | | | | | (_) | |  | |_| |" << endl;
    cout <<"|_| |_| |_|\\___|_| |_|_| |_| |_|\\___/|_|   \\__, |" << endl;
    cout <<"                                            __/ |" << endl;
    cout <<"                                           |___/ " << endl;
    cout << "Please read the introduction before use ^_^" << endl;
    return 0;
}


int learn(){
    fstream hist;   //��¼ָ��λ��
    fstream cfile;   //��ȡ���ʶ�Ӧ������
    fstream efile;  //��ȡӢ�ﵥ��
    fstream wefile;  //д���ѿ�����
    fstream wcfile;  //д���ѿ�����
    long pose;   //�洢���������ָ���λ��
    long posc;    //�洢���������ָ��λ��

    //��ȡ��ʷ��¼
    hist.open("history",ios::in);
    hist >> pose;
    hist >> posc;
    hist.close();

    //Ӣ��
    char letter[30]={""};
    string english[30]={""};
    efile.open("english.log",ios::in);
    efile.seekp(pose);
    for(int i=0;i<10;i++){
        efile >> letter;
        english[i]=letter;
    }
    pose=efile.tellp();
    efile.close();

    //����
    wefile.open("english1.log",ios::app);
    for(int i=0;i<10;i++){
        wefile << english[i] << endl;
    }
    wefile.close();


    //����
    char character[100]={""};
    string chinese[40]={""};
    cfile.open("chinese.log",ios::in);
    cfile.seekp(posc);
    for(int n=0;n<10;n++){
        cfile >> character;
        chinese[n]=character;
    }
    posc=cfile.tellp();
    cfile.close();

    //����
    wcfile.open("chinese1.log",ios::app);
    for(int i=0;i<10;i++){
        wcfile << chinese[i] << endl;
    }
    wcfile.close();

    hist.open("history",ios::out);
    hist << pose << endl;
    hist << posc;
    hist.close();

/*
    //��ʼ
    for(int i=0;i<10;i++){
        cout << i+1 << ". " << english[i] << endl;
    }
    string an;
    while(1){
        cout << "Please input enter to check your answer ^_^ :";
        cin >> an;
   
        if(an=="check"){
            
            for(int i=0;i<10;i++){
                cout << i+1 << ". " << chinese[i] << endl;
            }
            break;
        }else{
            cout << "input check" << endl;
        }
    }
}
*/
    for(int i=0;i<10;i++){
        cout << english[i] << "     " << chinese[i] << endl;
    }
    return 0;
}

int review(){
    fstream hist;   //��¼ָ��λ��
    fstream cfile;   //��ȡ���ʶ�Ӧ������
    fstream efile;  //��ȡӢ�ﵥ��
    fstream wefile;  //д���ѿ�����
    fstream wcfile;  //д���ѿ�����
    long pose;   //�洢���������ָ���λ��
    long posc;    //�洢���������ָ��λ��

    //��ȡ��ʷ��¼
    hist.open("r_history",ios::in);
    hist >> pose;
    hist >> posc;
    hist.close();

    //Ӣ��
    char letter[30]={""};
    string english[30]={""};
    efile.open("english1.log",ios::in);
    efile.seekp(pose);
    for(int i=0;i<10;i++){
        efile >> letter;
        english[i]=letter;
    }
    pose=efile.tellp();
    efile.close();


    //����
    char character[100]={""};
    string chinese[40]={""};
    cfile.open("chinese1.log",ios::in);
    cfile.seekp(posc);
    for(int n=0;n<10;n++){
        cfile >> character;
        chinese[n]=character;
    }
    posc=cfile.tellp();
    cfile.close();


    hist.open("r_history",ios::out);
    hist << pose << endl;
    hist << posc;
    hist.close();

/*
    //��ʼ
    for(int i=0;i<10;i++){
        cout << i+1 << ". " << english[i] << endl;
    }
    cin.get();
    cin.get();
    cout << "Please input enter to check your answer ^_^" << endl;
    for(int i=0;i<10;i++){
        cout << i+1 << ". " << chinese[i] << endl;
    }
    
}
*/
    for(int i=0;i<10;i++){
        cout << i+1 << ". " << english[i] << endl;
    }
    string an;
    while(1){
        cout << "Please input enter to check your answer ^_^ :";
        cin >> an;
   
        if(an=="check"){
            
            for(int i=0;i<10;i++){
                cout << i+1 << ". " << chinese[i] << endl;
            }
            break;
        }else{
            cout << "input check" << endl;
        }
    }
    return 0;
}

int main(){
    welcome();
    while(1){
        char choose;
        cout << endl << "If you want to exit please enter 'q',\nlearn or review ,case1 is learn,2 is review:";
        cin >> choose;
        cout << endl; 
        if(choose=='1'){
            learn();
          
        }else if(choose=='2'){
            review();
        
        }else if(choose=='q'){
            cout << "Thank you for your use!" << endl;
            break;
        }else{
            cout << "please make a choose!";
        }
    }
    return 0;
}

