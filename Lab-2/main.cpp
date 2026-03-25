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
        cout << "\n>>> Sonraki sarkiya gecildi:"<< current->title << endl;
    } else {
        cout << "\nListenin sonundasin daha ileri gidilemez."<< endl;
    }
}
void movePrev() {
    if (current != nullptr && current->prev != nullptr) {
        current = current->prev;
        cout << "\n<<< Onceki sarkiya gecildi: " << current->title << endl;
    } else {
        cout << "\n!!! Listenin basindasin daha geri gidilemez." << endl;
    }
}
void removeCurrent() {
    if (current == nullptr) {
        cout << "Silinecek sarki yok" << endl;
        return;
    }
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

    cout << "\n Silinen Sarki: " << toDelete->title << endl;
delete toDelete;
}
void display() {
  cout << "\n GUNCEL PLAYLIST " << endl;
   if (head == nullptr) {
     cout << "Liste bos!" << endl;
        return;
    }

       Song* temp = head;
while (temp != nullptr) {
        if (temp == current) {
            cout << "->";
        }else{
            cout << "   ";
        }

        cout << "[" << temp->title << "] - " << temp->artist << "|Puanlar:";
    for (int i = 0; i < 3; i++) {
        cout << temp->ratings[i] << (i < 2 ? ", " : "");
        }
        cout << endl;
        temp=temp->next;
    }
    cout<<"=====================================\n" << endl;
}

int main() {
    int p1[] = {8, 9, 7};
    addSong("Starboy","The Weeknd", p1);

    int p2[] = {10, 8, 9};
    addSong("Mockingbird","Eminem", p2);

    int p3[] = {7, 7, 8};
    addSong("Sweater Weather","The Neighbourhood",p3);

    display();

    moveNext();
    display();

    removeCurrent();
    display();

    movePrev();
    display();

    return 0;
}
