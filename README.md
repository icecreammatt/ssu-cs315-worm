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

Munchies that appear inside the worm will disappear after worm completely leaves the space. Going over this space after with the worm will read from uninitialized memory
and shoot the score up very high. This will eventually lead to a crash.

Munchies can appear inside the worms body as I didn't have enough time to fully implement an auto updating free pool.

Munchies can also appear inside of the top wall due to the same reasons that the worm can walk inside the top wall.
