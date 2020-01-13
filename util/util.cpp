/**
    Dans l'urgence de la livraison d'un code opérationnel
    ce fichier source n'a pas été proprement restructuré
    Ceci n'est pas un code "modèle" !
**/

#include "util.h"

#include <random>
#include <ctime>
#include <iostream>
#include <cstdio>

namespace util {

/// Vide tampon clavier
void videCin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/// Cette fonction retourne un entier aléatoire dans [min...max]
int alea(int min, int max) {
    // Sur un système Linux il est possible(préférable ?) de faire
    //static std::mt19937 randGen( std::random_device{}() );
    static std::mt19937 randGen(time(nullptr));
    return std::uniform_int_distribution<>(min, max)(randGen);
}

/// Cette fonction retourne un réel aléatoire dans [min...max[
double alea(double min, double max) {
    // Sur un système Linux il est possible(préférable ?) de faire
    //static std::mt19937 randGen( std::random_device{}() );
    static std::mt19937 randGen(time(nullptr));
    return std::uniform_real_distribution<>(min, max)(randGen);
}

/// Cette fonction retourne un entier aléatoire dans [min...max]
int alea(int min, int max, std::mt19937 &randGen) {
    return std::uniform_int_distribution<>(min, max)(randGen);
}

/// Cette fonction retourne un réel aléatoire dans [min...max[
double alea(double min, double max, std::mt19937 &randGen) {
    return std::uniform_real_distribution<>(min, max)(randGen);
}

}


/**

Permettre de logger en console les "saisies simulées"
venant d'un fichier de test

Modifié (mutilé !) par rapport au code original :
http://www.voidcn.com/article/p-vjnlygmc-gy.html

PARTIE INTERFACE (pas dans le .h pour ne pas polluer)

**/

// ORIGINAL :
// Copyright 2007 Edd Dawson.
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file BOOST_LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt

#include <streambuf>
#include <vector>
#include <cstdlib>

#include <cstdio>

/// Couleur Windows par défaut des saisies simulées
/// 0x0a -> Vert sur fond noir
/// couleur : colorisation (WINDOWS seulement https://ss64.com/nt/color.html
///                         préfixer par 0x, exemple 0x1a vert sur fond bleu)
short autoCinWinCouleur = 0x0a;

struct FILE_buffer_style {
  size_t tempo_;
  short color_;
};

class FILE_buffer : public std::streambuf {
 public:
  explicit FILE_buffer(std::string file_name, FILE_buffer_style bs,
                       std::size_t buff_sz = 256, std::size_t put_back = 8);
  FILE *getFptr() { return fptr_; }

 private:
  // overrides base class underflow()
  int_type underflow();

  // copy ctor and assignment not implemented;
  // copying not allowed
  FILE_buffer(const FILE_buffer &);
  FILE_buffer &operator=(const FILE_buffer &);

 private:
  const std::size_t put_back_;
  std::vector<char> buffer_;
  FILE_buffer_style bufstyle_;
  FILE *fptr_;
};


/**

PARTIE IMPLEMENTATION

**/

// ORIGINAL :
// Copyright 2007 Edd Dawson.
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file BOOST_LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt

#include <algorithm>
#include <cstring>
#include <iostream>
#include "mingw.thread.h"

using std::size_t;

FILE_buffer::FILE_buffer(std::string file_name, FILE_buffer_style bs,
                         size_t buff_sz, size_t put_back) :
    put_back_(std::max(put_back, size_t(1))),
    buffer_(std::max(buff_sz, put_back_) + put_back_),
    bufstyle_(bs) {
    fptr_ = std::fopen(file_name.c_str(), "r");
    if (!fptr_)
        throw std::runtime_error("Could not open autoCin file " + file_name);

    // Set the back, current and end buffer pointers to be equal.
    // This will force an underflow() on the first read and hence
    // fill the buffer.
    char *end = &buffer_.front() + buffer_.size();
    setg(end, end, end);
}

#ifdef _WIN32
void windowsChangeCouleur(short couleur);
short windowsRecupCouleur();
#endif // _WIN32

/// Adapté depuis https://stackoverflow.com/a/10151286
static std::streambuf *previous_cinbuf = nullptr;
static FILE_buffer *custom_sbuf;

std::streambuf::int_type FILE_buffer::underflow() {
    if (gptr() < egptr()) // buffer not exhausted
        return traits_type::to_int_type(*gptr());

    char *base = &buffer_.front();
    char *start = base;

    if (eback() == base) {
        // Make arrangements for putback characters
        std::memmove(base, egptr() - put_back_, put_back_);
        start += put_back_;
    }

    // start is now the start of the buffer, proper.
    // Read from fptr_ in to the provided buffer
    ///size_t n = std::fread(start, 1, buffer_.size() - (start - base), fptr_);
    size_t n = std::fread(start, 1, 1, fptr_);
    if (n == 0)
        return traits_type::eof();

#ifdef _WIN32

    short prevcol = windowsRecupCouleur();
    if (bufstyle_.color_)
        windowsChangeCouleur(bufstyle_.color_);
    else
        windowsChangeCouleur(autoCinWinCouleur);

#endif // _WIN32
    /// Echo à la console des caractères lus
    for (size_t i = 0; i < n; ++i)
        std::cout << start[i];

#ifdef _WIN32
    windowsChangeCouleur(prevcol);
#endif // _WIN32

    if (bufstyle_.tempo_)
        std::this_thread::sleep_for(std::chrono::milliseconds(bufstyle_.tempo_));

    // Set buffer pointers
    setg(base, start, start + n);

    return traits_type::to_int_type(*gptr());
}

#include "util.h"

void util::startAutoCin(std::string fileName, size_t temporisation, short couleur) {
    /// Erreur on ouvre simultanément 2 flots autoCin !
    if (previous_cinbuf)
        throw std::runtime_error("Ouverture d'un nouveau flot autoCin sans fermeture precedent");

    previous_cinbuf = std::cin.rdbuf(); //save old buf
    custom_sbuf = new FILE_buffer(fileName, {temporisation, couleur}, 1);
    std::cin.rdbuf(custom_sbuf);
}

void util::stopAutoCin() {
    if (!previous_cinbuf)
        return;

    std::cin.rdbuf(previous_cinbuf);   //reset to standard input again

    std::fclose(custom_sbuf->getFptr());

    delete custom_sbuf;
    custom_sbuf = nullptr;
    previous_cinbuf = nullptr;
}


/// Le code qui suit est spécifique aux plateformes Windows
/// et ne concerne ni macOS ni les Linux
#ifdef _WIN32

#include <windows.h>

void util::accentsPourWindows() {
    // 28591 correspond au Code Page ISO 8859-1 Latin 1; Western European (ISO)
    // https://docs.microsoft.com/en-us/windows/desktop/intl/code-page-identifiers
    SetConsoleOutputCP(28591);
}

void windowsChangeCouleur(short couleur) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, couleur);
}

/// https://stackoverflow.com/a/26452451
short windowsRecupCouleur() {
    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))
        return 7;
    return info.wAttributes;
}

#endif // _WIN32
