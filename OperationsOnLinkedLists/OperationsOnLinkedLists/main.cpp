//
//  main.cpp
//  OperationOnLinkedLists
//
//  Created by Sakshil Verma
//

#include <iostream>
using namespace std;

//Create a node
struct node{
int data;
  struct node *next;
}*start1=NULL, *start2=NULL;
int n1=0,n2=0,indicator=0;

//merge both the lists
void merge(){
    node *p=start1;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=start2;
}

//delete a node from the linked list
node *del(node *start, int pos){
    if(start==NULL){
        cout<<"No elements to be deleted"<<endl;
        indicator=0;
    }
    else{
node *p=start;
  node *q=p->next;
  int i=2,flag=0;
  if(pos==1){
    start=q;
    flag=1;
  free(p);
  }
  else{
  while(p->next != NULL){
  if(i==pos){
  p->next=q->next;
    free(q);
    flag=1;
    break;
  }
    else{
    p=p->next;
        if(q->next != NULL){
      q=q->next;
        }
      i++;
    }
  }
  }
if(flag==0){
cout<<"Invalid position!"<<endl;
    indicator=0;
}
    }
    indicator=1;
    return start;
}

//sort the linked list
void sort(node *start,int n){
int i=0,temp;
    node *p=start;
    node *q=p;
    while(i<n){
        q=p;
        while(q->next!=NULL){
  if(q->data > q->next->data){
  temp=q->data;
    q->data=q->next->data;
    q->next->data=temp;
  }
            q=q->next;
  }
        i++;
  }
}

//print the linked list
void print(node *start){
if(start==NULL){
printf("list is empty\n");
}
  else{
    printf("Linked list : ");
  struct node *ptr=start;
    while(ptr->next != NULL){
    printf("-->%d",ptr->data);
      ptr=ptr->next;
    }
    printf("-->%d\n",ptr->data);
  }
}

//insert the element in the middle of the linked list
node *insert_middle(node *start,int pos, int v,int n){
node *newnode=(node*)malloc(sizeof(struct node));
  newnode->data=v;
  node *p=start;
    if(pos==1){
        newnode->next=p;
        start=newnode;
    }
    else if(n==pos){
        while(p->next!=NULL){
        p=p->next;
        }
        newnode->next=NULL;
        p->next=newnode;
    }
    else{
  int i=1;
  while(i<pos){
  p=p->next;
    i++;
  }
  newnode->next=p->next;
  p->next=newnode;
    }
    return start;
}

//insert the element in the end of the linked list
node *insert_end(node *start,int v){
node *new_node=(node*) malloc(sizeof(node));
  new_node->data=v;
  if(start==NULL){
  new_node->next=NULL;
    start=new_node;
  }
  else{
  node *ptr=start;
  while(ptr->next != NULL){
  ptr=ptr->next;
  }
    ptr->next=new_node;
    new_node->next=NULL;
  }
    return start;
}

//to find the index of a particular value in the linked list
int traverse(node *start, int v){
  int i=1,flag=0;
node *p=start;
  while(p != NULL){
    if(p->data==v){
    flag=1;
      break;
    }
    p=p->next;
    i++;
  }
  if(flag==1){
  return i;
  }
  return 0;
}

