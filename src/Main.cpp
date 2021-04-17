#include <iostream>
#include <string>

#include "Character.hpp"
#include "Weapon.hpp"
#include "Player.hpp"
using namespace std;

void Menu(Player* list); //Menu awal 
void AdminMenu(Player* list); //Menu admin
void AddCharacter(Player* list); //Menambah karakter ke list
void AddWeapon(Player* list); //Menambah senjata ke list
void ChooseCharacter(Player* p, Player* list); //Player memilih karakter
void ChooseWeapon(Player* p, Player* list); //Player memilih senjata
void Attack(Player* p1, Player* p2); //Penyerangan
int CheckDefeat(Player* p1, Player* p2); //Cek apakah ada yang kalah
void DisplayChar(Player p1, Player p2); //Menampilkan karakter player

int main() {

    Player list("List");
    Player p1("Player 1");
    Player p2("Player 2");

    Menu(&list);
    cout << endl << endl << endl;

    cout << p1.name <<endl;
    ChooseCharacter(&p1, &list);
    cout << endl << endl << endl;
    ChooseWeapon(&p1, &list);
    cout << endl << endl << endl;

    cout << p2.name << endl;
    ChooseCharacter(&p2, &list);
    cout << endl << endl << endl;
    ChooseWeapon(&p2, &list);
    cout << endl << endl << endl;

    cout << "GAME START" << endl << endl;

    while(!CheckDefeat(&p1, &p2)) {
        DisplayChar(p1, p2);
        cout << p1.name << " turn" << endl;
        Attack(&p1, &p2);

        if(CheckDefeat(&p1, &p2)) break;

        DisplayChar(p1, p2);
        cout << p2.name << " turn" << endl;
        Attack(&p2, &p1);
    }

    return 0;
}

void Menu(Player* list) {
    int opt;
    cout << "MENU PERMAINAN STRATEGI" << endl;
    cout << "1. PLAY" << endl;
    cout << "2. Run as Admin" << endl;
    cout << "Pilihan menu : ";
    cin >> opt;
    cout << endl;
    if(opt==1) return;
    else if(opt==2) AdminMenu(list);
}

void AdminMenu(Player* list) {
    int opt;
    cout << "1. Tambahkan Pemain" << endl;
    cout << "2. Tambahkan Senjata" << endl;
    cout << "Pilihan menu : ";
    cin >> opt;
    cout << endl;
    if(opt==1) AddCharacter(list);
    else if(opt==2) AddWeapon(list);
}

void AddCharacter(Player* list) {
    int jml;
    string name;
    cout << "Jumlah karakter yang ingin ditambahkan : ";
    cin >> jml;
    for (int i=0; i<jml; i++) {
        cout << "Nama Karakter : ";
        cin >> name;
        list->AddCharacter(new Character(name));
    }
    cout << endl;
    Menu(list);
}

void AddWeapon(Player* list) {
    int jml, power;
    string name;
    cout << "Jumlah senjata yang ingin ditambahkan : ";
    cin >> jml;
    for (int i=0; i<jml; i++) {
        cout << "Nama Senjata : ";
        cin >> name;
        cout << "Kekuatan : ";
        cin >> power;
        list->AddWeapon(new Weapon(name, power));
    }
    cout << endl;
    Menu(list);
}

void ChooseCharacter(Player* p, Player* list) {
    int temp, i=1;
    cout << "DAFTAR KARAKTER" << endl;
    for (auto character : list->Getlistc()) {
        cout << i << ". ";
        cout << character->getName() << endl;
        i++;
    }

    for (int i=0; i<3; i++) {
        cout << "Masukkan nomor karakter yang ingin dipakai : ";
        cin >> temp;
        p->AddCharacter(new Character(list->Getlistc()[temp-1]->getName()));
    }

    cout << endl << "Karakter yang anda pakai : " << endl;
    for (auto character : p->Getlistc()) {
        cout << character->getName() << endl;
    }
}

void ChooseWeapon(Player* p, Player* list) {
    int temp, i=1;
    cout << "DAFTAR SENJATA" << endl;
    for (auto weapon : list->Getlistw()) {
        cout << i << ". ";
        cout << weapon->getName() << " power : " << weapon->getPower() << endl;
        i++;
    }
    for(auto character : p->Getlistc()) {
        cout << character->getName()<< " ";
        cout << "memilih senjata nomor : ";
        cin >> temp;
        character->equipWeapon(list->Getlistw()[temp-1]);
    }
}

void Attack(Player* p1, Player* p2) {
    int a, b;
    cout << "Pilih penyerang : ";
    cin >> a;
    cout << "Pilih korban : ";
    cin >> b;
    
    (p1->Getlistc()[a-1])->attack(p2->Getlistc()[b-1]);
    cout << endl << endl;
}

int CheckDefeat(Player* p1, Player* p2) {
    int flag1=0, flag2=0;
    for(auto character : p1->Getlistc()) {
        if(character->getHealth()<=0) flag1++;
    }
    for(auto character : p2->Getlistc()) {
        if(character->getHealth()<=0) flag2++;
    }
    if(flag1==3||flag2==3) {
        if(flag1==3) cout << p1->name << " KALAH" << endl;
        else if(flag2==3) cout << p2->name << " KALAH" << endl;
        return 1;
    }
    else return 0;
}


void DisplayChar(Player p1, Player p2) {
    int i=1, j=1;
    cout << p1.name << endl;
    for (auto character : p1.Getlistc()) {
        if(character->getHealth()>0) cout << i << ". ";
        character->display();
        i++;
    }
    cout << endl << endl;
    cout << p2.name << endl;
    for (auto character : p2.Getlistc()) {
        if(character->getHealth()>0) cout << j << ". ";
        character->display();
        j++;
    }
    cout << endl << endl;
}