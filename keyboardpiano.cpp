#include <iostream>
#include <string>
#include <thread>
#include <vector>

// SDL (Simple DirectMedia Layer)
//  - multimedia library that provides crossplatform access to audio, keyboard, mouse, etc.
// SDL Mixer
//  - extension for SDL, focusing on audio playback.
#include <SDL.h>
#include <SDL_mixer.h>
#include <ncurses.h>

using namespace std;

class Piano {
public:
    Piano() {
        initscr();
        cbreak();
        noecho();
        keypad(stdscr, TRUE);

        if (SDL_Init(SDL_INIT_AUDIO) < 0) {
            cerr << "SDL initialization failed: " << SDL_GetError() << endl;
            endwin();
            exit(1);
        }

        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
            cerr << "SDL_mixer initialization failed: " << Mix_GetError() << endl;
            SDL_Quit();
            endwin();
            exit(1);
        }
    }

    ~Piano() {
        Mix_CloseAudio();
        SDL_Quit();
        endwin();
    }

    void startPiano() {
        int tuneNumber;
        vector<thread> threads;

        printPiano();

        while (true) {
            mvprintw(14, 0, "Happy Birthday Tune - 223254 223265 2265432 665432\nEnter a tune number from 0 to 9 to play (or 'q' to quit): ");
            refresh();

            int key = getch();
            if (key == 'q') {
                break;
            }

            tuneNumber = key - '0';

            if (tuneNumber >= 0 && tuneNumber <= 9) {
                threads.push_back(thread(playTune, tuneNumber));
            }
            else {
                mvprintw(15, 0, "Invalid tune number. Please enter a number from 0 to 9.");
                refresh();
            }
        }

        for (auto& thread : threads) {
            thread.join();
        }
    }

private:
    void printPiano() {
        mvprintw(0, 0, "=============================================================================");
        mvprintw(1, 0, "|-------------------------------[Keyboard Piano]----------------------------|");
        mvprintw(2, 0, "=============================================================================");
        mvprintw(3, 0, "|                 ___________________________________________               |");
        mvprintw(4, 0, "|                 ||=======================================||               |");
        mvprintw(5, 0, "|                 |-----------------------------------------|               |");
        mvprintw(6, 0, "|                 || C | D | E | F | G | A | B | C | D | E ||               |");
        mvprintw(7, 0, "|                 || ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ ||               |");
        mvprintw(8, 0, "|                 || 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 ||               |");
        mvprintw(9, 0, "|___________________=== === === === === === === === === ===_________________|");
    }

    static string getTuneFilename(int tune_number) {
        return "piano_tunes/" + to_string(tune_number) + ".mp3";
    }

    static void playTune(int tune_number) {
        string tuneFilename = getTuneFilename(tune_number);

        Mix_Music* music = Mix_LoadMUS(tuneFilename.c_str());
        if (!music) {
            cerr << "Failed to load MP3: " << Mix_GetError() << endl;
            return;
        }

        mvprintw(11, 0, "Playing tune %d...", tune_number);
        refresh();

        Mix_PlayMusic(music, 0);
        SDL_Delay(3000);
        Mix_FreeMusic(music);

        mvprintw(11, 0, "                        ");
        refresh();
    }
};

int main() {
    Piano piano;
    cout << "Do you want to start the piano? (Y/N): ";
    char response;
    cin >> response;
    if (response == 'Y' || response == 'y') {
        piano.startPiano();
    }
    return 0;
}



// For compilation use "g++ -o piano piano.cpp -I/usr/include/SDL2 -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_mixer -lncurses"