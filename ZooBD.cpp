#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <locale>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <Windows.h>

using namespace std;

class Stern {
private:
    bool location;
    string type;
    int size;
    int price;
    string maker;

public:
    Stern(bool location_, string type_, int size_, int price_, string maker_) {
        location = location_;
        type = type_;
        size = size_;
        price = price_;
        maker = maker_;
    }

    virtual string GetLocation() {
        return location ? "Виготовлений" : "Закуплений";
    }

    virtual string GetType() {
        return type;
    }

    virtual string GetMaker() {
        return maker;
    }

    virtual int GetSize() {
        return size;
    }

    virtual int GetPrice() {
        return price;
    }

    virtual ~Stern() {}
};

class PurchasedStern : public Stern {
public:
    PurchasedStern(string type_, int size_, int price_, string maker_)
        : Stern(false, type_, size_, price_, maker_) {}
};

class ManufacturedStern : public Stern {
public:
    ManufacturedStern(string type_, int size_, int price_, string maker_)
        : Stern(true, type_, size_, price_, maker_) {}
};

class Employee {
protected:
    string name, soname, category;
    int yearsOfWork, age, salary;
    string gender;

public:
    virtual void Print() {
        cout << name << "\t" << soname << "\t" << gender << " \t" << age << "\t" << category << "\t" << salary << "\t      " << yearsOfWork << "\n";
    }

    virtual string GetName() {
        return name;
    }
    
    virtual string GetSoName() {
        return soname;
    }

    virtual string GetCategory() {
        return category;
    }

    virtual int GetYearsofWork() {
        return yearsOfWork;
    }

    virtual int GetAge() {
        return age;
    }

    virtual int GetSalary() {
        return salary;
    }

    virtual string GetGender() {
        return gender;
    }
};

class ZooEmployee : public Employee {
public:
    ZooEmployee(string name_, string soname_, bool gender_, int age_, string category_, int salary_, int yearsOfWork_) {
        name = name_;
        soname = soname_;
        gender = gender_ ? "Чоловіча" : "Жіноча";
        age = age_;
        category = category_;
        salary = salary_;
        yearsOfWork = yearsOfWork_;
    }
};

class Animal {
protected:
    string kind, gender, food, kindoffood, replaceonwinter, pregnantly, splintering;
    string ill, location;
    int age, feeding;
    double weight;

public:
    virtual void Print() {
        cout << kind << "\t" << gender << "\t" << food << "\t" << kindoffood << "\t" << age << "\t" << weight << "\t" << feeding << "\t" << ill << "\t" << replaceonwinter << "\t" << pregnantly << "\t" << splintering << "\t" << location << endl;
    }

    virtual string GetKind() {
        return kind;
    }

    virtual string GetGender() {
        return gender;
    }

    virtual string GetFood() {
        return food;
    }

    virtual string GetKindofFood() {
        return kindoffood;
    }

    virtual int GetAge() {
        return age;
    }

    virtual double GetWeight() {
        return weight;
    }

    virtual int GetFeeding() {
        return feeding;
    }

    virtual string GetIll() {
        return ill;
    }

    virtual string GetReplaceOnWinter() {
        return replaceonwinter;
    }

    virtual string GetPregnantly() {
        return pregnantly;
    }

    virtual string GetSplintering() {
        return splintering;
    }

    virtual string GetLocation() {
        return location;
    }
};

class ZooAnimal : public Animal {
public:
    ZooAnimal(string kind_, bool gender_, string food_, bool kindoffood_, int age_, double weight_, int feeding_, bool ill_, bool replaceonwinter_, bool pregnantly_, bool splintering_, string location_) {
        kind = kind_;
        gender = gender_ ? "Самець" : "Самка";
        food = food_;
        kindoffood = kindoffood_ ? "Хижак" : "Травоїдний";
        age = age_;
        weight = weight_;
        feeding = feeding_;
        ill = ill_ ? "В_стаціонарі" : "Здоровий";
        replaceonwinter = replaceonwinter_ ? "Потрібне_переселення" : "Непотрібне_переселення";
        pregnantly = pregnantly_ ? "Вагітна" : "Не_вагітна";
        splintering = splintering_ ? "Зроблено" : "Не_зроблено";
        location = location_;
    }

    void Print() override {
        cout << kind << "\t" << gender << "\t" << food << "\t" << kindoffood << "\t" << age << "\t" << weight << "\t" << feeding << "\t" << ill << "\t" << replaceonwinter << "\t" << pregnantly << "\t" << splintering << "\t" << location << endl;
    }
};

vector<Stern*>& allStern(){
	static vector<Stern*> stern; 
	return stern;      
}

vector<Animal*>& allAnimals() {
    static vector<Animal*> animals;
    return animals;
}

vector<ZooEmployee*>& allEmployees() {
    static vector<ZooEmployee*> employees;
    return employees;
}

void clearAnimalsfromFile() {
    std::ofstream outfile("animals1.txt", std::ofstream::trunc);
    if (outfile.is_open()) {
        outfile.close();
        // Очищення вектора allAnimals()
        vector<Animal*>& animals = allAnimals();
        animals.clear();
        cout << "Файл успішно очищено." << std::endl;
    } else {
        std::cout << "Не вдалося відкрити файл." << std::endl;
    }
}

