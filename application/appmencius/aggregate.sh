cat ../../../build/mace/application/appmencius/$1 | grep "real" | sed 's/real 0m//g' | sed 's/s//g'
