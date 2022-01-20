searchstrings=("printf" "scanf" "int")
filenames=($1 $2 $3)
if [[ ! -f "$1" ||  ! -f "$2" || ! -f "$3" ]]
then
    echo "Some files don't exist"
    exit 1
fi
echo "-----------------------------------------------------------------------------"
echo -e "Name of the file\t${searchstrings[0]}\t\t${searchstrings[1]}\t\t${searchstrings[2]}\t"
echo "-----------------------------------------------------------------------------"
for file in ${filenames[*]}
do
	echo -n -e "\t$file\t"
	for string in ${searchstrings[*]}
	do
		freq=$(grep -o -w "$string" $file  | wc -l )
		echo -n -e "\t$freq\t"
	done
	echo
done

echo "-----------------------------------------------------------------------------"
echo

