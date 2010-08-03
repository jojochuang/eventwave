package Mace::Compiler::MInclude;

use Mace::Compiler::Globals;

sub expandFile {
    my $filename = shift;
    my $lines = shift;
    my $oldline = shift || 0;
    my $oldfile = shift || "";

    my $errMsg = "";
    my $errFlag = 0;

    my $path = Mace::Util::findPath($filename, @Mace::Compiler::Globals::INCLUDE_PATH);
    if ($path ne "") {
        $path .= "/"
    }
    if (not open(IN, "$path$filename")) {
        $errMsg = $!;
        $errFlag = 1;
    } 

    if ($errFlag) {
        Mace::Compiler::Globals::error('minclude', $oldfile, $oldline, "Can't open file $filename: $errMsg");
        return -1;
    }

    my @in = <IN>;
    close(IN);

    push(@$lines, qq{#line 1 "$path$filename"\n});

    my $lineno = 1;
    for my $msg (@in) {
        if ($msg =~ /^\s*#minclude\s+"(\S+)"\s*$/) {
            if (expandFile($1, $lines, $lineno, $filename) < 0) { 
                Mace::Compiler::Globals::error('minclude', $oldfile, $oldline, "Error in sub-file included from here.");
            }
            $lineno++;
            push(@$lines, qq{#line $lineno "$path$filename"\n});
        } else {
            push(@$lines, $msg);
            $lineno++;
            if ($msg =~ /^\s*#line\s+([0-9]+)\s+"(\S+)"\s*$/) {
                $lineno = $1;
                $filename = $2;
            } elsif ($msg =~ /^\s*#line\s+([0-9]+)\s*$/) {
                $lineno = $1;
            }
        }
    }

    return 0;
}

sub getLines {
    my $filename = shift;
    my $lines = shift;
    my $linemap = shift;
    my $filemap = shift;
    my $offsetmap = shift;

    my $i = 1;
    my $offset = 0;
    my $lineno = 1;
    #my $file = $filename;

    my $path = Mace::Util::findPath($filename, @Mace::Compiler::Globals::INCLUDE_PATH);
    if ($path ne "") {
        $path .= "/"
    }

    my $file = "$path$filename";

    $linemap->[0] = 0;
    $filemap->[0] = $file;
    $offsetmap->[0] = 0;

    #open(OUT, ">>", "/tmp/bar");
    
    #print OUT "*** File: $file\n";

    for my $line (@$lines) {
        $linemap->[$i] = $lineno;
        $filemap->[$i] = $file;
        $offsetmap->[$i] = $offset;

        #print OUT "$i:$file:$lineno:$offset $line";
        #print "Line $i at $lineno of $file\n";

        $lineno++;
        $offset += length($line);

        if ($line =~ m/^\s*#line\s+(\d+)\s+"([^"]+)"\s*/) {
            $lineno = $1;
            $file   = $2;
            my $path = Mace::Util::findPath($file, @Mace::Compiler::Globals::INCLUDE_PATH);
            if ($path ne "") {
                $path .= "/"
            }
            my $file = "$path$file";
        }
        elsif ($line =~ m/^\s*#line\s+(\d+)\s*/) {
            $lineno = $1;
        }

        $i++;
    }

    #close(OUT);
}

1;