int main(int argc, const char * argv[]) {
    int e,in,temp,pos;
    cout<<"Hello and Welcome"<<endl<<"Here you can perform the operations like insert, delete, display & merge the elements of 2 linked lists -"<<endl;
    do{
        cout<<endl<<"Now To check if the lists are empty enter 1 and press enter"<<endl<<"To insert the element in the lists enter 2 and press enter"<<endl<<"To delete the element in the lists enter 3 and press enter"<<endl<<"To display the elements in the lists enter 4 and press enter"<<endl<<"To merge the elements of both the lists to list 1 enter 5 and press enter"<<endl<<"To end the assignment enter 0 and press enter"<<endl;
        cin>>in;
        //if user wants to check if the list is empty or not
        if(in==1){
            cout<<"For list 1 enter 1 or for list 2 enter 2 and press enter : ";
            cin>>temp;
            if(temp==1){
                if(n1==0){
                    cout<<"List 1 is empty"<<endl;
                }
                else cout<<"List 1 is not empty and it contains "<<n1<<" elements"<<endl;
            }
            else if(temp==2){
                if(n2==0){
                    cout<<"List 2 is empty"<<endl;
                }
                else cout<<"List 2 is not empty and it contains "<<n2<<" elements"<<endl;
            }
            else cout<<"Wrong input"<<endl;
        }
        //if user wants to insert a element in the list
        else if(in==2){
            cout<<"For list 1 enter 1 or for list 2 enter 2 and press enter : ";
            cin>>temp;
            if(temp==1){
                cout<<"To insert in the end enter 1 or to insert in the middle enter 2 and press enter : ";
                cin>>temp;
                if(temp==1){
          cout<<"Enter element ";
      cin>>e;
        start1=insert_end(start1,e);
                    n1++;
            }
                else if(temp==2){
                    cout<<"To enter the element after a specific element then enter 1 or to enter the element at a particular index enter 2 and press enter : ";
                    cin>>temp;
                    if(temp==1){
                        cout<<"Enter the value of the element after which you need to enter your next element : ";
                        cin>>temp;
                        pos=traverse(start1,temp);
                        if(pos==0){
                            cout<<"Element not found"<<endl;
                        }
                        else{
                        cout<<"Now enter the element to be inserted and press enter : ";
                        cin>>e;
                        start1=insert_middle(start1,pos,e,n1);
                        n1++;
                        }
                        
                    }
                    else if(temp==2){
                        cout<<"Enter the index at which you need to enter your next element : ";
                        cin>>pos;
                        if(pos>n1){
                            cout<<"Invalid index"<<endl;
                        }
                        else{
                        cout<<"Now enter the element to be inserted and press enter : ";
                        cin>>e;
                        start1=insert_middle(start1,pos,e,n1);
                        n1++;
                        }
                    }
                    else cout<<"Wrong input"<<endl;
                }
                else cout<<"Wrong input"<<endl;
        }
            else if(temp==2){
                cout<<"To insert in the end enter 1 or to insert in the middle enter 2 and press enter : ";
                cin>>temp;
                if(temp==1){
          cout<<"Enter element ";
      cin>>e;
        start2=insert_end(start2,e);
                    n2++;
            }
                else if(temp==2){
                    cout<<"To enter the element after a specific element then enter 1 or to enter the element at a particular index enter 2 and press enter : ";
                    cin>>temp;
                    if(temp==1){
                        cout<<"Enter the value of the element after which you need to enter your next element : ";
                        cin>>temp;
                        pos=traverse(start2,temp);
                        if(pos==0){
                            cout<<"Element not found"<<endl;
                        }
                        else{
                        cout<<"Now enter the element to be inserted and press enter : ";
                        cin>>e;
                        start2=insert_middle(start2,pos,e,n1);
                        n2++;
                        }
                    }
                    else if(temp==2){
                        cout<<"Enter the index at which you need to enter your next element : ";
                        cin>>pos;
                        if(pos>n2){
                            cout<<"Invalid index"<<endl;
                        }
                        else{
                        cout<<"Now enter the element to be inserted and press enter : ";
                        cin>>e;
                        start2=insert_middle(start2,pos,e,n1);
                        n2++;
                        }
                        
                    }
                    else cout<<"Wrong input"<<endl;
                }
                else cout<<"Wrong input"<<endl;
            }
            else cout<<"Wrong input"<<endl;
        }
        //if user wants to delete a element in the list
        else if(in==3){
            cout<<"For list 1 enter 1 or for list 2 enter 2 and press enter : ";
            cin>>temp;
            if(temp==1){
                cout<<"Enter the position of the element which you want to delete : ";
                cin>>pos;
                if(pos>n1){
                    cout<<"Invalid Position"<<endl;
                }
                else{
                start1=del(start1,pos);
                if(indicator==1){
                    n1--;
                }
                    
                }
            }
            else if(temp==2){
                cout<<"Enter the position of the element which you want to delete : ";
                cin>>pos;
                if(pos>n2){
                    cout<<"Invalid Position"<<endl;
                }
                else{
                start2=del(start2,pos);
                if(indicator==1){
                    n2--;
                }
                    
                }
            }
            else cout<<"Wrong input"<<endl;
        }
        
        //if user wants to display the elements of the list
        else if(in==4){
            cout<<"For list 1 enter 1 or for list 2 enter 2 and press enter : ";
            cin>>temp;
            if(temp==1){
                print(start1);
            }
            else if(temp==2){
                print(start2);
            }
            else cout<<"Wrong input"<<endl;
        }
        //if user wants to merge both the lists
        else if(in==5){
            if(start1==NULL){
                cout<<"List 1 is empty can't be merged with list 2"<<endl;
            }
            else if(start2==NULL){
                cout<<"List 2 is empty can't be merged with list 1"<<endl;
            }
            else{
            merge();
    sort(start1,n1+n2);
            }
            
        }
    }while(in!=0);
    cout<<endl<<"Thankyou!!"<<endl;
        return 0;
}
