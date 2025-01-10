#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

#define Books 200
struct Book 
{
    int bookID;
    char bookName[50];
    char authorName[50];
    char category[50];
    int price;
    int rating;
};

Book*books=new Book[Books]; //array to store book
int count=0;

// globally declared Functions
void addBook();
void removeBook();
void searchBook();
void booksByAuthor();
void booksByCategory();
void updateBook();
void top3Books();
void displayAllBooks();

int main() 
{
    int choice;
    while (1) 
	{
        cout <<"\nBook Management System\n";
        cout<<"1. Add Book\n";
        cout<<"2. Remove Book\n";
        cout<<"3. Search Book\n"; 
		cout<<"4. Books by Author\n";
		cout<<"5. Books by Category\n";
        cout<<"6. Update Book\n";
        cout<<"7. Top 3 Books by Price and Rating\n";
        cout<<"8. Display All Books\n";
        cout<<"Enter the choice: ";
        cin>>choice;

        switch (choice) 
		{
            case 1: addBook(); 
			break;
            case 2: removeBook(); 
			break;
            case 3: searchBook(); 
			break;
            case 4: booksByAuthor(); 
			break;
			case 5: booksByCategory(); 
			break;
            case 6: updateBook(); 
			break;
            case 7: top3Books(); 
			break;
            case 8: displayAllBooks(); 
			break;
            default: cout<<"Invalid choice\n";
        }
    }
    return 0;
}
void addBook() 
{
    if (count>= Books) 
	{
        cout<<"Book storage is full\n";
        return;
    }
    Book newBook;
    cout<<"\n-------------*--------------";
    cout<<"\nEnter Book ID: ";
    cin>> newBook.bookID;
    cout<<"Enter Book Name: ";
    cin>>newBook.bookName;
    cout<<"Enter Author Name: ";
    cin>>newBook.authorName;
    cout<<"Enter Category: ";
    cin>>newBook.category;
    cout<<"Enter Price: ";
    cin>>newBook.price;
    cout<<"Enter Rating: ";
    cin>>newBook.rating;

    books[count++]=newBook;
    cout<<"\nBook is added";
    cout<<"\n-------------*--------------";
}

void removeBook() 
{
	int bookID=0;
	int a=0;
	int found=0;
	cout<<"\n-------------*--------------";
	cout<<"\nEnter bookid to remove:";
	cin>>bookID;
	
    for(a=0;a<count;a++)
    {
    	if(books[a].bookID==bookID)
    	{
    		for(int b=a;b<count-1;b++)
    		{
    			books[b]=books[b+1];
    		}
    			count--;
    			found=1;
    			cout<<"\n-------------*--------------";
    			cout<<"\nBook is removed";
    			cout<<"\n-------------*--------------\n";
    			break;
		}
	}
		 if (!found) 
	{
		cout<<"\n-------------*--------------";
        cout<<"\nBook is not found";
        cout<<"\n-------------*--------------";
	}
}
void searchBook() 
{
    int bookID=0;
	int a=0;
	int found=0;
    cout<<"\n-------------*--------------";
    cout<<"\nEnter Book ID to search: ";
    cin>>bookID;
    for (a=0; a<count; a++) 
	{
        if (books[a].bookID==bookID) 
        
		{
            cout<<"\nBook ID:"<< books[a].bookID;
            cout<<"\nBook Name:"<< books[a].bookName;
            cout<<"\nAuthor Name: "<< books[a].authorName;
            cout<<"\nCategory:"<< books[a].category;
            cout<<"\nPrice: "<< books[a].price;
            cout<<"\nRating: "<< books[a].rating;
            cout<<"\n-------------*--------------";
            found = 1;
            break;
        }
    }
    if (!found) 
	{
        cout<<"\nBook is not found";
        cout<<"\n-------------*--------------";
    }
}

void booksByAuthor() 
{
    char author[50];
    int found = 0;
    cout<<"\n-------------*--------------";
    cout<<"\nEnter Author's Name: ";
    cin>>author;

    for (int a=0; a<count; a++) 
	{
        if (strcmp(books[a].authorName, author)==0) 
		{
            cout<<"\nBook ID:"<< books[a].bookID;
            cout<<"\nBook Name:"<< books[a].bookName;
            cout<<"\nCategory:"<< books[a].category;
            cout<<"\nPrice:"<< books[a].price;
            cout<<"\nRating:"<< books[a].rating;
            cout<<"\n-------------*--------------";
            found = 1;
        }
   }
    if (!found) 
	{
        cout<<"No books by author %s!\n",author;
       	cout<<"\n-------------*--------------";
    }
}