void clearEmploeesfromFile() {
    std::ofstream outfile("employees1.txt", std::ofstream::trunc);
    if (outfile.is_open()) {
        outfile.close();
        // Очищення вектора allEmploees()
        vector<ZooEmployee*>& employees = allEmployees();
        employees.clear();
        cout << "Файл успішно очищено." << std::endl;
    } else {
        std::cout << "Не вдалося відкрити файл." << std::endl;
    }
}

void clearSternfromFile() {
    std::ofstream outfile("stern.txt", std::ofstream::trunc);
    if (outfile.is_open()) {
        outfile.close();
        // Очищення вектора allEmploees()
        vector<Stern*>& stern = allStern();
        stern.clear();
        cout << "Файл успішно очищено." << std::endl;
    } else {
        std::cout << "Не вдалося відкрити файл." << std::endl;
    }
}

void addAnimalsToFile() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ofstream outfile1("animals1.txt", ios_base::app | ios_base::out | ios_base::binary); // Відкриття файлу у режимі додавання
    if (outfile1.is_open()) {

        vector<Animal*>& animals = allAnimals();

        // Перевірка, чи вже є такі дані у файлі
        bool dataExists = false;
        std::string line;
        std::ifstream infile("animals1.txt");
        while (std::getline(infile, line)) {
            if (line.find("Вид\t\tСтать\t\tЇжа\t\tТип Їжі\t\tВік\t\tВага\t\tКількість годувань\tХвороба\t\t        Переселення\t\tВагітність\tЩеплення\tМісце народження") != std::string::npos) {
                dataExists = true;
                break;
            }
        }
        infile.close();

        if (!dataExists) {
            // Запис заголовка
            outfile1 << "Вид\t\tСтать\t\tЇжа\t\tТип Їжі\t\tВік\t\tВага\t\tКількість годувань\tХвороба\t\t        Переселення\t\tВагітність\tЩеплення\tМісце народження" << endl;
        }

        // Запис нових тварин
        int lastIndex = -1;
        ofstream outfile2("animals1.txt", ios_base::app | ios_base::out | ios_base::binary); // Відкриття файлу у режимі додавання
        if (outfile2.is_open()) {
            lastIndex = animals.size() - 1; // Оновлення значення lastIndex
            for (int i = lastIndex; i < animals.size(); i++) {
                outfile2 << setw(15) << left << animals[i]->GetKind() << "\t"
                         << setw(15) << left << boolalpha << animals[i]->GetGender() << "\t"
                         << setw(15) << left << animals[i]->GetFood() << "\t"
                         << setw(15) << left << boolalpha << animals[i]->GetKindofFood() << "\t"
                         << setw(10) << left << animals[i]->GetAge() << "\t"
                         << setw(10) << left << animals[i]->GetWeight() << "\t"
                         << setw(20) << left << animals[i]->GetFeeding() << "\t"
                         << setw(20) << left << animals[i]->GetIll() << "\t"
                         << setw(20) << left << boolalpha << animals[i]->GetReplaceOnWinter() << "\t"
                         << setw(15) << left << boolalpha << animals[i]->GetPregnantly() << "\t"
                         << setw(20) << left << boolalpha << animals[i]->GetSplintering() << "\t"
                         << setw(15) << left << animals[i]->GetLocation() << endl;
            }

            outfile2.close();

            // Оновлення вектора allAnimals()
            allAnimals() = animals;
        }
		 else {
            cout << "Не вдалося відкрити файл для запису" << endl;
        }

        outfile1.close();
    } else {
        cout << "Не вдалося відкрити файл для запису" << endl;
    }
}

void addEmployeesToFile(){
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	ofstream outfile;
    outfile.open("employees1.txt", ios_base::app | ios_base::out | ios_base::binary); // Відкриття файлу у режимі додавання);
    if (outfile.is_open()) {
    	 vector<ZooEmployee*>& employees = allEmployees();
    	 
    	 bool dataExists = false;
        std::string line;
        std::ifstream infile("employees1.txt");
        while (std::getline(infile, line)) {
            if (line.find("Iм`я\t                        Стать\t        Вiк\tПосада  \t\tЗарплата(грн)\t        Роки роботи") != std::string::npos) {
                dataExists = true;
                break;
            }
        }
        infile.close();
        
         if (!dataExists) {
            // Запис заголовка
            outfile << "Iм`я\t                        Стать\t        Вiк\tПосада  \t\tЗарплата(грн)\t        Роки роботи" << endl;
        }
      int lastIndex = -1;
        ofstream outfile2("employees1.txt", ios_base::app | ios_base::out | ios_base::binary); // Відкриття файлу у режимі додавання
        if (outfile2.is_open()) {
            lastIndex = employees.size() - 1; // Оновлення значення lastIndex
     for (int i = 0; i < employees.size(); i++) {
            outfile << setw(15) << left << employees[i]->GetName() << "\t"
                    << setw(15) << left << employees[i]->GetSoName() << "\t"
                    << setw(10) << left << employees[i]->GetGender() << "\t"
                    << setw(6)  << left << employees[i]->GetAge() << "\t"
                    << setw(16) << left << employees[i]->GetCategory() << "\t"
                    << setw(16) << left << employees[i]->GetSalary() << "\t"
                    << setw(15) << left << employees[i]->GetYearsofWork() << endl;
        }
         outfile2.close();

            // Оновлення вектора allAnimals()
            allEmployees() = employees;
        }
        
        outfile.close();
    } else {
        cout << "Не вдалося відкрити файл для запису";
    }
}

