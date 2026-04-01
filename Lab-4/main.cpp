#include <iostream>
#include <string>

using namespace std;
  struct Package {
      string packageID;
      string destinationCity;
        int dimensions[3];
         Package* next;
};

struct Courier {
    string courierName;
     string vehicleType;
};

  class PackageStack {
   private:
    Package* top;

public:
    PackageStack():top(nullptr) {}

    void push(string id,string city,int l,int w,int h) {
Package* newPackage=new Package();
newPackage->packageID=id;
newPackage->destinationCity = city;
newPackage->dimensions[0] = l;
newPackage->dimensions[1] = w;
newPackage->dimensions[2] = h;
newPackage->next=top;
top = newPackage;
        cout<<" Package"<<id<<" Depoya eklendi"<<endl;
    }

    Package* pop() {
    if (isEmpty()) return nullptr;
    Package* temp=top;
    top=top->next;
    return temp;
    }
    bool isEmpty(){return top==nullptr; }
    void display() {
        if (isEmpty()) {
        cout <<" Depo boþ"<<endl;
        return;
        }
        Package*current=top;
        cout <<"\n Mevcut Depo"<< endl;
        while (current) {
            cout <<"ID:"<< current->packageID << " | Sehir: " << current->destinationCity
                 <<"|Dim:"<< current->dimensions[0] << "x" << current->dimensions[1] << "x" << current->dimensions[2] << endl;
            current=current->next;
        }
    }
};
class CourierQueue {
private:
    static const int MAX_SIZE = 5;
    Courier queue[MAX_SIZE];
    int front,rear,count;

public:
    CourierQueue():front(0),rear(-1),count(0){}

    bool isFull(){return count== MAX_SIZE;}
    bool isEmpty(){return count==0;}

    void enqueue(string name, string type) {
        if (isFull()) {
            cout<<" Sýra dolu,Kurye "<<name<<" Kaydedilemez" << endl;
            return;
        }
        rear=(rear+1)%MAX_SIZE;
        queue[rear].courierName=name;
        queue[rear].vehicleType=type;
        count++;
        cout << " Kurye" << name << " Kaydedildi" << endl;
    }

    Courier dequeue() {
        Courier empty={"", ""};
        if (isEmpty()) return empty;
        Courier removed = queue[front];
        front=(front + 1)%MAX_SIZE;
        count--;
        return removed;
    }

    void display() {
        if (isEmpty()) {
        cout<<" Sýrada Kurye yok"<<endl;
        return;
        }
        cout <<"\n Kuryeler Bekleniyor"<<endl;
        for (int i=0;i<count;i++) {
            int index = (front+i)%MAX_SIZE;
             cout << "Ad: " << queue[index].courierName << " | Arac: " << queue[index].vehicleType << endl;
        }
    }
};
void dispatch(PackageStack& stack, CourierQueue& queue) {
    if (stack.isEmpty() || queue.isEmpty()) {
        cout << "\n Sevk Hatalý" << (stack.isEmpty() ? " Paket yok":"")
             << (queue.isEmpty() ? " Kurye Yok!!" : "") << endl;
        return;
    }

    Package* p=stack.pop();
    Courier c=queue.dequeue();

    cout <<"\nSevk Basarili<<<" << endl;
    cout <<" Kurye" << c.courierName << " Paket teslim ediliyor. " << p->packageID
         <<">>" << p->destinationCity << "." << endl;

    delete p;
}

int main() {

    PackageStack myStack;
    CourierQueue myQueue;


    myStack.push(" P001", " Eskisehir", 20, 10, 5);
    myStack.push(" P002", " Balikesir", 30, 20, 10);

    myQueue.enqueue(" Ahmet", " Motorsiklet");
    myQueue.enqueue(" Can", " Araba");

myStack.display();
myQueue.display();


dispatch(myStack, myQueue);
    myStack.display();
    myQueue.display();

    return 0;
}
