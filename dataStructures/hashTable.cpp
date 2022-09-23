#include <iostream>
#include <functional>
#include <string>
#include <list>
#include <utility>

class HashTable
{
private:
    static const int hashGroups = 3001;
    std::list<std::pair<std::string, int>> table[hashGroups]; // List 1, index 0, List 2, index 1
public:
    bool isEmpty() const;
    void insertItem(std::string key, int value);
    void removeItem(std::string key);
    int searchItem(std::string key);
    void printTable();
};

// Si el tamanio de cada lista es igual o mayor a cero
// con eso se sabe si esta vacio o no
bool HashTable::isEmpty() const
{
    int sum{};
    for (int i{}; i < hashGroups; i++)
    {
        sum += table[1].size();
    }
    if (!sum)
    {
        return true;
    }
    else
        return false;
}

/*Usando la Hash code function de la libreria se obtiene el hasheo del string
pero hay que tener cuidado con el hash code porque puede que no quepa en 
nuestro array de linked list
Se recorre todo la lista para ver si el valor la llave aun no exite para agregarla
al final, sino solo cambiamos el valor
*/
void HashTable::insertItem(std::string key, int value)
{
    std::hash<std::string> hashF;
    unsigned int hashCode = hashF(key);
    auto &cell = table[hashCode % hashGroups];
    auto bIter = std::begin(cell);
    bool keyExists = false;
    for (; bIter != std::end(cell); bIter++)
    {
        if (bIter->first == key)
        {
            keyExists = true;
            bIter->second = value;
            std::cout << "Adevertencia! Valor cambiado" << std::endl;
            break;
        }
    }

    if (!keyExists)
    {
        cell.emplace_back(key, value);
    }
    return;
}

/* Se recorre toda la lista buscando el key y ya que se encuentra solo
lo quitamos de la lista, sino es encontrado lanzamos un mensaje
*/
void HashTable::removeItem(std::string key)
{
    std::hash<std::string> hashF;
    unsigned int hashCode = hashF(key);
    auto &cell = table[hashCode % hashGroups];
    auto bIter = std::begin(cell);
    bool keyExists = false;
    for (; bIter != std::end(cell); bIter++)
    {
        if (bIter->first == key)
        {
            keyExists = true;
            bIter = cell.erase(bIter);
            std::cout << "Info! Par borrado" << std::endl;
            break;
        }
    }

    if (!keyExists)
    {
        std::cout << "Item no encontrado" << std::endl;
    }
    return;
}
/* Se recorre toda la lista buscando el key y ya que se encuentra solo
recuperamos el value de la key, sino es encontrado lanzamos un mensaje
*/
int HashTable::searchItem(std::string key)
{
    std::hash<std::string> hashF;
    unsigned int hashCode = hashF(key);
    auto &cell = table[hashCode % hashGroups];
    auto bIter = std::begin(cell);
    bool keyExists = false;
    for (; bIter != std::end(cell); bIter++)
    {
        if (bIter->first == key)
        {
            keyExists = true;
            std::cout << "Valor encontado" << std::endl;
            return bIter->second;
            break;
        }
    }

    if (!keyExists)
    {
        std::cout << "Valor no encontado" << std::endl;
    }
    return -1;
}

void HashTable::printTable()
{
    for (int i{}; i < hashGroups; i++)
    {
        if (table[i].size() == 0)
            continue;

        auto bIter = table[i].begin();
        for (; bIter != table[i].end(); bIter++)
        {
            std::cout << "key: " << bIter->first << " Value: " << bIter->second << std::endl;
        }
    }
    return;
}

int main()
{
    HashTable HT;

    if (HT.isEmpty())
    {
        std::cout << "Bien echo bro" << std::endl;
    }
    else
    {
        std::cout << "Valio cheto bro" << std::endl;
    }

    HT.insertItem("Sam", 22);
    HT.insertItem("Sam", 23);
    HT.insertItem("Andy", 23);
    HT.insertItem("Wong", 22);
    HT.insertItem("Emma", 22);
    HT.insertItem("Coca", 22);
    HT.insertItem("Lusito", 21);

    HT.printTable();

    HT.removeItem("Andy");

    HT.printTable();
    HT.searchItem("Andy");
    return 0;
}