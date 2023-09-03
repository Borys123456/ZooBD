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
        return location ? "������������" : "����������";
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
        gender = gender_ ? "�������" : "Ƴ����";
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
        gender = gender_ ? "������" : "�����";
        food = food_;
        kindoffood = kindoffood_ ? "�����" : "���������";
        age = age_;
        weight = weight_;
        feeding = feeding_;
        ill = ill_ ? "�_���������" : "��������";
        replaceonwinter = replaceonwinter_ ? "�������_�����������" : "���������_�����������";
        pregnantly = pregnantly_ ? "������" : "��_������";
        splintering = splintering_ ? "��������" : "��_��������";
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
        // �������� ������� allAnimals()
        vector<Animal*>& animals = allAnimals();
        animals.clear();
        cout << "���� ������ �������." << std::endl;
    } else {
        std::cout << "�� ������� ������� ����." << std::endl;
    }
}

void clearEmploeesfromFile() {
    std::ofstream outfile("employees1.txt", std::ofstream::trunc);
    if (outfile.is_open()) {
        outfile.close();
        // �������� ������� allEmploees()
        vector<ZooEmployee*>& employees = allEmployees();
        employees.clear();
        cout << "���� ������ �������." << std::endl;
    } else {
        std::cout << "�� ������� ������� ����." << std::endl;
    }
}

void clearSternfromFile() {
    std::ofstream outfile("stern.txt", std::ofstream::trunc);
    if (outfile.is_open()) {
        outfile.close();
        // �������� ������� allEmploees()
        vector<Stern*>& stern = allStern();
        stern.clear();
        cout << "���� ������ �������." << std::endl;
    } else {
        std::cout << "�� ������� ������� ����." << std::endl;
    }
}

void addAnimalsToFile() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ofstream outfile1("animals1.txt", ios_base::app | ios_base::out | ios_base::binary); // ³������� ����� � ����� ���������
    if (outfile1.is_open()) {

        vector<Animal*>& animals = allAnimals();

        // ��������, �� ��� � ��� ��� � ����
        bool dataExists = false;
        std::string line;
        std::ifstream infile("animals1.txt");
        while (std::getline(infile, line)) {
            if (line.find("���\t\t�����\t\t���\t\t��� ��\t\t³�\t\t����\t\tʳ������ ��������\t�������\t\t        �����������\t\t��������\t��������\t̳��� ����������") != std::string::npos) {
                dataExists = true;
                break;
            }
        }
        infile.close();

        if (!dataExists) {
            // ����� ���������
            outfile1 << "���\t\t�����\t\t���\t\t��� ��\t\t³�\t\t����\t\tʳ������ ��������\t�������\t\t        �����������\t\t��������\t��������\t̳��� ����������" << endl;
        }

        // ����� ����� ������
        int lastIndex = -1;
        ofstream outfile2("animals1.txt", ios_base::app | ios_base::out | ios_base::binary); // ³������� ����� � ����� ���������
        if (outfile2.is_open()) {
            lastIndex = animals.size() - 1; // ��������� �������� lastIndex
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

            // ��������� ������� allAnimals()
            allAnimals() = animals;
        }
		 else {
            cout << "�� ������� ������� ���� ��� ������" << endl;
        }

        outfile1.close();
    } else {
        cout << "�� ������� ������� ���� ��� ������" << endl;
    }
}

void addEmployeesToFile(){
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	ofstream outfile;
    outfile.open("employees1.txt", ios_base::app | ios_base::out | ios_base::binary); // ³������� ����� � ����� ���������);
    if (outfile.is_open()) {
    	 vector<ZooEmployee*>& employees = allEmployees();
    	 
    	 bool dataExists = false;
        std::string line;
        std::ifstream infile("employees1.txt");
        while (std::getline(infile, line)) {
            if (line.find("I�`�\t                        �����\t        �i�\t������  \t\t��������(���)\t        ���� ������") != std::string::npos) {
                dataExists = true;
                break;
            }
        }
        infile.close();
        
         if (!dataExists) {
            // ����� ���������
            outfile << "I�`�\t                        �����\t        �i�\t������  \t\t��������(���)\t        ���� ������" << endl;
        }
      int lastIndex = -1;
        ofstream outfile2("employees1.txt", ios_base::app | ios_base::out | ios_base::binary); // ³������� ����� � ����� ���������
        if (outfile2.is_open()) {
            lastIndex = employees.size() - 1; // ��������� �������� lastIndex
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

            // ��������� ������� allAnimals()
            allEmployees() = employees;
        }
        
        outfile.close();
    } else {
        cout << "�� ������� ������� ���� ��� ������";
    }
}

