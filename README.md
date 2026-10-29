# Address-Book
This is a console-based Address Book Management System written in C. It allows users to perform standard CRUD (Create, Read, Update, Delete) operations on contact details, with pre-populated dummy data and file persistence capabilities.
Features

* Add Contacts: Create new contacts with a Name, Phone Number, and Email (supports multi-word names)[cite: 3].
* Search Contacts: Look up contacts flexibly by:
  1. Name
  2. Phone Number
  3. Email Address
* Edit Contacts: Locate and update specific fields (Name, Phone, or Email) for existing records[cite: 3].
* Delete Contacts: Remove contacts and dynamically shift remaining records[cite: 3].
* List All Contacts: View a clean, tabular summary of all stored contacts[cite: 3].
* File Persistence: Save and load contacts securely using a local `contact.csv` file[cite: 5].
* Pre-populated Data: Automatically loads a set of dummy contacts upon initialization for quick testing[cite: 3, 8].

 📂 Project Structure
├── main.c           # Program entry point and main application loop
├── contact.c        # Core business logic for CRUD operations
├── contact.h        # Data structures (Contact, AddressBook) and function declarations
├── file.c           # File I/O operations for saving/loading CSV data
├── file.h           # File handling headers
├── populate.c       # Pre-defined dummy contact records
└── populate.h       # Population utility header
