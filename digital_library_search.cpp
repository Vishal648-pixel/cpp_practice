#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Book Structure
struct Book {
  int bookID;
  string title;
  string author;
  string genre;
  int pages;
  float rating;
  int year;
};

class DigitalLibrary {
private:
  Book* books;
  int totalBooks;
  int searchComparisons;
  
public:
  // Constructor
  DigitalLibrary(int size) {
    totalBooks = size;
    books = new Book[size];
    searchComparisons = 0;
  }
  
  // Add book to library
  void addBook(int index, int id, string title, string author, 
               string genre, int pages, float rating, int year) {
    books[index].bookID = id;
    books[index].title = title;
    books[index].author = author;
    books[index].genre = genre;
    books[index].pages = pages;
    books[index].rating = rating;
    books[index].year = year;
  }
  
  // BINARY SEARCH BY TITLE
  int searchByTitle(string searchTitle) {
    searchComparisons = 0;
    
    int left = 0;
    int right = totalBooks - 1;
    
    while(left <= right) {
      searchComparisons++;
      int mid = left + (right - left) / 2;
      
      if(books[mid].title == searchTitle) {
        return mid;
      }
      else if(searchTitle > books[mid].title) {
        left = mid + 1;
      }
      else {
        right = mid - 1;
      }
    }
    
    return -1;
  }
  
  // Display book details
  void displayBook(int index) {
    if(index == -1) {
      cout << "\n❌ Book not found in library!" << endl;
      return;
    }
    
    cout << "\n" << "╔════════════════════════════════════════╗" << endl;
    cout << "║          BOOK FOUND - DETAILS           ║" << endl;
    cout << "╠════════════════════════════════════════╣" << endl;
    cout << "║ Book ID:     " << books[index].bookID << endl;
    cout << "║ Title:       " << books[index].title << endl;
    cout << "║ Author:      " << books[index].author << endl;
    cout << "║ Genre:       " << books[index].genre << endl;
    cout << "║ Pages:       " << books[index].pages << endl;
    cout << "║ Rating:      " << books[index].rating << "/5" << endl;
    cout << "║ Published:   " << books[index].year << endl;
    cout << "║ Search took: " << searchComparisons << " comparisons" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
  }
  
  // Display all books
  void displayAllBooks() {
    cout << "\n" << "═══════════════════════════════════════════════════════════" << endl;
    cout << "DIGITAL LIBRARY CATALOG (SORTED BY TITLE):" << endl;
    cout << "═══════════════════════════════════════════════════════════" << endl;
    
    for(int i = 0; i < totalBooks; i++) {
      cout << (i+1) << ". \"" << books[i].title << "\" by " 
           << books[i].author << " (" << books[i].year << ")" << endl;
    }
  }
  
  // Get comparison count
  int getComparisons() {
    return searchComparisons;
  }
  
  // Destructor
  ~DigitalLibrary() {
    delete[] books;
  }
};

