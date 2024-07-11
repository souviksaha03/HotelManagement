#include<iostream>
using namespace std;
class Hotel{
    private:
    struct Node{
        int id, date;
        string name,roomtype;
        Node* next;
    };
    public:
    Node* head = NULL;
    void Allocate();
    void menu();
    void UpdateRoom();
    void SearchRoomData();
    void DelRoomData();
    void ShowRoom();

};

void Hotel::menu(){
    int choice;
    cout<<"/n";
    cout<<"\t ************welcome to Hotel Management System**************\n"<<endl;
    cout<<"\n\n S.No     Operations              Description"<<endl;
    cout<<"\n1\tAllocate the room\t\tAllocate new Room"<<endl;
    cout<<"\n2\tSearch room\t\tSearch room using room id"<<endl;
    cout<<"\n3\tUpdate room\t\tupdate Room description"<<endl;
    cout<<"\n4\tDelete Allocated Room\t\tDelete  Room allocation using room id"<<endl;
    cout<<"\n5 \tShow room Records\t\tShow room record"<<endl;
    cout<<"\n6 \texit "<<endl;

    cout<<"Enter your choice"<<endl;
    cin>> choice;
    
    switch(choice){
        case 1:
            Allocate();
            menu();
        break;
        case 2:
            SearchRoomData();
            menu();
            break;
        case 3:
            UpdateRoom();
            menu();
            break;
        case 4:
            DelRoomData();
            menu();
            break;
        case 5:
            ShowRoom();
            menu();
            break;
        case 6:
            exit(0);
            
    }
    }


void Hotel:: Allocate(){
    cout<<"\n\t__________Hotel Management System__________________";
    Node *newnode = new Node;
    cout<<endl<<"Enter Room Id"<<endl;
    cin>> newnode->id ;

    cout<<"Enter customer name"<<endl;
    cin>> newnode->name ;

    cout<<"Enter date"<<endl;
    cin>> newnode->date ;

    cout<<"Enter Room Type(single/double)"<<endl;
    cin>> newnode->roomtype;

    if(head== NULL){
        head= newnode;
    }
    else{
        Node *ptr = head;
        while(ptr->next !=  NULL){
           ptr=ptr->next;

        }
         ptr->next = newnode;
            
    }
    cout<<"\n\n\t\t New Room Allocated"<<endl;
    
}

void Hotel:: SearchRoomData(){
    cout<<"\n\t__________Hotel Management System__________________"<<endl;
    
    int id;
    if(head== NULL){
        cout<<"\n\nAll rooms are  Empty";
        
    }
    else{
        cout<<"Enter room id "<<endl;
        cin>>id;
        Node *ptr = head;
        while(ptr!=  NULL){
           if(id == ptr->id){
            cout<<"\n\nRoom Id"<<" "<<ptr->id<<" "<<"Customer name"<<" "<<ptr->name<<" "<<"Date"<<" "<<ptr->date<<" "<<"Room type"<<" "<<ptr->roomtype;
           }
        //    else{
            ptr=ptr->next;
        //    }

        }
    
            
    }
    
}

void Hotel:: UpdateRoom(){
    cout<<"\n\t__________Hotel Management System__________________";
    int id;
    if(head==NULL){
        cout<<"\n\nAll rooms are Empty";

    }
    else{
        cout<<"\n Enter Room Id"<<endl;
        cin>>id;
        Node *ptr = head;
        while(ptr!=NULL){
            if(id==ptr->id){
                cout<<"\n\n RoomId";
                cin>>ptr->id;
                  cout<<"\n\n Customer name";
                cin>>ptr->name;
                  cout<<"\n\n Allocated Date";
                cin>>ptr->date;
                  cout<<"\n\n Room Type";
                cin>>ptr->roomtype;

                cout<<"\n\n Romm Record Updated Successfully"<<endl;

            }
            ptr=ptr->next;
        }
        
    }
}

void Hotel::DelRoomData(){
    cout<<"\n\t__________Hotel Management System__________________";
    int id;
    if(head==NULL){
        cout<<"\n\nAll rooms are Empty";

    }
    else{
        cout<<"\n\n Enter Room Id"<<endl;
        cin>>id;
        if(id ==head->id){
            Node* ptr = head;
            head= head->next;
            delete ptr;
            cout<<"Room Record Deleted Successfully\n"<<endl;

        }
        else{
                Node *pte = head;
                Node *ptr= head;
                while(ptr!=NULL){
                    if(id == ptr->id){
                        pte->next = ptr->next;
                        delete ptr;
                        cout<<"Room Record Deleated Successfully"<<endl;
                        break;

                    }
                    pte=ptr;
                    ptr=ptr->next;

                }

        }
    }
}

void Hotel::ShowRoom(){
    Node* ptr = head;
    while(ptr!= NULL){
        cout<<"\n\nRoom Id"<<ptr->id;
         cout<<"\n\nCustomer Name"<<ptr->name;
          cout<<"\n\nDate"<<ptr->date;
           cout<<"\n\nRoom Type"<<ptr->roomtype;
           cout<<endl;
           ptr=ptr->next;
    }
}

int main(){
Hotel Htl;
Htl.menu();
}