void addSternToFile() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ofstream outfile("stern.txt", ios_base::out);
    if (outfile.is_open()) {
        vector<Stern*>& stern = allStern();

        outfile << "������������\t        ���\t\t���\t\t�����(��)\t\tֳ��(��)" << endl;

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
        cout << "�� ������� ������� ���� ��� ������" << endl;
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

    cout << "��������� ���� ������� (��� ������ ������ 'exit'):\n";

    // ���������� ����� � ������
    cout << "������ ��� �������: ";
    cin >> kind;
    if (kind == "exit") {
        return;
    }

    cout << "������ ����� ������� (1 - ������, 0 - �����): ";
    cin >> gender;
    if (cin.fail()) {
        cout << "�������: ������� ������ ���� �������" << endl;
        cin.clear();
        return;
    }

    cout << "������ ��� �������: ";
    cin >> food;
    if (food == "exit") {
        return;
    }

    cout << "������ ��� �� ������� (1 - �����, 0 - ���������): ";
    cin >> kindoffood;
    if (cin.fail()) {
        cout << "�������: ������� ������ ���� �� �������" << endl;
        cin.clear();
        return;
    }
    cin.ignore();

    cout << "������ �� �������: ";
    cin >> age;
    if (cin.fail()) {
        cout << "�������: ������� ������ ��� �������" << endl;
        cin.clear();
        return;
    }

    cout << "������ ���� �������: ";
    cin >> weight;
    if (cin.fail()) {
        cout << "�������: ������� ������ ���� �������" << endl;
        cin.clear();
        return;
    }

    cout << "������ ������� ��������� �������: ";
    cin >> feeding;
    if (cin.fail()) {
        cout << "�������: ������� ������ ������� ��������� �������" << endl;
        cin.clear();
        return;
    }

    cout << "������ ���� ������'� ������� (1 - ����������� �� ���������, 0 - ��������): ";
    cin >> ill;
    if (cin.fail()) {
        cout << "�������: ������� ������ ����� ������'� �������" << endl;
        cin.clear();
        return;
    }
    cin.ignore();

    cout << "������ ���������� ��� ����������� ����������� ������� �� �������� (1 - ������� �����������, 0 - ��������� �����������): ";
    cin >> replaceonwinter;
    if (cin.fail()) {
        cout << "�������: ������� ������ ���������� ��� ����������� ������� �� ��������" << endl;
        cin.clear();
        return;
    }
    cin.ignore();

    if (!gender) {
        cout << "������ ���������� ��� �������� ������� (1 - ������, 0 - �� ������): ";
        cin >> pregnantly;
        if (cin.fail()) {
            cout << "�������: ������� ������ ���������� ��� �������� �������" << endl;
            cin.clear();
            return;
        }
        cin.ignore();
    } else {
        pregnantly = 0;
    }

    cout << "������ ���������� ��� ������� �������� ��� ������� (1 - ��������, 0 - �� ��������): ";
    cin >> splintering;
    if (cin.fail()) {
        cout << "�������: ������� ������ ���������� ��� �������� �������" << endl;
        cin.clear();
        return;
    }
    cin.ignore();  // �������� ������

    cout << "������ ������������ ������� (������ 1 ���� ��� ������� ��� �������� ����� ������): ";
    cin >> location;
    if (location == "exit") {
        return;
    }
    cin.ignore();  // �������� ������

    animals.push_back(new ZooAnimal(kind, gender, food, kindoffood, age, weight, feeding, ill, replaceonwinter, pregnantly, splintering, location));
    cout << "������� ������ ������!" << endl;

    // �������� ��� � ����
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

cout << "��������� ������ ���������� (��� ������ ������ 'exit'):\n";

cout << "��'� ����������: ";
cin >> name;
if (cin.fail()) {
    cout << "�������: ������� ������ ���� ����������" << endl;
    cin.clear();
    return;
}
cin.ignore();

cout << "������� ����������: ";
cin >> soname;
if (cin.fail()) {
    cout << "�������: ������� ������ ������� ����������" << endl;
    cin.clear();
    return;
}
cin.ignore();

cout << "����� (������� - 1, ����� - 0): ";
cin >> gender;
if (cin.fail()) {
    cout << "�������: ������� ������ ���� ����������" << endl;
    cin.clear();
    return;
}
cin.ignore();

cout << "³� ����������: ";
cin >> age;
if (cin.fail()) {
    cout << "�������: ������� ������ ��� ����������" << endl;
    cin.clear();
    return;
}
cin.ignore();

cout << "�������� ����������: ";
getline(cin, category);

cout << "�������� ����������: ";
cin >> salary;
if (cin.fail()) {
    cout << "�������: ������� ������ �������� ����������" << endl;
    cin.clear();
    return;
}
cin.ignore();

cout << "���� ������: ";
cin >> yearsOfWork;
if (cin.fail()) {
    cout << "�������: ������� ������ ���� ������ ����������" << endl;
    cin.clear();
    return;
}
cin.ignore();

employees.push_back(new ZooEmployee(name, soname, gender, age, category, salary, yearsOfWork));

cout << "��������� ������ �������!";

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

cout << "��������� ������ ����� (��� ������ ������ 'exit'):\n";

cout << "������ ���� ���������� ����� (1 - ������������, 0 - ����������): ";
cin >> location;
if (cin.fail() || (location != 0 && location != 1)) {
    cout << "�������: ������� ������ ���� ���������� �����" << endl;
    cin.clear();
    return;
}
cin.ignore();

cout << "������ ��� �����: ";
getline(cin, type);

cout << "������ ����� �����: ";
cin >> size;
if (cin.fail()) {
    cout << "�������: ������� ������ ������ �����" << endl;
    cin.clear();
    return;
}
cin.ignore();

cout << "������ ���� �����: ";
cin >> price;
if (cin.fail()) {
    cout << "�������: ������� ������ ���� �����" << endl;
    cin.clear();
    return;
}
cin.ignore();

if (!location) {
    cout << "������ ��������� �����: ";
    cin >> maker;
} else {
    maker = "����";
}

if (location) {
    stern.push_back(new ManufacturedStern(type, size, price, maker));
} else {
    stern.push_back(new PurchasedStern(type, size, price, maker));
}

cout << "���� ������ �������!" << endl;

addSternToFile();
}

