#read -p "Input file name: " 
filename="exampleFile1.txt"
string="saman"
#read -p "Input string to be searched in file: " string

echo
freq=$(grep -o $string $filename | wc -l)
if [ $freq == 0 ]
then 
	echo "No \"$string\" found in file \"$filename\""
	exit 1
fi

#read -p "Now Input string to be replaced with: " 
replacestring="aman"

sed -i 's/'"$string"'/'"$replacestring"'/g' $filename