int main() {
  
  cout << "\n╔═══════════════════════════════════════════════════════════╗" << endl;
  cout << "║     DIGITAL LIBRARY MANAGEMENT SYSTEM                      ║" << endl;
  cout << "║     Using Binary Search (Fast & Efficient)                 ║" << endl;
  cout << "╚═══════════════════════════════════════════════════════════╝" << endl;
  
  // Create library with 15 books
  DigitalLibrary library(15);
  
  // Add books (SORTED BY TITLE - REQUIRED FOR BINARY SEARCH)
  library.addBook(0, 101, "1984", "George Orwell", "Dystopian", 328, 4.2, 1949);
  library.addBook(1, 102, "Atomic Habits", "James Clear", "Self-Help", 416, 4.6, 2018);
  library.addBook(2, 103, "Dune", "Frank Herbert", "Sci-Fi", 688, 4.5, 1965);
  library.addBook(3, 104, "Educated", "Tara Westover", "Memoir", 352, 4.5, 2018);
  library.addBook(4, 105, "Game of Thrones", "George Martin", "Fantasy", 694, 4.4, 1996);
  library.addBook(5, 106, "Grandpa's Gun", "Etc", "Fiction", 250, 4.1, 2010);
  library.addBook(6, 107, "Harry Potter", "JK Rowling", "Fantasy", 309, 4.7, 1997);
  library.addBook(7, 108, "Mindset", "Carol Dweck", "Psychology", 276, 4.3, 2006);
  library.addBook(8, 109, "Sapiens", "Yuval Harari", "Non-fiction", 443, 4.6, 2011);
  library.addBook(9, 110, "The Hobbit", "JRR Tolkien", "Fantasy", 366, 4.6, 1937);
  library.addBook(10, 111, "The Power of Now", "Eckhart Tolle", "Spirituality", 272, 4.4, 1997);
  library.addBook(11, 112, "Thinking Fast", "Daniel Kahneman", "Psychology", 499, 4.4, 2011);
  library.addBook(12, 113, "Twilight", "Stephenie Meyer", "Romance", 544, 3.9, 2005);
  library.addBook(13, 114, "Wings of Fire", "Apj Abdul Kalam", "Biography", 310, 4.5, 1999);
  library.addBook(14, 115, "Zero to One", "Peter Thiel", "Business", 237, 4.3, 2014);
  
  // Display library
  library.displayAllBooks();
  
  // SEARCH TESTS
  cout << "\n\n" << "═══════════════════════════════════════════════════════════" << endl;
  cout << "SEARCH TESTS - BINARY SEARCH IN ACTION" << endl;
  cout << "═══════════════════════════════════════════════════════════" << endl;
  
  // Test 1: Search at beginning
  cout << "\n\n📚 TEST 1: Search for book at BEGINNING" << endl;
  cout << "───────────────────────────────────────" << endl;
  cout << "Searching for: \"1984\"" << endl;
  
  int result1 = library.searchByTitle("1984");
  library.displayBook(result1);
  cout << "⚡ Comparisons: " << library.getComparisons() << " (log2(15) ≈ 4)" << endl;
  
  // Test 2: Search in middle
  cout << "\n\n📚 TEST 2: Search for book in MIDDLE" << endl;
  cout << "──────────────────────────────────────" << endl;
  cout << "Searching for: \"Harry Potter\"" << endl;
  
  int result2 = library.searchByTitle("Harry Potter");
  library.displayBook(result2);
  cout << "⚡ Comparisons: " << library.getComparisons() << " (Very fast!)" << endl;
  
  // Test 3: Search at end
  cout << "\n\n📚 TEST 3: Search for book at END" << endl;
  cout << "─────────────────────────────────────" << endl;
  cout << "Searching for: \"Zero to One\"" << endl;
  
  int result3 = library.searchByTitle("Zero to One");
  library.displayBook(result3);
  cout << "⚡ Comparisons: " << library.getComparisons() << " (Still fast!)" << endl;
  
  // Test 4: Book not in library
  cout << "\n\n📚 TEST 4: Search for NON-EXISTENT book" << endl;
  cout << "──────────────────────────────────────────" << endl;
  cout << "Searching for: \"The Lord of the Rings\"" << endl;
  
  int result4 = library.searchByTitle("The Lord of the Rings");
  library.displayBook(result4);
  cout << "⚡ Comparisons: " << library.getComparisons() 
       << " (Even when not found, still efficient!)" << endl;
  
  // Test 5: Case-sensitive search
  cout << "\n\n📚 TEST 5: Case-sensitive search" << endl;
  cout << "───────────────────────────────────────" << endl;
  cout << "Searching for: \"harry potter\" (lowercase)" << endl;
  
  int result5 = library.searchByTitle("harry potter");
  library.displayBook(result5);
  cout << "⚡ Comparisons: " << library.getComparisons() 
       << " (Didn't match - C++ is case-sensitive)" << endl;
  
  // Summary and Analysis
  cout << "\n\n" << "═══════════════════════════════════════════════════════════" << endl;
  cout << "PERFORMANCE SUMMARY" << endl;
  cout << "═══════════════════════════════════════════════════════════" << endl;
  
  cout << "\nFor 15 books in library:" << endl;
  cout << "  Maximum comparisons: " << (int)ceil(log2(15)) << endl;
  cout << "  Average case: 2-3 comparisons" << endl;
  cout << "  Time per search: ~0.001 milliseconds" << endl;
  cout << "  User experience: INSTANT ✅" << endl;
  
  cout << "\nFor 100,000 books:" << endl;
  cout << "  Maximum comparisons: " << (int)ceil(log2(100000)) << endl;
  cout << "  Time per search: ~0.017 milliseconds" << endl;
  cout << "  User experience: INSTANT ✅" << endl;
  
  cout << "\nFor 1,000,000 books:" << endl;
  cout << "  Maximum comparisons: " << (int)ceil(log2(1000000)) << endl;
  cout << "  Time per search: ~0.020 milliseconds" << endl;
  cout << "  User experience: INSTANT ✅" << endl;
  
  // Key insights
  cout << "\n\n" << "═══════════════════════════════════════════════════════════" << endl;
  cout << "KEY INSIGHTS" << endl;
  cout << "═══════════════════════════════════════════════════════════" << endl;
  
  cout << "\n✅ WHY BINARY SEARCH FOR DIGITAL LIBRARY:" << endl;
  cout << "  1. Books are ALWAYS stored sorted (by ID, Title, or Author)" << endl;
  cout << "  2. Logarithmic time complexity O(log n)" << endl;
  cout << "  3. Handles millions of books instantly" << endl;
  cout << "  4. Minimal server load" << endl;
  cout << "  5. Superior user experience" << endl;
  cout << "  6. Cost-effective for large-scale systems" << endl;
  
  cout << "\n❌ WHY NOT LINEAR SEARCH:" << endl;
  cout << "  1. O(n) time complexity is too slow" << endl;
  cout << "  2. Users would wait 0.5+ seconds for large libraries" << endl;
  cout << "  3. Server CPU usage would be extreme" << endl;
  cout << "  4. Not scalable for millions of books" << endl;
  cout << "  5. Bad user experience" << endl;
  cout << "  6. Would require more servers = higher costs" << endl;
  
  cout << "\n\n" << "═══════════════════════════════════════════════════════════" << endl;
  cout << "🏆 BINARY SEARCH IS THE OPTIMAL SOLUTION!" << endl;
  cout << "═══════════════════════════════════════════════════════════" << endl;
  
  return 0;
}