void GetOutAnimalsFromFile(){
	SetConsoleOutputCP(1251);
        vector<Animal*>& animals = allAnimals();

	string str;
	int CategoryChoise1, currentLineIndex, index, str_number = 0;	
	ifstream infile1;
    
	cout << "������� ��� ������" << endl
	     << "1. ����������� ��������� �������" << endl
	     << "2. ����������� ���" << endl;
	     
	 cout << "��� ����: ";    
	 cin >> CategoryChoise1;
	cout << "���\t        �����\t        ���\t        ��� ��\t        ³�  \t       ����\t     ʳ������ ��������\t\t��������" << endl;
	 cout << endl;
	switch(CategoryChoise1){
	
        case 1:
        	int choiseAnimal;
        	system("cls");
        	

        	cout << "������ ����� �������: " << endl;
        	
        	
        	cin >> choiseAnimal;
        	system("cls");
        	cout << "���\t        �����\t        ���\t        ��� ��\t        ³�  \t       ����\t     ʳ������ ��������\t\t��������" << endl;

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
        	
			cout << "���\t        �����\t        ���\t        ��� ��\t        ³�  \t       ����\t     ʳ������ ��������\t\t�������\t\t       ��������" << endl;

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
        animals.clear();  // ������� ������ ����� ������������� ����� � �����

        string line;
        bool skipHeader = true;  // ���� ��� �������� ������� ����� (���������)
        while (getline(infile, line)) {
            if (skipHeader) {
                skipHeader = false;
                continue;  // ���������� ���������
            }

            istringstream ss(line);
            string kind, genderStr, food, kindoffoodStr, illStr, replaceonwinterStr, pregnantlyStr, splinteringStr, location;
            int age, feeding;
            double weight;

            if (ss >> kind >> genderStr >> food >> kindoffoodStr >> age >> weight >> feeding >> illStr >> replaceonwinterStr >> pregnantlyStr >> splinteringStr >> location ) {
            	

            	
            		
                
                bool gender = (genderStr == "������") ;
                bool kindoffood = (kindoffoodStr == "�����") ;
                bool ill = (illStr == "�_���������") ;
                bool replaceonwinter = (replaceonwinterStr == "�������_�����������") ;
                bool pregnantly = (pregnantlyStr == "������") ;
                bool splintering = (splinteringStr.find("��������") != string::npos) ;

                animals.push_back(new ZooAnimal(kind, gender, food, kindoffood, age, weight, feeding, ill, replaceonwinter, pregnantly, splintering, location));
            }
			 else {
                cout << "������� ������� �����: " << line << endl;
            }
        }
        infile.close();
    }
	 else {
        cout << "�� ������� ������� ���� ��� �������" << endl;
    }
}

