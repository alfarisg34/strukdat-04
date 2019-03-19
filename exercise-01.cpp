/*	Nama program	: exercise-01
	Nama			: Alfari Sidnan Ghilmana
	NPM				: 140810180011
	Tanggal buat	: 19 03 2019
	Deskripsi		: Data pegawai
********************************************************************/
#include<iostream>
using namespace std;
struct pegawai{
    string nama;
    string divisi;
    int gaji;
    pegawai*next;
};
typedef pegawai*pointer;
typedef pointer List;
void createList(List& first)
{ 
    first=NULL;
}
void createElm(pointer&pBaru)
{
    pBaru=new pegawai;
    cout<<"Nama: ";cin.ignore();getline(cin,pBaru->nama);
    cout<<"Divisi: ";getline(cin,pBaru->divisi);
    cout<<"Gaji: ";cin>>pBaru->gaji;
    pBaru->next=NULL;
}
void insertFirst(List&first,pointer pBaru)
{
    if(first==NULL)
    {
        first=pBaru;
    }
    else
    {
        pBaru->next=first;
        first=pBaru;
    }
}
void insertLast(List& First, pointer pBaru)
{
    pointer last; //last utk mencatat elemen terakhir
    cout<<"Insert Last"<<endl;
    if (First==NULL)
    { //kosong
        First=pBaru;
    }
    else 
    { // ada isi
        last=First; // menemukan elemen terakhir
        while (last->next!=NULL)
        {
            last=last->next;
        }
    last->next=pBaru; // sambungkan
    }
}
void traversal(List first)
{
    pointer pBantu;
    pBantu=first;
    if(first==NULL){
        cout<<"Data kosong"<<endl;
    }
    else{
        cout<<"Output "<<endl;
        cout<<"Nama\t\tDivisi\t\tGaji"<<endl;
        while(pBantu!=NULL){
        cout<<pBantu->nama<<"\t\t"<<pBantu->divisi<<"\t\t"<<pBantu->gaji<<"\t"<<endl;
        pBantu=pBantu->next;
        }
    }
}
void deleteFirst(List& First, pointer& pHapus)
{
    if (First==NULL)
    { // kosong
        pHapus=NULL;
        cout<<"List kosong, tidak ada yang dihapus"<<endl;
    }
    else if (First->next==NULL)
    { //isi 1 elemen
        pHapus=First;
        First=NULL;
    }
    else 
    { // isi > 1 elemen
        pHapus=First; // 1
        First=First->next; // 2
        pHapus->next=NULL; // 3
    }
}
void deleteLast(List& First, pointer& pHapus){
    pointer last,precLast;
    cout<<"Delete Last"<<endl;
    if (First==NULL)
    { // kosong
        pHapus=NULL;
        cout<<"List kosong, tidak ada yang dihapus"<<endl;
    }
    else if (First->next==NULL)
    { //isi 1 elemen
        pHapus=First;
        First=NULL; // list jadi kosong
    }
    else 
    { // isi > 1 elemen
        last=First; // menemukan elemen terakhir
        precLast=NULL;
        while (last->next!=NULL)
        {
            precLast=last; // preclast mencatat yg akan ditinggalkan Last
            last=last->next; // last berpindah
        }
    pHapus=last;
    precLast->next=NULL;
    }
}
int main()
{
    pointer p;
    List m;
    int pilihan;
    createList(m);
    do{
        cout<<"pilihan : "<<endl;
        cout<<"1. InsertFirst"<<endl;
        cout<<"2. Insertlast"<<endl;
        cout<<"3. DeleteFirst"<<endl;
        cout<<"4. Deletelast"<<endl;
        cout<<"5. Traversal"<<endl;
        cout<<"0. Selesai"<<endl;
        cout<<"pilihan : ";cin>>pilihan;
        
            switch(pilihan){
            case 1:
                createElm(p);
                insertFirst(m,p);
                break;

            case 2:
                createElm(m);
                insertLast(m, p);
                break;

            case 3:
                deleteFirst(m,p);
                break;

            case 4:
                deleteLast(m, p);
                break;

            case 5:
                traversal(m);
                break;

            default:
                return 0;
        }
    }  while(pilihan==1||pilihan==2||pilihan==3||pilihan==4||pilihan==5);
}