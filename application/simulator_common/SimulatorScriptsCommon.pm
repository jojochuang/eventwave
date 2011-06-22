package SimulatorScriptsCommon;

use strict;

sub findSimulator {
  # Find the simulator executable by searching various places. Returns the path, else die.

  # Search Environment
  if (defined $ENV{"MACE_SIMULATOR"}
      and -x $ENV{"MACE_SIMULATOR"}) {
    return $ENV{"MACE_SIMULATOR"};
  }

  # Search PATH
  my $simulator_executable_name = "mace_simulator";
  my $path;
  foreach $path (split(/:/, $ENV{"PATH"})) {
    my $filename = $path . "/" . $simulator_executable_name;
    if (-x $filename) {
      return $filename;
    }
  }
  
  die "Cannot locate the Simulator! Try setting MACE_SIMULATOR environment or put mace_simulator in PATH.\n";
}

1;
