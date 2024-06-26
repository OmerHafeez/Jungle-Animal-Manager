#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string name;
    string species;
    float age;
    bool availability;
    static int totalAnimals;

public:
    Animal() : age(0), availability(false) {
        totalAnimals++;
    }

    Animal(const string& name, const string& species, float age, bool availability)
        : name(name), species(species), age(age), availability(availability) {
        totalAnimals++;
    }

    ~Animal() {
        totalAnimals--;
        cout << "Destroying " << name << ", the " << species << endl;
    }

    string getName() const {
        return name;
    }

    void setName(const string& name) {
        this->name = name;
    }

    string getSpecies() const {
        return species;
    }

    void setSpecies(const string& species) {
        this->species = species;
    }

    float getAge() const {
        return age;
    }

    void setAge(float age) {
        this->age = age;
    }

    bool checkAvailability() const {
        return availability;
    }

    void setAvailability(bool availability) {
        this->availability = availability;
    }

    void inputAttributes() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Species: ";
        cin >> species;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Availability (1 for available, 0 for not available): ";
        cin >> availability;
    }

    void display() const {
        cout << "Animal's name " << name << endl;
        cout << "Animal's species " << species << endl;
        cout << "Animal's age " << age << endl;
        cout << "Animal's availability " << availability << endl;
    }

    static int getNumberOfAnimals() {
        return totalAnimals;
    }
};

int Animal::totalAnimals = 0;

class Jungle {
private:
    static const int maxSize = 80;
    Animal* ptr[maxSize];
    int currentSize;

public:
    Jungle() : currentSize(0) {
        for (int i = 0; i < maxSize; ++i) {
            ptr[i] = nullptr;
        }
    }

    ~Jungle() {
        for (int i = 0; i < currentSize; ++i) {
            delete ptr[i];
        }
    }

    void addAnimal(const string& name, const string& species, float age, bool availability) {
        if (currentSize < maxSize) {
            ptr[currentSize] = new Animal(name, species, age, availability);
            cout << "Animal added: " << name << endl;
            currentSize++;
        }
        else {
            cout << "Jungle is full! Cannot add more animals." << endl;
        }
    }

    void removeAnimal(const string& nameToRemove) {
        for (int i = 0; i < currentSize; ++i) {
            if (ptr[i] && ptr[i]->getName() == nameToRemove) {
                delete ptr[i];
                for (int j = i; j < currentSize - 1; ++j) {
                    ptr[j] = ptr[j + 1];
                }
                cout << "Animal removed: " << nameToRemove << endl;
                currentSize--;
                return;
            }
        }
        cout << "Animal not found: " << nameToRemove << endl;
    }

    const Animal* searchAnimalByName(const string& nameToFind) const {
        for (int i = 0; i < currentSize; ++i) {
            if (ptr[i] && ptr[i]->getName() == nameToFind) {
                return ptr[i];
            }
        }
        return nullptr;
    }

    const Animal* searchAnimalBySpecies(const string& speciesToFind) const {
        for (int i = 0; i < currentSize; ++i) {
            if (ptr[i] && ptr[i]->getSpecies() == speciesToFind) {
                return ptr[i];
            }
        }
        return nullptr;
    }

    const Animal* searchAnimalByAge(float ageToFind) const {
        for (int i = 0; i < currentSize; ++i) {
            if (ptr[i] && ptr[i]->getAge() == ageToFind) {
                return ptr[i];
            }
        }
        return nullptr;
    }

    void displayJungle() const {
        for (int i = 0; i < currentSize; ++i) {
            if (ptr[i]) {
                ptr[i]->display();
                cout << "-----------------------------" << endl;
            }
        }
    }
};

int main() {
    Jungle jingle;

    int choice = -1;
    while (choice != 0) {
        cout << "----------------------------------------" << endl;
        cout << "  Jungle and Animal Management System" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Welcome to Beastie Jungle" << endl;
        cout << "Below are the options for your convenience. Happy Jungling!!!" << endl;
        cout << "1. Add new animals to Jungle" << endl;
        cout << "2. Remove animals from Jungle" << endl;
        cout << "3. Search for animals by name" << endl;
        cout << "4. Search for animals by age" << endl;
        cout << "5. Search for animals by species" << endl;
        cout << "6. Display all available animals in the jungle " << endl;
        cout << "7. Check the total number of available animals in the Jungle" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;

        if (choice == 1) {
            string name, species;
            float age;
            bool availability;
            cout << "Enter Name of Animal: ";
            cin >> name;
            cout << "Enter Species of Animal: ";
            cin >> species;
            cout << "Enter Age of Animal: ";
            cin >> age;
            cout << "Enter Availability of Animal (1 for available, 0 for not available): ";
            cin >> availability;
            jingle.addAnimal(name, species, age, availability);
        }
        else if (choice == 2) {
            string name;
            cout << "Enter the name of the animal you want to remove: ";
            cin >> name;
            jingle.removeAnimal(name);
        }
        else if (choice == 3) {
            string name;
            cout << "Enter the name of the animal you want to search for: ";
            cin >> name;
            const Animal* foundAnimal = jingle.searchAnimalByName(name);
            if (foundAnimal) {
                foundAnimal->display();
            }
            else {
                cout << "Animal not found: " << name << endl;
            }
        }
        else if (choice == 4) {
            float age;
            cout << "Enter the age: ";
            cin >> age;
            const Animal* foundAnimal = jingle.searchAnimalByAge(age);
            if (foundAnimal) {
                foundAnimal->display();
            }
            else {
                cout << "Animal not found for age: " << age << endl;
            }
        }
        else if (choice == 5) {
            string species;
            cout << "Enter the species: ";
            cin >> species;
            const Animal* foundAnimal = jingle.searchAnimalBySpecies(species);
            if (foundAnimal) {
                foundAnimal->display();
            }
            else {
                cout << "Animal not found for species: " << species << endl;
            }
        }
        else if (choice == 6) {
            jingle.displayJungle();
        }
        else if (choice == 7) {
            cout << "Total number of available animals in the Jungle: " << Animal::getNumberOfAnimals() << endl;
        }
        else if (choice == 0) {
            cout << "Exiting Interface" << endl;
            break;
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
