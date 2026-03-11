#include <iostream>
#include<string>


using namespace std;

struct Node{
  string word;
    Node* next;
    Node(string val):word(val),next(nullptr){}

};

void  ekleme(Node*& head,string yenikelime){
    Node* Node2=new Node(yenikelime);
    if(head==nullptr){
            head=Node2;
    return;
    }
       Node* temp=head;
       while(temp->next!=nullptr){
            temp=temp->next;
       }
       temp->next=Node2;
}

void undo(Node*& head){

    if(head==nullptr){

        cout<<"Liste zaten bos"<< endl;
           return;
    }


    if(head->next==nullptr){
            delete head;
              head=nullptr;

     return;
    }

      Node* temp=head;
      while(temp->next->next!=nullptr){
            temp=temp->next;
      }


      delete temp->next;
      temp->next=nullptr;
    }


void display(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<"[" <<temp->word <<"] ->";
          temp=temp->next;
    }
    cout<<"NULL"<<endl;


}




int main()
{
Node* head=nullptr;
string input;
cout<<"(UNDO:son kelimeyi sil,EXIT:cikis)"<<endl;
while(true){
            cout<<"Kelime girin:";
            cin>>input;

if(input=="EXIT"){
        break;
}
else if(input == "UNDO"){
        undo(head);

}else{
    ekleme(head,input);
}
display(head);
}






    return 0;
}



