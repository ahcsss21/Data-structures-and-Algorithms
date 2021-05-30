//Creating,Traversing,display,Insertion,Deletion of Doubly linked list
//A.Harichandana, Roll no-100519733001,CSE Third SEM.
#include <iostream>
#include<stdlib.h>

using namespace std;
struct node{
    int data;
    struct node *prev;
    struct node *next;
}*head,*last;
void createlist(int n);
void insertatbeginning(int data);
void insertatend(int data);
void insertatpos(int pos,int data);
void deleteatbeginning();
void deleteatend();
void deleteatpos(int pos);
void displaylist();

int main()
{
    int data,n,pos;
    cout<<"Enter no of nodes: ";
    cin>>n;
    createlist(n);
    cout<<"Enter data to be inserted at beginning: ";
    cin>>data;
    insertatbeginning(data);
    cout<<"New data is: ";
    displaylist();
    cout<<"Enter data to be inserted at end: ";
    cin>>data;
    insertatend(data);
    cout<<"New data is: ";
    displaylist();
    cout<<"Enter data to be inserted,position: ";
    cin>>data>>pos;
    insertatpos(pos,data);
    cout<<"New data is: ";
    displaylist();
    deleteatbeginning();
    cout<<"New data is: ";
    displaylist();
    deleteatend();
    cout<<"New data is: ";
    displaylist();

    return 0;
}
void createlist(int n)
{
    struct node *newNode;
    int data,i;
    newNode=new node;
    if(newNode==NULL)
    {
        cout<<"Unable to allocate memory.";
    }
    else{
        cout<<"Enter data for first node: ";
        cin>>data;
        newNode->data=data;
        newNode->next=NULL;
        newNode->prev=NULL;
        head=newNode;
        last=newNode;
        for(i=2;i<=n;i++)
        {
            struct node *newNode;
            newNode=new node;
            if(newNode==NULL)
            {
                cout<<"unable to allocate memory.";
            }
            else{
                cout<<"Data for node: ";
                cin>>data;
                newNode->data=data;
                newNode->prev=last;
                newNode->next=NULL;
                last->next=newNode;
                last=newNode;
            }
        }
    }
}
void insertatbeginning(int data)
{
    struct node *newNode;
    newNode=new node;
    if(head==NULL)
    {
        cout<<"List is empty!";
    }
    else{
        newNode->data=data;
        newNode->next=head;
        newNode->prev=NULL;
        head->prev=newNode;
        head=newNode;
        cout<<"Data inserted!";
    }
}
void insertatend(int data)
{
    struct node *newNode;
    if(last==NULL)
    {
        cout<<"List is empty!";
    }
    else{
        newNode=new node;
        newNode->data=data;
        newNode->prev=last;
        newNode->next=NULL;
        last->next=newNode;
        last=newNode;
        cout<<"Data inserted!";
    }

}
void displaylist()
{
    struct node *temp;
    if(head==NULL)
    {
        cout<<"List is empty";
    }
    else{
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data;
            cout<<"\n";
            temp=temp->next;
        }
    }
}
void insertatpos(int pos,int data)
{
    int i;
    struct node *newNode,*temp;
    if(head==NULL)
    {
        cout<<"LIst is already empty!";
    }
    else{
        temp=head;
        i=1;
        while(i<pos-1 && temp!=NULL)
        {
            temp=temp->next;
            i++;
        }
        if(pos==1)
        {
            insertatbeginning(data);
        }
        else if(temp!=NULL)
        {
           newNode=(struct node*)malloc(sizeof(struct node));
           newNode->data=data;
           newNode->next=temp->next;
           newNode->prev=temp;
           if(temp->next==NULL)
           temp->next->prev=newNode;
           temp->next=newNode;
        }

        else
        cout<<"Invalid position!";
    }


}
void deleteatbeginning(){
    struct node *temp;
    if(head==NULL)
    {
        cout<<"LIst is already empty!";
    }
    else{
        temp=head;
        head=head->next;
        cout<<"Data deleted is: "<< temp->data;
        if(head!=NULL){
            head->prev=NULL;
        }
        free(temp);

    }

}
void deleteatend()
{
    struct node *temp;
    if(last==NULL)
    {
        cout<<"Unable to end!";
    }
    else
    {
        temp=last;
        last=last->prev;
        if(last!=NULL)
        {
            last->next=NULL;
        }
        free(temp);
        cout<<"Node deleted!";
    }
}
