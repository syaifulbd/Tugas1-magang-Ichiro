Ichiro - Implementasi OOP
    Program ini ditujukan untuk memenuhi tugas 1 magang dalam divisi programming Tim Robotik ichiro ITS. Program ini merupakan eksplorasi dalam belajar mengimplementasikan Object Oriented Programming dengan bahasa c++.

Gambaran Umum
    Program ini berjudul "Permainan Strategi" karena merupakan Permainan sederhana dengan menggunakan console yang mengandalkan strategi. Program ini adalah permainan yang dilakukan oleh dua pemain yang masing-masing memiliki 3 karakter dengan senjata masing-masing yang akan saling menyerang hingga salah satu pemain kehilangan semua karakternya. Dalam program ini terdapat 7 file yaitu Player.hpp, Player.cpp, Character.hpp, Character.cpp, Weapon.hpp, Weapon.cpp, dan Main.cpp. Dalam program ini juga menggunakan 3 class yaitu class Player, class Character, dan class Weapon.

Yang Bisa Dilakukan
    Dalam program ini, Anda dapat melakukan :
        1. Menambahkan karakter ke dalam list
        2. Menambahkan senjata ke dalam list
        3. Bermain permainan strategi

Penjelasan Rinci
    class Player : merupakan class yang menyimpan data dari pemain, berupa karakter yang ingin dimainkan beserta senjatanya dan nama pemain itu sendiri.
        1. Attribute
            name (public access) dengan tipe data string untuk menyimpan nama pemain.

            listc (private access) untuk menyimpan array of Character objek, yang merupakan karakter-karakter yang akan dimainkan oleh pemain tersebut.

            listw (private access) untuk menyimpan array of Weapon objek, yang merupakan senjata-senjata yang digunakan oleh karakter pemain tersebut.

        2. Constructor
            Player(string name) untuk mengalokasikan objek baru bertipe Player dengan parameter name bertipe string yang dijadikan sebagai attribute name untuk objek tersebut.

        3. Method
            AddCharacter(Character* character) (public access) untuk menambah suatu karakter ke dalam objek. Method ini tidak memiliki nilai kembalian.

            AddWeapon(Weapon* weapon) (public access) untuk menambah suatu senjata ke dalam objek, yang nantinya akan digunakan oleh karakter dalam objek tersebut. Method ini tidak memiliki nilai kembalian.

            Getlistc() (public access) untuk mendapatkan array of Character yang ada di dalam objek. Method ini mengembalikan data dengan tipe array of Character.

            Getlistw() (public access) untuk mendapatkan array of Weapon yang ada di dalam objek. Method ini mengembalikan data dengan tipe array of Weapon.

    class Character : merupakan class yang menyimpan suatu karakter yang dapat dimainkan oleh pemain.
        1. Attribute
            name (private access) dengan tipe data string untuk menyimpan nama dari sebuah karakter.

            health (private access) dengan tipe data double untuk menyimpan nyawa dari suatu karakter.

            weapon (private access) dengan tipe data pointer to Weapon objek untuk menyimpan senjata yang digunakan suatu karakter.

        2. Constructor
            Character(string name) untuk mengalokasikan objek baru bertipe Character dengan parameter name bertipe string yang dijadikan sebagai attribute name untuk objek tersebut.

        3. Method
            defence(double damage) (private access) untuk mengkalkulasi serangan yang dilakukan antar karakter. Method ini mengurangi nyawa setiap karakter yang diserang. Method ini tidak memiliki nilai kembalian.

            display() (public access) untuk menampilkan rincian suatu karakter yang berupa name, health, dan weapon. Method ini tidak memiliki nilai kembalian.

            attack(Character* character) (public access) untuk melakukan penyerangan terhadap karakter lain. Method ini tidak memiliki nilai kembalian.

            getName() (public access) untuk mengambil nama dari sebuah karakter. Method ini merupakan getter. Method ini mengembalikan data dengan tipe string.

            getWeapon() (public access) untuk mengambil nama dari senjata yang digunakan oleh karakter. Method ini merupakan getter. Method ini mengembalikan data dengan tipe string.

            getHealth() (pbulic access) untuk mengambil nyawa dari sebuah karakter. Method ini merupakan getter. Method ini mengembalikan data dengan tipe double.

            equipWeapon (Weapon* weapon) (public access) untuk mengatur senjata yang digunakan oleh sebuah karakter. Method ini merupakan setter. Method ini tidak memiliki nilai kembalian.

    class Weapon : merupakan class yang menyimpan suatu senjata yang dapat digunakan oleh karakter.
        1. Attribute
            name (private access) dengan tipe data string untuk menyimpan nama dari suatu senjata.

            power (private access) dengan tipe data double untuk menyimpan kekuatan dari sebuah senjata.

        2. Constructor
            Weapon(string name, double power) untuk mengalokasikan objek baru bertipe Weapon dengan parameter name bertipe string dan power bertipe double yang dijadikan sebagai attribute name dan power untuk objek tersebut.

        3. Method
            getPower() (public access) untuk mengambil nilai kekuatan dari sebuah senjata. Method ini merupakan getter. Method ini mengembalikan data dengan tipe double.

            getName() (public access) untuk mengambil nama dari sebuah senjata. Method ini merupakan getter. Method ini mengembalikan data dengan tipe string.

    Program Flow
        Dalam program ini dideklarasikan tiga objek Player yaitu list, p1, dan p2. Objek list menyimpan semua karakter-karakter dan senjata-senjata yang dimasukkan oleh Admin. Objek p1 merupakan pemain pertama dan objek p2 merupakan pemain kedua.

        Pertama, program memanggil fungsi Menu(Player* list) dimana user akan diberi pilihan yaitu 1. PLAY untuk bermain dan 2. Run as Admin untuk menambahkan data permainan.

        1.
            Jika user menginput 1, maka program akan menampilkan nama pemain, kemudian memanggil fungsi void ChooseCharacter(Player* p, Player* list) dengan mem-passing alamat dari objek p1 dan list. Pada fungsi ini, user pemain pertama harus menginput 3 nomor karakter tersedia dalam list untuk dimainkan dalam gamenya. 
                
            Kemudian program akan memanggil fungsi void ChooseWeapon(Player* p, Player* list) dengan mem-passing alamat objek p1 dan list. Pada fungsi ini, user pemain pertama diharuskan memilih senjata yang ada di list untuk setiap karakternya.
                
            Setelah selesai, program memanggil fungsi ChooseCharacter(Player* p, Player* list) dan ChooseWeapon(Player* p, Player* list) lagi namun dengan mem-passing objek p2 dan list untuk pemain kedua memilih karakter dan senjata yang akan dipakainya.

            Selanjutnya program melakukan perulangan hingga salah satu pemain kalah. Perulangan tersebut dimulai dengan memanggil fungsi void DisplayChar(Player p1, Player p2) dengan mem-passing objek p1 dan p2 untuk ditampilkan rincian karakter dari setiap pemain. Kemudian program memanggil fungsi void Attack(Player* p1, Player* p2) dengan mem-passing objek p1 dan p2 untuk pemain pertama melakukan serangan terhadap pemain kedua. Selanjutnya dicek apakah telah ada pemain yang kalah dengan memanggil fungsi int CheckDefeat(Player* p1, Player* p2). Jika belum ada pemain yang kalah, maka dipanggil kembali fungsi void DisplayChar(Player p1, Player p2) untuk menampilkan kembali rincian karakter pemain. Kemudian program memanggil fungsi void Attack(Player* p1, Player* p2) kembali namun dengan objek passing yang terbalik sehingga dilakukan seragan dari pemain kedua ke pemain pertama. Pada setiap serangan, user menginput karakter yang digunakan untuk menyerang dan karakter lawan sebagai sasaran. Jika setelah saling serang masih belum ada pemain yang kalah, maka perulangan dilanjutkan. Jika terdapat pemain yang kalah, maka perulangan berhenti.

        2.
            Jika user menginput 2, maka program akan memanggil fungsi void AdminMenu(Player* list) untuk memilih ingin menambahkan karakter atau senjata.

                Jika user menginput 1, maka program akan memanggil fungsi void AddCharacter(Player* list) untuk menambah karakter dalam list. Jika telah selesai menambahkan karakter maka program akan memanggil fungsi void Menu(Player* list) untuk kembali ke menu utama.

                Jika user menginput 2, maka program akan memanggil fungsi void AddWeapon(Player* list) untuk menambahkan senjata dalam list. Jika telah selesai menambahkan senjata maka program akan memanggil fungsi void Menu(Player* list) untuk kembali ke menu utama.