void addSternToFile() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ofstream outfile("stern.txt", ios_base::out);
    if (outfile.is_open()) {
        vector<Stern*>& stern = allStern();

        outfile << "Постачальник\t        Тип\t\tВид\t\tРозмір(кг)\t\tЦіна(кг)" << endl;

        for (int i = 0; i < stern.size(); i++) {
            outfile << setw(20) << left << stern[i]->GetMaker() << "\t"
                    << setw(15) << left << stern[i]->GetLocation() << "\t"
                    << setw(15) << left << stern[i]->GetType() << "\t"
                    << setw(20) << left << stern[i]->GetSize() << "\t"
                    << setw(15) << left << stern[i]->GetPrice() << endl;
        }

        outfile.close();

        allStern() = stern;
    } else {
        cout << "Не вдалося відкрити файл для запису" << endl;
    }
}

void addAnimals() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Animal*>& animals = allAnimals();

    string kind;
    bool gender;
    string food;
    bool kindoffood;
    int age;
    double weight;
    int feeding;
    bool ill;
    bool replaceonwinter;
    bool pregnantly;
    bool splintering;
    string location;

    cout << "Додавання нової тварини (для виходу введіть 'exit'):\n";

    // Зчитування даних з консолі
    cout << "Введіть вид тварини: ";
    cin >> kind;
    if (kind == "exit") {
        return;
    }

    cout << "Введіть стать тварини (1 - самець, 0 - самка): ";
    cin >> gender;
    if (cin.fail()) {
        cout << "Помилка: невірний формат статі тварини" << endl;
        cin.clear();
        return;
    }

    cout << "Введіть їжу тварини: ";
    cin >> food;
    if (food == "exit") {
        return;
    }

    cout << "Введіть вид їжі тварини (1 - хижак, 0 - травоїдний): ";
    cin >> kindoffood;
    if (cin.fail()) {
        cout << "Помилка: невірний формат виду їжі тварини" << endl;
        cin.clear();
        return;
    }
    cin.ignore();

    cout << "Введіть вік тварини: ";
    cin >> age;
    if (cin.fail()) {
        cout << "Помилка: невірний формат віку тварини" << endl;
        cin.clear();
        return;
    }

    cout << "Введіть вагу тварини: ";
    cin >> weight;
    if (cin.fail()) {
        cout << "Помилка: невірний формат ваги тварини" << endl;
        cin.clear();
        return;
    }

    cout << "Введіть частоту годування тварини: ";
    cin >> feeding;
    if (cin.fail()) {
        cout << "Помилка: невірний формат частоти годування тварини" << endl;
        cin.clear();
        return;
    }

    cout << "Введіть стан здоров'я тварини (1 - знаходиться на стаціонарі, 0 - здоровий): ";
    cin >> ill;
    if (cin.fail()) {
        cout << "Помилка: невірний формат стану здоров'я тварини" << endl;
        cin.clear();
        return;
    }
    cin.ignore();

    cout << "Введіть інформацію про необхідність переселення тварини на зимовник (1 - потрібне переселення, 0 - непотрібне переселення): ";
    cin >> replaceonwinter;
    if (cin.fail()) {
        cout << "Помилка: невірний формат інформації про переселення тварини на зимовник" << endl;
        cin.clear();
        return;
    }
    cin.ignore();

    if (!gender) {
        cout << "Введіть інформацію про вагітність тварини (1 - вагітна, 0 - не вагітна): ";
        cin >> pregnantly;
        if (cin.fail()) {
            cout << "Помилка: невірний формат інформації про вагітність тварини" << endl;
            cin.clear();
            return;
        }
        cin.ignore();
    } else {
        pregnantly = 0;
    }

    cout << "Введіть інформацію про зроблені щеплення для тварини (1 - зроблено, 0 - не зроблено): ";
    cin >> splintering;
    if (cin.fail()) {
        cout << "Помилка: невірний формат інформації про щеплення тварини" << endl;
        cin.clear();
        return;
    }
    cin.ignore();  // Очищення буфера

    cout << "Введіть розташування тварини (Введіть 1 якщо цей зоопарк або напишіть назву іншого): ";
    cin >> location;
    if (location == "exit") {
        return;
    }
    cin.ignore();  // Очищення буфера

    animals.push_back(new ZooAnimal(kind, gender, food, kindoffood, age, weight, feeding, ill, replaceonwinter, pregnantly, splintering, location));
    cout << "Тварина успішно додана!" << endl;

    // Записати дані в файл
    addAnimalsToFile();
}

void addEmployee() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<ZooEmployee*>& employees = allEmployees();

    string name, soname;
bool gender;
int age, salary, yearsOfWork;
string category;

cout << "Додавання нового працівника (для виходу введіть 'exit'):\n";

cout << "Ім'я працівника: ";
cin >> name;
if (cin.fail()) {
    cout << "Помилка: невірний формат імені працівника" << endl;
    cin.clear();
    return;
}
cin.ignore();

cout << "Прізвище працівника: ";
cin >> soname;
if (cin.fail()) {
    cout << "Помилка: невірний формат прізвища працівника" << endl;
    cin.clear();
    return;
}
cin.ignore();

