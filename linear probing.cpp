#include <iostream>
#include <cstring> // For memset

#define TABLE_SIZE 10 // Define the size of the hash table

struct HashNode {
    int key;
    bool isOccupied;
};

class HashTable {
private:
    HashNode table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE; // Simple modulo hash function
    }

public:
    HashTable() {
        // Initialize the table
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i].isOccupied = false;
        }
    }

    bool insert(int key) {
        int index = hashFunction(key);
        int originalIndex = index; // To detect cycles

        while (table[index].isOccupied) {
            index = (index + 1) % TABLE_SIZE; // Linear probing

            if (index == originalIndex) {
                // Table is full
                std::cout << "Hash table is full. Cannot insert key: " << key << "\n";
                return false;
            }
        }

        // Insert the key
        table[index].key = key;
        table[index].isOccupied = true;
        return true;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i].isOccupied) {
                std::cout << "Index " << i << ": " << table[i].key << "\n";
            } else {
                std::cout << "Index " << i << ": Empty\n";
            }
        }
    }
};

int main() {
    HashTable hashTable;

    int keys[] = {15, 25, 35, 45, 55};
    int size = sizeof(keys) / sizeof(keys[0]);

    // Insert keys into the hash table
    for (int i = 0; i < size; ++i) {
        if (hashTable.insert(keys[i])) {
            std::cout << "Inserted key: " << keys[i] << "\n";
        } else {
            std::cout << "Failed to insert key: " << keys[i] << "\n";
        }
    }

    // Display the hash table
    std::cout << "\nHash Table:\n";
    hashTable.display();

    return 0;
}
