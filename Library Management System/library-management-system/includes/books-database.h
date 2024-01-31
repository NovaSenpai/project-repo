#include "insert-books.h"

void fetchDataBase(LibraryCatalog &library) { 

library.insert(1234, "To Kill a Mockingbird", "Harper Lee", "Fiction");
library.insert(5678, "1984", "George Orwell", "Dystopian");
library.insert(9876, "The Great Gatsby", "F. Scott Fitzgerald", "Classic");
library.insert(5432, "Pride and Prejudice", "Jane Austen", "Romance");
library.insert(7890, "The Catcher in the Rye", "J.D. Salinger", "Coming of Age");
library.insert(6543, "Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "Fantasy");
library.insert(2109, "The Hobbit", "J.R.R. Tolkien", "Adventure");
library.insert(8765, "The Da Vinci Code", "Dan Brown", "Mystery");
library.insert(4321, "The Lord of the Rings", "J.R.R. Tolkien", "Fantasy");
library.insert(3456, "The Chronicles of Narnia", "C.S. Lewis", "Fantasy");
library.insert(3344, "The Odyssey", "Homer", "Epic");
library.insert(5566, "One Hundred Years of Solitude", "Gabriel Garcia Marquez", "Magical Realism");
library.insert(7788, "The Road", "Cormac McCarthy", "Post-Apocalyptic");
library.insert(9900, "Jane Eyre", "Charlotte Bronte", "Gothic");
library.insert(2211, "The Shawshank Redemption", "Stephen King", "Drama");
library.insert(4433, "Slaughterhouse-Five", "Kurt Vonnegut", "Satire");
library.insert(6655, "The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "Science Fiction");
library.insert(8877, "Moby-Dick", "Herman Melville", "Adventure");
library.insert(1099, "The Alchemist", "Paulo Coelho", "Philosophical Fiction");
library.insert(5566, "The Shining", "Stephen King", "Horror");
library.insert(9900, "The Road", "Cormac McCarthy", "Post-apocalyptic");
library.insert(2211, "Crime and Punishment", "Fyodor Dostoevsky", "Psychological Fiction");
library.insert(4433, "Frankenstein", "Mary Shelley", "Gothic");
library.insert(6655, "The Color Purple", "Alice Walker", "Drama");
library.insert(8877, "The Martian", "Andy Weir", "Science Fiction");
library.insert(2345, "The Picture of Dorian Gray", "Oscar Wilde", "Gothic");
library.insert(4567, "One Hundred Years of Solitude", "Gabriel García Márquez", "Magical Realism");
library.insert(6789, "The Kite Runner", "Khaled Hosseini", "Historical Fiction");
library.insert(8901, "The Handmaid's Tale", "Margaret Atwood", "Dystopian");
library.insert(1122, "The Road Not Taken", "Robert Frost", "Poetry");
library.insert(3344, "The Old Man and the Sea", "Ernest Hemingway", "Adventure");
library.insert(5566, "Wuthering Heights", "Emily Brontë", "Gothic");
library.insert(7788, "The Count of Monte Cristo", "Alexandre Dumas", "Adventure");
library.insert(9900, "Anna Karenina", "Leo Tolstoy", "Classics");
library.insert(2211, "Moby-Dick", "Herman Melville", "Adventure");
library.insert(4433, "Les Misérables", "Victor Hugo", "Historical Fiction");
library.insert(6655, "Dracula", "Bram Stoker", "Gothic");
library.insert(8877, "A Clockwork Orange", "Anthony Burgess", "Dystopian");
library.insert(1111, "The Metamorphosis", "Franz Kafka", "Surreal");
library.insert(2222, "The Brothers Karamazov", "Fyodor Dostoevsky", "Philosophical");
library.insert(3333, "The Iliad", "Homer", "Epic Poetry");
library.insert(4444, "The Odyssey", "Homer", "Epic Poetry");
library.insert(5555, "Percy Jackson and the Lightning Thief", "Rick Riordan", "Fantasy");
library.insert(6666, "The Girl with the Dragon Tattoo", "Stieg Larsson", "Mystery");
library.insert(7777, "The Alchemist", "Paulo Coelho", "Philosophical Fiction");
library.insert(8888, "The Wind in the Willows", "Kenneth Grahame", "Children's Literature");
library.insert(9999, "The Art of War", "Sun Tzu", "Philosophy");
library.insert(1010, "The Great Expectations", "Charles Dickens", "Classics");
library.insert(2020, "A Tale of Two Cities", "Charles Dickens", "Historical Fiction");
library.insert(3030, "The Hunchback of Notre-Dame", "Victor Hugo", "Gothic");
library.insert(4040, "The Three Musketeers", "Alexandre Dumas", "Historical Fiction");
library.insert(5050, "The War of the Worlds", "H.G. Wells", "Science Fiction");
library.insert(6060, "The Invisible Man", "H.G. Wells", "Science Fiction");
library.insert(7070, "The Hand of Ethelberta", "Thomas Hardy", "Satire");
library.insert(8080, "Around the World in Eighty Days", "Jules Verne", "Adventure");
library.insert(9090, "The Adventures of Sherlock Holmes", "Arthur Conan Doyle", "Mystery");
library.insert(1234, "The Adventures of Tom Sawyer", "Mark Twain", "Adventure");
library.insert(5678, "The War and Peace", "Leo Tolstoy", "Historical Fiction");
library.insert(9876, "The Sun Also Rises", "Ernest Hemingway", "Modernist");
library.insert(5432, "A Farewell to Arms", "Ernest Hemingway", "War Fiction");
library.insert(7890, "The Stranger", "Albert Camus", "Absurdist");
library.insert(6543, "The Road to Wigan Pier", "George Orwell", "Social Critique");
library.insert(2109, "The Fountainhead", "Ayn Rand", "Philosophical Fiction");
library.insert(8765, "The Grapes of Wrath", "John Steinbeck", "Social Realism");
library.insert(4321, "The Canterbury Tales", "Geoffrey Chaucer", "Middle English Poetry");
library.insert(3456, "The Divine Comedy", "Dante Alighieri", "Epic Poetry");


library.saveToFile("libraryData.txt");
}