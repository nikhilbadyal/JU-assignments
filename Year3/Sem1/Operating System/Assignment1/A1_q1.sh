
echo "Enter two numbers: "
read a b

# perform addition
add=`expr "$a + $b" | bc`
# perform subtraction
sub=`expr "$a - $b" | bc`
# perform multiplication
mul=`expr "$a * $b" | bc`
#perform division
div=`expr "$a / $b" | bc -l`

# show result
echo "Add: $add"
echo "multiplication: $mul"
echo "division: $div"
echo "Subtraction: $sub"


#reading two strings
echo "Enter First String"
read word1
echo "Enter Second String"
read word2

#concatinating
c="${word1} ${word2}"
echo "concatination : ${c}"

#finding common substring
if [ ${#word1} -lt ${#word2} ]
then
	temp=$word1;
        word1=$word2;
        word2=$temp
fi

for ((i=${#word2}; i>0; i--)); do
     echo $i 
        for ((j=0; j<=${#word2}-i; j++)); do
        	echo "j: $j"
        	#echo ${word2:j:i}
                if [[ $word1 =~ ${word2:j:i} ]]
                then
                        echo "substring : "${word2:j:i}
                        exit
                fi
        done
done


