#include<iostream>
using namespace std;
 void delete_atbeg();
 void delete_atend();
struct Node{
	int valeu;
	Node* next;
	
};
Node* last=NULL;
void createnode(int val){
	Node* newnode=new Node();
	newnode->valeu=val;
	if(last==NULL){
	last=newnode;
	newnode->next=last;
	}
	else{
		newnode->next=last->next;
		last->next=newnode;
		last=newnode;
	}	
	
}
void insertbeg(int val){
	Node* newnode=new Node();
	newnode->valeu=val;
	if(last==NULL){
cout<<"Frist create the list!"<<endl;
	}
	else{
		newnode->next=last->next;
		last->next=newnode;
	}	}	
	void insertend(int val){
		Node* newnode=new Node();
		newnode->valeu=val;
		newnode->next=last->next;
		last->next=newnode;
		last=newnode;
	}
	void insert_spec(int val,int pos){
		
		Node* newnode=new Node();
		Node* temp;
		temp=last;
		for(int i=1;i<pos;i++){
		temp=temp->next;	
		}
		newnode->next=temp->next;
		newnode->valeu=val;
		temp->next=newnode;
	}
	void delete_atbeg(){
		Node* temp=new Node();
	 temp=last;
			if (temp== NULL){
cout<<"No item to delete \n";}
else if (temp->next==last)
{
 delete temp;
 last=NULL;
 return;
 }else
 	  temp=last->next;
		last->next=temp->next;
		delete temp;	
}
	void delete_atend(){
		Node* temp=new Node();
		Node* deleted_temp;
		temp=last;
	if (temp== NULL){
cout<<"No item to delete \n";  
}
else if (temp->next==last)
{
 delete temp;
 last=NULL;
 }else{
		while(temp->next!=last){
			temp=temp->next;
		}
		deleted_temp=temp->next;
		temp->next=last->next;
		delete deleted_temp;
		last=temp;
	}}
	void delete_at_spec(int pos){
	Node* temp;
	Node* prenode;
	temp=last;
				if (temp== NULL){
cout<<"No item to delete \n";
return ;}

else{
	temp=last->next;
 	for(int i=1;i<pos;i++){
    prenode=temp;
 	temp=temp->next;
	 }
	 if(pos==1){
	 	delete_atbeg();
	 }
	 else if(temp==last){delete_atend();return;}
else{

   prenode->next=temp->next;
    delete temp;}//deleting specific node
}
}
	void display(){
	Node* temp;
		if(last==NULL){
		cout<<"    list is empty nothing to display!"<<endl;	
		}
		else{
		temp=last->next;
		while(temp!=last){
			cout<<"\t"<<temp->valeu<<endl;
			temp=temp->next;
		}	
			cout<<"\t"<<temp->valeu<<endl;
		}
	}

int main(){

	int pos_in,val;
	int pos_del,counter;
	cout<<"enter the initial node:";
	cin>>val;
	createnode(val);
	cout<<"the new created NODE:\n";
	display();
	cout<<"enter how many elements you want to add at the beginning:";
	cin>>counter;
for(int i=1;i<=counter;i++){
	cout<<"enter the("<<i<<") element you want to insert:";
	cin>>val;
	insertbeg(val);	
	cout<<"here is when the("<<i<<") element is added at the beginning:\n";
	display();
}

	cout<<"enter how many elements you want to add at the end:";
	cin>>counter;
for(int i=1;i<=counter;i++){
	cout<<"enter the("<<i<<") element you want to insert at the end:";
	cin>>val;
insertend(val);
	cout<<"here is when the("<<i<<") element is added at the end:\n";
	display();
}
	cout<<"enter the position you want to put the Node:";
	cin>>pos_in; 
	cout<<"enter the valeu you want to insert: ";
	cin>>val;
insert_spec(val,pos_in);
	cout<<"here is when  "<<(val)<<"  is added at the  "<<(pos_in)<<"  position:\n";
	display();
	delete_atbeg();
	cout<<"here is when the node is deleted at the beginning position:\n";
	display();
	delete_atend();
		cout<<"here is when the node is deleted at the end position:\n";
	display();
		cout<<"enter the position you from you want delete the valeu:";
		cin>>pos_del;
	delete_at_spec(pos_del);
	cout<<"here is when the node is deleted at the "<<(pos_del)<<" position:\n";
	display();
}
