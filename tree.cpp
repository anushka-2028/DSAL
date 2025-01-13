#include<iostream>
#include<string.h>

using namespace std;
struct node
{
  int count;
  string label;
  node* child[20];
 
}*root;

class tree1
{
public:
int i,j,k;
   int chapter;
   int sections;
   int subsections;
 tree1()
 {
   root=NULL;
 }
 void create()
 {
   
   root=new node;
   
   cout<<"\n ENTER NAME OF BOOK:";
   cin>>root->label;
   
   cout<<"\n ENTER NUMBER OF CHAPTERS :";
   cin>>chapter;
   
   
   
   for(i=0;i<chapter;i++)
   {
     root->child[i]=new node;
     cout<<"\n ENTER NAME OF CHAPTER "<<i+1<<":";
     cin>>root->child[i]->label;
     
     cout<<"\n  ENTER NUMBER OF SECTIONS IN CHAPTER"<<i+1<<":";
     cin>>sections;
     for(j=0;j<sections;j++)
     {
       root->child[i]->child[j]=new node;
       cout<<"\n  ENTER NAME OF SECTION "<<j+1<<":";
       cin>>root->child[i]->child[j]->label;
       
        cout<<"\n   ENTER NUMBER OF SUB-SECTIONS IN SECTION"<<j+1<<":";
        cin>>subsections;
        for(k=0;k<subsections;k++)
       {
       root->child[i]->child[j]->child[k]=new node;
       cout<<"\n       ENTER NAME OF SUB-SECTION "<<k+1<<":";
       cin>>root->child[i]->child[j]->child[k]->label;
       }
     }
   }
 }
 
 
 
 void display()
 {
  cout<<"\n----------BOOK HIERARCHY---------\n";
   cout<<"\nNAME OF BOOK :"<<root->label;
   cout<<"\n\n NUMBER OF CHAPTERS :"<<chapter;
   
   for(i=0;i<chapter;i++)
   {
     cout<<"\n NAME OF CHAPTER "<<i+1<<":"<<root->child[i]->label;  
     cout<<"\n  NUMBER OF SECTION IN CHAPTER"<<i+1<<":"<<sections;
     for(j=0;j<sections;j++)
     {
       cout<<"\n  NAME OF SECTION "<<j+1<<":"<<root->child[i]->child[j]->label;
       cout<<"\n    NUMBER OF SUB-SECTION IN SECTION "<<j+1<<":"<<subsections;
       
       for(k=0;k<subsections;k++)
       {
         cout<<"\n     NAME OF SUB-SECTION "<<k+1<<":"<<root->child[i]->child[j]->child[k]->label;
       }
     }
   }
 }
 
};


int main()
{
 tree1 t1;
 int ch;
 while(1)
 {
 cout<<"\n----------MENU---------\n";
 cout<<"\n1.ADD BOOK";
 cout<<"\n2.DISPLAY BOOK";
 cout<<"\n3.EXIT";
 
 cout<<"\n ENTER YOUR CHOICE :";
 cin>>ch;
 
 switch(ch)
 {
   case 1:
     t1.create();
   break;
   
   case 2:
     t1.display();
   break;
   
   case 3:
      exit(0);
   break;
   
   default:
      cout<<"\nENTER VALID CHOISE";
   break;
 }
}
 return 0;
}