cout << "Стать (чоловіча - 1, жіноча - 0): ";
cin >> gender;
if (cin.fail()) {
    cout << "Помилка: невірний формат статі працівника" << endl;
    cin.clear();
    return;
}
cin.ignore();

cout << "Вік працівника: ";
cin >> age;
if (cin.fail()) {
    cout << "Помилка: невірний формат віку працівника" << endl;
    cin.clear();
    return;
}
cin.ignore();

cout << "Категорія працівника: ";
getline(cin, category);

cout << "Зарплата працівника: ";
cin >> salary;
if (cin.fail()) {
    cout << "Помилка: невірний формат зарплати працівника" << endl;
    cin.clear();
    return;
}
cin.ignore();

cout << "Роки роботи: ";
cin >> yearsOfWork;
if (cin.fail()) {
    cout << "Помилка: невірний формат років роботи працівника" << endl;
    cin.clear();
    return;
}
cin.ignore();

employees.push_back(new ZooEmployee(name, soname, gender, age, category, salary, yearsOfWork));

cout << "Працівник успішно доданий!";

addEmployeesToFile();
}

void addStern(){
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
	 vector<Stern*>& stern = allStern();
	 
bool location;
string type;
int size;
int price;
string maker;

cout << "Додавання нового корму (для виходу введіть 'exit'):\n";

cout << "Введіть місце походження корму (1 - виготовлений, 0 - закуплений): ";
cin >> location;
if (cin.fail() || (location != 0 && location != 1)) {
    cout << "Помилка: невірний формат місця походження корму" << endl;
    cin.clear();
    return;
}
cin.ignore();

cout << "Введіть тип корму: ";
getline(cin, type);

cout << "Введіть розмір корму: ";
cin >> size;
if (cin.fail()) {
    cout << "Помилка: невірний формат розміру корму" << endl;
    cin.clear();
    return;
}
cin.ignore();

cout << "Введіть ціну корму: ";
cin >> price;
if (cin.fail()) {
    cout << "Помилка: невірний формат ціни корму" << endl;
    cin.clear();
    return;
}
cin.ignore();

if (!location) {
    cout << "Введіть виробника корму: ";
    cin >> maker;
} else {
    maker = "Немає";
}

if (location) {
    stern.push_back(new ManufacturedStern(type, size, price, maker));
} else {
    stern.push_back(new PurchasedStern(type, size, price, maker));
}

cout << "Корм успішно доданий!" << endl;

addSternToFile();
}

void GetOutAnimalsFromFile(){
	SetConsoleOutputCP(1251);
        vector<Animal*>& animals = allAnimals();

	string str;
	int CategoryChoise1, currentLineIndex, index, str_number = 0;	
	ifstream infile1;
    
	cout << "Виберіть вид тварин" << endl
	     << "1. Переглянути конкретну тварину" << endl
	     << "2. Переглянути всіх" << endl;
	     
	 cout << "Ваш вибір: ";    
	 cin >> CategoryChoise1;
	cout << "Вид\t        Стать\t        Їжа\t        Тип Їжі\t        Вік  \t       Вага\t     Кількість годувань\t\tЩеплення" << endl;
	 cout << endl;
	switch(CategoryChoise1){
	
        case 1:
        	int choiseAnimal;
        	system("cls");
        	

        	cout << "Введіть номер тварини: " << endl;
        	
        	
        	cin >> choiseAnimal;
        	system("cls");
        	cout << "Вид\t        Стать\t        Їжа\t        Тип Їжі\t        Вік  \t       Вага\t     Кількість годувань\t\tЩеплення" << endl;

        	cout    << setw(15) << left << animals[choiseAnimal]->GetKind() << "\t"
                        << setw(10) << left << animals[choiseAnimal]->GetGender() << "\t"
                        << setw(12) << left << animals[choiseAnimal]->GetFood() << "\t"
                        << setw(15) << left << animals[choiseAnimal]->GetKindofFood() << "\t"
                        << setw(15) << left << animals[choiseAnimal]->GetAge() << "\t"
                        << setw(14) << left << animals[choiseAnimal]->GetWeight() << "\t"
                        << setw(20) << left << animals[choiseAnimal]->GetFeeding() << "\t"
                        << setw(15) << left << animals[choiseAnimal]->GetSplintering() << endl;
    
     break;       
        case 2:
        	system("cls");
        	
			cout << "Вид\t        Стать\t        Їжа\t        Тип Їжі\t        Вік  \t       Вага\t     Кількість годувань\t\tХвороба\t\t       Щеплення" << endl;

         for(int i = 0; i < animals.size(); i++){
    	
        	cout    << setw(15) << left << animals[i]->GetKind() << "\t"
                    << setw(10) << left << boolalpha << animals[i]->GetGender() << "\t"
                    << setw(12) << left << animals[i]->GetFood() << "\t"
                    << setw(15) << left << boolalpha << animals[i]->GetKindofFood() << "\t"
                    << setw(15) << left << animals[i]->GetAge() << "\t"
                    << setw(14) << left << animals[i]->GetWeight() << "\t"
                    << setw(20) << left << animals[i]->GetFeeding() << "\t"
                    << setw(20) << left << boolalpha << animals[i]->GetIll() << "\t"
                    << setw(15) << left << boolalpha << animals[i]->GetSplintering() << endl;
            cout << "_______________________________________________________________________________________________________________________________________________________" << endl;
		
	}
    break;
	}
	}
	
