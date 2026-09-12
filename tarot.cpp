#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

// Alle 78 Tarotkarten (Index 1-78)
// 1-22: Grosse Arkana
// 23-78: Kleine Arkana (Staebe, Kelche, Schwerter, Muenzen je 14 Karten)
const std::array<std::string, 79> kartenNamen = {
    "", // Index 0 wird nicht verwendet

    // Grosse Arkana (1-22)
    "Der Narr", "Der Magier", "Die Hohepriesterin", "Die Herrscherin",
    "Der Herrscher", "Der Hierophant", "Die Liebenden", "Der Wagen",
    "Die Kraft", "Der Eremit", "Das Rad des Schicksals", "Die Gerechtigkeit",
    "Der Gehaengte", "Der Tod", "Die Maessigkeit", "Der Teufel",
    "Der Turm", "Der Stern", "Der Mond", "Die Sonne",
    "Das Gericht", "Die Welt",

    // Staebe (23-36)
    "As der Staebe", "Zwei der Staebe", "Drei der Staebe", "Vier der Staebe",
    "Fuenf der Staebe", "Sechs der Staebe", "Sieben der Staebe", "Acht der Staebe",
    "Neun der Staebe", "Zehn der Staebe", "Bube der Staebe", "Ritter der Staebe",
    "Koenigin der Staebe", "Koenig der Staebe",

    // Kelche (37-50)
    "As der Kelche", "Zwei der Kelche", "Drei der Kelche", "Vier der Kelche",
    "Fuenf der Kelche", "Sechs der Kelche", "Sieben der Kelche", "Acht der Kelche",
    "Neun der Kelche", "Zehn der Kelche", "Bube der Kelche", "Ritter der Kelche",
    "Koenigin der Kelche", "Koenig der Kelche",

    // Schwerter (51-64)
    "As der Schwerter", "Zwei der Schwerter", "Drei der Schwerter", "Vier der Schwerter",
    "Fuenf der Schwerter", "Sechs der Schwerter", "Sieben der Schwerter", "Acht der Schwerter",
    "Neun der Schwerter", "Zehn der Schwerter", "Bube der Schwerter", "Ritter der Schwerter",
    "Koenigin der Schwerter", "Koenig der Schwerter",

    // Muenzen (65-78)
    "As der Muenzen", "Zwei der Muenzen", "Drei der Muenzen", "Vier der Muenzen",
    "Fuenf der Muenzen", "Sechs der Muenzen", "Sieben der Muenzen", "Acht der Muenzen",
    "Neun der Muenzen", "Zehn der Muenzen", "Bube der Muenzen", "Ritter der Muenzen",
    "Koenigin der Muenzen", "Koenig der Muenzen"
};

// Gibt den Namen einer Karte anhand ihrer Nummer (1-78) zurueck
std::string kartenName(int nummer) {
    if (nummer < 1 || nummer > 78) {
        return "Ungueltige Karte";
    }
    return kartenNamen[nummer];
}

// Gibt den Zustand als Text zurueck: 'a' = Richtig rum, 'b' = Auf dem Kopf
std::string zustandText(char zustand) {
    return (zustand == 'a') ? "Richtig rum" : "Auf dem Kopf";
}

int main() {
    // Zufallsgenerator initialisieren
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> zustandVerteilung(0, 1); // 0 = a, 1 = b

    // Alle 78 Kartennummern (1-78) in einen Topf legen und mischen,
    // damit jede Karte pro Zug nur einmal vorkommen kann
    std::vector<int> alleKarten(78);
    std::iota(alleKarten.begin(), alleKarten.end(), 1); // fuellt mit 1..78
    std::shuffle(alleKarten.begin(), alleKarten.end(), gen);

    // Die ersten drei gemischten Karten ziehen (ohne Zuruecklegen)
    int kartenNummer1 = alleKarten[0];
    int kartenNummer2 = alleKarten[1];
    int kartenNummer3 = alleKarten[2];

    // Fuer jede gezogene Karte separat den Zustand auswuerfeln
    char zustand1 = (zustandVerteilung(gen) == 0) ? 'a' : 'b';
    char zustand2 = (zustandVerteilung(gen) == 0) ? 'a' : 'b';
    char zustand3 = (zustandVerteilung(gen) == 0) ? 'a' : 'b';

    // Kartennamen anhand der Nummern nachschlagen
    std::string karte1 = kartenName(kartenNummer1);
    std::string karte2 = kartenName(kartenNummer2);
    std::string karte3 = kartenName(kartenNummer3);

    // Ausgabe im gewuenschten Format
    std::cout << "(\"" << karte1 << "\" " << zustandText(zustand1) << ") "
              << "(\"" << karte2 << "\" " << zustandText(zustand2) << ") "
              << "(\"" << karte3 << "\" " << zustandText(zustand3) << ")"
              << std::endl;

    return 0;
}
