# 2048 Game

* A simple 2048 game written in C++ with CLI Graphics using ncurses.
* Author : Nachiket Agrawal (C++), and Amit Chauhan (Code Refactoring and Makefile) 

Instructions
----

> Cloning the repository

        cd ~
        git clone https://github.com/regalmoix/2048.git
        cd ~/2048

> [Optional] Using Development branch (Output bugs untested) for minimal version.s

        git checkout development

>  Building the source

        make

>  Running the executable

        ./build/game
>  [Optional] Building and running

        make run
        
>  [Optional] Cleaning Build

        make clean

Rules
----
* w, s, a, d to do the moves in up, down, left, right directions respectively.
* For development branch use w, s, a, d followed by Enter to move.
* Score is incremented by the sum of values of the newly merged tiles.
* Game ends when no empty tiles remain and no more moves possible.
* Press Esc to quit the game early. Progress will be lost.

License
----

GNU GPL v3.0