void loadAnimalsFromFile() {
    vector<Animal*>& animals = allAnimals();

    ifstream infile("animals1.txt");
    if (infile.is_open()) {
        animals.clear();  // Очищаємо вектор перед завантаженням даних з файлу

        string line;
        bool skipHeader = true;  // Флаг для пропуску першого рядка (заголовка)
        while (getline(infile, line)) {
            if (skipHeader) {
                skipHeader = false;
                continue;  // Пропускаємо заголовок
            }

            istringstream ss(line);
            string kind, genderStr, food, kindoffoodStr, illStr, replaceonwinterStr, pregnantlyStr, splinteringStr, location;
            int age, feeding;
            double weight;

            if (ss >> kind >> genderStr >> food >> kindoffoodStr >> age >> weight >> feeding >> illStr >> replaceonwinterStr >> pregnantlyStr >> splinteringStr >> location ) {
            	

            	
            		
                
                bool gender = (genderStr == "Самець") ;
                bool kindoffood = (kindoffoodStr == "Хижак") ;
                bool ill = (illStr == "В_стаціонарі") ;
                bool replaceonwinter = (replaceonwinterStr == "Потрібне_переселення") ;
                bool pregnantly = (pregnantlyStr == "Вагітна") ;
                bool splintering = (splinteringStr.find("Зроблено") != string::npos) ;

                animals.push_back(new ZooAnimal(kind, gender, food, kindoffood, age, weight, feeding, ill, replaceonwinter, pregnantly, splintering, location));
            }
			 else {
                cout << "Помилка читання рядка: " << line << endl;
            }
        }
        infile.close();
    }
	 else {
        cout << "Не вдалося відкрити файл для читання" << endl;
    }
}

void loadEmployeesFromFile() {
    vector<ZooEmployee*>& employees = allEmployees();

    ifstream infile("employees1.txt");
    if (infile.is_open()) {
        employees.clear();  // Очищаємо вектор перед завантаженням даних з файлу

        string line;
        bool skipHeader = true;  // Флаг для пропуску першого рядка (заголовка)
        while (getline(infile, line)) {
            if (skipHeader) {
                skipHeader = false;
                continue;  // Пропускаємо заголовок
            }

            string name, soname, genderStr;
            int age, salary, yearsOfWork;
            string category;

            istringstream ss(line);

            if (ss >> name >> soname >> genderStr >> age >> category >> salary >> yearsOfWork) {
                bool gender = (genderStr == "Чоловіча");

                employees.push_back(new ZooEmployee(name, soname, gender, age, category, salary, yearsOfWork));
            } else {
                cout << "Помилка читання рядка: " << line << endl;
            }
        }
        infile.close();
    } else {
        cout << "Не вдалося відкрити файл працівників для читання" << endl;
    }
}

void loadSternFromFile() {
    vector<Stern*>& stern = allStern();

    ifstream infile("stern.txt");
    if (infile.is_open()) {
        stern.clear();  // Очищаємо вектор перед завантаженням даних з файлу

        string line;
        bool skipHeader = true;  // Флаг для пропуску першого рядка (заголовка)
        while (getline(infile, line)) {
            if (skipHeader) {
                skipHeader = false;
                continue;  // Пропускаємо заголовок
            }

            bool location;
            string type, locationStr;
            int size;
            int price;
            string maker;

            istringstream ss(line);

            if (ss >> maker >> locationStr >> type >> size >> price) {
                 bool location = (locationStr == "Виготовлений");

                if (location) {
                 stern.push_back(new ManufacturedStern(type, size, price, maker));
               }
			    else {
                  stern.push_back(new PurchasedStern(type, size, price, maker));
                     }        
            }
			 else {
                cout << "Помилка читання рядка: " << line << endl;
            }
        }
        infile.close();
    } else {
        cout << "Не вдалося відкрити файл працівників для читання" << endl;
    }
}

