📘 Address Book Management System – C Project

A fully functional Contact Management System written in C.
Supports adding, editing, deleting, searching, and listing contacts with file persistence using CSV.

🌟 Features
✅ Contact Operations

-Add new contact

-Search contact (Name / Phone / Email)

-Edit contact

-Delete contact

-List all contacts

🔐 Data Validation

Name → Only alphabets & spaces

Phone → Exactly 10 digits

Email → Lowercase + must follow @gmail.com

🧩 Technical Highlights

-Modular Programming (multiple .c files)

-File Handling (contacts.csv)

-Custom string comparison functions

-Error handling & input validation

⚙️ Compilation Instructions

🔧 Compile
gcc \*.c

▶️ Run
./a.out

🧱 Data Structures
📌 Contact Structure
--typedef struct {
char name[50];
char phone[15];
char email[20];
} Contact;

📌 AddressBook Structure
--typedef struct {
Contact contacts[100];
int contactCount;
} AddressBook;

---

🔍 Major Functions
➕ createContact()

Accepts inputs

Validates them

Inserts into AddressBook

🔎 searchContact()

Linear search

Matches name, number, or email

✏️ editContact()

Modify existing contact details

❌ deleteContact()

Deletes and shifts elements

Auto-saves updated list

💾 saveContactsToFile()

Writes entire contact list to CSV

📥 loadContactsFromFile()

## Loads contacts on program startup

📄 File Format (contacts.csv) #<Number of contacts>
Name,Phone,Email
John Doe,9876543210,john@gmail.com
Alice Roy,9123456780,alice@gmail.com
