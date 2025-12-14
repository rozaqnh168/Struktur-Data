# Final Project Struktur Data Ball Collision Simulation (C++ with SFML)

Proyek ini merupakan final project dari mata kuliah **Struktur Data dan Analisis Algoritma** yang dibimbing oleh `Arta Kusuma Hernanda, S.T., M.T`. Tugas ini bertujuan untuk membuat **collision simulation** menggunakan bahasa pemrograman **C++** dan library **SFML**.

> **Nama**: Rozaq Nafi'ul Hafidz  
> **Departemen**: Teknik Komputer  
> **NRP**: 5024241072

## Daftar Isi

- [Proyek Akhir Mata Kuliah Struktur Data dan Analisis Algoritma](#proyek-akhir-mata-kuliah-struktur-data-dan-analisis-algoritma)
  - [Daftar Isi](#daftar-isi)
  - [Gambaran Umum](#gambaran-umum)
  - [Struktur Proyek](#struktur-proyek)
  - [Algoritma yang Digunakan](#algoritma-yang-digunakan)
  - [Dependensi](#dependensi)
  - [Cara Build dan Menjalankan Program](#cara-build-dan-menjalankan-program)
  - [Progress Pengerjaan](#progress-pengerjaan)
Collision Simulation with Brute Force and Quadtree
Daftar Isi
Pendahuluan
Proyek Struktur
Algoritma
Dependencies
Build dan Running Projectnya
Progress (Logbook)
## Pendahuluan
Proyek ini adalah simulasi tabrakan bola 2D menggunakan library SFML (Simple and Fast Multimedia Library). Simulasi ini mendemonstrasikan dua algoritma deteksi tabrakan: Brute Force dan Quadtree. Pengguna dapat mengalihkan antara kedua algoritma dengan menekan tombol Space, dan melihat perbedaan performa dalam hal FPS saat jumlah bola ditingkatkan.

## Proyek Struktur
Struktur proyek terdiri dari beberapa file C++ sebagai berikut:

## Project Structure

```
final/
├── obj/                      # File object hasil kompilasi
├── src/                      # Source code utama
│ ├── main.cpp                # Program utama
│ ├── ball.cpp                # Implementasi kelas Ball
│ ├── ball.hpp                # Header kelas Ball
│ ├── bruteforce.cpp          # Algoritma brute force
│ ├── bruteforce.hpp          # Header brute force
│ ├── quadtree.cpp            # Implementasi QuadTree
│ └── quadtree.hpp            # Header QuadTree
├── ARIAL.TTF                 # Font untuk tampilan teks
├── Ball.d                    # File dependensi Ball
├── Bruteforce.d              # File dependensi BruteForce
├── Quadtree.d                # File dependensi QuadTree
├── main.d                    # File dependensi main
├── Makefile                  # Makefile untuk build program
├── myapp                     # File executable hasil build
└── README.md                 # Dokumentasi proyek
```
Ball.cpp: Implementasi kelas Ball, yang mewakili bola dengan properti seperti posisi, kecepatan, radius, dan warna. Termasuk metode untuk update, draw, dan deteksi tabrakan dengan batas.
Ball.hpp: Header file untuk kelas Ball (konten biner, tidak ditampilkan di sini).
Bruteforce.cpp: Implementasi algoritma Brute Force untuk deteksi tabrakan antar bola. Termasuk fungsi untuk memeriksa tabrakan dan menyelesaikannya menggunakan fisika momentum.
Bruteforce.hpp: Header file untuk namespace Physics (konten biner, tidak ditampilkan di sini).
Quadtree.cpp: Implementasi struktur data Quadtree untuk optimasi deteksi tabrakan. Termasuk metode untuk insert, retrieve, dan draw quadtree untuk debugging.
Quadtree.hpp: Header file untuk kelas Quadtree (konten biner, tidak ditampilkan di sini).
main.cpp: File utama yang menjalankan simulasi. Mengatur window SFML, membuat bola, menangani input, dan menggambar elemen UI seperti FPS dan mode algoritma.


## Algoritma
Proyek ini mengimplementasikan dua algoritma deteksi tabrakan:

### Brute Force
Algoritma sederhana yang memeriksa setiap pasangan bola untuk tabrakan. Kompleksitas waktu O(n²), cocok untuk jumlah bola kecil (misalnya <100). Ketika tabrakan terdeteksi, posisi dikoreksi dan kecepatan dihitung ulang menggunakan rumus momentum 1D.
### Quadtree
Struktur data spasial yang membagi ruang menjadi kuadran untuk mengurangi jumlah pemeriksaan tabrakan. Kompleksitas waktu rata-rata O(n log n), lebih efisien untuk jumlah bola besar. Bola dimasukkan ke quadtree, lalu kandidat tabrakan diambil untuk pemeriksaan lebih lanjut.
Pengguna dapat beralih antara algoritma dengan menekan Space, dan melihat visualisasi quadtree saat mode aktif.

## Dependencies
SFML: Library multimedia untuk rendering grafis dan handling input.
C++ Compiler: Compiler yang mendukung C++11 atau lebih baru, seperti g++ (GCC) atau clang.
Font: File "arial.ttf" diperlukan untuk teks UI.

## Build dan Running Projectnya
### Build
Pastikan SFML terinstall di sistem Anda. 
Proyek ini menggunakan Makefile untuk proses kompilasi.
Langkah Build
cd final
make
Makefile akan mengkompilasi file di src/ dan menghasilkan executable "myapp" di root folder.
Jika ada error, pastikan semua header file (.hpp) tersedia dan path SFML benar. Gunakan make clean untuk membersihkan file object sebelum rebuild.
Running
Jalankan executable: ./myapp [jumlah_bola]
Contoh: ./myapp 100 untuk 100 bola (default 50).
Window simulasi akan muncul. Tekan Space untuk beralih antara Brute Force dan Quadtree.
Tutup window untuk keluar. FPS dan jumlah bola ditampilkan di layar.

Progress (Logbook)
Tanggal 1 (Inisialisasi): Membuat struktur proyek dasar, implementasi kelas Ball dengan update dan draw.
Tanggal 2 (Brute Force): Menambahkan algoritma Brute Force untuk deteksi tabrakan, termasuk resolusi fisika.
Tanggal 3 (Quadtree): Implementasi Quadtree untuk optimasi, dengan insert, retrieve, dan draw untuk debugging.
Tanggal 4 (Integrasi): Mengintegrasikan kedua algoritma di main.cpp, menambahkan toggle dengan Space dan UI untuk FPS/mode.
Tanggal 5 (Testing): Testing dengan berbagai jumlah bola, memperbaiki bug pada boundary collision dan overlap. Proyek siap untuk distribusi.



