#include <iostream>
#include <string>
#include <vector>

// --- User-defined function to reverse a string ---
// Wajib dibuat sendiri, tidak boleh pakai std::reverse
std::string reverseString(std::string str) {
    std::string reversed_str = "";
    for (int i = str.length() - 1; i >= 0; i--) {
        reversed_str += str[i];
    }
    return reversed_str;
}

// --- Fungsi 1: Enkripsi (Membuat Sandi) ---
void encrypt() {
    std::string original_word;
    std::cout << "\n[ENKRIPSI] Masukkan kata asli: ";
    std::cin >> original_word;

    // 1. Balik kata asli
    std::string reversed_word = reverseString(original_word);
    
    // 2. Simpan nilai ASCII dari karakter kedua terakhir dari kata ASLI
    int ascii_value = 0;
    if (original_word.length() >= 2) {
        ascii_value = (int)original_word[original_word.length() - 2];
    } else if (original_word.length() == 1) {
        // Jika kata hanya 1 huruf, gunakan ASCII huruf itu sendiri
        ascii_value = (int)original_word[0];
    }

    // 3. Geser setiap karakter (huruf berikutnya dalam ASCII)
    std::string shifted_word = "";
    for (char c : reversed_word) {
        shifted_word += (c + 1);
    }

    // 4. Sisipkan nilai ASCII di antara karakter pertama dan kedua
    std::string final_password = "";
    if (shifted_word.length() >= 1) {
        final_password += shifted_word[0];
        final_password += std::to_string(ascii_value);
        if (shifted_word.length() > 1) {
            final_password += shifted_word.substr(1);
        }
    } else {
         final_password += std::to_string(ascii_value);
    }
    
    std::cout << "-> Kata Sandi yang Dihasilkan: " << final_password << std::endl;
}

// --- Fungsi 2: Dekripsi (Mendapatkan Sebagian Kata Asli) ---
void decrypt() {
    std::string password;
    std::cout << "\n[DEKRIPSI] Masukkan kata sandi: ";
    std::cin >> password;

    // 1. Ekstrak nilai ASCII dari sandi
    std::string extracted_ascii_str = "";
    std::string shifted_word_with_first_char = "";
    shifted_word_with_first_char += password[0];

    int i = 1;
    while (i < password.length() && isdigit(password[i])) {
        extracted_ascii_str += password[i];
        i++;
    }
    
    if (i < password.length()) {
        shifted_word_with_first_char += password.substr(i);
    }

    // 2. Kembalikan karakter yang digeser (huruf sebelumnya dalam ASCII)
    std::string reversed_word = "";
    for (char c : shifted_word_with_first_char) {
        reversed_word += (c - 1);
    }

    // 3. Balikkan kembali string untuk mendapatkan kata asli
    std::string original_word = reverseString(reversed_word);

    // 4. Konversi ASCII yang diekstrak menjadi karakter
    char original_char_from_ascii = '?';
    if (!extracted_ascii_str.empty()) {
        int ascii_value = std::stoi(extracted_ascii_str);
        original_char_from_ascii = (char)ascii_value;
    }
    
    std::cout << "-> Sebagian Kata Asli yang Ditemukan: " << original_word << std::endl;
    std::cout << "-> Karakter kedua terakhir dari kata asli adalah: '" << original_char_from_ascii << "'" << std::endl;
}

// --- Main Program Logic ---
int main() {
    int choice;
    do {
        std::cout << "\n--- Mesin Sandi Detektif Timothy ---" << std::endl;
        std::cout << "1. Buat Kata Sandi (Enkripsi)" << std::endl;
        std::cout << "2. Temukan Sebagian Kata Asli (Dekripsi)" << std::endl;
        std::cout << "3. Keluar" << std::endl;
        std::cout << "Pilih opsi: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                encrypt();
                break;
            case 2:
                decrypt();
                break;
            case 3:
                std::cout << "Menutup program." << std::endl;
                break;
            default:
                std::cout << "Pilihan tidak valid. Coba lagi." << std::endl;
        }
    } while (choice != 3);
    
    return 0;
}