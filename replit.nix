{ pkgs }: {
	deps = [
		pkgs.twelf
  pkgs.run
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}