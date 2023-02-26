{
  description = "Worm CLI game";

  inputs = {
    # Pointing to the current stable release of nixpkgs. You can
    # customize this to point to an older version or unstable if you
    # like everything shining.
    #
    # E.g.
    #
    # nixpkgs.url = "github:NixOS/nixpkgs/unstable";
    nixpkgs.url = "github:NixOS/nixpkgs/22.11";

    utils.url = "github:numtide/flake-utils";

  };

  outputs = { self, nixpkgs, ... }@inputs: inputs.utils.lib.eachSystem [
    # Add the system/architecture you would like to support here. Note that not
    # all packages in the official nixpkgs support all platforms.
    "x86_64-linux" "aarch64-linux" "x86_64-darwin" "aarch64-darwin"
  ] (system: let pkgs = import nixpkgs { inherit system; };
  in {

    # This block here is used when running `nix develop`
    devShells.default = pkgs.mkShell rec {
      # Update the name to something that suites your project.
      name = "worm";

      packages = with pkgs; [
        llvmPackages_14.clang
        ncurses6
      ];

      # Setting up the environment variables you need during development.

      # Todo figure out why I can't use clang on Asahi but can on Darwin
      # Use "clang++" for most systems but OSX Asahi requires g++ for some reason or a runtime error occurs
      shellHook = let
        # This is for an icon that is used below for the command line input below
        icon = "f121";
      in ''
        export PS1="$(echo -e '\u${icon}') {\[$(tput sgr0)\]\[\033[38;5;228m\]\w\[$(tput sgr0)\]\[\033[38;5;15m\]} (${name}) \\$ \[$(tput sgr0)\]"
        export COMPILER="clang++"
        #export COMPILER="g++"
        make
      '';
    };

    # This is used when running `nix build`
    packages.default = pkgs.llvmPackages_14.stdenv.mkDerivation rec {
      name = "worm";
      version = "0.1.1";
  
      src = self;

      buildInputs = [ pkgs.ncurses6 ];

      buildPhase = "COMPILER='clang++' make";

      installPhase = ''
        mkdir -p $out/bin; 
        install -t $out/bin worm
      '';

      meta = with inputs.utils.lib; {
        homepage = "https://github.com/icecreammatt/ssu-cs315-worm";
        description = ''
          Terminal CLI Worm Game
        '';
      };
    };
  });

}
