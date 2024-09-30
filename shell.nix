let
  pkgs = import <nixpkgs> {};
in pkgs.mkShell rec {
  buildInputs = with pkgs; [ 
    clang
    gcc13
    gnumake
    pylint
    libGL
    armadillo
  ];
  
  nativeBuildInputs = with pkgs.buildPackages; [
    clang-tools
    cmakeWithGui
  ];
  
  LD_LIBRARY_PATH = "${pkgs.lib.makeLibraryPath buildInputs}";

  CFLAGS = "-I${pkgs.lib.makeIncludePath buildInputs}";
}
