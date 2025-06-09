#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <ctime>
#include <chrono>

using namespace std;

string encrypt(const string& message, const unordered_map<char, char>& cipher) {
    string encrypted = "";
    for (char c : message) {
        encrypted += cipher.at(c);
    }
    return encrypted;
}

string decrypt(const string& encrypted, const unordered_map<char, char>& cipher) {
    // Build reverse map
    unordered_map<char, char> reverse;
    for (auto& pair : cipher) {
        reverse[pair.second] = pair.first;
    }

    string decrypted = "";
    for (char c : encrypted) {
        decrypted += reverse.at(c);
    }
    return decrypted;
}

unordered_map<char, char> generateCipher(const string& alphabet) {
    vector<char> shuffled(alphabet.begin(), alphabet.end());
    random_shuffle(shuffled.begin(), shuffled.end());
    
    unordered_map<char, char> cipher;
    for (int i = 0; i < alphabet.size(); ++i) {
        cipher[alphabet[i]] = shuffled[i];
    }
    return cipher;
}

int main() {
    string original = "HELLO";
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Step 1: Generate true cipher and encrypt the message
    unordered_map<char, char> trueCipher = generateCipher(alphabet);
    string encrypted = encrypt(original, trueCipher);

    cout << "Encrypted: " << encrypted << endl;

    // Step 2: Brute-force
    int tries = 0;
    string found;
    auto start = chrono::high_resolution_clock::now();

    // Pre-generate 999 ciphers + the correct one
vector<unordered_map<char, char>> ciphers;
for (int i = 0; i < 999; ++i) {
    ciphers.push_back(generateCipher(alphabet));
}
int correctIndex = rand() % 1000;
ciphers.insert(ciphers.begin() + correctIndex, trueCipher);

// Brute-force
for (const auto& guess : ciphers) {
    string attempt = decrypt(encrypted, guess);
    tries++;
    if (attempt == original) {
        found = attempt;
        break;
    }
}

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "Decrypted: " << found << endl;
    cout << "Tries: " << tries << endl;
    cout << "Time taken: " << elapsed.count() << " seconds" << endl;

    return 0;
}