void booksByCategory()
{
    char category[50];
    int found = 0;
    cout<<"\n-------------*--------------";
    cout<<"\nEnter Category: ";
    cin>>category;

    for (int a=0; a<count; a++) 
	{
        if (strcmp(books[a].category, category)==0) 
		{
            cout<<"\nBook ID:"<< books[a].bookID;
            cout<<"Book Name:"<< books[a].bookName;
            cout<<"\nCategory:"<< books[a].category;
            cout<<"\nPrice:"<< books[a].price;
            cout<<"\nRating:"<<books[a].rating;
            cout<<"\n-------------*--------------";
            found = 1;
        }
   }
    if (!found) 
	{
        cout<<"\nNo books by category",category;
       	cout<<"\n-------------*--------------";
    }
}

void updateBook() 
{
    int bookID=0;
	int a=0;
	int found = 0;
    cout<<"\n-------------*--------------";
    printf("\nEnter Book ID: ");
    cin>>bookID;

    for (a=0; a<count; a++) 
	{
        if (books[a].bookID == bookID) 
		{
            cout<<"Enter new Book Name: ";
            cin>> books[a].bookName;
            cout<<"Enter new Author Name: ";
            cin>> books[a].authorName;
            cout<<"Enter new Category: ";
            cin>> books[a].category;
            cout<<"Enter new Price: ";
            cin>>books[a].price;
            cout<<"Enter new Rating: ";
            cin>>books[a].rating;

            cout<<"\nBook is updated";
            cout<<"\n-------------*--------------";
            found = 1;
            break;
        }
    }
    if (!found)
	{
        cout<<"\nBook not found";
        cout<<"\n-------------*--------------";
    }
}

void top3Books() 
{
   if (count<3) 
   {
       cout<<"\nNo books to show top 3";
       cout<<"\n-------------*--------------";
       return;
   }
   Book sortedBooks[Books];
   memcpy(sortedBooks,books,sizeof(books));
   int n = count;
    // Sort books by price
    for (int a = 0; a < n-1; a++) {
        for (int b = 0; b < n-a-1; b++) {
            if (sortedBooks[b].price < sortedBooks[b+1].price) {
                Book temp = sortedBooks[b];
                sortedBooks[b] = sortedBooks[b+1];
                sortedBooks[b+1] = temp;
            }
        }
    }
    cout<<"\n-------------*--------------";
    cout<<"\nTop 3 Books by Price are:";
    for (int a = 0; a < 3; a++) {
        cout<<"\nBook ID:"<< sortedBooks[a].bookID;
        cout<<"\nBook Name: " <<sortedBooks[a].bookName;
        cout<<"\nAuthor Name:"<< sortedBooks[a].authorName;
        cout<<"\nCategory:"<< sortedBooks[a].category;
        cout<<"\nPrice:"<<sortedBooks[a].price;
        cout<<"\nRating:" <<sortedBooks[a].rating;
    }
    // Sort books by rating
    for (int a = 0; a < n-1; a++) {
        for (int b= 0; b < n-a-1; b++) {
            if (sortedBooks[a].rating < sortedBooks[a+1].rating) {
                Book temp = sortedBooks[a];
                sortedBooks[a] = sortedBooks[a+1];
                sortedBooks[a+1] = temp;
            }
        }
    }
    cout<<"\n-------------*--------------";
    cout<<"\nTop 3 Books by Rating are:";
    for (int a = 0; a < 3; a++) {
        cout<<"\nBook ID:"<< sortedBooks[a].bookID;
        cout<<"\nBook Name:"<< sortedBooks[a].bookName;
        cout<<"\nAuthor Name:"<< sortedBooks[a].authorName;
        cout<<"\nCategory:"<< sortedBooks[a].category;
        cout<<"\nPrice:"<< sortedBooks[a].price;
        cout<<"\nRating:"<< sortedBooks[a].rating;
    }
}
void displayAllBooks() 
{
    if (count==0) 
	{
        cout<<"\n-------------*--------------";
        cout<<"\nNo Books";
		cout<<"\n-------------*--------------";
    return;
    }
    for (int a = 0; a < count; a++) 
	{
		cout<<"\n-------------*--------------";
        cout<<"\nBook ID:"<< books[a].bookID;
        cout<<"\nBook Name:"<< books[a].bookName;
        cout<<"\nAuthor Name:"<< books[a].authorName;
        cout<<"\nPrice:"<< books[a].price;
        cout<<"\nRating:"<< books[a].rating;
        cout<<"\n-------------*--------------";
    }
}