void loadEmployeesFromFile() {
    vector<ZooEmployee*>& employees = allEmployees();

    ifstream infile("employees1.txt");
    if (infile.is_open()) {
        employees.clear();  // ������� ������ ����� ������������� ����� � �����

        string line;
        bool skipHeader = true;  // ���� ��� �������� ������� ����� (���������)
        while (getline(infile, line)) {
            if (skipHeader) {
                skipHeader = false;
                continue;  // ���������� ���������
            }

            string name, soname, genderStr;
            int age, salary, yearsOfWork;
            string category;

            istringstream ss(line);

            if (ss >> name >> soname >> genderStr >> age >> category >> salary >> yearsOfWork) {
                bool gender = (genderStr == "�������");

                employees.push_back(new ZooEmployee(name, soname, gender, age, category, salary, yearsOfWork));
            } else {
                cout << "������� ������� �����: " << line << endl;
            }
        }
        infile.close();
    } else {
        cout << "�� ������� ������� ���� ���������� ��� �������" << endl;
    }
}

void loadSternFromFile() {
    vector<Stern*>& stern = allStern();

    ifstream infile("stern.txt");
    if (infile.is_open()) {
        stern.clear();  // ������� ������ ����� ������������� ����� � �����

        string line;
        bool skipHeader = true;  // ���� ��� �������� ������� ����� (���������)
        while (getline(infile, line)) {
            if (skipHeader) {
                skipHeader = false;
                continue;  // ���������� ���������
            }

            bool location;
            string type, locationStr;
            int size;
            int price;
            string maker;

            istringstream ss(line);

            if (ss >> maker >> locationStr >> type >> size >> price) {
                 bool location = (locationStr == "������������");

                if (location) {
                 stern.push_back(new ManufacturedStern(type, size, price, maker));
               }
			    else {
                  stern.push_back(new PurchasedStern(type, size, price, maker));
                     }        
            }
			 else {
                cout << "������� ������� �����: " << line << endl;
            }
        }
        infile.close();
    } else {
        cout << "�� ������� ������� ���� ���������� ��� �������" << endl;
    }
}

