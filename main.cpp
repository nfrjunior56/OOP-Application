#include <iostream>
#include <string>
//Deklaracja dynamicznej tablicy
#include <vector>

using namespace std;

//Definowanie klasy Workout

class WorkoutPlan{
    //Deklaracja klasy Workout

public:     //Dostęp spoza klasy

        WorkoutPlan(const string & name) : name_(name) {}     //Referencja do obiektu string (imię) za pomocą listy name_(name)
            //Zapisanie imienia wewnątrz obiektu

        void Run(){    //Planowanie treningu (powitanie+wybór partii)
            cout << "Cześć, " + name_ + "! " + "Jakie partie mięśniowe chcesz dzisiaj ćwiczyć?" + "\n" + "\n";

            ChooseMuscleGroups();    //Wybór partii mięśniowych

            ShowWorkoutPlan();      //Wyświetlanie planu

            cout << "Miłego treningu, " + name_ + "!" + "\n";    //Wiadomość dla użytkownika
        }

private:    //Modyfikator dostępu (dostęp do stałych tylko z poziomu tej klasy)
        string name_;   //Imię użytkownika

        vector<string> PartOfMuscle_ = {"klata", "plecy", "nogi", "biceps", "triceps"};   //Lista dostępnych partii mięśniowych

        vector<string> SelectedMuscleParts_;    //Wybrane partie mięśniowe

            void ChooseMuscleGroups() {  //Deklaracja funkcji

                    int numParts = 2;   //Ilość partii do wyboru

                    for (int i = 0; i < numParts; ++i) {    //Pętla for (ze względu na działanie aplikacji zrezygnowałem z dalszego używania "\n")

                        cout << name_ << ", wybierz numer partii " << i + 1 << ", która Cię interesuje" << endl; //Wybór partii

                    for (int j = 0; j < PartOfMuscle_.size(); ++j) {

                        cout << j + 1 << ". " << PartOfMuscle_[j] <<endl;    //Numer, nazwa partii używając interacji z pętli
                }

                    int choice;

                        cin >> choice;

                    SelectedMuscleParts_.push_back(PartOfMuscle_[choice - 1]);    //Indeksowanie wektora
            }
        }

    void ShowWorkoutPlan() {    //Deklaracja funkcji

        cout << "Oto przykładowy trening stworzony dla Ciebie:" << endl;    //Wypisanie komunikatu

        for (const auto& MusclePart : SelectedMuscleParts_) {   //Pętla for-each, iteruje elementy wektora i selectedMuscleParts_ i przypisuje wartość każego elementu do zmiennej musclePart

            cout << endl << "Ćwiczenia dla wybranej partii mięśniowej: " << MusclePart << endl << endl;

                if (MusclePart == "klata") {

                        cout << "1. Barbell Bench Press - 4 serie od 8 do 12 powtórzen" << endl;

                        cout << "2. Dumbbell Incline Chest Flys - 4 serie od 8 do 12 powtórzeń" << endl << endl;

                } else if (MusclePart == "plecy") {

                        cout << "1. Pull Ups - 5 serii od 5 do 10 powtórzeń" << endl;

                        cout << "2. Machine Pulldown - 4 serie od 8 do 12 powtórzeń" << endl << endl;

                } else if (MusclePart == "nogi") {

                        cout << "1. Squat - 4 serie od 8 do 12 powtórzeń" << endl;

                        cout << "2. Lunges - 4 serie od 8 do 12 powtórzeń" << endl << endl;

                } else if (MusclePart == "biceps") {

                        cout << "1. Barbell Curl - 3 serie od 8 do 12 powtórzeń" << endl;

                        cout << "2. Hammer Curl - 3 serie od 8 do 12 powtórzeń" << endl << endl;

                } else if (MusclePart == "triceps") {

                        cout << "1. Cable push down  - 3 serie od 6 do 10 powtórzeń" << endl;

                        cout << "2. Skullcrusher - 4 serie od 6 do 10 powtórzeń" << endl << endl;
                }
            }
        }
};

int main() {

    string name;

    cout << "Podaj swoje imię: ";

    cin >> name;

    WorkoutPlan plan(name);

    plan.Run();

    return 0;
}
//Koniec aplikacji
