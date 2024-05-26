#include <iostream>
#include <ctime>
#include <conio.h>
#include <cctype>
using namespace std;

string player_name;
long cash = 0;
long question_price = 1000;
int question_no = 1;
const long CHECKPOINT1 = 7000;
const long CHECKPOINT2 = 127000;
const long FINAL_PRIZE = 1000000;
long last_checkpoint = 0;

void results(bool won);
void game_rules();
void random_q();
void check_answer(char answer, char correct_answer);

struct Question {
    string question;
    string option_a;
    string option_b;
    string option_c;
    string option_d;
    char answer;
    bool availability;
};

Question questions[10];

int main() {
    system("cls");
    questions[0] = {"Who was the Mughal emperor of India during the Battle of Plassey in 1757? ", "Akbar II", "Bahadur Shah II", "Alamgir II", "Ahmad Shah Bahadur", 'c', true};
    questions[1] = {"Who won the Nobel Prize in Physics in 2020 for the discovery of a supermassive compact object at the center of our galaxy? ", "James Peebles", "Andrea Ghez", "Kip Thorne", "Reinhard Genzel", 'b', true};
    questions[2] = {"Which novel by Salman Rushdie won the Booker Prize in 1981? ", "The Satanic Verses", "Midnight's Children", "The Moor's Last Sigh", "Shame", 'b', true};
    questions[3] = {"Which desert is the largest hot desert in the world? ", "Kalahari", "Arabian", "Gobi", "Sahara", 'd', true};
    questions[4] = {"Who is known as the 'Father of Econombics'? ", "John Maynard Keynes", "Adam Smith", "Milton Friedman", "Karl Marx", 'b', true};
    questions[5] = {"Who was the first Deputy Prime Minister of India? ", "Vallabhbhai Patel", "Morarji Desai", "Charan Singh", "Lal Bahadur Shastri", 'a', true};
    questions[6] = {"In which year did the Berlin Wall fall? ", "1987", "1988", "1989", "1990", 'c', true};
    questions[7] = {"What is the most abundant gas in the Earth's atmosphere? ", "Oxygen", "Carbon Dioxide", "Nitrogen", "Hydrogen", 'c', true};
    questions[8] = {"Which composer wrote the opera 'The Magic Flute'? ", "Ludwig van Beethoven", "Richard Wagner", "Wolfgang Amadeus Mozart", "Giuseppe Verdi", 'c', true};
    questions[9] = {"In Greek mythology, who is considered the king of the gods? ", "Poseidon", "Hades", "Zeus", "Apollo", 'c', true};

    cout << "WELCOME TO KAUN BANEGA KARORPATI GAME SHOW" << endl;
    cout << "ENTER YOUR NAME: ";
    getline(cin, player_name);
    system("cls");
    game_rules();

    while (true) {
        if (question_no > 10) {
            cash = FINAL_PRIZE;
            break;
        }
        random_q();
    }

    results(question_no > 10);
    return 0;
}

void game_rules() {
    cout << "GAME RULES:" << endl;
    cout << "1. Answer the questions correctly to earn cash prizes." << endl;
    cout << "2. Each correct answer doubles the cash prize for the next question." << endl;
    cout << "3. A wrong answer will end the game." << endl;
    cout << "4. Checkpoints at Rs.7000 and Rs.127000 guarantee those amounts if reached." << endl;
    cout << "5. You can quit before any question to take the current cash." << endl;
    cout << "6. Answer all 10 questions correctly to win Rs.1000000." << endl;
    cout << "Press any key to start..." << endl;
    _getwch();
}

void random_q() {
    srand(time(0));
    while (true) {
        system("cls");
        int number = rand() % 10;
        if (questions[number].availability) {
            questions[number].availability = false;
            cout << "WELCOME TO KAUN BANEGA KARORPATI GAME SHOW" << endl;
            cout << endl;
            cout << "THIS IS QUESTION NO: " << question_no << " FOR Rs " << question_price << "\t\t\t\tPURSE: Rs " << cash << endl;
            cout << "Choose your option (Press 'q' to quit):" << endl;
            cout << questions[number].question << endl << endl;
            cout << "A) " << questions[number].option_a << "\t\tB) " << questions[number].option_b << endl << endl;
            cout << "C) " << questions[number].option_c << "\t\tD) " << questions[number].option_d << endl << endl;
            char answer = _getwch();
            answer = tolower(answer);
            cout << endl;

            if (answer == 'q') {
                results(false);
                exit(0);
            }

            question_no++;
            check_answer(answer, questions[number].answer);
            break;
        }
    }
}

void check_answer(char answer, char correct_answer) {
    if (answer == correct_answer) {
        cout << "CONGRATULATIONS...! YOUR ANSWER IS RIGHT" << endl;
        cout << "YOU EARNED Rs " << question_price << endl;
        cout << "PRESS ANY KEY TO CONTINUE..." << endl;
        _getwch();
        cash += question_price;

        if (cash >= CHECKPOINT1 && last_checkpoint < CHECKPOINT1) {
            last_checkpoint = CHECKPOINT1;
        } else if (cash >= CHECKPOINT2 && last_checkpoint < CHECKPOINT2) {
            last_checkpoint = CHECKPOINT2;
        }

        question_price *= 2;
    } else {
        cout << "SORRY...! YOUR ANSWER IS WRONG..." << endl;
        cout << "YOU LOST!!!" << endl;
        cout << "PRESS ANY KEY TO CONTINUE..." << endl;
        _getwch();
        cash = last_checkpoint;
        results(false);
        exit(0);
    }
}

void results(bool won) {
    system("cls");
    if (won) {
        cout << "CONGRATULATIONS! YOU HAVE WON Rs " << cash << "!" << endl;
    } else {
        cout << "Your final winnings are Rs " << cash << endl;
    }
    cout << "THANK YOU FOR PLAYING!" << endl;
}



