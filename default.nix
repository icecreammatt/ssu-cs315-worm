{ lib , llvmPackages_11, ncurses6 }:

llvmPackages_11.stdenv.mkDerivation rec {
  pname = "worm";
  version = "0.1.0";
  
  src = ./.;

  nativeBuildInputs = [ ];

  buildInputs = [ ncurses6 ];

  buildPhase = "make";

  installPhase = "mkdir -p $out/bin; install -t $out/bin worm";

  cmakeFlags = [ ];

  meta = with lib; {
    homepage = "https://github.com/icecreammatt/ssu-cs315-worm";
    description = ''
      Terminal CLI Worm Game
    '';
    platforms = with platforms; linux ++ darwin;
  };
}