void GetOutEmploeesFromFile(){
	SetConsoleOutputCP(1251);
	vector<ZooEmployee*>& employees = allEmployees();
	//addEmploeesToFile();
	string str;
	ifstream infile;
	int CategoryChoise, currentLineIndex, index, str_number = 0;

	cout << "Виберiть категорiю працiвникiв" << endl
	     << "1. Переглянути ветеринарiв" << endl
	     << "2. Переглянути прибиральникiв" << endl
	     << "3. Переглянути дресерувальникiв" << endl
	     << "4. Переглянути будiвельникiв" << endl
	     << "5. Переглянути робiтникiв адмiнiстрацiї" << endl
	     << "6. Переглянути конкретного працівника" << endl
	     << "7. Переглянути всiх" << endl;
	     
	cout << "Ваш вибір: ";       
	cin >> CategoryChoise;
	cout << "Iм`я\t                        Стать\t        Вiк\tПосада  \t\tЗарплата(грн)\t        Роки роботи" << endl;
	
	switch(CategoryChoise){
	/*	case 1:
		for (int i = 0; i < employees->size(); i++) {
			if((*employees)[i].GetCategory() == "Ветеринар"){
            cout << setw(30) << left << (*employees)[i].GetName() << "\t"
                    << setw(10) << left << (*employees)[i].GetGender() << "\t"
                    << setw(6) << left << (*employees)[i].GetAge() << "\t"
                    << setw(16) << left << (*employees)[i].GetCategory() << "\t"
                    << setw(16) << left << (*employees)[i].GetSalary() << "\t"
                    << setw(15) << left << (*employees)[i].GetYearsofWork() << endl;
        
        
		}
	}
        delete employees;
		    break;
		case 2:
		    for (int i = 0; i < employees->size(); i++) {
			if((*employees)[i].GetCategory() == "Прибиральник"){
            cout << setw(30) << left << (*employees)[i].GetName() << "\t"
                    << setw(10) << left << (*employees)[i].GetGender() << "\t"
                    << setw(6) << left << (*employees)[i].GetAge() << "\t"
                    << setw(16) << left << (*employees)[i].GetCategory() << "\t"
                    << setw(16) << left << (*employees)[i].GetSalary() << "\t"
                    << setw(15) << left << (*employees)[i].GetYearsofWork() << endl;
        
        
		}
	}
        delete employees;
    break;
	    case 3:
	       for (int i = 0; i < employees->size(); i++) {
			if((*employees)[i].GetCategory() == "Дресерувальник"){
            cout << setw(30) << left << (*employees)[i].GetName() << "\t"
                    << setw(10) << left << (*employees)[i].GetGender() << "\t"
                    << setw(6) << left << (*employees)[i].GetAge() << "\t"
                    << setw(16) << left << (*employees)[i].GetCategory() << "\t"
                    << setw(16) << left << (*employees)[i].GetSalary() << "\t"
                    << setw(15) << left << (*employees)[i].GetYearsofWork() << endl;
        
        
		}
	}
        delete employees;
    break;
       case 4:
       	   for (int i = 0; i < employees->size(); i++) {
			if((*employees)[i].GetCategory() == "Будівельник"){
            cout << setw(30) << left << (*employees)[i].GetName() << "\t"
                    << setw(10) << left << (*employees)[i].GetGender() << "\t"
                    << setw(6) << left << (*employees)[i].GetAge() << "\t"
                    << setw(16) << left << (*employees)[i].GetCategory() << "\t"
                    << setw(16) << left << (*employees)[i].GetSalary() << "\t"
                    << setw(15) << left << (*employees)[i].GetYearsofWork() << endl;
        
        
		}
	}
        delete employees;
    break;
       case 5:
          for (int i = 0; i < employees->size(); i++) {
			if((*employees)[i].GetCategory() == "Адміністрація"){
            cout << setw(30) << left << (*employees)[i].GetName() << "\t"
                    << setw(10) << left << (*employees)[i].GetGender() << "\t"
                    << setw(6) << left << (*employees)[i].GetAge() << "\t"
                    << setw(16) << left << (*employees)[i].GetCategory() << "\t"
                    << setw(16) << left << (*employees)[i].GetSalary() << "\t"
                    << setw(15) << left << (*employees)[i].GetYearsofWork() << endl;
        
        
		}
	}
        delete employees;
    break;*/
       case 6:
       	int choiseEmployee;
        	system("cls");
        	cout << "Введіть номер працівника: " << endl;
        	cin >> choiseEmployee;
        	
        	system("cls");
        	cout << "Iм`я\t                        Стать\t        Вiк\tПосада  \t\tЗарплата(грн)\t        Роки роботи" << endl;
        	
        	cout    << setw(15) << left << employees[choiseEmployee]->GetName() << "\t"
        	        << setw(15) << left << employees[choiseEmployee]->GetSoName() << "\t"
                    << setw(10) << left << employees[choiseEmployee]->GetGender() << "\t"
                    << setw(6)  << left << employees[choiseEmployee]->GetAge() << "\t"
                    << setw(16) << left << employees[choiseEmployee]->GetCategory() << "\t"
                    << setw(16) << left << employees[choiseEmployee]->GetSalary() << "\t"
                    << setw(15) << left << employees[choiseEmployee]->GetYearsofWork() << endl;
                    
        	break;
       case 7:
       		system("cls");
        	
				cout << "Iм`я\t                        Стать\t        Вiк\tПосада  \t\tЗарплата(грн)\t        Роки роботи" << endl;

         for(int i = 0; i < employees.size(); i++){
    	
        	cout    << setw(15) << left << employees[i]->GetName() << "\t"
                    << setw(15) << left << employees[i]->GetSoName() << "\t"
                    << setw(10) << left << employees[i]->GetGender() << "\t"
                    << setw(6)  << left << employees[i]->GetAge() << "\t"
                    << setw(16) << left << employees[i]->GetCategory() << "\t"
                    << setw(16) << left << employees[i]->GetSalary() << "\t"
                    << setw(15) << left << employees[i]->GetYearsofWork() << endl;
            cout << "____________________________________________________________________________________________________________________________" << endl;
		
	}
    break;
	}    


}

