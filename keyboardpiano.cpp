#include <iostream>
#include <string>

// SDL (Simple DirectMedia Layer)
//  - multimedia library that provides crossplatform access to audio, keyboard, mouse, etc.
// SDL Mixer
//  - extension for SDL, focusing on audio playback.
#include <SDL.h>
#include <SDL_mixer.h>

using namespace std;

void print_piano();
string get_tune_filename(int tune_number);
void play_tune(int tune_number);

int main() {

    print_piano();

    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        cerr << "SDL initialization failed: " << SDL_GetError() << endl;
        return 1;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        cerr << "SDL_mixer initialization failed: " << Mix_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    string tuneFilename;
    int tuneNumber;

    while (true) {
        cout << "Enter a tune number from 0 to 9 to play (or -1 to quit): ";
        cin >> tuneNumber;

        if(tuneNumber == -1){
            break;
        }

        if(tuneNumber >= 0 && tuneNumber <= 9){
            tuneFilename = get_tune_filename(tuneNumber);

            Mix_Music* music = Mix_LoadMUS(tuneFilename.c_str());
            if (!music) {
                cerr << "Failed to load MP3: " << Mix_GetError() << endl;
                continue;
            }

            cout << "Playing tune " << tuneNumber << "..." << endl;

            Mix_PlayMusic(music, 0);
            while (Mix_PlayingMusic()) {
                SDL_Delay(100);
            }

            Mix_FreeMusic(music);
        }
        else{
            cout << "Invalid tune number. Please enter a number from 0 to 9." << endl;
        }
    }

    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}

string get_tune_filename(int tune_number) {
    return "piano_tunes/" + to_string(tune_number) + ".mp3";
}

void print_piano() {
    cout << "=============================================================================\n"
            "|-------------------------------[Keyboard Piano]----------------------------|\n"
            "=============================================================================\n"
            "|                 ___________________________________________               |\n"
            "|                 ||=======================================||               |\n"
            "|                 |-----------------------------------------|               |\n"
            "|                 || C | D | E | F | G | A | B | C | D | E ||               |\n"
            "|                 || ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ ||               |\n"
            "|                 || 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 ||               |\n"
            "|___________________=== === === === === === === === === ===_________________|\n\n";
}

// g++ -o piano piano.cpp -I/usr/include/SDL2 -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_mixer
