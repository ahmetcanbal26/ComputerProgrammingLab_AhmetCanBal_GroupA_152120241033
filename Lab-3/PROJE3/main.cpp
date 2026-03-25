#include <iostream>
#include <string>

using namespace std;

struct Song {
    string title;
    string artist;
    int ratings[3];
    Song *next;
    Song *prev;

    Song(string t, string a, int r[]) : title(t), artist(a), next(nullptr), prev(nullptr) {
        for(int i = 0; i < 3; i++) {
            ratings[i] = r[i];
        }
    }
};

Song* head = nullptr;
Song* tail = nullptr;
Song* current = nullptr;

void addSong(string title, string artist, int ratings[]) {
    Song* newSong = new Song(title, artist, ratings);

    if (head == nullptr) {
        head = tail = current = newSong;
    } else {
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }
}

void moveNext() {
    if (current != nullptr && current->next != nullptr) {
        current = current->next;
        cout << "\n>>> Sonraki sarki: " << current->title << endl;
    } else {
        cout << "\nListenin sonundasin." << endl;
    }
}

void movePrev() {
    if (current != nullptr && current->prev != nullptr) {
        current = current->prev;
        cout << "\n<<< Onceki sarki: " << current->title << endl;
    } else {
        cout << "\nListenin basindasin." << endl;
    }
}

void removeCurrent() {
    if (current == nullptr) return;

    Song* toDelete = current;

    if (toDelete->prev != nullptr) {
        toDelete->prev->next = toDelete->next;
    } else {
        head = toDelete->next;
    }

    if (toDelete->next != nullptr) {
        toDelete->next->prev = toDelete->prev;
        current = toDelete->next;
    } else {
        tail = toDelete->prev;
        current = tail;
    }

    cout << "\nSilinen: " << toDelete->title << endl;
    delete toDelete;

    if (head == nullptr) {
        current = tail = nullptr;
    }
}

void display() {
    if (head == nullptr) {
        cout << "\nListe bos!" << endl;
        return;
    }

    cout << "\n--- GUNCEL PLAYLIST ---" << endl;
    Song* temp = head;
    while (temp != nullptr) {
        if (temp == current) cout << "-> ";
        else cout << "   ";

        cout << "[" << temp->title << "] - " << temp->artist << " | Puanlar: ";
        for (int i = 0; i < 3; i++) {
            cout << temp->ratings[i] << (i < 2 ? ", " : "");
        }
        cout << endl;
        temp = temp->next;
    }
    cout << "-----------------------" << endl;
}

int main() {
    int r1[] = {8, 9, 7};
    addSong("Starboy", "The Weeknd", r1);

    int r2[] = {10, 8, 9};
    addSong("Mockingbird", "Eminem", r2);

    int r3[] = {7, 7, 8};
    addSong("Sweater Weather", "The Neighbourhood", r3);

    display();

    moveNext();
    display();

    removeCurrent();
    display();

    movePrev();
    display();

    return 0;
}
