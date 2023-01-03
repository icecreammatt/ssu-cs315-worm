with import <nixpkgs> {};

stdenv.mkDerivation {
    name = "worm";

    buildInputs = [ ncurses6 gdb ];

    shellHook = ''
      make
    '';

}
