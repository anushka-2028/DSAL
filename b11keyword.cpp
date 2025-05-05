#include<iostream>
#include<string>
using namespace std;

struct Node {
    string keyword;
    string meaning;
    Node* left;
    Node* right;
};

class Dictionary {
    Node* root;

public:
    Dictionary() {
        root = NULL;
    }

    Node* insert(Node* root, string key, string mean) {
        if (root == NULL) {
            Node* newNode = new Node{key, mean, NULL, NULL};
            return newNode;
        }
        if (key < root->keyword)
            root->left = insert(root->left, key, mean);
        else if (key > root->keyword)
            root->right = insert(root->right, key, mean);
        else
            cout << "Keyword already exists!\n";
        return root;
    }

    void insertKeyword(string key, string mean) {
        root = insert(root, key, mean);
    }

    Node* search(Node* root, string key, int &count) {
        while (root != NULL) {
            count++;
            if (key == root->keyword)
                return root;
            else if (key < root->keyword)
                root = root->left;
            else
                root = root->right;
        }
        return NULL;
    }

    void searchKeyword(string key) {
        int count = 0;
        Node* result = search(root, key, count);
        if (result != NULL) {
            cout << "Found: " << result->keyword << " = " << result->meaning << endl;
            cout << "Comparisons: " << count << endl;
        } else {
            cout << "Keyword not found.\n";
            cout << "Comparisons: " << count << endl;
        }
    }

    void updateMeaning(string key, string newMeaning) {
        int count = 0;
        Node* result = search(root, key, count);
        if (result != NULL) {
            result->meaning = newMeaning;
            cout << "Meaning updated.\n";
        } else {
            cout << "Keyword not found.\n";
        }
    }

    Node* findMin(Node* root) {
        while (root->left != NULL)
            root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, string key) {
        if (root == NULL) return NULL;

        if (key < root->keyword)
            root->left = deleteNode(root->left, key);
        else if (key > root->keyword)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* temp = findMin(root->right);
                root->keyword = temp->keyword;
                root->meaning = temp->meaning;
                root->right = deleteNode(root->right, temp->keyword);
            }
        }
        return root;
    }

    void deleteKeyword(string key) {
        root = deleteNode(root, key);
        cout << "Deleted if it existed.\n";
    }

    void displayAscending(Node* root) {
        if (root != NULL) {
            displayAscending(root->left);
            cout << root->keyword << " : " << root->meaning << endl;
            displayAscending(root->right);
        }
    }

    void showAscending() {
        cout << "\nDictionary in Ascending Order:\n";
        displayAscending(root);
    }
};

int main() {
    Dictionary dict;
    int choice;
    string key, mean;

    while (true) {
        cout << "\n--- DICTIONARY MENU ---\n";
        cout << "1 -> Insert" << endl;
        cout << "2 -> Search" << endl;
        cout << "3 -> Update" << endl;
        cout << "4 -> Delete" << endl;
        cout << "5 -> Display Ascending" << endl;
        cout << "6 -> Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter keyword: ";
            cin >> key;
            cout << "Enter meaning: ";
            cin.ignore();
            getline(cin, mean);
            dict.insertKeyword(key, mean);
            break;

        case 2:
            cout << "Enter keyword to search: ";
            cin >> key;
            dict.searchKeyword(key);
            break;

        case 3:
            cout << "Enter keyword to update: ";
            cin >> key;
            cout << "Enter new meaning: ";
            cin.ignore();
            getline(cin, mean);
            dict.updateMeaning(key, mean);
            break;

        case 4:
            cout << "Enter keyword to delete: ";
            cin >> key;
            dict.deleteKeyword(key);
            break;

        case 5:
            dict.showAscending();
            break;

        case 6:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