void addToStationare(){
	
        vector<Animal*>& animals = allAnimals();
    
     cout << "Вид\t        Стать\t        Їжа\t        Тип Їжі\t        Вік  \t       Вага\t     Кількість годувань\t\tЩеплення" << endl;

    for(int i = 0; i < animals.size(); i++){
    	
        if(animals[i]->GetIll() == "В_стаціонарі"){
        	
            cout    << setw(15) << left << animals[i]->GetKind() << "\t"
                    << setw(10) << left << animals[i]->GetGender() << "\t"
                    << setw(12) << left << animals[i]->GetFood() << "\t"
                    << setw(15) << left << animals[i]->GetKindofFood() << "\t"
                    << setw(15) << left << animals[i]->GetAge() << "\t"
                    << setw(14) << left << animals[i]->GetWeight() << "\t"
                    << setw(20) << left << animals[i]->GetFeeding() << "\t"
                    << setw(15) << left << animals[i]->GetSplintering() << endl;
            cout << "___________________________________________________" << endl;
        }
    }

}

void TimeOfFeeding() {
        vector<Animal*>& animals = allAnimals();

    for (int i = 0; i < animals.size(); i++) {
    	cout << animals[i]->GetKind() << "-" << animals[i]->GetGender() << endl;
        for (int j = 8; j < 24; j += animals[i]->GetFeeding()) {
            cout << j << ":00" << "\t";
        }
        cout << endl;
        cout << "___________________________________________________" << endl;
    }

}

void ReplaceOnWinter(){
        vector<Animal*>& animals = allAnimals();
    
    cout << "Вид\t        Стать\t        Їжа\t        Тип Їжі\t        Вік  \t       Вага\t     Кількість годувань\t\tЩеплення" << endl
	     << endl;
    
    for(int i = 0; i < animals.size(); i++){
    	if(animals[i]->GetReplaceOnWinter() == "Потрібне_переселення"){
        	 cout   << setw(15) << left << animals[i]->GetKind() << "\t"
                    << setw(10) << left << animals[i]->GetGender() << "\t"
                    << setw(12) << left << animals[i]->GetFood() << "\t"
                    << setw(15) << left << animals[i]->GetKindofFood() << "\t"
                    << setw(15) << left << animals[i]->GetAge() << "\t"
                    << setw(14) << left << animals[i]->GetWeight() << "\t"
                    << setw(20) << left << animals[i]->GetFeeding() << "\t"
                    << setw(15) << left << animals[i]->GetSplintering() << endl;
            cout << "____________________________________________________________________________________________________________________________" << endl;
		}
	}
		
}

void PregnantAnimals(){
        vector<Animal*>& animals = allAnimals();
	 
	 cout << "Вид\t        Стать\t        Їжа\t        Тип Їжі\t        Вік  \t       Вага\t     Кількість годувань\t\tЩеплення" << endl;
	 cout << endl;
    
    for(int i = 0; i < animals.size(); i++){
    	if(animals[i]->GetPregnantly() == "Вагітна"){
        	cout    << setw(15) << left << animals[i]->GetKind() << "\t"
                    << setw(10) << left << animals[i]->GetGender() << "\t"
                    << setw(12) << left << animals[i]->GetFood() << "\t"
                    << setw(15) << left << animals[i]->GetKindofFood() << "\t"
                    << setw(15) << left << animals[i]->GetAge() << "\t"
                    << setw(14) << left << animals[i]->GetWeight() << "\t"
                    << setw(20) << left << animals[i]->GetFeeding() << "\t"
                    << setw(15) << left << animals[i]->GetSplintering() << endl;
            cout << "____________________________________________________________________________________________________________________________" << endl;
		}
	}
	
}

void SelfPreparationStern(){
	vector<Stern*>& stern = allStern();
	
	cout << "Спосіб виготовлення\tТип\t Розмір(кг)" << endl;
	
	for(int i = 0; i < stern.size(); i++){
		if(stern[i]->GetLocation() == "Виготовлений"){
			cout << setw(20) << left << stern[i]->GetLocation() << "\t" 
			     << setw(10) << left << stern[i]->GetType() << "\t" 
				 << setw(15) << left << stern[i]->GetSize() << endl;
		}
	}
	
}

void BuyingStern(){
	vector<Stern*>& stern = allStern();
	
	cout << "Спосіб виготовлення\tТип\t\tРозмір(кг)\tЦіна(грн)\tПостачальник" << endl;
	
	for(int i = 0; i < stern.size(); i++){
		if(stern[i]->GetLocation() == "Закуплений"){
			cout << setw(20) << left << stern[i]->GetLocation() << "\t" 
			     << setw(15) << left << stern[i]->GetType() << "\t" 
				 << setw(15) << left << stern[i]->GetSize() << "\t" 
				 << setw(15) << left << stern[i]->GetPrice() << "\t"
				 << setw(15) << left << stern[i]->GetMaker() << endl;
		}
	}
	
}

void GetPostman(){
    vector<Stern*>& stern = allStern();
    
    cout << "Постачальник\t\tТип\t\tРозмір(кг)\tЦіна(кг)" << endl;
    
    for(int i = 0; i < stern.size(); i++){
        if(stern[i]->GetMaker() != "Немає"){
            cout << setw(20) << left << stern[i]->GetMaker() << "\t" 
                 << setw(15) << left << stern[i]->GetType() << "\t"
                 << setw(15) << left << stern[i]->GetSize() << "\t"
                 << setw(15) << left << stern[i]->GetPrice() << endl;
        }
    }
    
}

