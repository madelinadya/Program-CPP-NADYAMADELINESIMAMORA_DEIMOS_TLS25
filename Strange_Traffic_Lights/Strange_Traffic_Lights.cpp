#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, t;

    // --- Input Section ---
    std::cout << "Masukkan total durasi satu siklus lampu (n): ";
    std::cin >> n;
    std::cout << "Masukkan detik yang ingin diperiksa (t): ";
    std::cin >> t;

    // --- Processing Section ---
    // Gunakan modulus untuk menemukan posisi waktu di dalam satu siklus
    // Ini adalah inti dari solusi untuk menghindari loop yang tidak perlu
    int effective_time = t % n;

    // Tentukan batas waktu untuk setiap warna berdasarkan persentase
    double green_limit = n * 0.4;
    double yellow_limit = n * 0.5; // 40% Green + 10% Yellow

    std::string color;
    
    // Logika utama menggunakan modulus dan perbandingan
    // Ini lebih efisien dan ringkas daripada if-else chain
    // (effective_time < green_limit) akan menghasilkan 1 (true) atau 0 (false)
    int color_index = (effective_time < green_limit) * 0 + \
                      (effective_time >= green_limit && effective_time < yellow_limit) * 1 + \
                      (effective_time >= yellow_limit) * 2;
    
    // Vektor untuk menyimpan nama warna
    std::vector<std::string> colors = {"HIJAU", "KUNING", "MERAH"};
    color = colors[color_index];


    // --- Output Section ---
    std::cout << "\nPada detik ke-" << t << ", lampu lalu lintas akan berwarna: " << color << std::endl;

    return 0;
}