void GetOutEmploeesFromFile(){
	SetConsoleOutputCP(1251);
	vector<ZooEmployee*>& employees = allEmployees();
	//addEmploeesToFile();
	string str;
	ifstream infile;
	int CategoryChoise, currentLineIndex, index, str_number = 0;

	cout << "�����i�� �������i� ����i����i�" << endl
	     << "1. ����������� ���������i�" << endl
	     << "2. ����������� ������������i�" << endl
	     << "3. ����������� ��������������i�" << endl
	     << "4. ����������� ���i�������i�" << endl
	     << "5. ����������� ���i����i� ���i�i�����i�" << endl
	     << "6. ����������� ����������� ����������" << endl
	     << "7. ����������� ��i�" << endl;
	     
	cout << "��� ����: ";       
	cin >> CategoryChoise;
	cout << "I�`�\t                        �����\t        �i�\t������  \t\t��������(���)\t        ���� ������" << endl;
	
	switch(CategoryChoise){
	/*	case 1:
		for (int i = 0; i < employees->size(); i++) {
			if((*employees)[i].GetCategory() == "���������"){
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
			if((*employees)[i].GetCategory() == "������������"){
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
			if((*employees)[i].GetCategory() == "��������������"){
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
			if((*employees)[i].GetCategory() == "����������"){
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
			if((*employees)[i].GetCategory() == "�����������"){
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
        	cout << "������ ����� ����������: " << endl;
        	cin >> choiseEmployee;
        	
        	system("cls");
        	cout << "I�`�\t                        �����\t        �i�\t������  \t\t��������(���)\t        ���� ������" << endl;
        	
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
        	
				cout << "I�`�\t                        �����\t        �i�\t������  \t\t��������(���)\t        ���� ������" << endl;

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
    
     cout << "���\t        �����\t        ���\t        ��� ��\t        ³�  \t       ����\t     ʳ������ ��������\t\t��������" << endl;

    for(int i = 0; i < animals.size(); i++){
    	
        if(animals[i]->GetIll() == "�_���������"){
        	
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
    
    cout << "���\t        �����\t        ���\t        ��� ��\t        ³�  \t       ����\t     ʳ������ ��������\t\t��������" << endl
	     << endl;
    
    for(int i = 0; i < animals.size(); i++){
    	if(animals[i]->GetReplaceOnWinter() == "�������_�����������"){
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
	 
	 cout << "���\t        �����\t        ���\t        ��� ��\t        ³�  \t       ����\t     ʳ������ ��������\t\t��������" << endl;
	 cout << endl;
    
    for(int i = 0; i < animals.size(); i++){
    	if(animals[i]->GetPregnantly() == "������"){
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
	
	cout << "����� ������������\t���\t �����(��)" << endl;
	
	for(int i = 0; i < stern.size(); i++){
		if(stern[i]->GetLocation() == "������������"){
			cout << setw(20) << left << stern[i]->GetLocation() << "\t" 
			     << setw(10) << left << stern[i]->GetType() << "\t" 
				 << setw(15) << left << stern[i]->GetSize() << endl;
		}
	}
	
}

void BuyingStern(){
	vector<Stern*>& stern = allStern();
	
	cout << "����� ������������\t���\t\t�����(��)\tֳ��(���)\t������������" << endl;
	
	for(int i = 0; i < stern.size(); i++){
		if(stern[i]->GetLocation() == "����������"){
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
    
    cout << "������������\t\t���\t\t�����(��)\tֳ��(��)" << endl;
    
    for(int i = 0; i < stern.size(); i++){
        if(stern[i]->GetMaker() != "����"){
            cout << setw(20) << left << stern[i]->GetMaker() << "\t" 
                 << setw(15) << left << stern[i]->GetType() << "\t"
                 << setw(15) << left << stern[i]->GetSize() << "\t"
                 << setw(15) << left << stern[i]->GetPrice() << endl;
        }
    }
    
}

void GetLocationOfBirthInZoo() {
    vector<Animal*>& animals = allAnimals();

    cout << "���\t        �����\t        ���\t        ��� ��\t        ³�  \t       ����\t    ʳ������ ��������\t\t��������" << endl;

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

    cout << "���\t        �����\t        ���\t        ��� ��\t        ³�  \t       ����\t    ʳ������ ��������\t        ̳��� ����������" << endl;

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
	cout << "��� ��������" << endl
	     << "1. ������ ������ ��������" << endl
	     << "2. �������� ������ ��������" << endl
	     << "3. ������ ���������� ��������" << endl
	     << "4. �������� ���������� ��������" << endl
	     << "5. ������ ���� ��������" << endl
	     << "6. �������� ���� ��������" << endl
	     << "7. ����������� ��� ������ ��������" << endl
	     << "8. ����������� ��� �������� ��������" << endl
	     << "9. ����������� ������ � ���������" << endl
	     << "10. ����������� ������ ��������" << endl
	     << "11. ����������� ������ ��� ����������� �� ����" << endl
	     << "12. ����������� ������� ������" << endl
	     << "13. ����������� ���� ������������ ���������" << endl
	     << "14. ����������� ���������� ����" << endl
	     << "15. ����������� ������������� �������" << endl
	     << "16. ����������� ������ ���������� � ��������" << endl
	     << "17. ����������� ������ �������� � ����� ��������" << endl
	     << "18. �����" << endl;

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
    	
    	cout << "��� ����:";
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
			cout << " ������� ����, ������ �� ���";
			break;									
		}
		
		cout << endl;
	}
	
cout << "����� �� �����!";

return 0;
}

