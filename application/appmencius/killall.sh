names=( cloud03 cloud04 cloud05 cloud06 cloud07 cloud08 cloud09 cloud10 cloud11 )

pkill mencius

for (( i = 0 ; i < ${#names[@]} ; i++ ))
do
/scratch/yoo7/mace-project/mace/application/appmencius/sshdo.exp r3530t71bb ${names[$i]} pkill mencius
done

