

read -p "Input file name: " filename
read -p "Input string to be searched in file: " string

echo
freq=$(grep -o $string $filename | wc -l)
if [ $freq == 0 ]
then
	echo "No \"$string\" found in file \"$filename\""
	exit 1
fi

echo "Occurence of \"$string\" in file \"$filename\" is : $freq"

freqarr=(`grep -o -n $string $filename | cut -d : -f 1 | uniq -c`) 
						#  -o print matched part
						#  -n print matched line and line number
#grep -o -n $string $filename 					
#3:scanf
#4:scanf
#4:scanf
#5:scanf

#grep -n -o $string $filename #| cut -d : -f 1 | uniq -c

echo -e "\tLine number \tFrequency"


for(( i=0; i<${#freqarr[@]}; i+=2 ))
do 
	echo -e "\t${freqarr[$i+1]} \t\t${freqarr[$i]}"
done
echo
