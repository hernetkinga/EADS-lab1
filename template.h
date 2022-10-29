#include <iostream>
#include <cstdio>

using namespace std;

template<typename Key, typename Info>
class Sequence;

// external functions
template<typename Key, typename Info>
void split_pos(const Sequence<Key, Info> &seq, int start_pos, int len1, int len2, int count, Sequence<Key, Info> &seq1,
               Sequence<Key, Info> &seq2);

template<typename Key, typename Info>
void split_key(const Sequence<Key, Info> &seq, const Key &start_key, int start_occ, int len1, int len2, int count,
               Sequence<Key, Info> &seq1, Sequence<Key, Info> &seq2);


template<typename Key, typename Info>
// description of a single element
struct Object {
    Key key;
    Info info;
    Object<Key, Info> *next;
    template<typename X,typename Y> friend class Sequence;
};

template<typename Key, typename Info>
class Sequence {
private:
    Object<Key, Info> *head;
public:
    Sequence() {
        head = nullptr;
    };

    Sequence(const Sequence &src) {
        if (head != nullptr) return;
        Object<Key, Info> *temp = src.head;
        this->head=nullptr;
        while (temp) {
            //insert_back(temp->key,temp->info);
            this->insert_back(temp->key, temp->info);
            temp = temp->next;
        }
    }

    ~Sequence() {
        clear_list();
    };

    Sequence &operator=(const Sequence &src) {
        if (src.head != this->head) {
            Object<Key, Info> *current_src = src.head;
            this->head = nullptr;
            while (current_src != nullptr) {
                this->insert_back(current_src->key, current_src->info);
                current_src = current_src->next;
            }
        }
        return *this;
    }

    void insert_back(const Key &key, const Info &info) {
        Object<Key, Info> *current = new Object<Key, Info>({key, info});
        if (head == nullptr) {
            head = current;
            return;
        }
        Object<Key, Info> *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = current;
    };

    void insert_front(const Key &key, const Info &info) {
        Object<Key, Info> *current = new Object<Key, Info>({key, info});
        if (head == nullptr) {
            head = current;
            return;
        } else {
            current->next = head;
            head = current;
        }
    }

    unsigned int length() const {
        unsigned len = 0;
        Object<Key, Info> *current = head;
        while (current != nullptr) {
            len++;
            current = current->next;
        }
        return len;
    }

    void clear_list() {
        Object<Key, Info> *current;
        while (head != nullptr) {
            current = head;
            head = head->next;
            delete current;
        }

    };

    void print() const {
        Object<Key, Info> *current = head;
        if (current == nullptr) {
            cout << "List is empty" << endl;
        } else {
            while (current != nullptr) {
                cout << "Key: " << current->key << " | " << "Info: " << current->info << endl;
                current = current->next;
            }
        }
        cout << endl;
    };

    bool pop_front() {
        Object<Key, Info> *temp = head;
        if (head == nullptr) return false;
        head = head->next;
        delete temp;
        return true;
    }

    friend void
    split_pos(const Sequence<Key, Info> &seq, int start_pos, int len1, int len2, int count, Sequence<Key, Info> &seq1,
              Sequence<Key, Info> &seq2);

    friend void
    split_key<Key, Info>(const Sequence<Key, Info> &seq, const Key &start_key, int start_occ, int len1, int len2,
                         int count, Sequence<Key, Info> &seq1, Sequence<Key, Info> &seq2);
};

// external functions
template<typename Key, typename Info>
void split_pos(const Sequence<Key, Info> &seq, int start_pos, int len1, int len2, int count, Sequence<Key, Info> &seq1,
               Sequence<Key, Info> &seq2) {
    Object<Key, Info> *current = seq.head;

    for (int i = 0; i < start_pos; i++) {
        if (current != nullptr) {
            current = current->next;
        } else return;
    }
    int diff = 0;
    while (current != nullptr && count > diff) {
        int repeat = 0;
        while (current != nullptr && len1 > repeat) {
            seq1.insert_back(current->key, current->info);
            repeat++;
            current = current->next;
        }

        repeat = 0;
        while (current != nullptr && len2 > repeat) {
            seq2.insert_back(current->key, current->info);
            repeat++;
            current = current->next;
        }
        diff++;
    }
}

template<typename Key, typename Info>
void split_key(const Sequence<Key, Info> &seq, const Key &start_key, int start_occ, int len1, int len2, int count,
               Sequence<Key, Info> &seq1, Sequence<Key, Info> &seq2) {
    Object<Key,Info> *current = seq.head;


    int temp = 0;
    while (current != nullptr) {
        if (current->key == start_key){
            temp++;
            if (temp==start_occ)  break;
        }
        current=current->next;
    }
    int diff = 0;
    while (current != nullptr && count > diff){
        int repeat = 0;
        while (current != nullptr && len1 > repeat) {
            seq1.insert_back(current->key,current->info);
            repeat++;
            current = current->next;
        }
        diff++;
        repeat=0;
        while (current != nullptr && len2 > repeat){
            seq2.insert_back(current->key,current->info);
            repeat++;
            current = current->next;
        }
    }
}