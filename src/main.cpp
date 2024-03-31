#include <iostream>

using namespace std;
const int maxSize = 5;
struct Qeue
{
    int front;
    int rear;
    string nama[maxSize];
    string jurusan[maxSize];
};

void CreateEmpty(Qeue &q)
{
    q.front = 1;
    q.rear = 0;
}

bool IsEmpty(Qeue &q)
{
    return q.rear == 0;
}

bool IsFull(Qeue &q)
{
    return q.rear >= maxSize;
}

void Qpush(Qeue &q)
{
    if (IsFull(q))
    {
        cout << " data full" << endl;
        return;
    }
    cout << "Masukkan nama : ";
    cin >> q.nama[q.rear];

    cout << "Masukkan jurusan : ";
    cin >> q.jurusan[q.rear];
    q.rear += 1;
}

void Qpop(Qeue &q)
{

    if (IsEmpty(q))
    {
        cout << "Data kosong " << endl;
        return;
    }
    cout << "antrian sebelumnya" << endl;
    cout << "Nama depan : " << q.nama[0] << endl;
    cout << "jurusan : " << q.jurusan[0] << endl;
    for (int i = 0; i < q.rear; i++)
    {
        q.nama[i] = q.nama[i + 1];
        q.jurusan[i] = q.jurusan[i + 1];
    }
    q.rear -= 1;
    cout << "antrian sekarang" << endl;
    cout << "Nama depan : " << q.nama[0] << endl;
    cout << "jurusan : " << q.jurusan[0] << endl;
}

void Qprint(Qeue &q)
{
    if (IsEmpty(q))
    {
        cout << " data kosong " << endl;
        return;
    }
    for (int i = 0; i < q.rear; i++)
    {
        cout << "\nNama depan : " << q.nama[i] << endl;
        cout << "jurusan : " << q.jurusan[i] << endl;
    }
}

int Menu()
{
    int pil;
    cout << "1. print" << endl;
    cout << "2. push" << endl;
    cout << "3. pop" << endl;
    cout << "4. exit" << endl;
    cout << "Silahkan Pilih : ";
    cin >> pil;
    cin.ignore();
    return pil;
}
int main()
{
    Qeue q;
    CreateEmpty(q);
    int pil = Menu();
    while (pil != 4)
    {
        switch (pil)
        {
        case 1:
            Qprint(q);
            break;
        case 2:
            Qpush(q);
            break;
        case 3:
            Qpop(q);
            break;

        default:
            break;
        }
        cin.get();
        pil = Menu();
    }

    return 0;
}