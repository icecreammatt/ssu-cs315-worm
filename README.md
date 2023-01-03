# Worm

Author: Matt Carrier  
Class: CS315: Project 4 - Worm  

## Building

Run `nix-shell` to create a build environment and run the initial compile. Run `make` for subsequent builds.

## Running

Run `./worm` to start the game.

## Controls

`w`, `a`, `s`, `d` or `i`, `j`, `k`, `l` to move the worm.

## Known issues program

Score can randomly shoot up extremely high I believe there might be some uninitalized memory

Munchies can appear inside the worms body as I didn't have enough time to fully implement an auto updating free pool.

Munchies can also appear inside of the top wall due to the same reasons that the worm can walk inside the top wall.

In the very beginning the worm can go through itself because the freepool isn't updated, but after it moves out of the initial position it will collide with itself.
