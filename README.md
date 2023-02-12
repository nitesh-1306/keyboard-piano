# Keyboard Piano

Keyboard Piano is a simple command-line piano program that allows you to play tunes using your computer keyboard. It uses the SDL and SDL_mixer libraries to provide audio playback and a basic piano interface.

## Features

- Play tunes using your computer keyboard.
- Supports playing multiple tunes simultaneously.
- Comes with a default "Happy Birthday" tune.
- Easy-to-use command-line interface.

## Requirements

Before using Keyboard Piano, make sure you have the following dependencies installed:

- [SDL](https://www.libsdl.org/)
- [SDL_mixer](https://www.libsdl.org/projects/SDL_mixer/)

## Installation

### Windows

1. **Download SDL and SDL_mixer for Windows:**

   - Go to the [SDL download page](https://www.libsdl.org/download-2.0.php).
   - Download the "Development Libraries" for Windows.
   - Go to the [SDL_mixer download page](https://www.libsdl.org/projects/SDL_mixer/).
   - Download the "Development Libraries" for Windows.

2. **Install SDL and SDL_mixer:**

   - Extract the downloaded SDL and SDL_mixer archives.
   - Copy the necessary `.dll` files from the archives to your system's `System32` directory (e.g., `C:\Windows\System32`).

3. **Compile and Run:**

   - Use your preferred C/C++ compiler to compile the Keyboard Piano source code.
   - Run the executable.

### Linux

1. **Install SDL and SDL_mixer using your package manager:**

   - On Ubuntu or Debian-based systems:

     ```bash
     sudo apt-get install libsdl2-dev libsdl2-mixer-dev
     ```

   - On Fedora:

     ```bash
     sudo dnf install SDL2-devel SDL2_mixer-devel
     ```

   - On CentOS:

     ```bash
     sudo yum install SDL2-devel SDL2_mixer-devel
     ```

2. **Compile and Run:**

   - Use your preferred C/C++ compiler to compile the Keyboard Piano source code.
   - Run the executable.

3. **For Compilation:**

    - Compile - 
    ```bash
    g++ -o piano keyboardpiano.cpp -I/usr/include/SDL2 -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_mixer -lncurses
    ```
    - Run Executable - 
    ```bash
    ./piano
    ```
## Usage

- Run the Keyboard Piano executable.
- Follow the on-screen instructions to start playing tunes using your keyboard.
- Enter a tune number from 0 to 9 to play a tune.
- Press 'q' to quit the program.

## Sample Tunes

You can add your own MP3 tunes to the `piano_tunes` directory or use the default "Happy Birthday" tune included with the program.

## License

This project is licensed under the MIT License - see the [LICENSE](https://choosealicense.com/licenses/mit/) file for details.
