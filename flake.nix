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
    "x86_64-linux" "i686-linux" "aarch64-linux" "x86_64-darwin" "aarch64-darwin"
  ] (system: let
    pkgs = import nixpkgs {
      inherit system;

      # Add overlays here if you need to override the nixpkgs
      # official packages.
      overlays = [];
      
      # Uncomment this if you need unfree software (e.g. cuda) for
      # your project.
      #
      # config.allowUnfree = true;
    };
  in {
    devShells.default = pkgs.mkShell rec {
      # Update the name to something that suites your project.
      name = "worm";

      packages = with pkgs; [
        llvmPackages_14.clang
        ncurses6
      ];

      # Setting up the environment variables you need during
      # development.
      # Todo figure out why I can't use clang on Asahi but can on Darwin
      # Use "clang++" for most systems but OSX Asahi requires g++ for some reason or a runtime error occurs
      shellHook = let
        icon = "f121";
      in ''
        #export COMPILER="clang++"
        export COMPILER="g++"
        make
      '';
    };

    packages.default = pkgs.callPackage ./default.nix {};
  });
}
