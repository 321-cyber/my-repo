#include <iostream>
#include <string>
using namespace std;

// ����ڵ�
struct Node {
    char data;
    Node* next;
    Node(char c) : data(c), next(nullptr) {}
};

// �ַ���������
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

// ��������
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
        encrypt(list); // �������������ͬ
    }
};

int main() {
    StringList list;
    string text, key;

    cout << "��������: ";
    getline(cin, text);

    cout << "������Կ: ";
    getline(cin, key);

    for (char c : text) list.addChar(c);

    cout << "\nԭʼ�ַ���(�ַ�): ";
    list.showChar();
    cout << "ԭʼ�ַ���(ʮ������): ";
    list.showHex();

    Encryption enc(key);
    enc.encrypt(list);
    cout << "\n���ܺ�(ʮ������): ";
    list.showHex();

    enc.decrypt(list);
    cout << "���ܺ�(�ַ�): ";
    list.showChar();

    return 0;
}