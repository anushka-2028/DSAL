#include<iostream>
#include<string>
using namespace std;

struct node {
    node* left;
    node* right;
    string key, mean;

    node(string k = "", string m = "") {
        left = right = nullptr;
        key = k;
        mean = m;
    }
};

class b11 {
public:
    node* root;

    b11() {
        root = nullptr;
    }

    bool insert(string key, string value) {
        if (root == nullptr) {
            root = new node(key, value);
            return true;
        }

        node* temp = root;
        node* prev = nullptr;

        while (temp != nullptr) {
            prev = temp;
            if (temp->key == key) {
                return false;  // Duplicate key, insertion fails
            } else if (temp->key < key) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }

        if (prev->key < key) {
            prev->right = new node(key, value);
        } else {
            prev->left = new node(key, value);
        }
        return true;
    }

    string search(string key) {
        node* temp = root;
        while (temp != nullptr) {
            if (temp->key == key) {
                return temp->mean;  // Found key
            } else if (temp->key < key) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }
        return "";  // Key not found
    }

    bool update(string key, string value) {
        node* temp = root;
        while (temp != nullptr) {
            if (temp->key == key) {
                temp->mean = value;  // Update value
                return true;
            } else if (temp->key < key) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }
        return false;  // Key not found for update
    }

    bool delete_key(string key) {
        node** cur = &root;
        while (*cur != nullptr) {
            if ((*cur)->key == key) {
                node* temp = *cur;
                if ((*cur)->left == nullptr) {
                    *cur = (*cur)->right;
                } else if ((*cur)->right == nullptr) {
                    *cur = (*cur)->left;
                } else {
                    node* successor = (*cur)->right;
                    while (successor->left != nullptr)
                        successor = successor->left;
                    (*cur)->key = successor->key;
                    (*cur)->mean = successor->mean;
                    delete_key(successor->key);  // Recursively delete the successor
                    return true;
                }
                delete temp;
                return true;
            } else if ((*cur)->key < key) {
                cur = &((*cur)->right);
            } else {
                cur = &((*cur)->left);
            }
        }
        return false;  // Key not found for deletion
    }

    void display(node* cur) {
        if (cur == nullptr) {
            return;
        }
        display(cur->left);
        cout << cur->key << " : " << cur->mean << endl;
        display(cur->right);
    }
};

int main() {
    b11 tree;
    int ch;
    string k, v, ans;

    do {
        cout << "--- MAIN MENU ---" << endl;
        cout << "1 -> Insert" << endl;
        cout << "2 -> Search" << endl;
        cout << "3 -> Update" << endl;
        cout << "4 -> Delete" << endl;
        cout << "5 -> Display Ascending" << endl;
        cout << "0 -> Exit" << endl;
        cout << "Choose an option (0-5):\t";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Key (word) to insert:\t";
                cin >> k;
                cout << "Value (meaning):\t";
                cin >> v;
                if (tree.insert(k, v)) {
                    cout << "Element insertion successful." << endl;
                } else {
                    cout << "Element already exists." << endl;
                }
                break;

            case 2:
                cout << "Key (word) to search:\t";
                cin >> k;
                ans = tree.search(k);
                if (ans == "") {
                    cout << "Element does not exist." << endl;
                } else {
                    cout << "Value (meaning) is:\t" << ans << endl;
                }
                break;

            case 3:
                cout << "Key (word) to update:\t";
                cin >> k;
                cout << "New value (meaning):\t";
                cin >> v;
                if (tree.update(k, v)) {
                    cout << "Element updated." << endl;
                } else {
                    cout << "Element does not exist." << endl;
                }
                break;

            case 4:
                cout << "Key (word) to delete:\t";
                cin >> k;
                if (tree.delete_key(k)) {
                    cout << "Element deletion successful." << endl;
                } else {
                    cout << "Element does not exist." << endl;
                }
                break;

            case 5:
                cout << "Data in ascending order:\t" << endl;
                tree.display(tree.root);
                break;

            case 0:
                cout << "\n// END OF CODE\n";
                break;

            default:
                cout << "Please choose a valid option (0-5)." << endl;
                break;
        }
    } while (ch != 0);

    return 0;
}

