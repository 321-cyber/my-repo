#include <iostream>
#include <string>
using namespace std;

// 链表节点
struct Node {
    char data;
    Node* next;
    Node(char c) : data(c), next(nullptr) {}
};

// 字符串链表类
class StringList {
private:
    Node* head;
public:
    StringList() : head(nullptr) {}
    ~StringList() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    void addChar(char c) {
        Node* newNode = new Node(c);
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    Node* getHead() { return head; }

    int length() {
        int len = 0;
        Node* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    void showHex() {
        Node* temp = head;
        while (temp) {
            cout << hex << "0x" << static_cast<int>(static_cast<unsigned char>(temp->data)) << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void showChar() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }

    friend class Encryption;
};

// 异或加密类
class Encryption {
private:
    string key;
public:
    Encryption(const string& k) : key(k) {}

    void encrypt(StringList& list) {
        Node* node = list.getHead();
        int i = 0;
        while (node) {
            node->data ^= key[i];
            i = (i + 1) % key.length();
            node = node->next;
        }
    }

    void decrypt(StringList& list) {
        encrypt(list); // 异或解密与加密相同
    }
};

int main() {
    StringList list;
    string text, key;

    cout << "输入明文: ";
    getline(cin, text);

    cout << "输入密钥: ";
    getline(cin, key);

    for (char c : text) list.addChar(c);

    cout << "\n原始字符串(字符): ";
    list.showChar();
    cout << "原始字符串(十六进制): ";
    list.showHex();

    Encryption enc(key);
    enc.encrypt(list);
    cout << "\n加密后(十六进制): ";
    list.showHex();

    enc.decrypt(list);
    cout << "解密后(字符): ";
    list.showChar();

    return 0;
}