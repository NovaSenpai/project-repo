#pragma once // used to prevent if a file is included twice by mistake

class CatalogEntry {
public:
    int isbn;
    string bookName;
    string authorName; 
    string bookType;
    bool availabilityStatus;
    CatalogEntry* left;
    CatalogEntry* right;
    int height;

    CatalogEntry(int isbn, string bookName, string authorName, string bookType) {
        this->isbn=isbn;
        this->bookName=bookName;
        this->authorName=authorName;
        this->bookType=bookType;
        left = right = nullptr;
        height = 1;
        availabilityStatus= true;
    }

    bool isDublicateISBN(const string &filename, int isbn) { // check if any dupliacation 
        ifstream infile(filename);
        int existingISBN;
        while(infile>>existingISBN) {
            if(existingISBN==isbn) {
                return true;
            }
            infile.ignore(numeric_limits<streamsize>::max(), '\n'); // skipping an entire line in a stream
        }
        return false;
    }

    void saveNodeToFile(ofstream& file, const string fileName) {
        if (this != nullptr) { // this pointing to root 

            if(!isDublicateISBN(fileName, isbn)) {

                transform(bookName.begin(),bookName.end(),bookName.begin(), :: toupper);
                transform(authorName.begin(),authorName.end(),authorName.begin(), :: toupper);
                transform(bookType.begin(),bookType.end(),bookType.begin(), :: toupper);

                
                file << setw(6) << isbn << setw(40) << bookName << setw(30) << authorName << setw(25) <<
                        bookType << setw(25) << (availabilityStatus ? "AVAILABLE " : "NOT AVAILABLE") << endl;
            }

            if (left != nullptr) {
                left->saveNodeToFile(file, fileName);
            }
            if (right != nullptr) {
                right->saveNodeToFile(file, fileName);
            }
        }
    }
};

class LibraryCatalog {
public:
    CatalogEntry* root;

    LibraryCatalog() {
        root = nullptr;
    }

    void bookReturn(const string& file, int isbn_To_Check) {
        CatalogEntry* node = search(root, isbn_To_Check);
        if(node!=NULL && node->availabilityStatus==false) {
            node->availabilityStatus=true;

            updateFileData(file, node, node->availabilityStatus);

            cout<<"YOU HAD BORROWED " << node->isbn<<" " << node->bookName << " " << node->authorName 
                << " " << node->bookType <<"\n";
            cout<<"THANK YOU FOR RETURNING THE BOOK. HAVE A GREAT DAY!\n";
        }
        else {
            cout<<"BOOK NOT FOUND!\n";
        }
    }

    void updateFileData(const string &fileName, CatalogEntry *node, bool availabilityStatus) {
    ifstream inFile(fileName);
    fstream tempFile("temp.txt", ios::out);  // Specify the mode

    if (!inFile.is_open() || !tempFile.is_open()) {
        cerr << "Error opening files." << endl;
        return;
    }

    int existingISBN;
    string line;

    while (getline(inFile, line)) {
        stringstream ss(line);
        ss >> existingISBN;  // Assuming ISBN is the first element in each line

        if (existingISBN == node->isbn) {
            tempFile << setw(6) << node->isbn << setw(40) << node->bookName << setw(30) << node->authorName << setw(25) <<
                        node->bookType << setw(25) << (node->availabilityStatus ? "AVAILABLE " : "NOT AVAILABLE") << endl;
        } else {
            tempFile << line << "\n";
        }
    }

    inFile.close();
    tempFile.close();

    // Rename temp file to original file
    if (remove(fileName.c_str()) != 0) {
        cerr << "Error deleting file: " << fileName << endl;
        return;
    }

    if (rename("temp.txt", fileName.c_str()) != 0) {
        cerr << "Error renaming file." << endl;
    }
}

    void bookBorrow(const string& file, int isbn_To_Check){
        CatalogEntry* node = search(root, isbn_To_Check);
        if(node!=NULL && node->availabilityStatus==true) {
            node->availabilityStatus=false;
            updateFileData(file, node, node->availabilityStatus);

            system("cls");
            cout<< node->isbn<<" " << node->bookName << " " << node->authorName << " " << node->bookType 
                               << " Has been Borrowed!\n";
            cout<<"THANK YOU FOR WISITING, HAVE A GOOD DAY!\n";
        }
        else {
            cout<<"Book Already Borrowed or Not Available!\n";
        }
    }

    void availability(int isbn) {
        CatalogEntry* node = search(root, isbn);
        if(node!=NULL) {
            
        transform(node->bookName.begin(),node->bookName.end(),node->bookName.begin(), :: toupper);
        transform(node->authorName.begin(),node->authorName.end(),node->authorName.begin(), :: toupper);
        transform(node->bookType.begin(),node->bookType.end(),node->bookType.begin(), :: toupper);

        cout<<"BOOK FOUND!\n";
        cout << setw(6) << node->isbn << setw(40) << node->bookName << setw(30) << node->authorName << setw(25) <<
                    node->bookType << setw(25) << (node->availabilityStatus ? "AVAILABLE " : "NOT AVAILABLE") << endl;
        }
        else
            cout<<"BOOK NOT FOUND!\n";
    }

