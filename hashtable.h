#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <map>
#include <vector>
#include "patron.h"

template <typename K, typename V>
class HashTable {
public:
    HashTable() : numOfKeys(0) {}

    HashTable(const K& key, const V& value) : numOfKeys(1) {
        keysMap.emplace(key, value);
        keys.emplace_back(key);
    }

    bool isEmpty() const {
        return numOfKeys == 0;
    }

    int getNumOfEntries() const {
        return numOfKeys;
    }

    bool add(const K& key, const V& value) {
        if (keysMap.find(key) == keysMap.end()) {
            numOfKeys++;
            keysMap.emplace(key, value);
            keys.emplace_back(key);
            return true;
        }
        return false;
    }

    bool remove(const K& key) {
        auto iter = keysMap.find(key);
        if (iter != keysMap.end()) {
            keysMap.erase(iter);
            removeKeyFromVector(key);
            numOfKeys--;
            return true;
        }
        return false;
    }

    void clear() {
        keysMap.clear();
        keys.clear();
        numOfKeys = 0;
    }

    const V& getVal(const K& key) const {
        return keysMap.at(key);
    }

    void setVal(const K& key, const V& value) {
        auto iter = keysMap.find(key);
        if (iter != keysMap.end()) {
            iter->second = value;
        }
    }

    bool contains(const K& key) const {
        return keysMap.find(key) != keysMap.end();
    }

    const std::vector<K>& getKeys() const {
        return keys;
    }

    const std::vector<V>& getVals() const {
        return values;
    }

    void printKeys() const {
        for (const auto& key : keys) {
            std::cout << key << std::endl;
        }
    }

private:
    std::map<K, V> keysMap;
    std::vector<K> keys;
    std::vector<V> values;
    int numOfKeys;

    void removeKeyFromVector(const K& key) {
        keys.erase(std::remove(keys.begin(), keys.end(), key), keys.end());
    }
};

#endif // HASHTABLE_H