void GetLocationOfBirthInZoo() {
    vector<Animal*>& animals = allAnimals();

    cout << "Вид\t        Стать\t        Їжа\t        Тип Їжі\t        Вік  \t       Вага\t    Кількість годувань\t\tЩеплення" << endl;

    for (int i = 0; i < animals.size(); i++) {
        if (animals[i]->GetLocation().find("1") != std::string::npos) {
            cout << setw(15) << left << animals[i]->GetKind() << "\t"
                 << setw(15) << left << animals[i]->GetGender() << "\t"
                 << setw(15) << left << animals[i]->GetFood() << "\t"
                 << setw(15) << left << animals[i]->GetKindofFood() << "\t"
                 << setw(15) << left << animals[i]->GetAge() << "\t"
                 << setw(15) << left << animals[i]->GetWeight() << "\t"
                 << setw(20) << left << animals[i]->GetFeeding() << "\t"
                 << setw(15) << left << animals[i]->GetSplintering() << endl;
        }
    }
}

void GetLocationOfBirthInOtherZoo(){
    vector<Animal*>& animals = allAnimals();

    cout << "Вид\t        Стать\t        Їжа\t        Тип Їжі\t        Вік  \t       Вага\t    Кількість годувань\t        Місце нарождення" << endl;

    for(int i = 0; i < animals.size(); i++){
        if(animals[i]->GetLocation().find("1") == std::string::npos){
            cout << setw(15) << left << animals[i]->GetKind() << "\t"
                    << setw(15) << left << animals[i]->GetGender() << "\t"
                    << setw(15) << left << animals[i]->GetFood() << "\t"
                    << setw(15) << left << animals[i]->GetKindofFood() << "\t"
                    << setw(15) << left << animals[i]->GetAge() << "\t"
                    << setw(15) << left << animals[i]->GetWeight() << "\t"
                    << setw(20) << left << animals[i]->GetFeeding() << "\t"
                    << setw(15) << left << animals[i]->GetLocation() << endl;
        }
    }
}


void Menu(){
	cout << "АІС зоопарку" << endl
	     << "1. Додати тварин зоопарку" << endl
	     << "2. Видалити тварин зоопарку" << endl
	     << "3. Додати працівників зоопарку" << endl
	     << "4. Видалити працівників зоопарку" << endl
	     << "5. Додати корм зоопарку" << endl
	     << "6. Видалити корм зоопарку" << endl
	     << "7. Переглянути всіх тварин зоопарку" << endl
	     << "8. Переглянути всіх робітників зоопарку" << endl
	     << "9. Переглянути тварин в стаціонарі" << endl
	     << "10. Переглянути графік годівання" << endl
	     << "11. Переглянути тварин для переселення на зиму" << endl
	     << "12. Переглянути вагітних тварин" << endl
	     << "13. Переглянути корм виготовлений зоопарком" << endl
	     << "14. Переглянути закуплений корм" << endl
	     << "15. Переглянути постачальників зоопрку" << endl
	     << "16. Переглянути тварин народжених у зоопарку" << endl
	     << "17. Переглянути тварин обміняних з інших зоопарків" << endl
	     << "18. Вихід" << endl;

}


int main(){
    SetConsoleOutputCP(1251);
    
    loadAnimalsFromFile();
    loadEmployeesFromFile();
    loadSternFromFile();
    
    int choise;
    bool exitMenu = false;
    
    while (!exitMenu){
    	Menu();
    	
    	cout << "Ваш вибір:";
    	cin >> choise;
    	system("cls");
    	
    	switch(choise){
    		
    		case 1:
    			addAnimals();
    			system("pause");
    			system("cls");
    		break;
    		
    		case 2:
    			clearAnimalsfromFile();
    			system("pause");
    			system("cls");
    		break;
    		
    		case 3:
    			addEmployee();
    			system("pause");
    			system("cls");
    		break;
    		
    		case 4:
    			clearEmploeesfromFile();
    			system("pause");
    			system("cls");
    		break;
    		
    		case 5:
    			addStern();
    			system("pause");
    			system("cls");
    		break;
    		
    		case 6:
    			clearSternfromFile();
    			system("pause");
    			system("cls");
    		break;
    		
    		case 7:
    			GetOutAnimalsFromFile();
    			system("pause");
    			system("cls");
    		break;
    		
			case 8:
			    GetOutEmploeesFromFile();
			    system("pause");
    			system("cls");
			break;	
				
			case 9:
			    addToStationare();
			    system("pause");
    			system("cls");
			break;
						
			case 10:
			    TimeOfFeeding();
			    system("pause");
    			system("cls");
			break;	
						
			case 11:
			    ReplaceOnWinter();
			    system("pause");
    			system("cls");
			break;	
						
			case 12:
			    PregnantAnimals();
			    system("pause");
    			system("cls");
			break;	
						
			case 13:
			    SelfPreparationStern();
			    system("pause");
    			system("cls");
			break;
							
			case 14:
			    BuyingStern();
			    system("pause");
    			system("cls");
			break;	
							
			case 15:
			    GetPostman();
			    system("pause");
    			system("cls");
			break;	
							
			case 16:
			    GetLocationOfBirthInZoo();
			    system("pause");
    			system("cls");
			break;	
							
			case 17:
			    GetLocationOfBirthInOtherZoo();
			    system("pause");
    			system("cls");
			break;	
			
			case 18:
			exitMenu = true;
			break;
			
			default:
			cout << " Невірний вибір, введіть ще раз";
			break;									
		}
		
		cout << endl;
	}
	
cout << "Дякую за увагу!";

return 0;
}