    void saveToFile(const string& FileName) {
        ofstream file(FileName, ios::app);
        if (!file.is_open()) {
            cerr << "File Open Unsuccessful";
            return;
        }

        if (root != nullptr) {
            root->saveNodeToFile(file, FileName);
        }

        file.close();
    }

    int height(CatalogEntry* node) {
        return (node == nullptr) ? 0 : node->height;
    }

    int balanceFactor(CatalogEntry* node) {
        return (node == nullptr) ? 0 : height(node->left) - height(node->right);
    }

    void updateHeight(CatalogEntry* node) {
        if (node != nullptr) {
            node->height = 1 + max(height(node->left), height(node->right));
        }
    }

    CatalogEntry* leftRotate(CatalogEntry* y) {
        CatalogEntry* x = y->right;
        CatalogEntry* T2 = x->left;

        // Perform rotation
        x->left = y;
        y->right = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    CatalogEntry* rightRotate(CatalogEntry* x) {
        CatalogEntry* y = x->left;
        CatalogEntry* T2 = y->right;

        y->right = x;
        x->left = T2;

        updateHeight(x);
        updateHeight(y);
        return y;
    }
    CatalogEntry* insert(CatalogEntry* node, int isbn, string bookName, string authorName, string bookType) {
        // Perform standard BST insert
        if (node == nullptr) {
            return new CatalogEntry(isbn, bookName, authorName, bookType);
        }

        if (isbn < node->isbn) {
            node->left = insert(node->left, isbn, bookName, authorName, bookType);
        }
        else if (isbn > node->isbn) {
            node->right = insert(node->right, isbn, bookName, authorName, bookType);
        }
        else {
            return node;
        }
       
        updateHeight(node);

        int balance = balanceFactor(node);
        if (balance > 1) {
            if (isbn < node->left->isbn) {
                return rightRotate(node); 
            }
            else {
                node->left = leftRotate(node->left); 
                return rightRotate(node);
            }
        }
        if (balance < -1) {
            if (isbn > node->right->isbn) {
                return leftRotate(node); 
            }
            else {
                node->right = rightRotate(node->right); 
                return leftRotate(node);
            }
        }
        return node;
    }

    CatalogEntry* deleteNode(CatalogEntry* root, int isbn) {
        if (root == nullptr) {
            return root;
        }
        if (isbn < root->isbn) {
            root->left = deleteNode(root->left, isbn);
        }
        else if (isbn > root->isbn) {
            root->right = deleteNode(root->right, isbn);
        }
        else {
            if (root->left == nullptr) {
                CatalogEntry* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                CatalogEntry* temp = root->left;
                delete root;
                return temp;
            }
            CatalogEntry* temp = findMin(root->right);
            root->isbn = temp->isbn;
            root->right = deleteNode(root->right, temp->isbn);
        }
        updateHeight(root);
        int balance = balanceFactor(root);
        if (balance > 1) {
            if (balanceFactor(root->left) >= 0) {
                return rightRotate(root);  
            }
            else {
                root->left = leftRotate(root->left);  
                return rightRotate(root);
            }
        }
        if (balance < -1) {
            if (balanceFactor(root->right) <= 0) {
                return leftRotate(root);  
            }
            else {
                root->right = rightRotate(root->right);  
                return leftRotate(root);
            }
        }
        return root;
    }

    CatalogEntry* findMin(CatalogEntry* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    CatalogEntry* search(CatalogEntry*& root, int isbn) {
        if (root == NULL) {
            return NULL;
        }
        if (isbn == root->isbn) {
            return root;
        }
        else if (isbn < root->isbn) {
            return search(root->left, isbn);
        }
        else {
            return search(root->right, isbn);
        }
    }

    void insert(int isbn, string bookName, string authorName, string bookType) {
        root = insert(root, isbn, bookName, authorName, bookType);
    }

    void deleteNode(int isbn) {
        root = deleteNode(root, isbn);
    }

    bool search(int value) {
        return search(root, value);
    }

 void inorderTraversal(CatalogEntry* root) {
    if (root != nullptr) {
        transform(root->bookName.begin(),root->bookName.end(),root->bookName.begin(), :: toupper);
        transform(root->authorName.begin(),root->authorName.end(),root->authorName.begin(), :: toupper);
        transform(root->bookType.begin(),root->bookType.end(),root->bookType.begin(), :: toupper);

        cout << setw(6) << root->isbn << setw(40) << root->bookName << setw(30) << root->authorName << setw(25) <<
            root->bookType << setw(25) << (root->availabilityStatus ? "AVAILABLE " : "NOT AVAILABLE") << endl;

        inorderTraversal(root->left);
        inorderTraversal(root->right);
    }
}
    void printTree() {
        inorderTraversal(root);
        cout << endl;
    }
    
};