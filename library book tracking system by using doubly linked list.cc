#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book{
int bookID;
char title[50];
char author[50];
char status[20];
char studentName[50];
char issueDate[20];
char returnDate[20];
struct Book *prev;
struct Book *next;
};

struct Book *head=NULL;

void addBook(){
struct Book *newBook=(struct Book*)malloc(sizeof(struct Book));

if(newBook==NULL){
printf("Memory allocation failed\n");
return;
}

printf("\nEnter Book ID: ");
scanf("%d",&newBook->bookID);

printf("Enter Book Title: ");
scanf(" %[^\n]",newBook->title);

printf("Enter Author Name: ");
scanf(" %[^\n]",newBook->author);

strcpy(newBook->status,"Available");
strcpy(newBook->studentName,"None");
strcpy(newBook->issueDate,"None");
strcpy(newBook->returnDate,"None");

newBook->prev=NULL;
newBook->next=NULL;

if(head==NULL){
head=newBook;
}
else{
struct Book *temp=head;
while(temp->next!=NULL){
temp=temp->next;
}
temp->next=newBook;
newBook->prev=temp;
}

printf("\nBook added successfully\n");
}

void displayBooks(){
struct Book *temp=head;

if(head==NULL){
printf("\nNo books available\n");
return;
}

printf("\nLibrary Records\n");

while(temp!=NULL){
printf("\nBook ID: %d",temp->bookID);
printf("\nTitle: %s",temp->title);
printf("\nAuthor: %s",temp->author);
printf("\nStatus: %s",temp->status);
printf("\nStudent: %s",temp->studentName);
printf("\nIssue Date: %s",temp->issueDate);
printf("\nReturn Date: %s\n",temp->returnDate);
temp=temp->next;
}
}

void searchBook(){
int id;
struct Book *temp=head;

printf("\nEnter Book ID: ");
scanf("%d",&id);

while(temp!=NULL){
if(temp->bookID==id){
printf("\nBook Found\n");
printf("Title: %s\n",temp->title);
printf("Author: %s\n",temp->author);
printf("Status: %s\n",temp->status);
return;
}
temp=temp->next;
}

printf("Book not found\n");
}

void issueBook(){
int id;
struct Book *temp=head;

printf("\nEnter Book ID to issue: ");
scanf("%d",&id);

while(temp!=NULL){
if(temp->bookID==id){
if(strcmp(temp->status,"Issued")==0){
printf("Already issued\n");
return;
}

strcpy(temp->status,"Issued");

printf("Enter Student Name: ");
scanf(" %[^\n]",temp->studentName);

printf("Enter Issue Date: ");
scanf(" %[^\n]",temp->issueDate);

printf("Enter Return Date: ");
scanf(" %[^\n]",temp->returnDate);

printf("Book issued\n");
return;
}
temp=temp->next;
}

printf("Book not found\n");
}

void returnBook(){
int id;
struct Book *temp=head;

printf("\nEnter Book ID to return: ");
scanf("%d",&id);

while(temp!=NULL){
if(temp->bookID==id){
if(strcmp(temp->status,"Available")==0){
printf("Already available\n");
return;
}

strcpy(temp->status,"Available");
strcpy(temp->studentName,"None");
strcpy(temp->issueDate,"None");
strcpy(temp->returnDate,"None");

printf("Book returned\n");
return;
}
temp=temp->next;
}

printf("Book not found\n");
}

void deleteBook(){
int id;
struct Book *temp=head;

printf("\nEnter Book ID to delete: ");
scanf("%d",&id);

while(temp!=NULL){
if(temp->bookID==id){

if(temp->prev!=NULL)
temp->prev->next=temp->next;
else
head=temp->next;

if(temp->next!=NULL)
temp->next->prev=temp->prev;

free(temp);

printf("Deleted\n");
return;
}
temp=temp->next;
}

printf("Book not found\n");
}

void displayReverse(){
struct Book *temp=head;

if(head==NULL){
printf("No books\n");
return;
}

while(temp->next!=NULL)
temp=temp->next;

printf("\nReverse Order\n");

while(temp!=NULL){
printf("\nID: %d",temp->bookID);
printf("\nTitle: %s\n",temp->title);
temp=temp->prev;
}
}

void countBooks(){
int count=0;
struct Book *temp=head;

while(temp!=NULL){
count++;
temp=temp->next;
}

printf("\nTotal books: %d\n",count);
}

int main(){
int choice;

while(1){
printf("\n1.Add 2.Display 3.Search 4.Issue 5.Return 6.Delete 7.Reverse 8.Count 9.Exit\n");
printf("Enter choice: ");
scanf("%d",&choice);

switch(choice){
case 1: addBook(); break;
case 2: displayBooks(); break;
case 3: searchBook(); break;
case 4: issueBook(); break;
case 5: returnBook(); break;
case 6: deleteBook(); break;
case 7: displayReverse(); break;
case 8: countBooks(); break;
case 9: exit(0);
default: printf("Invalid\n");
}
}

return 0;
}